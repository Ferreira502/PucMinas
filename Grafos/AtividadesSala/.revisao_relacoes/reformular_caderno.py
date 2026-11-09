"""Respostas diretas, desenhos vetoriais preservados e fórmulas diagramadas."""
from pathlib import Path
from functools import lru_cache
from itertools import combinations
from io import BytesIO
import json,re
import pymupdf as pdf
from matplotlib import font_manager
from matplotlib.mathtext import math_to_image

BASE=Path(__file__).resolve().parent.parent
SOURCE=BASE/'.revisao_relacoes/caderno_base_antes_reformulacao.pdf'
OUT=BASE/'.Caderno_Reformulado.pdf'
src=pdf.open(SOURCE);doc=pdf.open();doc.insert_pdf(src)
assert len(doc)==72
W,H=595.28,841.89;M=42;CW=W-2*M
INK=(.09,.17,.25);TEAL=(0,.40,.42);GREY=(.41,.48,.53);LIGHT=(.91,.95,.95);WHITE=(1,1,1);RED=(.70,.16,.20)
FB={k:Path(font_manager.findfont(font_manager.FontProperties(family='DejaVu Sans',weight='bold' if k=='bold' else 'normal'))).read_bytes() for k in ['body','bold']}
F={k:pdf.Font(fontbuffer=v) for k,v in FB.items()}
toc=[];log=[];mathcache={};formula_log=[]

def wrap(s,width,size=10.5,font='body'):
    out=[]
    for para in str(s).split('\n'):
        line=''
        for word in para.split():
            trial=(line+' '+word).strip()
            if line and F[font].text_length(trial,fontsize=size)>width:out.append(line);line=word
            else:line=trial
        out.append(line)
    return out

def formula_doc(tex):
    assert not any(ord(c)<32 for c in tex),repr(tex)
    tex=tex.replace(r'\bigl(',r'\left(').replace(r'\bigr)',r'\right)')
    tex=tex.replace(r'\land',r'\wedge')
    tex=re.sub(r'\\ge(?![a-zA-Z])',r'\\geq',tex)
    tex=re.sub(r'\\le(?![a-zA-Z])',r'\\leq',tex)
    if tex not in mathcache:
        buf=BytesIO()
        math_to_image('$'+tex+'$',buf,format='svg',prop=font_manager.FontProperties(size=14),dpi=144)
        svgdata=buf.getvalue().replace(b'fill: #ffffff',b'fill: none')
        svg=pdf.open(stream=svgdata,filetype='svg')
        mathcache[tex]=pdf.open(stream=svg.convert_to_pdf(),filetype='pdf')
    return mathcache[tex]

class Page:
    def __init__(self,n,chapter,title,bookmark=False):
        self.n=n;self.p=doc[n-1]
        for link in self.p.get_links():self.p.delete_link(link)
        self.p.add_redact_annot(self.p.rect,fill=WHITE,cross_out=False)
        self.p.apply_redactions(images=2,graphics=2)
        for k,v in FB.items():self.p.insert_font(fontname='r'+k,fontbuffer=v)
        self.p.draw_rect(pdf.Rect(0,0,W,8),color=None,fill=TEAL)
        self.txt(M,32,chapter.upper(),8.3,TEAL,'bold');self.y=53
        for line in wrap(title,CW,21,'bold'):
            self.txt(M,self.y+21,line,21,INK,'bold');self.y+=26
        self.y+=14
        self.p.draw_line((M,H-43),(W-M,H-43),color=LIGHT,width=.9)
        self.txt(M,H-27,'GRAFOS • Pergunta, resposta, desenho e demonstração',8,GREY)
        self.txt(W-M-20,H-27,n,8,TEAL,'bold')
        if bookmark:toc.append([1,title,n])
    def txt(self,x,y,s,size=10.5,color=INK,font='body'):
        self.p.insert_text((x,y),str(s),fontname='r'+font,fontsize=size,color=color)
    def need(self,h):
        if self.y+h>H-63:raise RuntimeError(f'Página {self.n}: altura {self.y:.1f}+{h:.1f}')
    def para(self,s,size=10.5,bold=False,color=INK,space=9):
        f='bold' if bold else 'body';ls=wrap(s,CW,size,f);lh=size*1.45;self.need(len(ls)*lh+space)
        for line in ls:self.txt(M,self.y+size,line,size,color,f);self.y+=lh
        self.y+=space
    def sub(self,s):self.para(s,12,True,TEAL,space=8)
    def answer(self,s):
        ls=wrap(s,CW-28,10.7);height=36+len(ls)*15.3;self.need(height+12)
        self.p.draw_rect(pdf.Rect(M,self.y,W-M,self.y+height),color=None,fill=LIGHT)
        self.p.draw_rect(pdf.Rect(M,self.y,M+4,self.y+height),color=None,fill=TEAL)
        self.txt(M+14,self.y+17,'Resposta direta',10.2,TEAL,'bold')
        for i,line in enumerate(ls):self.txt(M+14,self.y+36+i*15.3,line,10.7)
        self.y+=height+12
    def math(self,*equations,title='Fórmula e cálculo'):
        entries=[]
        for eq in equations:
            d=formula_doc(eq);r=d[0].rect;scale=min(1,(CW-28)/r.width)
            entries.append((eq,d,r.width*scale,r.height*scale))
        height=32+sum(h+9 for eq,d,w,h in entries)+5;self.need(height+11)
        self.p.draw_rect(pdf.Rect(M,self.y,W-M,self.y+height),color=None,fill=(.96,.97,.98))
        self.txt(M+14,self.y+17,title,10.2,TEAL,'bold');y=self.y+28
        for eq,d,w,h in entries:
            self.p.show_pdf_page(pdf.Rect(M+14,y,M+14+w,y+h),d,0)
            formula_log.append((self.n,eq));y+=h+9
        self.y+=height+11
    def diagram(self,source_page=None,height=170,pair=True):
        source_page=source_page or self.n;p=src[source_page-1]
        circles=[s for s in p.get_drawings() if s.get('fill') is not None and any(it[0]=='c' for it in s['items'])]
        assert circles,source_page
        r=pdf.Rect(circles[0]['rect'])
        for shape in circles[1:]:r|=shape['rect']
        r+=(-7,-7,7,7)
        self.need(height+38)
        if pair:
            self.txt(M,self.y+10,'G • grafo original',10,TEAL,'bold')
            self.txt(M+CW/2+13,self.y+10,'L(G) • grafo de linha',10,TEAL,'bold')
        else:self.txt(M,self.y+10,'Desenho do exemplo',10,TEAL,'bold')
        self.y+=20
        self.p.show_pdf_page(pdf.Rect(M,self.y,W-M,self.y+height),src,source_page-1,clip=r)
        self.y+=height+12
    def table(self,heads,rows,widths,size=9.1,links=None):
        for ri,row in enumerate([heads]+list(rows)):
            f='bold' if ri==0 else 'body';cells=[wrap(t,w-12,size,f) for t,w in zip(row,widths)]
            h=max(map(len,cells))*size*1.4+13;self.need(h);x=M
            for ci,(cell,width) in enumerate(zip(cells,widths)):
                r=pdf.Rect(x,self.y,x+width,self.y+h)
                self.p.draw_rect(r,color=WHITE,width=.7,fill=TEAL if ri==0 else LIGHT if ri%2 else (.97,.98,.98))
                for j,line in enumerate(cell):self.txt(x+6,self.y+size+5+j*size*1.4,line,size,WHITE if ri==0 else INK,f)
                if links and ri>0 and (ri-1,ci) in links:self.p.insert_link({'kind':pdf.LINK_GOTO,'from':r,'page':links[(ri-1,ci)]-1})
                x+=width
            self.y+=h
        self.y+=11
    def end(self):log.append((self.n,self.y))

