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
