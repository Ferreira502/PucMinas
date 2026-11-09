"""Caderno em formato de prova: somente pergunta, resposta discursiva e matemática."""
from pathlib import Path
from io import BytesIO
import runpy,re,json
import pymupdf as pdf
from matplotlib import font_manager
from matplotlib.mathtext import math_to_image

BASE=Path(__file__).resolve().parent.parent
OUT=BASE/'.Caderno_Respostas_Prova.pdf'
source=runpy.run_path(str(BASE/'.revisao_relacoes/reformular_caderno.py'))
records={}
class Dummy:
    def __getattr__(self,k):return lambda *a,**kw:None
class Recorder:
    def __init__(self,n,chapter,title,*a,**kw):self.n=n;self.y=0;self.p=Dummy();records[n]={'q':title}
    def answer(self,s):records[self.n]['short']=s
    def __getattr__(self,k):return lambda *a,**kw:None
for name in ['introduction','theory','bank','extra_questions']:
    f=source[name];f.__globals__['Page']=Recorder;f()
PAGES=list(range(3,42))+list(range(64,72))
assert len(PAGES)==47

def T(s):return ('text',s)
def F(*s):return ('math',s)
answers={
3:[T('Consideramos G=(V,E) finito, simples, não direcionado e conexo, com pelo menos três arestas. O grau d(v) é a quantidade de arestas incidentes em v. Escrevemos n=|V| e m=|E|. Em L(G), cada aresta e de G é representada por um vértice, cujo grau também é escrito d(e), com o contexto indicando o grafo.'),
   F(r'n=|V|,\qquad m=|E|,\qquad d(v)=\left|\{e\in E:v\in e\}\right|'),
   T('Usamos “euleriano” para a existência de circuito euleriano; “semieuleriano aberto” para exatamente dois vértices ímpares; “hamiltoniano” para a existência de ciclo hamiltoniano. A hipótese m≥3 evita que L(G) tenha menos de três vértices. As afirmações sobre Hamilton referem-se a ciclos, não apenas a caminhos.')],
4:[T('Euler trata de percorrer todas as arestas exatamente uma vez; Hamilton trata de visitar todos os vértices exatamente uma vez. Um circuito euleriano fecha no vértice inicial e pode repetir outros vértices, desde que não repita arestas. Um ciclo hamiltoniano também fecha, mas não repete vértices no meio do percurso.'),
   T('Por exemplo, dois triângulos abc e ade com o único vértice comum a admitem o circuito euleriano abaixo. O vértice a se repete no meio, o que é permitido para Euler. Esse grafo não é hamiltoniano: a é vértice de articulação, e um grafo com ciclo hamiltoniano não pode ter articulação.'),
   F(r'a\to b\to c\to a\to d\to e\to a')],
5:[T('Pelo teorema de Euler, um grafo conexo é euleriano se, e somente se, todos os seus vértices têm grau par. Se há exatamente dois vértices ímpares, existe caminho euleriano aberto, começando em um deles e terminando no outro. Com quatro ou mais ímpares, não existe caminho que percorra todas as arestas uma única vez.'),
   F(r'\sum_{v\in V}d(v)=2|E|'),
   T('A identidade é o lema do aperto de mãos: cada aresta contribui uma vez em cada ponta. Ela implica que a quantidade de vértices ímpares é par. A necessidade dos graus pares vem do emparelhamento entre entrada e saída em cada vértice de um circuito. A suficiência pode ser obtida construindo circuitos por arestas não usadas e unindo-os até consumir todas as arestas, como em Hierholzer. Somar graus e dividir por dois apenas conta as arestas; essa operação, sozinha, não prova que o grafo seja euleriano.')],
6:[T('Para construir L(G), crie um vértice para cada aresta de G e ligue dois desses vértices quando as arestas correspondentes compartilham uma extremidade. Formalmente:'),
   F(r'V(L(G))=E',r'\{e,f\}\in E(L(G))\ \Longleftrightarrow\ e\ne f\ \mathrm{e}\ e\cap f\ne\varnothing'),
   T('Por exemplo, se E={ab,ac,bc,ad}, os vértices de L(G) são ab,ac,bc,ad. Há as ligações ab—ac, ab—bc, ab—ad, ac—bc e ac—ad. Não há bc—ad, pois essas arestas não têm ponta comum. Se G é conexo, L(G) também é conexo: uma sequência de arestas incidentes em G se transforma em um passeio entre seus vértices correspondentes em L(G).')],
7:[T('O grau do vértice de L(G) correspondente à aresta e={u,v} é a soma dos graus de suas duas pontas em G menos dois:'),
   F(r'd(e)=(d(u)-1)+(d(v)-1)=d(u)+d(v)-2'),
   T('Existem d(u)−1 outras arestas incidentes em u e d(v)−1 incidentes em v. Subtraímos a própria aresta e das duas contagens. Como G é simples, nenhuma outra aresta é contada nos dois conjuntos; portanto a soma é correta. Na fórmula, d(e) é grau em L(G), enquanto d(u),d(v) são graus em G. Não é uma distância nem a quantidade total de vértices.'),
   F(r'|V(L(G))|=|E|=\frac{1}{2}\sum_{v\in V}d(v)'),
   T('Essa última expressão é uma conta diferente: informa quantos vértices existem em L(G).')],
8:[T('Para que L(G) seja euleriano, G deve ser conexo e todos os seus vértices devem ter graus de mesma paridade: todos pares ou todos ímpares. Assim, G não precisa ser euleriano; ter todos os graus ímpares também pode produzir L(G) euleriano.'),
   F(r'd(e)=d(u)+d(v)-2',r'd(u)=2k,\ d(v)=2\ell\ \Longrightarrow\ d(e)=2(k+\ell-1)',r'd(u)=2k+1,\ d(v)=2\ell+1\ \Longrightarrow\ d(e)=2(k+\ell)'),
   T('Nas duas situações, cada vértice e de L(G) tem grau par. Como G é conexo, L(G) também é conexo; pelo teorema de Euler, L(G) é euleriano. Reciprocamente, se L(G) é euleriano, a fórmula força cada aresta uv de G a ligar pontas de mesma paridade. A conectividade propaga essa igualdade por todos os vértices de G. Portanto, a condição é necessária e suficiente. A estrela K₁,₃, de graus 3,1,1,1, ilustra a possibilidade de todos os graus ímpares: seu grafo de linha é K₃.')],
9:[T('Para que L(G) seja semieuleriano aberto, G deve ser conexo e possuir exatamente duas arestas cujas extremidades tenham graus de paridades diferentes. Seja q a quantidade dessas arestas. Pela fórmula do grau, uma aresta par–ímpar gera um vértice ímpar em L(G), e somente esse tipo de aresta gera grau ímpar.'),
   F(r'd(e)=d(u)+d(v)-2',r'q=2\ \Longleftrightarrow\ L(G)\ \mathrm{semieuleriano\ aberto}'),
   T('Como L(G) é conexo, o teorema de Euler garante caminho euleriano aberto exatamente quando existem dois vértices ímpares. Se os únicos ímpares de G forem u,v, q=d(u)+d(v)−2 quando uv é aresta, ou q=d(u)+d(v) quando não é. No primeiro caso subtraímos dois porque uv foi contada nas duas pontas e não liga par a ímpar. Logo, G ter dois ímpares não basta: no losango com diagonal, q=3+3−2=4, e L(G) tem quatro ímpares.')],
10:[T('Para que L(G) seja hamiltoniano, G deve conter um subgrafo H conexo, com todos os graus internos pares, e que tenha pelo menos uma extremidade de cada aresta de G entre seus vértices. Essa é a condição necessária e suficiente de Harary–Nash-Williams, chamada existência de subgrafo euleriano dominante. Permite-se H com um único vértice, de grau zero.'),
    F(r'H\subseteq G,\qquad H\ \mathrm{conexo}',r'\forall v\in V(H),\quad d(v)\in\{0,2,4,\ldots\}\quad\mathrm{em}\ H',r'\forall\{u,v\}\in E,\quad u\in V(H)\ \mathrm{ou}\ v\in V(H)'),
    T('“Dominante” significa que não pode existir aresta de G com as duas pontas fora de H. Os graus precisam ser pares em H, não necessariamente em G. Um circuito euleriano de H permite ordenar suas arestas em ciclo; as outras arestas de G podem ser inseridas nessa ordem junto de uma ponta comum. Em L(G), essa ordem é um ciclo que visita todos os vértices uma vez. Em particular, G euleriano é suficiente (H=G); G hamiltoniano também é suficiente (H é um ciclo hamiltoniano de G). Essas condições individuais não são necessárias.')],
11:[T('O subgrafo euleriano dominante H garante um ciclo hamiltoniano em L(G) porque permite ordenar todas as arestas de G circularmente, com arestas consecutivas incidentes. Se H tem arestas, comece pela ordem de seu circuito euleriano. Atribua cada aresta externa a uma de suas pontas que pertença a H. Em uma passagem do circuito por v, insira as arestas atribuídas a v entre a chegada e a saída. Todas compartilham v, logo os vértices correspondentes são adjacentes em L(G). Cada aresta aparece uma vez e a sequência fecha.'),
    F(r'e_1\to e_2\to\cdots\to e_m\to e_1'),
    T('Se H tem só um vértice, todas as arestas de G incidem nele; então L(G)=Kₘ e, como m≥3, há ciclo hamiltoniano. A necessidade também vale: de um ciclo e₁,…,eₘ,e₁ de L(G), registre as pontas comuns xᵢ entre arestas consecutivas. Percorra eᵢ quando suas duas pontas registradas forem diferentes; caso sejam iguais, permaneça nessa ponta. Eliminando as permanências, obtemos uma trilha fechada sem arestas repetidas, ou um único vértice. Ela define H conexo, de graus pares, que encosta em toda aresta de G.')],
64:[T('Na questão 16 de sala, o gabarito é falso, falso, verdadeiro, falso, falso. Os itens 1 e 2 falham porque Euler e Hamilton não se implicam no próprio grafo. O item 3 é verdadeiro porque o circuito euleriano de G vira um ciclo hamiltoniano de L(G). O item 4 é falso porque P₄ gera P₃ e depois P₂. O item 5 falha no losango com diagonal, que é hamiltoniano e gera L(G) com quatro ímpares.'),
    T('Na questão 1 da P2 de 2026/1, o gabarito é verdadeiro, verdadeiro, falso. Na letra a, prove que cada grau d(u)+d(v)−2 em L(G) é par e use conectividade. Na letra b, transforme a ordem de arestas do circuito euleriano em ciclo de vértices de L(G). Na letra c, use o losango com diagonal: G tem dois ímpares, mas L(G) tem quatro. Só escrever o gabarito não constitui justificativa.')],
65:[T('Não. Aplicar o operador de grafo de linha duas vezes não devolve necessariamente um grafo igual nem isomorfo a G. Considere o caminho P₄, com quatro vértices e três arestas:'),
    F(r'G=P_4,\quad L(G)=P_3,\quad L(L(G))=P_2',r'|V|=4,\quad |V(L(G))|=3,\quad |V(L^2(G))|=2'),
    T('Como os números de vértices são diferentes, G e L²(G) não são isomorfos. Esse contraexemplo refuta a afirmação universal. Há casos em que funciona, como ciclos Cₙ com n≥3, pois L(Cₙ)≅Cₙ; isso não estabelece a identidade para grafos quaisquer.')],
66:[T('Se G é semieuleriano aberto, L(G) possui um caminho hamiltoniano. Não é garantido que esse caminho feche em ciclo. Escreva as arestas do caminho euleriano de G na ordem e₁,…,eₘ. Elas são distintas e incluem todas as arestas; em L(G), correspondem a todos os vértices. Consecutivas compartilham uma ponta, logo são adjacentes.'),
    F(r'e_1\to e_2\to\cdots\to e_m',r'P_4:\ a\to b\to c\to d\quad\longmapsto\quad ab\to bc\to cd'),
    T('Não precisamos ter adjacência entre a última e a primeira, por isso a conclusão é caminho, não ciclo hamiltoniano. A inversa falha: subdividindo um ramo de K₁,₃, G tem quatro ímpares, mas L(G) possui o caminho hamiltoniano de→ad→ab→ac. Portanto, L(G) ter caminho hamiltoniano não garante caminho euleriano em G.')],
67:[T('Os teoremas de Dirac e Ore fornecem condições suficientes de grau para L(G) ser hamiltoniano. Como L(G) tem m=|E| vértices, Dirac exige que cada grau em L(G) seja pelo menos m/2. Substituindo d(e)=d(u)+d(v)−2, obtemos:'),
    F(r'\forall\{u,v\}\in E,\quad d(u)+d(v)\geq\frac{m}{2}+2'),
    T('Se essa desigualdade vale em toda aresta de G, L(G) é hamiltoniano. Para Ore, cada par de vértices não adjacentes de L(G) corresponde a duas arestas disjuntas uv,xy de G. A soma dos graus em L(G) deve ser pelo menos m, o que equivale a exigir, para todo par dessas arestas:'),
    F(r'd(u)+d(v)+d(x)+d(y)\geq m+4'),
    T('Essas condições não são necessárias. Em C₅, os graus das pontas somam 4, menor que m/2+2=4,5; mesmo assim L(C₅)≅C₅ é hamiltoniano. Portanto falhar nos testes não prova ausência de ciclo.')],
68:[T('Uma folha, uma ponte ou um vértice de articulação impede um ciclo hamiltoniano. Em cada vértice do ciclo precisam existir duas arestas distintas para entrar e sair; por isso uma folha é impossível. Uma ponte seria a única ligação entre duas partes: um ciclo abrangente teria de atravessá-la na ida e na volta. Se v é de articulação, retirar v desconecta o grafo; mas retirar um vértice de um ciclo hamiltoniano deixaria um caminho por todos os outros vértices, que permaneceriam conectados.'),
    F(r'G\ \mathrm{hamiltoniano}\quad\Longrightarrow\quad\delta(G)\geq2'),
    T('Mais geralmente, retirar um conjunto não vazio S de vértices de um ciclo deixa no máximo |S| segmentos. Logo um grafo hamiltoniano deve satisfazer a condição abaixo. Arestas adicionais só podem unir componentes.'),
    F(r'\mathrm{numero\ de\ componentes\ de}\ (G-S)\leq |S|'),
    T('Essas condições são necessárias, mas não suficientes em geral. Não encontrar folhas, pontes ou articulações, sozinho, não prova que exista ciclo hamiltoniano.')],
69:[T('Não. Dizer que uma implicação é falsa significa que ela não vale para todos os grafos, e não que a combinação nunca ocorre. Formalmente, a negação de uma implicação universal exige um grafo em que a hipótese seja verdadeira e a conclusão falsa:'),
    F(r'\neg\left(\forall G,\ P(G)\Rightarrow Q(G)\right)',r'\Longleftrightarrow\quad\exists G:\ P(G)\wedge\neg Q(G)'),
    T('Por exemplo, o triângulo com folha é semieuleriano aberto e gera L(G) hamiltoniano. Já P₄ também é semieuleriano e gera P₃, que não é hamiltoniano. Assim G semi pode gerar L(G) hamiltoniano, mas não garante isso. Diferentemente, G semi aberto e L(G) euleriano é impossível nas hipóteses: a condição de mesma paridade em G não pode coexistir com exatamente dois ímpares e m≥3.')],
70:[T('No sentido inclusivo, todo grafo euleriano também é semieuleriano, pois um circuito fechado é admitido como caminho euleriano. Assim o sentido aberto exige exatamente dois ímpares, enquanto o inclusivo admite zero ou dois. Se q conta as arestas de G que ligam par a ímpar, então:'),
    F(r'L(G)\ \mathrm{semi\ aberto}\ \Longleftrightarrow\ q=2',r'L(G)\ \mathrm{semi\ inclusivo}\ \Longleftrightarrow\ q\in\{0,2\}'),
    T('As afirmações “G euleriano implica G semi”, “L(G) euleriano implica L(G) semi” e “G euleriano implica L(G) semi” passam de falsas no sentido aberto a verdadeiras no inclusivo. O gabarito da P2 de 2026/1 continua V,V,F: o losango com diagonal tem caminho euleriano em G, mas L(G) tem quatro ímpares e não é semi em nenhum sentido. Na prova, siga a definição do enunciado e explicite a convenção quando houver ambiguidade.')],
71:[T('A conectividade é necessária para garantir um único percurso por todas as arestas ou um ciclo por todos os vértices. Dois triângulos separados têm todos os graus pares, mas não há circuito único percorrendo as arestas de ambos; seu grafo de linha também fica desconexo. Vértices isolados desaparecem em L(G), pois não representam nenhuma aresta.'),
    T('A hipótese de grafo simples justifica a fórmula d(e)=d(u)+d(v)−2: não há laços nem outra aresta com as mesmas duas pontas para ser contada duas vezes. Com paralelas ou laços, a contagem precisa ser adaptada. Além disso, se G tiver menos de três arestas, L(G) terá menos de três vértices e não poderá ter um ciclo simples hamiltoniano. Por isso esses casos não devem ser incluídos automaticamente nos teoremas do caderno.')]
}