class Graph:
    def __init__(self,edges):
        self.es=tuple(sorted({tuple(sorted(e)) for e in edges}));self.vs=sorted({v for e in self.es for v in e})
        self.adj={v:set() for v in self.vs}
        for a,b in self.es:self.adj[a].add(b);self.adj[b].add(a)
        self.ds={v:len(self.adj[v]) for v in self.vs}
    @property
    def odd(self):return [v for v in self.vs if self.ds[v]%2]
    def line(self):return Graph([(''.join(e),''.join(f)) for e,f in combinations(self.es,2) if set(e)&set(f)])
    def cycle(self):
        if min(self.ds.values())<2:return None
        start=self.vs[0];failed=set()
        def dfs(path,seen):
            v=path[-1]
            if len(path)==len(self.vs):return path+[start] if start in self.adj[v] else None
            key=(v,tuple(sorted(seen)))
            if key in failed:return None
            for w in sorted(self.adj[v]-seen):
                ans=dfs(path+[w],seen|{w})
                if ans:return ans
            failed.add(key)
        return dfs([start],{start})
    def trail(self):
        assert len(self.odd) in [0,2]
        a={v:set(ns) for v,ns in self.adj.items()};stack=[self.odd[0] if self.odd else self.vs[0]];ans=[]
        while stack:
            v=stack[-1]
            if a[v]:w=min(a[v]);a[v].remove(w);a[w].remove(v);stack.append(w)
            else:ans.append(stack.pop())
        return ans[::-1]

G={}
def graph(k,es):G[k]=Graph(es)
graph('c3',['ab','ac','bc']);graph('c4',['ab','bc','cd','ad']);graph('p4',['ab','bc','cd'])
graph('star3',['ab','ac','ad']);graph('bowtie',['ab','ac','bc','ad','ae','de'])
graph('k4',list(combinations('abcd',2)));graph('diamond',['ab','ac','bc','ad','bd'])
graph('paw',['ab','ac','bc','ad']);graph('double',['ab','ac','ad','be','bf'])
graph('substar',['ab','ac','ad','de']);graph('bowtail',['ab','ac','bc','ad','ae','de','af'])
graph('dumbbell',['ab','ac','bc','cd','de','df','ef'])
graph('subk4',['ax','bx']+[e for e in combinations('abcd',2) if e!=('a','b')])
graph('c6chords',['ab','bc','cd','de','ef','af','ac','df'])
graph('bull',['ab','ac','bc','ad','be']);graph('star4',['ab','ac','ad','ae'])
graph('substar2',['ab','ac','cd','ae','ef'])
def seq(path):return ' → '.join(path)
def degrees(g):return '; '.join(f'd({v})={g.ds[v]}' for v in g.vs)
def status(g):return ('euleriano' if not g.odd else 'semieuleriano aberto' if len(g.odd)==2 else 'sem trajeto euleriano')+('; hamiltoniano' if g.cycle() else '; não hamiltoniano')
def eqdegrees(g):return r',\quad '.join('d('+v+')='+str(g.ds[v]) for v in g.vs)

