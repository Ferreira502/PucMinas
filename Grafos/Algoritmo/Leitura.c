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

void adicionarAresta(Grafo *grafo)
{
	printf("\nDigite os pares de arestas");
	printf("\nSe digitar 0 acaba de inserir arestas");
	printf("\n");

	char origem = ' ';
	char destino = ' ';
	
	scanf(" %c", &origem);

	while ( origem != '0' )
	{	
		scanf(" %c", &destino);

		int i = origem - 'A';
		int j = destino - 'A';
		
    		grafo->matriz[i][j] = 1;
    		grafo->matriz[j][i] = 1;
		scanf(" %c", &origem);
	}
}

void mostrarMatriz(Grafo *grafo)
{
	printf("\n Matriz de Adjacencia:\n\n");
	printf("  ");

	for ( int i = 0; i < grafo->qtdVertices; i++)
	{
		printf("%c ", 'A' + i);
	}

	printf("\n");

	for (int i = 0; i < grafo->qtdVertices; i++)
	{
		printf("%c ", 'A' + i);
		for ( int j = 0; j < grafo->qtdVertices; j++)
		{
			printf("%d ", grafo->matriz[i][j]);
		}

		printf("\n");
	}
}







