"""Atualiza a notação no PDF existente, preservando figuras, páginas e navegação."""
from pathlib import Path
import re
import pymupdf as pdf
from matplotlib import font_manager

BASE=Path(__file__).resolve().parent.parent
SRC=BASE/'Caderno_Resolvido_Euler_Hamilton_Grafo_de_Linha.pdf'
OUT=BASE/'.Caderno_notacao_professor.pdf'
W,H=595.28,841.89;M=42;CW=W-2*M
INK=(.09,.17,.25);TEAL=(0,.40,.42);GREY=(.41,.48,.53);LIGHT=(.91,.95,.95);WHITE=(1,1,1)
FB={k:Path(font_manager.findfont(font_manager.FontProperties(family='DejaVu Sans',weight='bold' if k=='pbold' else 'normal'))).read_bytes() for k in ['pbody','pbold']}
F={k:pdf.Font(fontbuffer=b) for k,b in FB.items()}
doc=pdf.open(SRC)
assert len(doc)==72
toc=doc.get_toc()

def wrap(s,width,size=10.5,font='pbody'):
    lines=[]
    for para in str(s).split('\n'):
        line=''
        for word in para.split():
            trial=(line+' '+word).strip()
            if line and F[font].text_length(trial,fontsize=size)>width:lines.append(line);line=word
            else:line=trial
        lines.append(line)
    return lines

def fonts(p):
    for k,v in FB.items():p.insert_font(fontname=k,fontbuffer=v)

def transform(s):
    s=s.replace('d_{L(G)}','d').replace('d_G','d').replace('d_L','d').replace('d_X','d')
    s=s.replace('C_n','Cₙ').replace('K_n','Kₙ')
    s=s.replace('d_H(v) é par','d(v) é par no subgrafo H').replace('d_H(v) par','grau de v par em H')
    s=s.replace('∑_{v∈V(G)} C(d(v),2)','∑ d(v)(d(v)−1)/2, v∈V')
    s=s.replace('∑_v C(d(v),2)','∑ d(v)(d(v)−1)/2, v∈V')
    s=s.replace('H(X) ⇒ δ(X)≥2.','Se G é hamiltoniano, então δ(G)≥2.')
    s=s.replace('H(X) ⇒ X não tem ponte nem vértice de articulação.','Se G é hamiltoniano, então G não tem ponte nem vértice de articulação.')
    s=s.replace('H(X) ⇒ c(X−S)≤|S| para todo S⊆V(X), S≠∅.','Se G é hamiltoniano: nº de componentes de G−S ≤ |S|, para S⊆V, S≠∅.')
    s=s.replace('Com S definido como exatamente dois ímpares e m≥3, é impossível G ser S e L(G) ser E. A','Com semi aberto significando dois ímpares e |E|≥3, G semi não pode gerar L(G) euleriano. A')
    s=s.replace('prova da paridade mostra isso. Já G ser S e L(G) ser H é possível, mas não garantido.','prova da paridade mostra isso. Já G semi gerar L(G) hamiltoniano é possível, mas não garantido.')
    return s

def bgcolor(p,rect):
    center=(rect.tl+rect.br)/2
    color=WHITE
    for d in p.get_drawings():
        if d.get('fill') is not None and d['rect'].contains(center) and any(item[0]=='re' for item in d['items']):color=d['fill']
    return color

# Páginas com tabelas de abreviações são refeitas por extenso.
REBUILD={3,5,9,42,43,44,45,46,47,70}
for number,p in enumerate(doc,1):
    if number in REBUILD:continue
    replacements=[]
    for block in p.get_text('dict')['blocks']:
        if block['type']!=0:continue
        for line in block['lines']:
            spans=line['spans'];old=''.join(s['text'] for s in spans);new=transform(old)
            if new==old:continue
            r=pdf.Rect(line['bbox']);sp=spans[0]
            font='pbold' if 'Bold' in sp['font'] else 'pbody'
            c=sp['color'];color=((c>>16&255)/255,(c>>8&255)/255,(c&255)/255)
            origin=sp['origin'];size=sp['size']
            # Nas fórmulas e parágrafos corridos, a linha pode usar a largura útil inteira.
            right=W-M-(14 if r.x0>M+5 else 0)
            available=max(r.width,right-r.x0)
            size=min(size,available/F[font].text_length(new,fontsize=1))
            assert size>=8,(number,new,size)
            fill=bgcolor(p,r)
            rr=pdf.Rect(r.x0,r.y0+.5,r.x1,r.y1-.5)
            replacements.append((rr,new,origin,size,color,font,fill))
    for r,new,origin,size,color,font,fill in replacements:p.add_redact_annot(r,fill=fill,cross_out=False)
    if replacements:
        p.apply_redactions(images=0,graphics=0)
        fonts(p)
        for r,new,origin,size,color,font,fill in replacements:p.insert_text(origin,new,fontname=font,fontsize=size,color=color)