# Ordem do banco e páginas preservadas para manter a navegação.
questions=[
 ('G','euleriano','G','hamiltoniano','bowtie','Não. G pode ser euleriano sem ser hamiltoniano. Dois triângulos com um vértice comum são um contraexemplo.','O vértice a é de articulação: sua remoção separa os dois triângulos. Um ciclo hamiltoniano não pode existir nesse caso.'),
 ('G','hamiltoniano','G','euleriano','k4','Não. Ser hamiltoniano não exige graus pares. K₄ é hamiltoniano e não é euleriano.','O ciclo a→b→c→d→a visita todos os vértices. Porém os quatro vértices têm grau 3, impedindo circuito euleriano.'),
 ('G','euleriano','G','semieuleriano aberto','c3','Não, usando semieuleriano no sentido aberto. Um euleriano tem zero ímpares, enquanto um semieuleriano aberto tem dois.','C₃ é euleriano e não possui os dois vértices ímpares exigidos para um caminho euleriano aberto.'),
 ('G','semieuleriano aberto','G','euleriano','p4','Não. Se G possui exatamente dois vértices ímpares, não pode possuir circuito euleriano.','P₄ possui caminho euleriano a→b→c→d. Os extremos têm grau 1 e o percurso não pode fechar usando todas as arestas uma vez.'),
 ('G','semieuleriano aberto','G','hamiltoniano','p4','Não. Um caminho euleriano aberto não garante ciclo hamiltoniano. P₄ é um contraexemplo.','As folhas a,d têm grau 1. Um ciclo hamiltoniano precisaria de duas arestas incidentes em cada uma delas.'),
 ('G','hamiltoniano','G','semieuleriano aberto','c3','Não. Um grafo hamiltoniano pode ter zero ímpares. C₃ é hamiltoniano e não é semieuleriano aberto.','O próprio triângulo é um ciclo hamiltoniano, mas todos os seus graus são pares.'),
 ('G','euleriano','L(G)','euleriano','c3','Sim. Se G é euleriano, então L(G) também é euleriano: ele é conexo e cada um dos seus vértices tem grau par.','Para qualquer aresta e=uv de G, as duas pontas têm grau par. A fórmula exibida dá grau par para o vértice e de L(G). G conexo garante L(G) conexo; o teorema de Euler conclui a prova.'),
 ('G','euleriano','L(G)','semieuleriano aberto','c3','Não, no sentido aberto. Se G é euleriano, L(G) é euleriano e tem zero ímpares, não dois.','No exemplo G=C₃, o grafo de linha também é C₃. Isso refuta a afirmação que exige exatamente dois ímpares.'),
 ('G','euleriano','L(G)','hamiltoniano','c3','Sim. O circuito euleriano de G fornece um ciclo hamiltoniano em L(G), pois cada aresta percorrida vira um vértice visitado.','Escreva as arestas do circuito como e₁,…,eₘ. Todas são distintas e cobrem E. Consecutivas compartilham uma ponta, inclusive a última e a primeira. Em L(G), isso é um ciclo por todos os vértices, uma única vez.'),
 ('G','semieuleriano aberto','L(G)','euleriano','p4','Não. Nas hipóteses do caderno, G semieuleriano aberto não pode gerar L(G) euleriano.','Se L(G) fosse euleriano, todos os graus de G teriam a mesma paridade. G tem dois ímpares: não são todos pares; se todos fossem ímpares, haveria só dois vértices e no máximo uma aresta, contrariando |E|≥3. P₄ ilustra a falha.'),
 ('G','semieuleriano aberto','L(G)','semieuleriano aberto','diamond','Não. G pode ter dois vértices ímpares e L(G) ter quatro. O losango com diagonal é um contraexemplo.','Em G, a,b têm grau 3; c,d têm grau 2. Em L(G), ab tem grau 4; ac,ad,bc,bd têm grau 3. Portanto L(G) possui quatro ímpares e não tem caminho euleriano.'),
 ('G','semieuleriano aberto','L(G)','hamiltoniano','p4','Não. A trilha euleriana aberta garante um caminho hamiltoniano em L(G), mas não garante um ciclo hamiltoniano.','P₄ gera P₃. O caminho ab→bc→cd visita todos os vértices do grafo de linha, mas a última e a primeira não são adjacentes.'),
 ('G','hamiltoniano','L(G)','euleriano','diamond','Não. G pode ser hamiltoniano e L(G) possuir vértices de grau ímpar.','G tem ciclo hamiltoniano a→c→b→d→a. Porém L(G) possui quatro ímpares; assim não é euleriano.'),
 ('G','hamiltoniano','L(G)','semieuleriano aberto','c3','Não. C₃ é hamiltoniano e seu grafo de linha é euleriano, com zero ímpares.','Semieuleriano aberto exige exatamente dois ímpares. O triângulo mostra que essa conclusão não é garantida.'),
 ('G','hamiltoniano','L(G)','hamiltoniano','diamond','Sim. Se G é hamiltoniano, então L(G) também é hamiltoniano.','O ciclo hamiltoniano de G contém todos os vértices e tem grau interno 2 em cada um. Portanto é um subgrafo euleriano dominante. Insira as demais arestas de G na ordem circular junto de uma ponta comum; elas também passam a compor o ciclo em L(G).'),
 ('L(G)','euleriano','G','euleriano','star3','Não. L(G) pode ser euleriano mesmo que G tenha todos os graus ímpares.','A estrela K₁,₃ tem graus 3,1,1,1 e gera o triângulo K₃, de graus 2,2,2. G não é euleriano.'),
 ('L(G)','euleriano','G','semieuleriano aberto','star3','Não. L(G) euleriano não obriga G a ter exatamente dois ímpares.','Na estrela K₁,₃, G tem quatro ímpares, embora L(G)=K₃ seja euleriano.'),
 ('L(G)','euleriano','G','hamiltoniano','star3','Não. Um grafo de linha euleriano pode vir de uma árvore, que não tem ciclo hamiltoniano.','K₁,₃ tem folhas e não possui ciclo. Seu grafo de linha é o triângulo euleriano K₃.'),
 ('L(G)','semieuleriano aberto','G','euleriano','p4','Não. L(G) semieuleriano aberto não garante G euleriano.','L(P₄)=P₃ tem dois ímpares. G=P₄ também tem dois ímpares, impedindo circuito euleriano.'),
 ('L(G)','semieuleriano aberto','G','semieuleriano aberto','substar','Não. O grafo de linha pode ter dois ímpares, enquanto G tem quatro.','Subdivida um ramo de K₁,₃. G fica com graus 3,1,1,2,1. L(G) é um triângulo com folha, cujos graus são 2,2,3,1.'),
 ('L(G)','semieuleriano aberto','G','hamiltoniano','p4','Não. L(P₄)=P₃ é semieuleriano, mas G=P₄ não é hamiltoniano.','As folhas de P₄ impedem um ciclo que visite todos os vértices.'),
 ('L(G)','hamiltoniano','G','euleriano','star3','Não. L(G) pode ser hamiltoniano e G ter quatro ímpares.','A estrela K₁,₃ gera o triângulo hamiltoniano K₃. A estrela não é euleriana.'),
 ('L(G)','hamiltoniano','G','semieuleriano aberto','star3','Não. L(G) hamiltoniano não exige que G tenha dois vértices ímpares.','K₁,₃ tem quatro ímpares e gera o triângulo hamiltoniano K₃.'),
 ('L(G)','hamiltoniano','G','hamiltoniano','star3','Não. L(G) pode possuir ciclo hamiltoniano mesmo que G não possua ciclo algum.','K₁,₃ é uma árvore e L(G)=K₃. Uma sequência circular de arestas que se encontram não precisa ser um percurso circular possível em G.'),
 ('L(G)','euleriano','L(G)','hamiltoniano','double','Não. Mesmo sendo um grafo de linha, ser euleriano não garante ser hamiltoniano.','A árvore com dois centros de grau 3 gera dois triângulos com um vértice comum ab. L(G) tem graus 4,2,2,2,2 e é euleriano, mas ab é de articulação e impede ciclo hamiltoniano.'),
 ('L(G)','hamiltoniano','L(G)','euleriano','paw','Não. Um grafo de linha hamiltoniano pode ter vértices ímpares.','Um triângulo com folha gera um losango com diagonal. L(G) tem ciclo ad→ab→bc→ac→ad, mas ab e ac têm grau 3.'),
 ('L(G)','euleriano','L(G)','semieuleriano aberto','star3','Não, no sentido aberto. Um grafo euleriano tem zero ímpares; um semieuleriano aberto precisa ter dois.','No exemplo, L(G)=K₃ possui todos os graus iguais a 2.'),
 ('L(G)','semieuleriano aberto','L(G)','euleriano','p4','Não. Se L(G) tem exatamente dois ímpares, não pode ter circuito euleriano.','L(P₄)=P₃ possui dois vértices de grau 1 e apenas caminho euleriano aberto.'),
 ('L(G)','semieuleriano aberto','L(G)','hamiltoniano','p4','Não. L(P₄)=P₃ é semieuleriano aberto e não é hamiltoniano.','O grafo de linha tem folhas. Um ciclo hamiltoniano precisaria de duas arestas em cada vértice.'),
 ('L(G)','hamiltoniano','L(G)','semieuleriano aberto','star3','Não. Um L(G) hamiltoniano pode ter zero ímpares, como K₃.','Semieuleriano aberto exige exatamente dois vértices de grau ímpar.')]
assert len(questions)==30
catkeys=['c3','bowtie','diamond','paw','p4','bowtail','dumbbell','k4','subk4','c6chords','star3','double','bull','substar','star4','substar2']
for g in G.values():
    lg=g.line()
    for a,b in g.es:assert lg.ds[a+b]==g.ds[a]+g.ds[b]-2