graphdefs={
 'c3':'Considere o triângulo G=C₃, com V={a,b,c} e E={ab,bc,ac}.',
 'k4':'Considere G=K₄, o grafo completo nos vértices a,b,c,d.',
 'p4':'Considere o caminho G=P₄, com V={a,b,c,d} e E={ab,bc,cd}.',
 'star3':'Considere a estrela G=K₁,₃, com centro a, folhas b,c,d e E={ab,ac,ad}.',
 'bowtie':'Considere G com V={a,b,c,d,e} e E={ab,bc,ac,ad,de,ae}, isto é, os triângulos abc e ade com apenas a em comum.',
 'diamond':'Considere G com V={a,b,c,d} e E={ab,ac,bc,ad,bd}, um losango com a diagonal ab.',
 'paw':'Considere G com V={a,b,c,d} e E={ab,bc,ac,ad}, o triângulo abc com a folha d ligada a a.',
 'double':'Considere a árvore G com V={a,b,c,d,e,f} e E={ab,ac,ad,be,bf}. Os centros adjacentes a,b têm grau 3 e as quatro folhas têm grau 1.',
 'substar':'Considere G com V={a,b,c,d,e} e E={ab,ac,ad,de}, uma estrela K₁,₃ com o ramo a—e subdividido pelo vértice d.'}