class Body:
    def __init__(self,n):
        self.n=n;self.p=doc[n-1]
        self.p.add_redact_annot(pdf.Rect(M-4,93,W-M+4,H-80),fill=WHITE,cross_out=False)
        self.p.apply_redactions(images=0,graphics=2);fonts(self.p);self.y=100
        for link in self.p.get_links():self.p.delete_link(link)
    def need(self,h):assert self.y+h<H-81,(self.n,self.y,h)
    def para(self,s,size=10.5,color=INK,bold=False):
        f='pbold' if bold else 'pbody';ls=wrap(s,CW,size,f);lh=size*1.45
        self.need(len(ls)*lh+9)
        for line in ls:self.p.insert_text((M,self.y+size),line,fontname=f,fontsize=size,color=color);self.y+=lh
        self.y+=9
    def box(self,title,s):
        ls=wrap(s,CW-28,10);h=40+len(ls)*14.5;self.need(h+11)
        self.p.draw_rect(pdf.Rect(M,self.y,W-M,self.y+h),color=None,fill=LIGHT)
        self.p.draw_rect(pdf.Rect(M,self.y,M+4,self.y+h),color=None,fill=TEAL)
        self.p.insert_text((M+14,self.y+19),title,fontname='pbold',fontsize=10.5,color=TEAL)
        for i,line in enumerate(ls):self.p.insert_text((M+14,self.y+39+i*14.5),line,fontname='pbody',fontsize=10,color=INK)
        self.y+=h+11
    def sub(self,s):self.para(s,12,TEAL,True)
    def table(self,heads,rows,widths,size=9.3,links=None):
        for ri,row in enumerate([heads]+list(rows)):
            f='pbold' if ri==0 else 'pbody';cells=[wrap(t,w-12,size,f) for t,w in zip(row,widths)]
            height=max(map(len,cells))*size*1.4+13;self.need(height);x=M
            for ci,(cell,width) in enumerate(zip(cells,widths)):
                r=pdf.Rect(x,self.y,x+width,self.y+height)
                self.p.draw_rect(r,color=WHITE,width=.7,fill=TEAL if ri==0 else LIGHT if ri%2 else (.97,.98,.98))
                for j,line in enumerate(cell):self.p.insert_text((x+6,self.y+size+5+j*size*1.4),line,fontname=f,fontsize=size,color=WHITE if ri==0 else INK)
                if links and ri>0 and (ri-1,ci) in links:
                    self.p.insert_link({'kind':pdf.LINK_GOTO,'from':r,'page':links[(ri-1,ci)]-1})
                x+=width
            self.y+=height
        self.y+=11

b=Body(3)
b.para('Usaremos G=(V,E), como nos enunciados do professor Silvio. O grau de um vértice é d(v); n=|V| é a quantidade de vértices e m=|E| a quantidade de arestas.')
b.table(['Notação / termo','Significado'],[
 ('d(v)','Número de arestas incidentes em v. Ao falar de G, L(G) ou de um subgrafo, o texto indica onde o grau está sendo calculado.'),
 ('L(G)','Grafo de linha de G: cada aresta de G corresponde a um vértice de L(G).'),
 ('Euleriano','Possui circuito euleriano: usa cada aresta uma vez e volta ao início.'),
 ('Semieuleriano aberto','Possui caminho euleriano aberto: exatamente dois vértices de grau ímpar.'),
 ('Hamiltoniano','Possui ciclo que visita todos os vértices uma vez e retorna ao início.'),
 ('Sem trajeto euleriano','Não possui caminho euleriano, aberto ou fechado: em grafo conexo, tem pelo menos quatro vértices ímpares.')],widths=[132,CW-132],size=10)
b.para('Hipóteses: G é finito, simples, não direcionado e conexo, com |E|≥3. As propriedades são escritas por extenso, como nas questões de sala, sem siglas para representar classes de grafos.')
b.box('Sentido de “semieuleriano”','O banco principal usa exatamente dois ímpares (caminho aberto). Os slides de apoio também apresentam o sentido inclusivo, que admite circuito fechado. Essa diferença é explicada na página 70 e não altera o gabarito da P2 de 2026/1.')
b.para('Euleriano e hamiltoniano podem ocorrer juntos. Semieuleriano aberto e hamiltoniano também; euleriano e semieuleriano aberto são classes disjuntas.',10)