def introduction():
    p=Page(1,'Caderno resolvido • P2 e questões de sala','Euler, Hamilton e grafos de linha',True)
    p.answer('Cada questão é respondida primeiro em palavras. Depois vêm o desenho de G e L(G), a fórmula com a notação correta e a justificativa.')
    p.diagram(1,185)
    p.para('O caderno cobre as questões 16 e 17 de sala, a questão 1 da P2 de 2026/1 e as implicações entre grafos eulerianos, semieulerianos e hamiltonianos.')
    p.para('As fórmulas agora são diagramadas como matemática: somatórios, frações, índices e símbolos não aparecem como código. O grau continua representado por d(v), como nos slides do professor.')
    p.math(r'd(e)=d(u)+d(v)-2',title='Exemplo de notação')
    p.para('Aqui e=uv é uma aresta de G que virou vértice de L(G). d(e) é calculado em L(G); d(u),d(v) são calculados em G.',10);p.end()
    p=Page(2,'Navegação','Sumário clicável');p.para('Clique em uma seção ou use os marcadores do leitor. As tabelas de implicações também levam diretamente às respostas.');p.end()
    p=Page(3,'Leia antes de responder','Qual notação e quais hipóteses são usadas?',True)
    p.answer('Usamos G=(V,E), d(v) para grau e L(G) para grafo de linha. G é simples, finito, não direcionado e conexo, com ao menos três arestas.')
    p.table(['Termo','Significado'],[
        ('Euleriano','Tem circuito que percorre todas as arestas uma vez e retorna ao início.'),
        ('Semieuleriano aberto','Tem caminho euleriano aberto: exatamente dois vértices de grau ímpar.'),
        ('Hamiltoniano','Tem ciclo que visita todos os vértices uma vez e retorna ao início.'),
        ('Sem trajeto euleriano','Não tem caminho euleriano, aberto ou fechado; no grafo conexo há pelo menos quatro ímpares.')],[145,CW-145],10)
    p.math(r'n=|V|,\qquad m=|E|',r'd(v)=\left|\{e\in E:\ v\in e\}\right|',title='Símbolos usados')
    p.para('Uma aresta e=uv de G vira um vértice de L(G). Ao escrever d(e), indicamos seu grau no grafo de linha; não é uma distância. Distância entre dois vértices costuma ser escrita d(u,v).')
    p.para('“Semieuleriano” tem duas convenções nos slides de apoio. As respostas principais usam exatamente dois ímpares, ou seja, caminho aberto. A página 70 explica o sentido inclusivo. Não usamos siglas para as classes de grafos.');p.end()
    p=Page(4,'Fundamentos','Qual a diferença entre Euler e Hamilton?')
    p.answer('Euler exige usar todas as arestas uma vez; Hamilton exige visitar todos os vértices uma vez. Um circuito euleriano pode repetir vértices no meio do percurso.')
    p.diagram(4,155,False)
    p.math(r'a\to b\to c\to a\to d\to e\to a',title='Circuito euleriano no desenho')
    p.para('O vértice a aparece no meio e no fechamento. Isso é permitido porque nenhuma aresta se repete. O desenho não é hamiltoniano: a é de articulação e separa os dois triângulos.')
    p.table(['Percurso','Não repete','Precisa fechar?'],[
        ('Caminho euleriano aberto','Arestas','Não: início e fim são distintos.'),('Circuito euleriano','Arestas','Sim.'),
        ('Caminho hamiltoniano','Vértices','Não.'),('Ciclo hamiltoniano','Vértices, salvo o inicial no fim','Sim.')],[155,195,CW-350],9.5);p.end()