def main_answers():
    G=source['G']
    for i,(a,pa,b,pb,key,short,why) in enumerate(source['questions']):
        n=12+i;g=G[key];lg=g.line();segments=[]
        if i==6:
            segments=[T('Sim. Como G é euleriano, pelo teorema de Euler todos os graus d(v) são pares. Para qualquer aresta e={u,v}, o vértice correspondente em L(G) possui grau:'),
              F(r'd(e)=d(u)+d(v)-2=2k+2\ell-2=2(k+\ell-1)'),
              T('Portanto cada grau de L(G) é par. Além disso, G conexo implica L(G) conexo. Assim L(G) é conexo e tem todos os graus pares; pelo teorema de Euler, é euleriano. A prova calcula o grau de cada vértice, e não apenas a soma total dos graus.')]
        elif i==8:
            segments=[T('Sim. Como G é euleriano, existe um circuito que percorre todas as suas arestas exatamente uma vez. Escreva esse circuito como v₀,e₁,v₁,…,eₘ,v₀. As arestas e₁,…,eₘ são distintas e formam todo E.'),
              F(r'V(L(G))=E=\{e_1,e_2,\ldots,e_m\}'),
              T('Arestas consecutivas do circuito compartilham uma extremidade, portanto seus vértices correspondentes são adjacentes em L(G). Como o circuito fecha, a última e a primeira também são adjacentes. Logo a sequência abaixo é um ciclo por todos os vértices de L(G), uma única vez:'),
              F(r'e_1\to e_2\to\cdots\to e_m\to e_1'),T('Portanto L(G) é hamiltoniano. O circuito euleriano transforma-se em ciclo hamiltoniano, e não somente em caminho aberto.')]
        elif i==14:
            segments=[T('Sim. Seja C um ciclo hamiltoniano de G. Ele é conexo, contém todos os vértices de G e tem grau 2 em cada um dentro do próprio C. Toda aresta adicional de G tem suas pontas em C; logo C é um subgrafo euleriano dominante.'),
              F(r'C\subseteq G,\quad V(C)=V,\quad d(v)=2\ \mathrm{em}\ C'),
              T('Pelo teorema de Harary–Nash-Williams, L(G) é hamiltoniano. Construtivamente, ordene as arestas de C circularmente e atribua cada aresta extra a uma de suas pontas v. Insira as atribuídas a v entre as arestas do ciclo que chegam e saem de v. Todas compartilham v. A sequência ampliada inclui toda aresta de G uma vez e fecha, formando o ciclo hamiltoniano de L(G). Não basta usar só as arestas de C se G possuir cordas.')]
        elif i in [2,3,7,26,27]:
            obj='G' if a=='G' else 'L(G)'
            if i in [2,7,26]:
                segments=[T(short+' Pelo teorema de Euler, um grafo conexo euleriano tem todos os graus pares, portanto zero vértices ímpares. Um caminho euleriano aberto existe exatamente quando há dois ímpares. Essas situações são incompatíveis. '+('Se G é euleriano, L(G) também é euleriano pela fórmula d(e)=d(u)+d(v)−2. ' if i==7 else '')+'O triângulo C₃, que também é L(K₁,₃), fornece um exemplo concreto de grafo euleriano que não é semieuleriano aberto.')]
            else:segments=[T(short+' Pelo teorema de Euler, exatamente dois vértices ímpares permitem somente o caminho euleriano aberto, que tem início e fim distintos. Um circuito euleriano exigiria zero ímpares. Logo a hipótese impede a conclusão. P₄, ou L(P₄)=P₃ quando a pergunta trata do grafo de linha, é um contraexemplo concreto.')]
        elif i==9:
            segments=[T('Não. Na verdade, nas hipóteses adotadas, G semieuleriano aberto impede L(G) euleriano. Suponha que L(G) fosse euleriano. Pela fórmula d(e)=d(u)+d(v)−2, cada aresta de G ligaria pontas com a mesma paridade. Como G é conexo, todos os seus vértices teriam graus de mesma paridade.'),T('G não pode ter todos os graus pares, pois tem dois ímpares. Se todos fossem ímpares e existissem apenas dois, G teria dois vértices; sendo simples e conexo, teria só uma aresta, contrariando |E|≥3. Assim L(G) não pode ser euleriano. Como exemplo, P₄ é semi aberto e L(P₄)=P₃ tem dois ímpares.')]
        elif i==16:
            segments=[T('Não. Se L(G) é euleriano e G é conexo, todos os graus de G têm a mesma paridade. Caso sejam todos pares, G é euleriano e não semi aberto. Caso sejam todos ímpares, G não pode ter exatamente dois vértices: no grafo simples conexo isso daria K₂, com uma única aresta, excluído pela hipótese |E|≥3.'),T('Portanto G não é semieuleriano aberto. A estrela K₁,₃ é um contraexemplo simples: L(G)=K₃ é euleriano, mas G tem quatro ímpares, de graus 3,1,1,1.')]
        elif i==18:
            segments=[T('Não. Se G fosse euleriano, então L(G) seria euleriano, pois cada grau d(u)+d(v)−2 seria par e L(G) seria conexo. Isso contradiz a hipótese de L(G) ter exatamente dois ímpares. Portanto G não pode ser euleriano. Por exemplo, L(P₄)=P₃ é semi aberto e G=P₄ não é euleriano.')]
        else:
            segments=[T(short+' '+graphdefs[key])]
            if key in ['p4','star3','diamond','substar','double','paw']:
                segments.append(F(r'G:\quad '+source['eqdegrees'](g),r'L(G):\quad '+source['eqdegrees'](lg)))
            elif key=='bowtie':segments.append(F(r'd(a)=4,\qquad d(b)=d(c)=d(d)=d(e)=2'))
            elif key=='k4':segments.append(F(r'd(a)=d(b)=d(c)=d(d)=3'))
            elif key=='c3':segments.append(F(r'd(a)=d(b)=d(c)=2'))
            hyp=g if a=='G' else lg
            if pa=='hamiltoniano':
                cycle=hyp.cycle();assert cycle
                segments.append(T('A hipótese hamiltoniana é satisfeita pelo ciclo '+source['seq'](cycle)+' em '+a+'.'))
            elif pa=='semieuleriano aberto':segments.append(T(a+' é conexo e tem exatamente dois vértices ímpares, portanto satisfaz a hipótese semieuleriana aberta.'))
            else:segments.append(T(a+' é conexo e todos os seus graus são pares, portanto satisfaz a hipótese euleriana.'))
            target=g if b=='G' else lg
            extra=' Um vértice de grau 1 não pode pertencer a um ciclo hamiltoniano, pois faltaria uma segunda aresta para entrar e sair.' if pb=='hamiltoniano' and min(target.ds.values())==1 else ''
            segments.append(T(why+extra+' Assim a hipótese é verdadeira neste exemplo e a conclusão é falsa, o que refuta a afirmação universal.'))
        answers[n]=segments
