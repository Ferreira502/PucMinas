#ifndef LEITURA_H
#define LEITURA_H
#include "Grafo.h"

int lerQuantidadeVertices();
void lerVertices(char vertices[], int n);
void telaOpcoes();
void adicionarAresta(Grafo *grafo);
void mostrarListaNDirecionado(Grafo *grafo);
void mostrarMatrizNDirecionado(Grafo *grafo);
int escolherGrafo();

#endif
