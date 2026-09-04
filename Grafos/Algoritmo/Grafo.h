// Grafo.h
#ifndef GRAFO_H
#define GRAFO_H

class Grafo 
{
private:
    int matriz[100][100];
    int qtdVertices;

public:
    Grafo(int n);

    void adicionarAresta(int origem, int destino);
    void mostrarMatriz();
    void dfs(int inicio);
    void componentesConexos();
};

#endif