def theory():
    p=Page(5,'Teorema de Euler','Como decidir se um grafo é euleriano?',True)
    p.answer('Em um grafo conexo, ele é euleriano se, e somente se, todos os vértices têm grau par. Exatamente dois ímpares caracterizam o caminho euleriano aberto.')
    p.diagram(4,125,False)
    p.math(r'\sum_{v\in V}d(v)=2|E|',r'\left|\{v\in V:\ d(v)\ \mathrm{impar}\}\right|\ \mathrm{e\ par}',title='Lema do aperto de mãos')
    p.para('Cada aresta contribui com 1 em cada ponta, totalizando 2. Por isso a soma dos graus é par e a quantidade de vértices ímpares também é par.')
    p.table(['Quantidade de ímpares','Resposta no grafo conexo'],[('0','Euleriano.'),('2','Semieuleriano aberto.'),('4,6,8,…','Sem caminho euleriano.')],[185,CW-185],10)
    p.para('Somar os graus e dividir por 2 apenas conta arestas. Não prova que cada grau é par. A conectividade também é necessária.');p.end()
    p=Page(6,'Grafo de linha','Como construir L(G) a partir de G?',True)
    p.answer('Crie um vértice em L(G) para cada aresta de G. Ligue dois desses vértices quando as arestas originais compartilham uma extremidade.')
    p.diagram(6,185)
    p.math(r'V(L(G))=E',r'\{e,f\}\in E(L(G))\ \Longleftrightarrow\ e\ne f\ \mathrm{e}\ e\cap f\ne\varnothing')
    p.para('No desenho, ab,ac,ad encontram-se em a: viram um triângulo em L(G). bc encontra ab e ac, mas não encontra ad; por isso não existe a ligação bc—ad.')
    p.para('G conexo implica L(G) conexo: entre quaisquer duas arestas de G existe uma sequência de arestas consecutivas que se encontram. Essa sequência conecta os vértices correspondentes em L(G).');p.end()
    p=Page(7,'Grau no grafo de linha','Como calcular o grau de um vértice de L(G)?',True)
    p.answer('Some os graus das duas pontas da aresta original e subtraia 2. Essa conta dá o grau de um único vértice de L(G), não a quantidade total de vértices.')
    p.diagram(22,145)
    p.math(r'e=\{u,v\}\in E',r'd(e)=(d(u)-1)+(d(v)-1)=d(u)+d(v)-2')
    p.para('d(e) é o grau no grafo de linha. d(u) e d(v) são os graus das pontas em G. Subtraímos 1 de cada grau para não contar a própria aresta e. Como G é simples, nenhuma outra aresta é contada nas duas pontas.')
    p.math(r'd(ab)=3+3-2=4',r'd(ac)=3+2-2=3',title='Exemplo do desenho')
    p.para('Assim, o vértice ab de L(G) tem grau par; ac tem grau ímpar. Pontas de mesma paridade produzem grau par; pontas de paridades diferentes produzem grau ímpar.',10);p.end()
    p=Page(8,'Sala • questão 17(a)','Para L(G) ser euleriano, como deve ser G?',True)
    p.answer('G deve ser conexo e ter todos os graus pares OU todos os graus ímpares. Não é obrigatório que G seja euleriano: graus todos ímpares também funcionam.')
    p.diagram(8,170)
    p.math(r'd(e)=d(u)+d(v)-2',r'd(u)=2k,\ d(v)=2\ell\ \Longrightarrow\ d(e)=2(k+\ell-1)',r'd(u)=2k+1,\ d(v)=2\ell+1\ \Longrightarrow\ d(e)=2(k+\ell)')
    p.para('Nas duas situações o resultado é par. Como G é conexo, L(G) é conexo; pelo teorema de Euler, L(G) é euleriano. No desenho, G tem graus 3,1,1,1 e L(G) tem graus 2,2,2.')
    p.para('A condição também é necessária: se L(G) é euleriano, cada aresta de G liga duas pontas de mesma paridade. Como G é conexo, essa igualdade de paridade se propaga por todo o grafo.');p.end()
    p=Page(9,'Caminho euleriano aberto','Para L(G) ser semieuleriano, como deve ser G?',True)
    p.answer('G deve ser conexo e ter exatamente duas arestas ligando vértices de grau par a vértices de grau ímpar. São elas que viram os dois vértices ímpares de L(G).')
    p.diagram(22,145)
    p.para('Seja q a quantidade de arestas de G cujas pontas têm paridades diferentes. A fórmula de grau mostra que q é exatamente a quantidade de vértices ímpares de L(G).',10)
    p.math(r'd(e)=d(u)+d(v)-2',r'q=2\ \Longleftrightarrow\ L(G)\ \mathrm{semieuleriano\ aberto}')
    p.para('O desenho é um contraexemplo à ideia de que basta G ser semi: seus dois ímpares a,b têm grau 3 e são adjacentes. Nesse caso, a contagem é:',10)
    p.math(r'q=d(a)+d(b)-2=3+3-2=4',title='Por que o desenho não atende à condição')
    p.para('L(G) tem quatro ímpares e não é semieuleriano. Se os únicos ímpares u,v não forem adjacentes, a conta é q=d(u)+d(v), sem subtrair 2.',10);p.end()
    p=Page(10,'Sala • questão 17(b)','Para L(G) ser hamiltoniano, como deve ser G?',True)
    p.answer('G deve conter um subgrafo H conexo, com todos os graus internos pares, que encoste em todas as arestas de G. Essa condição é necessária e suficiente.')
    p.diagram(6,155)
    p.math(r'H\subseteq G,\qquad H\ \mathrm{conexo}',r'\forall v\in V(H),\quad d(v)\in\{0,2,4,\ldots\}\quad\mathrm{em}\ H',r'\forall\{u,v\}\in E,\quad u\in V(H)\ \mathrm{ou}\ v\in V(H)')
    p.para('É a caracterização de Harary–Nash-Williams: H é um subgrafo euleriano dominante. “Dominante” significa que nenhuma aresta de G tem as duas pontas fora de H. Permite-se H com um único vértice, de grau zero.')
    p.para('No desenho, H é o triângulo abc: seus graus internos são 2. A aresta ad está fora de H, mas encosta em a. Portanto esse G gera L(G) hamiltoniano. G euleriano e G hamiltoniano são duas condições suficientes mais fáceis.',10);p.end()
    p=Page(11,'Justificativa do teorema','Por que o subgrafo dominante garante Hamilton?')
    p.answer('Porque seu circuito euleriano ordena as arestas de H em ciclo, e as demais arestas de G podem ser inseridas junto de uma ponta comum. Em L(G), a ordem ampliada visita todos os vértices uma vez.')
    p.diagram(6,130)
    p.math(r'ab\to bc\to ac\to ad\to ab',title='Ciclo hamiltoniano em L(G) neste exemplo')
    p.para('Suficiência: atribua cada aresta externa a uma ponta v em H. Em uma passagem do circuito por v, insira todas as arestas atribuídas a v entre a chegada e a saída. Todas compartilham v, logo seus vértices são adjacentes em L(G). Se H é um único vértice, L(G) é completo e tem ciclo pois |E|≥3.')
    p.para('Necessidade: tome um ciclo e₁,…,eₘ,e₁ em L(G). Seja xᵢ a ponta comum entre duas arestas consecutivas. Quando duas pontas consecutivas são diferentes, percorra a aresta entre elas; quando são iguais, permaneça no vértice. Retirando as permanências, obtemos uma trilha fechada sem repetir arestas.')
    p.para('Essa trilha define H conexo e de graus pares. Toda aresta de G encosta em uma das pontas visitadas, portanto H domina. Se não houver deslocamento, use como H o único vértice comum.',10);p.end()

def bank():
    for index,(a,pa,b,pb,key,answer,why) in enumerate(questions):
        n=12+index;g=G[key];lg=g.line()
        p=Page(n,f'Questão {index+1:02d} • banco resolvido',f'Se {a} é {pa}, então {b} é {pb}?',n in [12,18,27,36])
        p.answer(answer)
        p.diagram(n,155)
        if index==6:
            p.math(r'd(e)=d(u)+d(v)-2',r'd(e)=2k+2\ell-2=2(k+\ell-1)',title='Cada vértice de L(G) tem grau par')
        elif index==8:
            p.math(r'e_1\to e_2\to\cdots\to e_m\to e_1',r'V(L(G))=E=\{e_1,\ldots,e_m\}',title='O circuito de arestas vira ciclo de vértices')
        elif index==14:
            p.math(r'C\subseteq G,\qquad V(C)=V,\qquad d(v)=2\ \mathrm{em}\ C',title='O ciclo hamiltoniano é euleriano e dominante')
        elif key=='diamond':
            p.math(r'G:\quad d(a)=d(b)=3,\quad d(c)=d(d)=2',r'L(G):\quad d(ab)=4,\quad d(ac)=d(ad)=d(bc)=d(bd)=3',title='Graus que refutam a conclusão')
        elif key=='p4':
            p.math(r'G:\quad d(a)=d(d)=1,\quad d(b)=d(c)=2',r'L(G):\quad d(ab)=d(cd)=1,\quad d(bc)=2')
        elif key=='star3':
            p.math(r'G:\quad d(a)=3,\quad d(b)=d(c)=d(d)=1',r'L(G):\quad d(ab)=d(ac)=d(ad)=2')
        elif key=='c3':p.math(r'G:\quad d(a)=d(b)=d(c)=2',r'L(G):\quad d(ab)=d(ac)=d(bc)=2')
        else:p.math(r'G:\quad '+eqdegrees(g),r'L(G):\quad '+eqdegrees(lg),title='Graus do exemplo')
        p.sub('Justificativa')
        p.para(why,10.3)
        if index not in [6,8,14]:
            p.table(['Verificação','G','L(G)'],[('Vértices ímpares',len(g.odd),len(lg.odd)),('Ciclo hamiltoniano?','sim' if g.cycle() else 'não','sim' if lg.cycle() else 'não')],[180,(CW-180)/2,(CW-180)/2],9.3)
        p.end()

