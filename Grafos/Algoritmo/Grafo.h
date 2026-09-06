#ifndef GRAFO_H
#define GRAFO_H

#define MAX 100

typedef struct 
{
    int matriz[MAX][MAX];
    int qtdVertices;
} Grafo;

void inicializarGrafo(Grafo *grafo, int qtdVertices);
void adicionarAresta(Grafo *grafo, int origem, int destino);
void mostrarMatriz(const Grafo *grafo);
void bfs(const Grafo *grafo, int inicio);
void dfs(const Grafo *grafo, int inicio);
void componentesConexos(const Grafo *grafo);
int grafoConexo(const Grafo *grafo);

#endif