main_answers()
assert set(answers)==set(PAGES)

W,H=595.28,841.89;M=43;CW=W-2*M
INK=(.09,.17,.25);TEAL=(0,.40,.42);GREY=(.42,.48,.53);WHITE=(1,1,1)
FB={};FONT={}
for name,bold in [('body',False),('bold',True)]:
    FB[name]=Path(font_manager.findfont(font_manager.FontProperties(family='DejaVu Sans',weight='bold' if bold else 'normal'))).read_bytes()
    FONT[name]=pdf.Font(fontbuffer=FB[name])
doc=pdf.open();page=None;y=0;toc=[];mathcache={};locations=[]
SIZE=10.5;LEADING=15.1

def wrap(s,width,size=SIZE,font='body'):
    lines=[]
    for para in str(s).split('\n'):
        line=''
        for word in para.split():
            trial=(line+' '+word).strip()
            if line and FONT[font].text_length(trial,fontsize=size)>width:lines.append(line);line=word
            else:line=trial
        lines.append(line)
    return lines

def equation(tex):
    assert not any(ord(c)<32 for c in tex),repr(tex)
    tex=re.sub(r'\\ge(?![a-zA-Z])',r'\\geq',tex)
    tex=re.sub(r'\\le(?![a-zA-Z])',r'\\leq',tex)
    if tex not in mathcache:
        b=BytesIO();math_to_image('$'+tex+'$',b,format='svg',prop=font_manager.FontProperties(size=13.5))
        svg=pdf.open(stream=b.getvalue().replace(b'fill: #ffffff',b'fill: none'),filetype='svg')
        d=pdf.open(stream=svg.convert_to_pdf(),filetype='pdf');r=d[0].rect
        factor=min(1,(CW-24)/r.width);mathcache[tex]=(d,r.width*factor,r.height*factor)
    return mathcache[tex]

