"""Colinha de uma página: relações entre G e L(G)."""
from pathlib import Path
from io import BytesIO
import pymupdf as pdf
from matplotlib import font_manager
from matplotlib.mathtext import math_to_image

BASE=Path(__file__).resolve().parent.parent
OUT=BASE/'Colinha_Euler_Hamilton_Grafo_de_Linha.pdf'
W,H=595.28,841.89;M=36;CW=W-2*M
INK=(.09,.17,.25);TEAL=(0,.40,.42);LIGHT=(.93,.96,.96);WHITE=(1,1,1)
GREEN=(.05,.39,.26);RED=(.72,.15,.19);AMBER=(.59,.35,.04)
doc=pdf.open();p=doc.new_page(width=W,height=H)
F={}
for k,bold in [('body',False),('bold',True)]:
    b=Path(font_manager.findfont(font_manager.FontProperties(family='DejaVu Sans',weight='bold' if bold else 'normal'))).read_bytes()
    F[k]=pdf.Font(fontbuffer=b);p.insert_font(fontname=k,fontbuffer=b)
def text(x,y,s,size=9.5,font='body',color=INK):p.insert_text((x,y),s,fontname=font,fontsize=size,color=color)
def wrap(s,width,size=9.5,font='body'):
    lines=[];line=''
    for word in s.split():
        trial=(line+' '+word).strip()
        if line and F[font].text_length(trial,fontsize=size)>width:lines.append(line);line=word
        else:line=trial
    return lines+[line]

p.draw_rect(pdf.Rect(0,0,W,7),color=None,fill=TEAL)
text(M,35,'COLINHA • EULER, HAMILTON E L(G)',17,'bold',TEAL)
text(M,55,'G simples, não direcionado e conexo; pelo menos 3 arestas.',9)
text(M,70,'Semieuleriano = caminho euleriano ABERTO: exatamente dois vértices ímpares.',9,'bold')
text(M,91,'SIM',9,'bold',GREEN);text(M+28,91,'= sempre.',9)
text(M+108,91,'NÃO',9,'bold',RED);text(M+139,91,'= impossível.',9)
text(M+248,91,'DEPENDE',9,'bold',AMBER);text(M+307,91,'= pode ocorrer, mas não é garantido.',9)
y=107
def table(title,source,target,rows):
    global y
    text(M,y+12,title,11.2,'bold',TEAL);y+=23
    widths=[154,(CW-154)/3,(CW-154)/3,(CW-154)/3]
    headers=[f'Se {source} é…',f'{target} é euleriano?',f'{target} é semieuleriano?',f'{target} é hamiltoniano?']
    for ri,row in enumerate([headers]+rows):
        font='bold' if ri==0 else 'body';size=9
        cells=[wrap(s,w-12,size,font) for s,w in zip(row,widths)]
        h=max(len(c) for c in cells)*12+11;x=M
        for ci,(cell,width) in enumerate(zip(cells,widths)):
            p.draw_rect(pdf.Rect(x,y,x+width,y+h),color=WHITE,width=.7,fill=TEAL if ri==0 else LIGHT if ri%2 else (.98,.99,.99))
            for j,line in enumerate(cell):
                color=WHITE if ri==0 else GREEN if line=='SIM' else RED if line=='NÃO' else AMBER if line=='DEPENDE' else INK
                text(x+6,y+15+j*12,line,size,'bold' if ri==0 or ci>0 else 'body',color)
            x+=width
        y+=h
    y+=12

table('1. Partindo de G → o que acontece em L(G)?','G','L(G)',[
    ['Euleriano','SIM','NÃO','SIM'],
    ['Semieuleriano','NÃO','DEPENDE','DEPENDE'],
    ['Hamiltoniano','DEPENDE','DEPENDE','SIM']])
table('2. Partindo de L(G) → o que acontece em G?','L(G)','G',[
    ['Euleriano','DEPENDE','NÃO','DEPENDE'],
    ['Semieuleriano','NÃO','DEPENDE','DEPENDE'],
    ['Hamiltoniano','DEPENDE','DEPENDE','DEPENDE']])
table('3. Dentro do próprio G','G','G',[
    ['Euleriano','SIM','NÃO','DEPENDE'],
    ['Semieuleriano','NÃO','SIM','DEPENDE'],
    ['Hamiltoniano','DEPENDE','DEPENDE','SIM']])
table('4. Dentro do próprio L(G)','L(G)','L(G)',[
    ['Euleriano','SIM','NÃO','DEPENDE'],
    ['Semieuleriano','NÃO','SIM','DEPENDE'],
    ['Hamiltoniano','DEPENDE','DEPENDE','SIM']])

text(M,y+10,'LEMBRETES',10,'bold',TEAL);y+=25
notes=[
 'L(G) euleriano ⇔ todos os graus de G são pares OU todos são ímpares.',
 'G semieuleriano ⇒ L(G) tem caminho hamiltoniano; o ciclo não é garantido.',
 'Se “semi” incluir circuitos fechados, todo euleriano também será semi.']
for note in notes:
    for line in wrap(note,CW,9):text(M,y,line,9);y+=12
y+=5
tex=r'$e=\{u,v\}\in E:\qquad d(e)=d(u)+d(v)-2$'
buf=BytesIO();math_to_image(tex,buf,format='svg',prop=font_manager.FontProperties(size=12))
svg=pdf.open(stream=buf.getvalue().replace(b'fill: #ffffff',b'fill: none'),filetype='svg')
eq=pdf.open(stream=svg.convert_to_pdf(),filetype='pdf');r=eq[0].rect
p.show_pdf_page(pdf.Rect(M,y,M+r.width,y+r.height),eq,0);y+=r.height+13
text(M,y,'d(e): grau em L(G).  d(u), d(v): graus das pontas em G.',8.5)
assert y<805,y
doc.set_metadata({'title':'Colinha — Euler, Hamilton e grafo de linha','subject':'36 relações em uma página; semi no sentido aberto'})
doc.subset_fonts();doc.save(OUT,garbage=4,deflate=True)
print(f'{OUT}\nPaginas: {len(doc)}; conteudo ate y={y:.1f}')
