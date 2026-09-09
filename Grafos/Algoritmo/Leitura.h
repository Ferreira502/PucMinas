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
void mostrarGrauNDirecionado(Grafo *grafo);
void mostrarGrauDirecionado(Grafo *grafo);
int calcularGrauSaida(Grafo *grafo, int vertice);
int calcularGrauEntrada(Grafo *grafo, int vertice);
void mostrarGrauDirecionado(Grafo *grafo);
void mostrarGrauNDirecionado(Grafo *grafo);

int escolherGrafo();

#endif