def matrices_and_cases():
    lookup={(a,pa,b,pb):12+i for i,(a,pa,b,pb,*_) in enumerate(questions)}
    kinds=['euleriano','semieuleriano aberto','hamiltoniano']
    positives={18,20,26}
    direct={42:'No próprio G, somente repetir a mesma propriedade é sempre válido. Nenhuma das seis implicações entre propriedades diferentes é garantida.',
            43:'Sempre valem: G euleriano gera L(G) euleriano e hamiltoniano; G hamiltoniano gera L(G) hamiltoniano. As outras seis conclusões não são garantidas.',
            44:'Nenhuma das nove propriedades da tabela pode ser garantida em G apenas por uma dessas propriedades de L(G). Cada afirmação tem um contraexemplo.',
            45:'Mesmo dentro de L(G), só repetir a mesma propriedade é sempre válido. As seis implicações entre propriedades diferentes são falsas em geral.'}
    for n,(a,b) in enumerate([('G','G'),('G','L(G)'),('L(G)','G'),('L(G)','L(G)')],42):
        p=Page(n,'Mapa de respostas',f'Quais implicações de {a} para {b} valem?',n==42)
        p.answer(direct[n]);rows=[];links={}
        for ri,pa in enumerate(kinds):
            row=[pa.capitalize()]
            for ci,pb in enumerate(kinds,1):
                if a==b and pa==pb:row.append('V • identidade')
                else:
                    target=lookup[(a,pa,b,pb)];row.append(('V' if target in positives else 'F')+f' • p. {target}');links[(ri,ci)]=target
            rows.append(row)
        p.table(['Hipótese ↓ / conclusão →','Euleriano','Semieuleriano aberto','Hamiltoniano'],rows,[171,108,122,CW-401],9.5,links)
        p.para('V significa verdadeiro para todo grafo nas hipóteses; F significa que existe um contraexemplo. Clique no número da página para ler a resposta, ver o desenho e conferir a conta.')
        p.para('Aqui “semieuleriano” significa exatamente dois ímpares. “Falso em geral” não quer dizer “impossível”; a próxima tabela distingue essas situações.');p.end()
    states=['EH','E¬H','SH','S¬H','NH','N¬H']
    labels={'EH':'Euleriano; hamiltoniano','E¬H':'Euleriano; não hamiltoniano','SH':'Semieuleriano; hamiltoniano','S¬H':'Semieuleriano; não hamiltoniano','NH':'Sem trajeto euleriano; hamiltoniano','N¬H':'Sem trajeto euleriano; não hamiltoniano'}
    def profile(g):return ('E' if not g.odd else 'S' if len(g.odd)==2 else 'N')+('H' if g.cycle() else '¬H')
    cases={(profile(G[k]),profile(G[k].line())):i+1 for i,k in enumerate(catkeys)}
    assert len(cases)==16
    p=Page(46,'Combinações possíveis','Quais propriedades podem ocorrer juntas?',True)
    p.answer('Existem 16 combinações realizáveis entre os seis estados de G e os seis estados de L(G), nas hipóteses do caderno. As outras 20 são impossíveis.')
    rows=[];links={}
    for ri,a in enumerate(states):
        row=[labels[a]]
        for ci,b in enumerate(states,1):
            code=cases.get((a,b));row.append(f'C{code:02d}' if code else '—')
            if code:links[(ri,ci)]=47+code
        rows.append(row)
    p.table(['G ↓ / L(G) →']+[labels[s] for s in states],rows,[110]+[(CW-110)/6]*6,7.3,links)
    p.para('Cada código C01–C16 leva a um exemplo desenhado nas páginas 48–63. “—” significa impossível. Sem trajeto euleriano quer dizer que não há caminho euleriano aberto nem fechado.',10)
    p.para('A tabela trata de existência, não de garantia: um G semieuleriano e não hamiltoniano PODE gerar L(G) semieuleriano e hamiltoniano (C04). Isso não torna a implicação sempre verdadeira.',10);p.end()
    p=Page(47,'Prova de completude','Por que as outras combinações são impossíveis?')
    p.answer('Porque G euleriano força L(G) euleriano e hamiltoniano; G hamiltoniano força L(G) hamiltoniano; e G semieuleriano aberto impede L(G) euleriano. Se G também for hamiltoniano, L(G) terá pelo menos quatro ímpares.')
    p.diagram(50,125)
    p.math(r'q\ge d(u)+d(v)-2\ge 3+3-2=4',title='Se G é semieuleriano aberto e hamiltoniano')
    p.para('Os únicos ímpares u,v de um grafo hamiltoniano têm grau pelo menos 3: grau 1 impediria o ciclo. Se forem adjacentes, q=d(u)+d(v)−2; caso contrário, q=d(u)+d(v). Assim q≥4 e L(G) não é semi aberto.')
    p.para('G semi aberto não gera L(G) euleriano: isso exigiria que todos os graus de G tivessem a mesma paridade. Só haver dois ímpares, todos os graus serem ímpares e |E|≥3 não pode ocorrer em grafo simples conexo.')
    p.para('Essas restrições excluem todas as células “—”. Para cada uma das outras 16 há um exemplo no catálogo, o que completa a classificação.');p.end()

def catalog():
    reasons={
      'bowtie':'G não é hamiltoniano porque a é de articulação: sua remoção separa os triângulos.',
      'paw':'G não é hamiltoniano porque d é folha. O triângulo abc domina as arestas de G.',
      'p4':'G e L(G) possuem folhas, portanto nenhum admite ciclo hamiltoniano.',
      'bowtail':'G não é hamiltoniano porque f é folha; seus dois triângulos formam um subgrafo euleriano dominante.',
      'dumbbell':'G tem a ponte cd. Em L(G), cd é vértice de articulação. Nenhum dos dois grafos é hamiltoniano.',
      'star3':'G é uma árvore com folhas. Todas as suas arestas encontram a, por isso L(G) é o triângulo K₃.',
      'double':'G é uma árvore. Em L(G), ab é de articulação, separando {ac,ad} de {be,bf}.',
      'bull':'G não é hamiltoniano por causa das folhas d,e. O triângulo abc domina suas arestas.',
      'substar':'G tem folhas. Em L(G), de também é folha, com único vizinho ad.',
      'star4':'G é uma árvore com quatro folhas. Todas as arestas encontram a; assim L(G)=K₄.',
      'substar2':'G tem folhas. Em L(G), cd e ef têm grau 1, impedindo ciclo hamiltoniano.'}
    for i,key in enumerate(catkeys):
        n=48+i;g=G[key];lg=g.line()
        p=Page(n,f'Exemplo C{i+1:02d} • combinação certificada','Esta combinação entre G e L(G) é possível?')
        p.answer(f'Sim. Neste exemplo, G é {status(g)}. Já L(G) é {status(lg)}.')
        p.diagram(n,145)
        p.math(r'G:\quad '+eqdegrees(g),r'L(G):\quad '+eqdegrees(lg),title='Graus em cada grafo')
        p.table(['Contagem','G','L(G)'],[('Vértices ímpares',len(g.odd),len(lg.odd))],[180,(CW-180)/2,(CW-180)/2],9.5)
        if key in reasons:p.para(reasons[key],10)
        for gr,name in [(g,'G'),(lg,'L(G)')]:
            cycle=gr.cycle()
            if cycle:p.para('Ciclo hamiltoniano em '+name+': '+seq(cycle)+'.',9.6,space=6)
            if len(gr.odd) in [0,2]:p.para(('Circuito' if not gr.odd else 'Caminho aberto')+' euleriano em '+name+': '+seq(gr.trail())+'.',9.6,space=6)
        p.end()

