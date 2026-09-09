main.c:

Orquestra o programa:
- mostra menu;
- chama funções de leitura;
- chama metodos do grafo;
- controla o fluxo geral.

Grafo.h

Declara a classe Grafo:
- atributos;
- metodos;
- assinaturas das funções.

Grafo.c

Implementa a logica do grafo:
- adicionar aresta;
- mostrar matriz;
- DFS;
- BFS;
- componentes conexos;
- verificar se é conexo.

Leitura.h

Declara funções de entrada:
- ler quantidade de vértices;
- ler arestas;
- ler opção do menu;

Leitura.c

Implementa as funções que usam in e out para entrada.

----


implementos:

- Feito: escolha entre grafo direcionado e não direcionado
- Feito: leitura da quantidade de vértices
- Feito: leitura dos vértices
- Feito: inicialização da matriz de adjacência
- Feito: adicionar arestas para grafo não direcionado
- Feito: adicionar arestas para grafo direcionado
- Feito: imprimir matriz de adjacência
- Feito: imprimir lista de adjacência
- Fazer: calcular grau dos vértices em grafo não direcionado
- Fazer: calcular grau de entrada e grau de saída em grafo direcionado
- Fazer: verificar se existe ciclo no grafo não direcionado
- Fazer: verificar se existe ciclo no grafo direcionado
- Fazer: implementar BFS
- Fazer: implementar DFS
- Fazer: implementar verificação de conexidade
- Fazer: ajustar conexidade para grafo direcionado
- Fazer: achar raiz em grafo direcionado
- Fazer: achar base em grafo direcionado

---

Entrada:

Digite o numero de vértices:
5

Digite os vértices:
A B C D E

Digite as arestas:
A B
B C
D E
fim

---
Saida:

Lista de adjacência:
A -> B
B -> A, C
C -> B
D -> E
E -> D

Componentes conexos:
Componente 1: A, B, C
Componente 2: D, E

O grafo é conexo? Não

gcc main.c Leitura.c Grafo.c -o programa