b=Body(5)
b.box('Lema do aperto de mãos','∑ d(v) = 2|E|, para todo v∈V.\nA quantidade de vértices de grau ímpar é sempre par.')
b.para('Cada aresta contribui com 1 no grau de cada ponta. Por isso contribui com 2 na soma. Como os graus pares somam um número par, a quantidade de parcelas ímpares também precisa ser par.')
b.table(['Número de ímpares no grafo conexo','Conclusão'],[
 ('0','O grafo é euleriano: possui circuito euleriano.'),('2','O grafo é semieuleriano aberto.'),('4,6,8,…','O grafo não possui caminho euleriano, aberto ou fechado.')],widths=[230,CW-230],size=10)
b.para('Necessidade: ao atravessar um vértice interno, cada entrada precisa de uma saída. No circuito isso vale para todos. No caminho aberto, início e fim têm uma incidência sem par: são os dois ímpares.')
b.para('Suficiência: com graus pares, forme circuitos por arestas não usadas e una-os onde ainda restarem arestas. Com dois ímpares, acrescente uma aresta provisória entre eles, forme um circuito no multigrafo auxiliar e depois retire a aresta acrescentada.')
b.box('A soma par não basta','A soma dos graus é par em qualquer grafo não direcionado. Para o grafo ser euleriano, cada grau precisa ser par e as arestas precisam estar conectadas.')

b=Body(9)
b.para('Seja q a quantidade de arestas de G que ligam um vértice de grau par a um vértice de grau ímpar. O grau é d(v), calculado em G.')
b.box('Contagem no grafo de linha','Quantidade de vértices ímpares de L(G) = q.\nL(G) é euleriano ⇔ q=0.\nL(G) é semieuleriano aberto ⇔ q=2.\nL(G) não possui caminho euleriano ⇔ q≥4.')
b.para('Pela fórmula d(e)=d(u)+d(v)−2, com e=uv, o vértice e de L(G) é ímpar exatamente quando as pontas u,v têm paridades diferentes. Como L(G) é conexo, aplica-se o teorema de Euler.')
b.para('q é sempre par: some os graus dos vértices ímpares de G. Arestas entre dois ímpares contribuem com 2; as que ligam ímpar a par contribuem com 1. Como há uma quantidade par de vértices ímpares, essa soma é par; logo q também é par.')
b.sub('Se G possui exatamente dois ímpares u e v')
b.box('Fórmula usando d(v)','Se uv∈E: q=d(u)+d(v)−2.\nSe uv∉E: q=d(u)+d(v).')
b.para('Quando existe uv, ela foi contada duas vezes na soma dos graus e não liga par a ímpar; por isso subtraímos 2. No losango com diagonal, q=3+3−2=4: G é semieuleriano, mas L(G) não é.')

qpages={('G','E','G','H'):12,('G','H','G','E'):13,('G','E','G','S'):14,('G','S','G','E'):15,('G','S','G','H'):16,('G','H','G','S'):17,
 ('G','E','L','E'):18,('G','E','L','S'):19,('G','E','L','H'):20,('G','S','L','E'):21,('G','S','L','S'):22,('G','S','L','H'):23,
 ('G','H','L','E'):24,('G','H','L','S'):25,('G','H','L','H'):26,('L','E','G','E'):27,('L','E','G','S'):28,('L','E','G','H'):29,
 ('L','S','G','E'):30,('L','S','G','S'):31,('L','S','G','H'):32,('L','H','G','E'):33,('L','H','G','S'):34,('L','H','G','H'):35,
 ('L','E','L','H'):36,('L','H','L','E'):37,('L','E','L','S'):38,('L','S','L','E'):39,('L','S','L','H'):40,('L','H','L','S'):41}
