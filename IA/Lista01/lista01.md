Questão 1

Viés algorítmico é quando um sistema de IA erra de forma sistemática contra certos grupos, não é um erro aleatório, é um padrão. Isso normalmente vem de dados de treinamento que não representam bem a população, como poucas fotos de pessoas negras, dados que já carregam desigualdades históricas, tipo registros de contratação com discriminação embutida.
No documentário, a própria Joy Buolamwini percebeu que os sistemas de reconhecimento facial não detectavam seu rosto, só funcionou quando ela colocou uma máscara branca. Isso motivou o projeto Gender Shades, que mostrou erro de mais de 30% para mulheres negras contra quase 0% para homens brancos. Ou seja, os bancos de dados usados no treinamento eram bem desbalanceados.
Duas saídas: uma técnica, fazer auditorias de desempenho separadas por subgrupo, não só olhar a acurácia geral, e usar isso pra reamostrar e balancear os dados. E uma regulatória, exigir auditoria independente antes de liberar esses sistemas em áreas sensíveis, como contratação, policiamento e crédito, com transparência sobre erro por grupo.

Questão 2

Origem, 1956, Conferência de Dartmouth: aconteceu no Dartmouth College, no verão de 1956, durou umas 6 a 8 semanas. Foi organizado por McCarthy, Minsky, Rochester e Shannon. A ideia central era ousada: que qualquer aspecto da inteligência poderia, em tese, ser descrito com precisão suficiente pra uma máquina simular. Achavam que dava pra resolver isso num único verão.

50 anos depois, 2006, reunião comemorativa: reencontro no mesmo lugar, 50 anos depois, com apoio da DARPA. Cinco dos participantes originais voltaram. O foco foi ver o que tinha dado certo ou não, e surgiram falas importantes. Hinton falou de modelos gráficos, já anunciando o boom do deep learning. Norvig falou sobre busca na web. Kurzweil apostou que o teste de Turing cairia em uns 25 anos.

Pra mim a maior diferença é que em 1956 a aposta era toda em lógica simbólica e regras explícitas, achavam que dava pra programar a inteligência. Em 2006 ficou claro que quem realmente avançou foi o aprendizado estatístico, com muito dado e poder computacional, não a lógica pura que os fundadores imaginavam. O caminho foi bem mais lento e mais aprendido pelos dados do que eles previam.

Questão 3

a) Sim, é alto risco. O PL enquadra explicitamente sistemas de triagem e seleção de candidatos nessa categoria, art. 17, III, e aqui tem eliminação automática sem revisão humana, o que reforça ainda mais esse enquadramento.

b) Não. O PL trata isso como discriminação indireta, art. 4º, VII: mesmo sem usar raça ou gênero diretamente, variáveis como região e faculdade podem funcionar como proxy dessas características, porque o modelo aprende correlações que já existiam nos dados. Neutralidade técnica não é defesa suficiente.

c) Três coisas que eu incluiria: avaliação de impacto algorítmico com auditoria dos dados de treino, pra ver se região e instituição estão enviesadas. Revisão humana obrigatória antes de eliminar alguém, em vez de corte automático. E documentação clara de como o modelo decide, pra ser possível auditar depois.

d) Sim, com certeza. O PL garante isso: direito a explicação em até 15 dias, art. 8º, direito de contestar a decisão, art. 9º, e direito a revisão humana quando a decisão afeta algo importante, como emprego, art. 10.

e) Eu usaria uma análise de fairness por subgrupo, comparando a taxa de eliminação entre grupos, demographic parity, ou as taxas de erro, equalized odds, segmentando por região e instituição como proxy, e rodando um teste estatístico, tipo disparate impact ou regra dos 80%, pra ver se a diferença é significativa mesmo sem a variável sensível estar explícita no modelo.