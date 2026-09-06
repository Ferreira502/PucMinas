#include <stdio.h>
#include "Grafo.h"
#include "Leitura.h"

void telaOpcoes()
{
	printf("\nAlgoritmo para treinar Grafos\n");
	printf("\n");
	printf("\nDigite ENTER para continuar");
}

int lerQuantidadeVertices()
{
	int x = 0;
	char c = ' ';
	printf("\n");
	printf("Digite o numero de vertices:\n");
	scanf("%d", &x);

	return x;	
}

void lerVertices(char vertices[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &vertices[i]);
    }
}

/*
void adicionarAresta(Grafo *grafo, int origem, int destino)
{
    grafo->matriz[origem][destino] = 1;
    grafo->matriz[destino][origem] = 1;
}

*/