def newpage():
    global page,y
    page=doc.new_page(width=W,height=H)
    for k,data in FB.items():page.insert_font(fontname=k,fontbuffer=data)
    page.draw_rect(pdf.Rect(0,0,W,6),color=None,fill=TEAL)
    page.insert_text((M,33),'CADERNO RESOLVIDO • RESPOSTAS PARA A PROVA',fontname='bold',fontsize=12.4,color=TEAL)
    page.draw_line((M,H-40),(W-M,H-40),color=(.89,.93,.93),width=.7)
    page.insert_text((M,H-24),'Euler, Hamilton e grafos de linha',fontname='body',fontsize=8,color=GREY)
    page.insert_text((W-M-15,H-24),str(len(doc)),fontname='bold',fontsize=8,color=TEAL)
    y=55

def paragraph(s):
    global y
    for line in wrap(s,CW):
        page.insert_text((M,y+SIZE),line,fontname='body',fontsize=SIZE,color=INK);y+=LEADING
    y+=7

newpage()
for index,n in enumerate(PAGES,1):
    title=f'{index:02d}. '+records[n]['q'];head=wrap(title,CW,12.1,'bold');segments=answers[n]
    height=len(head)*17.2+9
    for si,(kind,data) in enumerate(segments):
        if kind=='text':height+=len(wrap(('Resposta: ' if si==0 else '')+data,CW))*LEADING+7
        else:height+=sum(equation(eq)[2]+9 for eq in data)+3
    assert height<H-110,(n,height)
    if y+height>H-55:newpage()
    top=y
    for line in head:
        page.insert_text((M,y+12.1),line,fontname='bold',fontsize=12.1,color=TEAL);y+=17.2
    y+=9
    for si,(kind,data) in enumerate(segments):
        if kind=='text':paragraph(('Resposta: ' if si==0 else '')+data)
        else:
            y+=3
            for eq in data:
                d,w,h=equation(eq)
                page.show_pdf_page(pdf.Rect(M+12,y,M+12+w,y+h),d,0);y+=h+9
    toc.append([1,title,len(doc),{'kind':pdf.LINK_GOTO,'page':len(doc)-1,'to':pdf.Point(M,top)}])
    locations.append({'numero':index,'pergunta':records[n]['q'],'pagina_pdf':len(doc),'pagina_caderno_anterior':n})
    y+=17

doc.set_toc(toc)
doc.set_metadata({'title':'Caderno resolvido — perguntas e respostas para prova',
                  'subject':'47 questões com demonstrações, contraexemplos, fórmulas e teoremas; sem tabelas ou desenhos',
                  'author':'Material de estudo de Grafos'})
doc.subset_fonts();doc.save(OUT,garbage=4,deflate=True)
check=pdf.open(OUT)
assert len(check.get_toc())==47
alltext='\n'.join(p.get_text() for p in check)
assert alltext.count('Resposta:')==47
for p in check:
    for block in p.get_text('dict')['blocks']:
        if block['type']!=0:continue
        for line in block['lines']:
            for s in line['spans']:
                r=pdf.Rect(s['bbox']);assert r.x0>=0 and r.x1<=W+.1 and r.y0>=0 and r.y1<=H+.1
(BASE/'.revisao_relacoes/respostas_prova_manifest.json').write_text(json.dumps(locations,ensure_ascii=False,indent=2),encoding='utf-8')
print(f'PDF: {OUT}\nPerguntas: 47\nPaginas: {len(check)}\nFormulas distintas: {len(mathcache)}')