true={('G','E','L','E'),('G','E','L','H'),('G','H','L','H')}
words={'E':'euleriano','S':'semieuleriano aberto','H':'hamiltoniano'}
for n,(s,t) in enumerate([('G','G'),('G','L'),('L','G'),('L','L')],42):
    b=Body(n);rows=[];links={}
    b.para('Leia por linha: assuma a propriedade da primeira coluna. Cada célula informa se a conclusão da coluna vale para todos os grafos. V=verdadeiro; F=há contraexemplo. Clique na página para consultar a resposta completa.')
    for ri,a in enumerate('ESH'):
        row=[words[a].capitalize()]
        for ci,bb in enumerate('ESH',1):
            key=(s,a,t,bb)
            if s==t and a==bb:row.append('V • identidade')
            else:
                row.append(('V' if key in true else 'F')+f' • p. {qpages[key]}');links[(ri,ci)]=qpages[key]
        rows.append(row)
    b.table(['Hipótese ↓ / conclusão →','Euleriano','Semieuleriano aberto','Hamiltoniano'],rows,[171,108,122,CW-401],9.7,links)
    b.box('Como interpretar','As propriedades estão por extenso. Semieuleriano significa exatamente dois vértices ímpares. Uma resposta F significa que a conclusão não é garantida; não significa que a combinação seja impossível.')
    b.para('As seis identidades (mesma propriedade no mesmo grafo) são verdadeiras. As outras 30 implicações possuem resposta demonstrada no banco.')
    if n==43:b.para('As implicações não triviais verdadeiras são: G euleriano ⇒ L(G) euleriano; G euleriano ⇒ L(G) hamiltoniano; G hamiltoniano ⇒ L(G) hamiltoniano.')

states=['EH','E¬H','SH','S¬H','NH','N¬H']
names={
 'EH':'Euleriano; hamiltoniano','E¬H':'Euleriano; não hamiltoniano',
 'SH':'Semieuleriano; hamiltoniano','S¬H':'Semieuleriano; não hamiltoniano',
 'NH':'Sem trajeto euleriano; hamiltoniano','N¬H':'Sem trajeto euleriano; não hamiltoniano'}
pairs=[('EH','EH'),('E¬H','EH'),('SH','NH'),('S¬H','SH'),('S¬H','S¬H'),('S¬H','NH'),('S¬H','N¬H'),('NH','EH'),('NH','SH'),('NH','NH'),('N¬H','EH'),('N¬H','E¬H'),('N¬H','SH'),('N¬H','S¬H'),('N¬H','NH'),('N¬H','N¬H')]
codes={pair:f'C{i:02d}' for i,pair in enumerate(pairs,1)}
b=Body(46)
b.para('Existe algum grafo com as propriedades da linha em G e da coluna em L(G)? Sem trajeto euleriano significa não possuir caminho euleriano aberto nem circuito fechado. Semieuleriano, aqui, significa aberto.',10)
rows=[];links={}
for ri,a in enumerate(states):
    row=[names[a]]
    for ci,bb in enumerate(states,1):
        code=codes.get((a,bb),'—');row.append(code)
        if code!='—':links[(ri,ci)]=47+int(code[1:])
    rows.append(row)
b.table(['G ↓ / L(G) →']+[names[s] for s in states],rows,[110]+[(CW-110)/6]*6,7.3,links)
b.box('Como ler','C01 a C16 identificam os exemplos desenhados nas páginas 48–63; clique em um código. “—” indica combinação impossível. Há 16 combinações realizáveis e 20 impossíveis.')
b.para('Exemplo: um G semieuleriano e não hamiltoniano pode gerar L(G) semieuleriano e hamiltoniano (C04). Poder ocorrer não significa ser garantido em todo grafo.',10)

b=Body(47)
b.sub('1. Se G é euleriano')
b.para('L(G) é euleriano e hamiltoniano. Portanto as duas linhas em que G é euleriano, seja ele hamiltoniano ou não, só podem chegar à coluna “euleriano e hamiltoniano”. Isso exclui dez células.')
b.sub('2. Se G é hamiltoniano')
b.para('L(G) também é hamiltoniano. Logo nenhuma coluna com L(G) não hamiltoniano é possível nas linhas em que G é hamiltoniano.')
b.sub('3. Se G é semieuleriano aberto')
b.para('L(G) não pode ser euleriano. Se fosse, todos os graus de G teriam a mesma paridade. Não podem ser todos pares, pois há dois ímpares. Se todos fossem ímpares e só dois vértices fossem ímpares, G teria apenas dois vértices e, sendo simples e conexo, seria K₂. Mas |E|≥3.')
b.sub('4. Se G é semieuleriano e hamiltoniano')
b.para('Os dois vértices ímpares u,v têm grau pelo menos 3, pois um ciclo hamiltoniano exige grau pelo menos 2. Assim, a quantidade de arestas par–ímpar é q=d(u)+d(v)−2 (se uv existir), ou q=d(u)+d(v) (caso contrário). Em ambos os casos, q≥4.')
b.para('Logo L(G) tem pelo menos quatro ímpares: não é euleriano nem semieuleriano aberto.')
b.box('Completude','Essas restrições excluem todas as células marcadas “—”. Cada uma das 16 células restantes possui um exemplo no catálogo. Portanto a classificação está completa nas hipóteses adotadas.')

