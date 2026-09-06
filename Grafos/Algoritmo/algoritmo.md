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

1. Adicionar vértice
2. Adicionar aresta
3. Mostrar lista de adjacência
4. Verificar se dois vértices são adjacentes
5. Mostrar grau de cada vértice
6. Fazer BFS a partir de um vértice
7. Fazer DFS a partir de um vértice
8. Encontrar componentes conexos
9. Verificar se o grafo é conexo
10. Sair

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
