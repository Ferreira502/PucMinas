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
        // Grafo nao direcionado
        printf("\nVoce Selecionou Grafo NAO Direcionado\n");
        printf("\nDigite ENTER para continuar\n");
        getchar();
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

        adicionarArestaNDirecionado(&grafo);
        
    
        printf("\nMostrar Matriz\n");
        getchar();
        mostrarMatriz(&grafo);


        printf("\nMostrar Lista de adjacencia\n");
        getchar();
        mostrarLista(&grafo);
    }
    else if( x == 1 )
    {
        // Grafo direcionado

        printf("\nVoce Selecionou Grafo Direcionado\n");
        printf("\nDigite ENTER para continuar\n");
        getchar();
        getchar();
        
        int n = lerQuantidadeVertices();

        inicializarGrafo(&grafo, n);

        char vertices[n];
        lerVertices(vertices, n);

        printf("\nVertices Digitados:\n");
        
        int i = 0;
        while ( i != n )
        {
            printf("%c", vertices[i]);
            i++;
        }

        adicionarArestaDirecionado(&grafo);
        printf("\nMostrar Matriz\n");
        getchar();
        mostrarMatriz(&grafo);

        printf("\nMostrar Lista de adjacencia\n");
        getchar();
        mostrarLista(&grafo);
    }

    else if ( x != 1 && x != 0)
    {
        printf("\nTu nao selecionou nada parabens\n");
    }

    return 0;
}
