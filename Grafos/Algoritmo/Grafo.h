#ifndef GRAFO_H
#define GRAFO_H

#define MAX 100

typedef struct 
{
    int matriz[MAX][MAX];
    int qtdVertices;
} Grafo;

void inicializarGrafo(Grafo *grafo, int qtdVertices);
void bfs(Grafo *grafo);
void dfs(Grafo *grafo);
void componentesConexos(Grafo *grafo);
int grafoConexo(Grafo *grafo);
int calcularGrauSaida(Grafo *grafo, int vertice);
int calcularGrau(Grafo *grafo, int vertice);
int calcularGrauEntrada(Grafo *grafo, int vertice);

#endif
