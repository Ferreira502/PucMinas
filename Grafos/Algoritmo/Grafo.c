#include <stdio.h>
#include "Grafo.h"
#include "Leitura.h"


void inicializarGrafo(Grafo *grafo, int n)
{
	grafo->qtdVertices = n;
	for ( int i = 0; i < n; i++)
	{
		for ( int j = 0; j < n; j++ )
		{
			grafo->matriz[i][j] = 0;
		}
	}
}

void adicionarArestaNDirecionado(Grafo *grafo)
{
	printf("\nDigite os pares de arestas\n");
	printf("\nSe digitar 0 acaba de inserir arestas\n");

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

void adicionarArestaDirecionado(Grafo *grafo)
{
	printf("\nDigite os pares de arestas direcionadas\n");
	printf("\nExemplo: A B significa A -> B\n");
	printf("\nSe digitar 0 acaba de inserir arestas\n");

	char origem = ' ';
	char destino = ' ';

	scanf(" %c", &origem);

	while (origem != '0')
	{
		scanf(" %c", &destino);

		int i = origem - 'A';
		int j = destino - 'A';

		grafo->matriz[i][j] = 1;

		scanf(" %c", &origem);
	}
}


int calcularGrau(Grafo *grafo, int vertice)
{
 	int grau = 0;
 	
	for ( int i = 0; i < grafo->qtdVertices; i++ )
 	{
		if ( grafo -> matriz[vertice][i] == 1 )
		{
			grau++;
		}
 	}

	return grau;
}

int calcularGrauSaida(Grafo *grafo, int vertice)
{
	int grau = 0;
	for ( int i = 0; i < grafo->qtdVertices; i++ )
	{
		if ( grafo->matriz[vertice][i] == 1 )
		{
			grau++;
		}
	}

	return grau;
}

int calcularGrauEntrada(Grafo *grafo, int vertice)
{
	int grau = 0;
	for ( int i = 0; i < grafo->qtdVertices; i++ )
	{
		if ( grafo->matriz[i][vertice] == 1 )
		{
			grau++;
		}
	}

	return grau;
}


void dfs(Grafo *grafo)
{
	int visitado[MAX] = {0};
	int pilha[MAX];
	int numeroComponente = 0;

	printf("\nDfs");

	for ( int i = 0; i < grafo->qtdVertices; i++ )
	{
		if ( visitado[inicio] == 0 )
		{
			int topo = -1;
			
		}
	}
}