for n,(a,bb) in enumerate(pairs,48):
    p=doc[n-1]
    p.add_redact_annot(pdf.Rect(M,54,W-M,88),fill=WHITE,cross_out=False)
    p.apply_redactions(images=0,graphics=0);fonts(p)
    p.insert_text((M,72),'G: '+names[a].lower(),fontname='pbold',fontsize=13.5,color=INK)
    p.insert_text((M,87),'L(G): '+names[bb].lower(),fontname='pbold',fontsize=13.5,color=INK)

b=Body(70)
b.para('Há duas convenções para “semieuleriano”: no sentido aberto, exige exatamente dois vértices ímpares; no sentido inclusivo, admite caminho aberto ou circuito fechado e exige zero ou dois ímpares.')
b.box('Contagem no grafo de linha','Se q é a quantidade de arestas par–ímpar em G:\nL(G) semieuleriano aberto ⇔ q=2.\nL(G) semieuleriano no sentido inclusivo ⇔ q=0 ou q=2.')
b.table(['Afirmação','Sentido aberto','Sentido inclusivo'],[
 ('G euleriano ⇒ G semieuleriano','F','V'),('L(G) euleriano ⇒ L(G) semieuleriano','F','V'),('G euleriano ⇒ L(G) semieuleriano','F','V')],[305,103,CW-408],9.5)
b.para('Essas são as três implicações que mudam nas matrizes quando se troca a definição aberta pela inclusiva. As identidades continuam verdadeiras.')
b.para('Para refutar as afirmações que continuam falsas: G=K₄ mostra que G hamiltoniano não garante G semi inclusivo. O losango com diagonal mostra que G hamiltoniano, ou L(G) hamiltoniano, não garante L(G) semi inclusivo.',10)
b.box('Na prova de 2026/1','O gabarito continua V,V,F. O losango com diagonal tem caminho euleriano aberto em G, mas L(G) possui quatro vértices ímpares: não é semieuleriano em nenhuma das duas convenções.')
b.para('Na resposta, declare qual sentido está usando. Quando o enunciado trouxer uma definição explícita, siga essa definição.',10)

# Explica o contexto da notação d(e) em L(G) sem criar uma segunda função de grau.
p=doc[6]
old=p.search_for('Para e={u,v}∈E(G):')
if old:
    r=old[0];p.add_redact_annot(r,fill=LIGHT,cross_out=False);p.apply_redactions(images=0,graphics=0);fonts(p)
    p.insert_text((r.x0,r.y1-2),'Para e={u,v}∈E: d(e) é o grau em L(G), e d(u),d(v) são graus em G.',fontname='pbody',fontsize=9,color=INK)

for row in toc:
    if row[2]==3:row[1]='Notação dos slides e hipóteses'
page=doc[2]
page.add_redact_annot(pdf.Rect(M,54,W-M,88),fill=WHITE,cross_out=False)
page.apply_redactions(images=0,graphics=0);fonts(page)
page.insert_text((M,76),'Notação dos slides e hipóteses',fontname='pbold',fontsize=22,color=INK)
# A referência da notação vem diretamente dos slides do professor Silvio.
oldsource='Slides Zenilton, 10-grafos-hamiltonianos-eurelianos-fleury.pdf, pp. PDF 2, 9, 19 e 23.'
for r in page.search_for(oldsource):page.add_redact_annot(r,fill=WHITE,cross_out=False)
page.apply_redactions(images=0,graphics=0)
page.insert_text((M,H-65),'Silvio, 01-graphs-concepts.pdf, pp. PDF 27–28: d(v). Semi: slides de apoio Zenilton, PDF 19 e 23.',fontname='pbody',fontsize=7.2,color=GREY)
doc.set_toc(toc)
meta=doc.metadata;meta['subject']='Notação dos slides: G=(V,E), d(v), L(G); propriedades escritas por extenso.';doc.set_metadata(meta)
doc.subset_fonts();doc.save(OUT,garbage=4,deflate=True)
check=pdf.open(OUT)
assert len(check)==72
text='\n'.join(p.get_text() for p in check)
assert 'd_G' not in text and 'd_L' not in text and 'd_H' not in text
assert 'd_{L(G)}' not in text
for i,p in enumerate(check):
    for block in p.get_text('dict')['blocks']:
        if block['type']!=0:continue
        for line in block['lines']:
            for s in line['spans']:
                r=pdf.Rect(s['bbox']);assert r.x0>=0 and r.x1<=W+.2 and r.y0>=0 and r.y1<=H+.2,(i+1,s['text'])
print('PDF ajustado:',OUT,'Paginas:',len(check))