def extra_questions():
    p=Page(64,'Questões originais','Quais são as respostas de sala e da P2?',True)
    p.answer('Sala 16: falso, falso, verdadeiro, falso, falso. Questão 1 da P2 de 2026/1: verdadeiro, verdadeiro, falso. As perguntas da Sala 17 são respondidas diretamente nas páginas 8 e 10.')
    rows=[('Sala 16.1','G euleriano ⇒ G hamiltoniano','F',12),('Sala 16.2','G hamiltoniano ⇒ G euleriano','F',13),
       ('Sala 16.3 / P2 1.2','G euleriano ⇒ L(G) hamiltoniano','V',20),('Sala 16.4','L(L(G))≅G para todo G','F',65),
       ('Sala 16.5','G hamiltoniano ⇒ L(G) euleriano','F',24),('P2 1.1','G euleriano ⇒ L(G) euleriano','V',18),
       ('P2 1.3','G semi ⇒ L(G) semi','F',22),('Sala 17(a)','Como deve ser G para L(G) ser euleriano?','Condição',8),
       ('Sala 17(b)','Como deve ser G para L(G) ser hamiltoniano?','Condição',10)]
    p.table(['Origem','Pergunta','Resposta / página'],[(a,b,f'{c} • p. {d}') for a,b,c,d in rows],[120,274,CW-394],9,links={(i,2):row[3] for i,row in enumerate(rows)})
    p.para('O enunciado da P2 exige justificativa. Nas páginas indicadas, a resposta direta vem antes do desenho, da fórmula e da demonstração. O contraexemplo da letra c vale nos dois sentidos de semieuleriano.');p.end()
    p=Page(65,'Sala • questão 16(4)','Aplicar L duas vezes devolve G?',True)
    p.answer('Não. L(L(G)) não é necessariamente igual nem isomorfo a G. Um caminho com quatro vértices gera um caminho com três e depois um caminho com dois vértices.')
    p.diagram(65,235,False)
    p.math(r'G=P_4,\qquad L(G)=P_3,\qquad L^2(G)=P_2',r'|V|=4,\quad |V(L(G))|=3,\quad |V(L^2(G))|=2')
    p.para('Como os números de vértices são diferentes, não há isomorfismo. Para um ciclo, porém, L(Cₙ)≅Cₙ e aplicar L duas vezes mantém o ciclo. Esse caso favorável não prova a identidade para grafos quaisquer.');p.end()
    p=Page(66,'Caminho versus ciclo','O que G semieuleriano garante em L(G)?')
    p.answer('G semieuleriano garante um caminho hamiltoniano em L(G). Não garante que esse caminho feche em ciclo, nem garante que L(G) seja semieuleriano.')
    p.diagram(66,155)
    p.math(r'e_1\to e_2\to\cdots\to e_m',r'P_4:\ a\to b\to c\to d\quad\longmapsto\quad ab\to bc\to cd')
    p.para('As arestas e₁,…,eₘ do caminho euleriano de G são distintas e cobrem todas as arestas. Elas viram todos os vértices de L(G), uma vez cada, com adjacência entre consecutivas. A primeira e a última não precisam se encontrar.')
    p.para('A inversa também falha: na estrela com um ramo subdividido, L(G) tem caminho de→ad→ab→ac. Mas G tem quatro ímpares e não possui caminho euleriano.');p.end()
    p=Page(67,'Condições suficientes','Que fórmulas de grau garantem Hamilton em L(G)?',True)
    p.answer('Dirac e Ore fornecem condições suficientes. Se a desigualdade correspondente vale em G, então L(G) é hamiltoniano. Se ela falha, ainda pode existir ciclo hamiltoniano.')
    p.diagram(8,105)
    p.para('Como L(G) tem m=|E| vértices, Dirac exige grau pelo menos m/2 em cada um. Substitua d(e)=d(u)+d(v)−2:',10)
    p.math(r'\forall\{u,v\}\in E,\quad d(u)+d(v)\ge\frac{m}{2}+2',title='Dirac: condição suficiente para L(G) hamiltoniano')
    p.para('Em Ore, vértices não adjacentes de L(G) correspondem a arestas disjuntas uv e xy de G. A soma de seus graus em L(G) deve ser pelo menos m:',10)
    p.math(r'd(u)+d(v)+d(x)+d(y)\ge m+4',r'\mathrm{para\ todo\ par\ de\ arestas}\ uv,xy\ \mathrm{disjuntas}',title='Ore: outra condição suficiente')
    p.para('No desenho, a estrela gera K₃, que atende a Dirac. Já C₅ não atende: 2+2=4<4,5; mesmo assim L(C₅)≅C₅ é hamiltoniano. Logo as desigualdades não são condições necessárias.',10);p.end()
    p=Page(68,'Como provar que não há ciclo','Quais características impedem Hamilton?')
    p.answer('Uma folha, uma ponte ou um vértice de articulação impede ciclo hamiltoniano. Não ter esses obstáculos é necessário, mas não garante Hamilton em um grafo qualquer.')
    p.diagram(4,130,False)
    p.math(r'G\ \mathrm{hamiltoniano}\quad\Longrightarrow\quad\delta(G)\ge2',r'\mathrm{numero\ de\ componentes\ de}\ (G-S)\le |S|\quad(S\ne\varnothing)')
    p.para('Folha: só tem uma aresta, mas um ciclo precisa entrar e sair por arestas distintas. Ponte: para visitar ambos os lados e fechar, seria preciso atravessá-la duas vezes. Articulação: retirá-la de um ciclo hamiltoniano deixaria um caminho por todos os outros vértices, que ainda estariam conectados.')
    p.para('No desenho, retirar a separa os triângulos; por isso G não é hamiltoniano, embora todos os seus graus sejam pares. A condição mais geral vem de retirar |S| vértices de um ciclo: restam no máximo |S| segmentos.');p.end()
    p=Page(69,'Como interpretar uma resposta falsa','“Não é garantido” significa “é impossível”?')
    p.answer('Não. Uma implicação falsa significa que existe pelo menos um contraexemplo. A conclusão ainda pode ocorrer em outros grafos com a mesma hipótese.')
    p.diagram(51,125)
    p.math(r'\neg\bigl(\forall G,\ P(G)\Rightarrow Q(G)\bigr)',r'\Longleftrightarrow\ \exists G:\ P(G)\land\neg Q(G)',title='Negação correta da afirmação universal')
    p.para('No desenho, G é semi aberto e L(G) é hamiltoniano. Mas P₄ também é semi aberto e gera P₃, que não é hamiltoniano. Portanto G semi não garante L(G) hamiltoniano, embora a combinação seja possível.')
    p.para('Já G semi aberto e L(G) euleriano é uma combinação impossível nas hipóteses do caderno. A prova usa a paridade de todos os graus, não apenas um exemplo.');p.end()
    p=Page(70,'As duas convenções dos slides','O que muda no sentido inclusivo de semieuleriano?',True)
    p.answer('No sentido inclusivo, um grafo euleriano também é semieuleriano. O sentido aberto exige dois ímpares; o inclusivo admite zero ou dois. O gabarito V,V,F da P2 não muda.')
    p.diagram(19,115)
    p.math(r'\mathrm{sentido\ aberto}:\quad 2\ \mathrm{vertices\ impares}',r'\mathrm{sentido\ inclusivo}:\quad 0\ \mathrm{ou}\ 2\ \mathrm{vertices\ impares}')
    p.table(['Afirmação','Aberto','Inclusivo'],[
        ('G euleriano ⇒ G semieuleriano','F','V'),('L(G) euleriano ⇒ L(G) semieuleriano','F','V'),('G euleriano ⇒ L(G) semieuleriano','F','V')],[305,103,CW-408],9.5)
    p.para('Essas são as três implicações que mudam nas matrizes. O triângulo do desenho é euleriano e também é semi no sentido inclusivo. Para a letra c da P2, o losango com diagonal continua refutando a afirmação: L(G) tem quatro ímpares.')
    p.para('Na prova, siga a definição fornecida no enunciado. Quando o termo estiver ambíguo, declare que você o usa no sentido de caminho euleriano aberto.',10);p.end()
    p=Page(71,'Hipóteses e exceções','Por que exigir conectividade e grafo simples?')
    p.answer('Porque graus pares sozinhos não garantem um circuito único em grafo desconexo, e a fórmula d(e)=d(u)+d(v)−2 pressupõe que G não tenha laços nem arestas paralelas.')
    # Exemplo novo desenhado diretamente em vetor.
    p.sub('Dois triângulos separados: todos os graus pares, mas sem circuito único')
    height=130;p.need(height+15);y=p.y
    points={'a':(M+20,y+110),'b':(M+100,y+10),'c':(M+180,y+110),'d':(M+300,y+110),'e':(M+380,y+10),'f':(M+460,y+110)}
    for a,b in ['ab','bc','ac','de','ef','df']:p.p.draw_line(points[a],points[b],color=GREY,width=1.3)
    for v,pt in points.items():
        p.p.draw_circle(pdf.Point(pt),12,color=None,fill=INK);p.txt(pt[0]-3.5,pt[1]+3.5,v,10,WHITE,'bold')
    p.y+=height+15
    p.math(r'd(v)=2\quad\mathrm{para\ todo}\ v\in V')
    p.para('Não há percurso que atravesse todas as arestas porque as componentes estão separadas. L(G) também fica desconexo. Vértices isolados, por outro lado, desaparecem em L(G), pois não correspondem a arestas.')
    p.para('Com menos de três arestas, L(G) tem menos de três vértices e não pode ter ciclo simples hamiltoniano. Com paralelas, uma outra aresta pode tocar u e v e ser contada duas vezes. Por isso esses casos precisam de análise separada.');p.end()
    p=Page(72,'Fontes','Quais fontes sustentam estas respostas?',True)
    p.answer('As perguntas vêm das atividades de sala e da P2 de 2026/1. A notação e os teoremas básicos seguem os slides; a caracterização de L(G) hamiltoniano usa o teorema de Harary–Nash-Williams.')
    p.sub('Material local')
    p.para('Grafos/AtividadesSala/AtividadesSala.txt: questões 16 e 17 até a P2. Grafos/Provas/Prova_02/2026-1-exam.pdf: questão 1, itens 1–3.')
    p.para('Silvio: Slides/Silvio/01-graphs-concepts.pdf, páginas PDF 27–28, para o grau d(v). Zenilton: Slides/Zenilton/10-grafos-hamiltonianos-eurelianos-fleury.pdf, páginas PDF 2, 9, 19 e 23, para Hamilton, Dirac/Ore e Euler.')
    p.sub('Literatura complementar')
    p.para('Harary e Nash-Williams, On Eulerian and Hamiltonian Graphs and Line Graphs, Canadian Mathematical Bulletin 8 (1965), pp. 701–709. DOI: 10.4153/CMB-1965-051-3.')
    p.para('Xia Liu, A related problem on s-Hamiltonian line graphs, AIMS Mathematics 7(10), 2022. DOI: 10.3934/math.20221073.')
    for title,url in [('Artigo original','https://doi.org/10.4153/CMB-1965-051-3'),('Caracterização por subgrafo dominante','https://doi.org/10.3934/math.20221073')]:
        y=p.y;p.para(title,10.5,color=TEAL)
        p.p.insert_link({'kind':pdf.LINK_URI,'from':pdf.Rect(M,y,W-M,y+18),'uri':url})
    p.para('Cada contraexemplo foi conferido pela construção do grafo de linha, cálculo dos graus e busca exata de ciclos hamiltonianos. Os exemplos não substituem provas das afirmações universais.');p.end()

