#ifndef GRAFO_H
#define GRAFO_H

#define MAX 100

typedef struct 
{
    int matriz[MAX][MAX];
    int qtdVertices;
} Grafo;

void inicializarGrafo(Grafo *grafo, int qtdVertices);
void bfs(Grafo *grafo, int inicio);
void dfs(Grafo *grafo, int inicio);
void componentesConexos(Grafo *grafo);
int grafoConexo(Grafo *grafo);

#endif
