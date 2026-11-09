"""Tabela com as perguntas e as respostas por extenso do caderno resolvido."""
from pathlib import Path
import runpy
import pymupdf as pdf
from matplotlib import font_manager

BASE=Path(__file__).resolve().parent.parent
OUT=BASE/'Colinha_Euler_Hamilton_Grafo_de_Linha.pdf'
source=runpy.run_path(str(BASE/'.revisao_relacoes/reformular_caderno.py'))
records={}

class DummyDrawing:
    def __getattr__(self,name):return lambda *args,**kwargs:None

class Recorder:
    """Lê as mesmas perguntas/respostas do gerador, sem renderizar o caderno."""
    def __init__(self,n,chapter,title,*args,**kwargs):
        self.n=n;self.y=0;self.p=DummyDrawing();records[n]={'question':title}
    def answer(self,s):records[self.n]['answer']=s
    def __getattr__(self,name):return lambda *args,**kwargs:None

for name in ['introduction','theory','bank','extra_questions']:
    func=source[name];func.__globals__['Page']=Recorder;func()
pages=list(range(3,42))+list(range(64,72))
qa=[records[n] for n in pages]
assert len(qa)==47 and all('answer' in row for row in qa)

W,H=595.28,841.89;M=35;CW=W-2*M
INK=(.09,.17,.25);TEAL=(0,.40,.42);LIGHT=(.94,.97,.97);WHITE=(1,1,1)
F={};FB={}
for name,bold in [('body',False),('bold',True)]:
    FB[name]=Path(font_manager.findfont(font_manager.FontProperties(family='DejaVu Sans',weight='bold' if bold else 'normal'))).read_bytes()
    F[name]=pdf.Font(fontbuffer=FB[name])

doc=pdf.open();page=None;y=0
widths=[211,CW-211];size=9;leading=12
def wrap(s,width,font):
    out=[];line=''
    for word in s.split():
        trial=(line+' '+word).strip()
        if line and F[font].text_length(trial,fontsize=size)>width:out.append(line);line=word
        else:line=trial
    return out+[line]
def text(x,y,s,font='body',size=9,color=INK):
    page.insert_text((x,y),s,fontname=font,fontsize=size,color=color)
def newpage():
    global page,y
    page=doc.new_page(width=W,height=H)
    for name,data in FB.items():page.insert_font(fontname=name,fontbuffer=data)
    page.draw_rect(pdf.Rect(0,0,W,7),color=None,fill=TEAL)
    text(M,34,'PERGUNTAS E RESPOSTAS • CADERNO RESOLVIDO','bold',13,TEAL)
    text(W-M-12,H-21,str(len(doc)),size=8)
    y=51;x=M
    for head,width in zip(['Pergunta','Resposta'],widths):
        page.draw_rect(pdf.Rect(x,y,x+width,y+25),color=WHITE,fill=TEAL,width=.7)
        text(x+8,y+17,head,'bold',10,WHITE);x+=width
    y+=25

newpage()
for i,row in enumerate(qa):
    cells=[wrap(row['question'],widths[0]-16,'bold'),wrap(row['answer'],widths[1]-16,'body')]
    height=max(map(len,cells))*leading+14
    if y+height>H-37:newpage()
    x=M
    for ci,(lines,width) in enumerate(zip(cells,widths)):
        rect=pdf.Rect(x,y,x+width,y+height)
        page.draw_rect(rect,color=(.83,.89,.89),width=.55,fill=LIGHT if i%2==0 else WHITE)
        for j,line in enumerate(lines):text(x+8,y+15+j*leading,line,'bold' if ci==0 else 'body')
        x+=width
    y+=height

doc.set_metadata({'title':'Perguntas e respostas do Caderno Resolvido','subject':'Tabela com 47 perguntas e respostas por extenso, sem rótulos de classificação'})
doc.subset_fonts();doc.save(OUT,garbage=4,deflate=True)
check=pdf.open(OUT)
for p in check:
    for block in p.get_text('dict')['blocks']:
        if block['type']!=0:continue
        for line in block['lines']:
            for span in line['spans']:
                r=pdf.Rect(span['bbox']);assert 0<=r.x0<=r.x1<=W and 0<=r.y0<=r.y1<=H
textall='\n'.join(p.get_text() for p in check)
assert 'DEPENDE' not in textall
print(f'PDF: {OUT}\nPerguntas: {len(qa)}\nPaginas: {len(check)}')