def finalize():
    p=doc[1];y=155
    for _,title,n in toc:
        if n==1:continue
        lines=wrap(title,CW-40,9.4)
        for line in lines:p.insert_text((M,y),line,fontname='rbody',fontsize=9.4,color=INK);y+=13
        p.insert_text((W-M-25,y-13),str(n),fontname='rbold',fontsize=9.4,color=TEAL)
        p.insert_link({'kind':pdf.LINK_GOTO,'from':pdf.Rect(M,y-13*len(lines),W-M,y+3),'page':n-1});y+=9
    assert y<H-63,y
    doc.set_toc(toc)
    doc.set_metadata({'title':'Caderno resolvido — Euler, Hamilton e grafos de linha',
      'subject':'Resposta direta, desenhos, fórmulas matemáticas diagramadas e demonstração',
      'author':'Material de estudo de Grafos'})
    doc.subset_fonts();doc.save(OUT,garbage=4,deflate=True)
    assert len(log)==72 and len({n for n,y in log})==72
    (BASE/'.revisao_relacoes/formulas_reformuladas.json').write_text(json.dumps(formula_log,ensure_ascii=False,indent=2),encoding='utf-8')
    print('PDF:',OUT,'Paginas:',len(doc),'Formulas:',len(formula_log),'Altura maxima:',max(y for n,y in log))

if __name__=='__main__':
    introduction();theory();bank();matrices_and_cases();catalog();extra_questions();finalize()
