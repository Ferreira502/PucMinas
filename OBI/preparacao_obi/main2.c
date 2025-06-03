// 842527 - Gabriel Ferreira Pereira
// 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// ---

#define MAX 10

// ---

/*
  Função para ...
*/

// ---

bool calMatrix (int matrix[MAX][MAX], int linhas, int colunas)
{
    bool resposta = false;
    int soma_1 = 0, soma_2 = 0;

    for (int i = 0; i < linhas; i++)
    {
        for (size_t j = 0; j < colunas; j++)
        {
            if (i < j) //triangulo superior
            {
                soma_1 = soma_1 + i; 
            }
            else if ( i > j)  //triangulo inferior
            {
                soma_2 = soma_2 + j;
            }
            
        }
        
    }

    if (soma_1 > soma_2)
    {
        resposta = true;
    }
    else {
        resposta = false;
    }
    
    return resposta;
}

int main ( void )
{
    int linhas = 0, colunas = 0, i = 0, j = 0;
    int matrix[MAX][MAX];

    printf("\nDigite o tamanho das linhas: ");
    scanf("%d", &linhas);
    printf("\nDigite o tamanho das colunas: ");
    scanf("%d", &colunas);

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("\nDigite o valor da posicao [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
        
    }

     printf("%d %d\n", linhas, colunas);
     for (int i = 0; i < linhas; i++) 
     {
        for (int j = 0; j < colunas; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\t\n");
    }
    
    bool soma = calMatrix(matrix, linhas, colunas);

    if (soma = false)
    {
        printf("\n1");
    }
    else 
    {
        printf("\n0");
    }
    
    
    printf ( "\n" );
    
    return ( 0 );
}

/*
    Testes - Comentarios - Observacoes
*/