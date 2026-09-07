#include <stdio.h>
#include "Grafo.h"
#include "Leitura.h"

int main()
{
    Grafo grafo;

    telaOpcoes();
    getchar();

    int n = lerQuantidadeVertices();

    inicializarGrafo(&grafo, n);

    char vertices[n];
    lerVertices(vertices, n);

    printf("\nVertices Digitados:\n");
    
    int x = 0;
    while ( x != n )
    {
	printf("%c", vertices[x]);
    	x++;
    }

    adicionarAresta(&grafo);
    
   
    printf("Mostrar Matriz");
    getchar();
    mostrarMatriz(&grafo);

    return 0;
}
