Questão 1

01) Viés algorítmico é quando um sistema de IA erra de forma sistemática contra certos grupos, não é um erro aleatório, é um padrão. Isso normalmente vem de dados de treinamento que não representam bem a população, como poucas fotos de pessoas negras, dados que já carregam desigualdades históricas, tipo registros de contratação com discriminação embutida.

02) No documentário, a própria Joy Buolamwini percebeu que os sistemas de reconhecimento facial não detectavam seu rosto, só funcionou quando ela colocou uma máscara branca. Isso motivou o projeto Gender Shades, que mostrou erro de mais de 30% para mulheres negras contra quase 0% para homens brancos. Ou seja, os bancos de dados usados no treinamento eram bem desbalanceados.

03) Duas estratégias: uma técnica, que seria analisar o desempenho do sistema por grupo, e não só a média geral, e usar isso para deixar os dados mais equilibrados. E outra seria exigir uma avaliação independente antes de usar esses sistemas em áreas mais delicadas, mostrando os erros de cada grupo.

Questão 2

01) Origem, 1956, Conferência de Dartmouth: aconteceu no Dartmouth College, no verão de 1956, durou umas 6 a 8 semanas. Foi organizado por McCarthy, Minsky, Rochester e Shannon. A ideia central era, que qualquer aspecto da inteligência poderia, em tese, ser descrito com precisão suficiente pra uma máquina simular. Achavam que dava pra resolver isso num único verão.

02) 50 anos depois, em 2006, teve uma reunião comemorativa no mesmo lugar, com apoio da DARPA. Cinco dos participantes originais voltaram. A ideia era ver o que tinha dado certo ou não. Hinton falou sobre modelos gráficos, que já apontavam para o crescimento do deep learning. Norvig falou sobre buscas na internet, e Kurzweil apostou que o teste de Turing seria superado em uns 25 anos.

03) Pra mim, a maior diferença é que em 1956 eles apostavam mais na lógica e em regras que seriam programadas para criar a inteligência. Já em 2006, ficou mais claro que o que realmente estava dando certo era o aprendizado com muitos dados e poder computacional. No fim, o avanço foi bem mais lento e aconteceu mais pelo aprendizado dos dados do que eles imaginavam.

Questão 3

a) Sim, é alto risco. O PL coloca sistemas de seleção e triagem de candidatos nessa categoria, no art. 17, III. E como aqui tem eliminação automática sem revisão humana, isso deixa o caso ainda mais claro.

b) Não. O PL considera isso uma forma de discriminação indireta, no art. 4º, VII. Mesmo sem usar raça ou gênero diretamente, coisas como região e faculdade podem acabar servindo como uma espécie de “atalho” para essas características, porque o modelo aprende padrões dos próprios dados. Então, dizer que o sistema é neutro não é suficiente.

c) Eu colocaria três coisas: uma análise do impacto do algoritmo, olhando também se os dados usados no treino têm algum viés. Revisão humana antes de eliminar alguém, em vez de deixar tudo automático. E uma documentação clara de como o modelo toma as decisões, para facilitar uma auditoria depois.

d) Sim, com certeza. O PL garante isso: a pessoa tem direito de receber uma explicação em até 15 dias, no art. 8º, pode contestar a decisão, no art. 9º, e também pode pedir revisão humana quando a decisão envolve algo importante, como um emprego, no art. 10.

e) Eu faria uma análise de fairness por grupo, comparando, por exemplo, quantas pessoas de cada região ou faculdade são eliminadas. Também dá para analisar as taxas de erro e usar um teste estatístico, como o disparate impact ou a regra dos 80%, para ver se existe uma diferença relevante entre os grupos.