#include <stdio.h>
#include "Grafo.h"
#include "Leitura.h"

void telaOpcoes()
{
	printf("\nAlgoritmo para treinar Grafos\n");
	printf("\n");
	printf("\nDigite ENTER para continuar\n");
}

int escolherGrafo()
{
	int x = 0;
	printf("\nDigite 1 para grafo direcionado e 0 para NAO direcionado\n");
	scanf("%d", &x);

	return x;
}

int lerQuantidadeVertices()
{
	int x = 0;
	char c = ' ';
	printf("\nDigite o numero de vertices:\n");
	scanf("%d", &x);

	return x;	
}

void lerVertices(char vertices[], int n)
{
	printf("\nDigite os vertices em maiusculo:\n");

    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &vertices[i]);
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

void mostrarLista(Grafo *grafo)
{
    for ( int i = 0; i < grafo->qtdVertices; i++ )
    {
        printf("%c -> ", 'A' + i);

        int primeiraAresta = 1;

        for (int j = 0; j < grafo->qtdVertices; j++)
        {
            if (grafo->matriz[i][j] == 1)
            {
                if (!primeiraAresta)
                {
                    printf(", ");
                }

                printf("%c", 'A' + j);
                primeiraAresta = 0;
            }
        }

        printf("\n");
    }
}
