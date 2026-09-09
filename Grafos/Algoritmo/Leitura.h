#ifndef LEITURA_H
#define LEITURA_H
#include "Grafo.h"

int lerQuantidadeVertices();
void lerVertices(char vertices[], int n);
void telaOpcoes();
void adicionarArestaNDirecionado(Grafo *grafo);
void adicionarArestaDirecionado(Grafo *grafo);
void mostrarLista(Grafo *grafo);
void mostrarMatriz(Grafo *grafo);
int escolherGrafo();

#endif
