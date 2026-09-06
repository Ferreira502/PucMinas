#include <stdio.h>
#include "Grafo.h"
#include "Leitura.h"

int main()
{
    Grafo grafo;

    telaOpcoes();
    getchar();
    int n = lerQuantidadeVertices();

    char vertices[n];
    lerVertices(vertices, n);

    printf("\nVertices Digitados:\n");
    
    int x = 0;
    while ( x != n )
    {
	printf("%c", vertices[x]);
    	x++;
    }

    // inicializarGrafo(&grafo, n);
    // lerArestas(&grafo);
    // mostrarMatriz(&grafo);

    return 0;
}
