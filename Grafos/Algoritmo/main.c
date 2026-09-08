#include <stdio.h>
#include "Grafo.h"
#include "Leitura.h"

int main()
{
    Grafo grafo;

    telaOpcoes();
    getchar();

    int x =  escolherGrafo();

    if ( x == 0 )
    {
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
        
    
        printf("Mostrar Matriz\n");
        getchar();
        mostrarMatrizNDirecionado(&grafo);


        printf("\nMostrar Lista de adjacencia");
        getchar();
        mostrarListaNDirecionado(&grafo);
    }
    else if( x == 1 )
    {
        printf("\nTo implementando ainda paizin\n");
    }

    return 0;
}
