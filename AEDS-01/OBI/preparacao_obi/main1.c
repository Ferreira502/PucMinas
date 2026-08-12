// 842527 - Gabriel Ferreira Pereira
// 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// ---

#define MAX 100

// ---

/*
  Função para ...
*/
int calcArray (int arr[], int n, int *soma  )
{
    int soma_1 = 0;
    if (n < 3)
    { 
        return -1;
    }
    
    
    for(int i = 0; i < n; i++)
    { 
        printf("\nDigite a posicao %d: ", i+1);
        scanf("%d",&arr[i]);
        if (i == 0 || i == n - 1)
        {
            soma_1 = soma_1;
        }
        else 
        {
            soma_1 = soma_1 + arr[i];
        }
    }

    *soma = soma_1;

    double quantidade = n - 2;
    
    if (quantidade == 0) 
    {
        return -1;
    }

    double media = (double) soma_1 / quantidade;
    int metade = n / 2;
    int cont = 0;
    
    for(int i = 1; i <= metade; i++)
    {
    
        if ( arr[i] < media)
           {
              cont ++;
               printf("%d", cont);
           }
    }

    if(cont == 0 ) 
    {
        return -1;
    }

    else 
    {
        return cont;
    }    
    
}
// ---

int main ( void )
{
    int n = 0, x = 0, soma = 0;
    int arr[MAX];

    printf("\nDigite o tamanho do array: ");
    scanf("%d", &n);

    int resultado = calcArray(arr, n, &soma);
    printf("%d %d %d\n",n, soma, resultado);
    
    printf ( "\n" );
    
    return ( 0 );
}
/*
    Testes - Comentarios - Observacoes
*/