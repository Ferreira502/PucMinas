/*
 R02 - v0.0. - 09 / 06 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : g++ -o R02 R02.cpp
 Windows: g++ -o R02 R02.cpp

 Para executar em terminal (janela de comandos):
 Linux : ./R02
 Windows: R02
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "myarray.h"

#define MAX 100


// -------------------------- definicao de metodos

// --------------- METODO01-----------------
void metodo01() 
{
    printf("\n\tMetodo01\n");

    Array arr;
    freadArray(&arr, "DADOS1.TXT");

    printf("\nArranjo original:\n");
    printArray(&arr);

    sort(&arr);

    printf("\nArranjo em ordem decrescente:\n");
    printArray(&arr);

    FILE* arquivo = fopen("CRESCENTE.TXT", "w");

    if (arquivo != NULL) 
    {
        fprintf(arquivo, "%d\n", arr.length);
        for (int i = 0; i < arr.length; i++) 
        {
            fprintf(arquivo, "%d\n", arr.data[i]);
        }
        fclose(arquivo);
        printf("Dados gravados com sucesso\n");
    } 
    else 
    {
        printf("Nao foi possivel abrir o arquivo\n");
    }

    getchar();
    printf("\nApertar ENTER para continuar.\n");
    getchar();

    freeArray(&arr);
}

// --------------- METODO02-----------------
void metodo02() 
{
    printf("\n\tmetodo02\n");

    Array arr;
    freadArray(&arr, "CRESCENTE.TXT");

    printf("\nArranjo original:\n");
    printArray(&arr);

    inverterArray(&arr);

    printf("\nArranjo invertido:\n");
    printArray(&arr);

    FILE* arquivo = fopen("INVERTIDOS.TXT", "w");

    if (arquivo != NULL) 
    {
        fprintf(arquivo, "%d\n", arr.length);
        for (int i = 0; i < arr.length; i++) 
        {
            fprintf(arquivo, "%d\n", arr.data[i]);
        }
        fclose(arquivo);
        printf("Dados invertidos gravados com sucesso no arquivo INVERTIDOS.TXT\n");
    } 
    else 
    {
        printf("Nao foi possivel abrir o arquivo INVERTIDOS.TXT\n");
    }

    freeArray(&arr);
    getchar();
    printf("\nApertar ENTER para continuar.\n");
    getchar();
}


// --------------- METODO03-----------------

// Função para achar a mediana personalizada
double arranjo_mediana(Array* arr, int tamanho) 
{
    if (tamanho <= 0) return 0;

    
    double soma = 0.0;
    for (int i = 0; i < tamanho; i++) 
    {
        soma += arr->data[i];
    }
    double media = soma / tamanho;

    double menor_diferenca = fabs(arr->data[0] - media);
    int mais_proximo1 = arr->data[0];
    int mais_proximo2 = arr->data[0];
    int empate = 0;

    for (int i = 1; i < tamanho; i++) 
    {
        double diferenca = fabs(arr->data[i] - media);
        if (diferenca < menor_diferenca) 
        {
            menor_diferenca = diferenca;
            mais_proximo1 = arr->data[i];
            empate = 0;
        } else if (diferenca == menor_diferenca && arr->data[i] != mais_proximo1) 
        {
            mais_proximo2 = arr->data[i];
            empate = 1;
        }
    }

    if (empate) 
    {
        return (mais_proximo1 + mais_proximo2) / 2.0;
    } else 
    {
        return (double)mais_proximo1;
    }
}


int arranjo_moda(Array* arr) 
{
    if (arr->length == 0) return 0;

    typedef struct {
        int valor;
        int frequencia;
    } Freq;

    Freq* freqArray = malloc(sizeof(Freq) * arr->length);
    int freqCount = 0;

    for (int i = 0; i < arr->length; i++) 
    {
        int val = arr->data[i];
        int j;
        for (j = 0; j < freqCount; j++) 
        {
            if (freqArray[j].valor == val) 
            {
                freqArray[j].frequencia++;
                break;
            }
        }
        if (j == freqCount)
         {
            freqArray[freqCount].valor = val;
            freqArray[freqCount].frequencia = 1;
            freqCount++;
        }
    }

    int moda_valor = freqArray[0].valor;
    int maior_frequencia = freqArray[0].frequencia;

    for (int i = 1; i < freqCount; i++) 
    {
        if (freqArray[i].frequencia > maior_frequencia) 
        {
            maior_frequencia = freqArray[i].frequencia;
            moda_valor = freqArray[i].valor;
        }
    }

    return moda_valor;
}


void metodo03() 
{
    printf("\n\tmetodo03\n");
    Array arr;
    int tamanho = 0;

    freadArray(&arr, "DADOS1.TXT");
    tamanho = arranjo_tamanho(&arr);

    printf("Arranjo:\n");
    printArray(&arr);

    double mediana = arranjo_mediana(&arr, tamanho);
    printf("\nMediana personalizada: %.2lf\n", mediana);

    int moda = arranjo_moda(&arr);
    printf("Moda: %d\n", moda);

    printf("\nApertar ENTER para continuar.\n");
    getchar();
}


// --------------- METODO04-----------------
void metodo04() 
{
    printf("\n\tmetodo04\n");

    Array arranjo1;
    Array arranjo2;
    Array arranjo3;

    freadArray(&arranjo1, "DADOS1.TXT");
    freadArray(&arranjo2, "DADOS2.TXT");

    arranjo3.data = (int*) malloc(MAX * sizeof(int));
    arranjo3.length = 0;
    arranjo3.optional = 0;

    printf("\nArranjo 1:\n");
    printArray(&arranjo1);

    printf("\nArranjo 2:\n");
    printArray(&arranjo2);

    arranjo_filtrar(&arranjo3, &arranjo1, &arranjo2);

    printf("\nElementos comuns sem repeticao:\n");
    printArray(&arranjo3);

    fprintArray(&arranjo3, "FILTRADOS.TXT");

    printf("\nApertar ENTER para continuar.\n");
    getchar();
}

// --------------- METODO05-----------------
void metodo05() 
{
    printf("\n\tmetodo05\n");
    printf("\nApertar ENTER para continuar.\n");
    getchar();
}

// --------------- METODO06-----------------
void metodo06() 
{
    printf("\n\tmetodo06\n");
    printf("\nApertar ENTER para continuar.\n");
    getchar();
}

// --------------- METODO07-----------------
void metodo07() 
{
    printf("\n\tmetodo07\n");
    printf("\nApertar ENTER para continuar.\n");
    getchar();
}

// --------------- METODO08-----------------
void metodo08() 
{
    printf("\n\tmetodo08\n");
    printf("\nApertar ENTER para continuar.\n");
    getchar();
}

// --------------- METODO09-----------------
void metodo09() 
{
    printf("\n\tmetodo09\n");
    printf("\nApertar ENTER para continuar.\n");
    getchar();
}

// --------------- METODO10-----------------
void metodo10() 
{
    printf("\n\tmetodo10\n");
    printf("\nApertar ENTER para continuar.\n");
    getchar();
}

// identificar
 void menuOpcoes ( void ) 
 {
   printf ( "\n" );             // para saltar linha
   printf ( "%s\n", "R02 - v.0.0 - 09/06/2025"       );
   printf ( "%s\n", "Matricula: 842527 Nome: Gabriel Ferreira Pereira" );

// mostrar opcoes
   printf ( "%s\n", "Opcoes:   "     );
   printf ( "%s\n", " 0 - parar"     );
   printf ( "%s\n", " 1 - metodo 01" );
   printf ( "%s\n", " 2 - metodo 02" );
   printf ( "%s\n", " 3 - metodo 03" );
   printf ( "%s\n", " 4 - metodo 04" );
   printf ( "%s\n", " 5 - metodo 05" );
   printf ( "%s\n", " 6 - metodo 06" );
   printf ( "%s\n", " 7 - metodo 07" );
   printf ( "%s\n", " 8 - metodo 08" );
   printf ( "%s\n", " 9 - metodo 09" );
   printf ( "%s\n", " 10- metodo 10" );
   printf ( "%s\n", "" );        // para saltar linha
 }


// -------------------------- definicao do metodo principal

 int main ( void )
 {
 // definir dados/resultados
    int opcao = 0;

 // repetir ate' desejar parar
    do
    {
      menuOpcoes();
     // ler opcao
        printf ( "%s", "Qual a sua opcao? " );
        scanf  ( "%d", &opcao ); getchar ( );
        printf ( "%d",  opcao );

     // escolher acao
        switch ( opcao )
        {
           case  0:               
                break;
           case  1: metodo01 ( ); 
                break;
           case  2: metodo02 ( ); 
                break;
           case  3: metodo03 ( );
                break;
           case  4: metodo04 ( ); 
                break;
           case  5: metodo05 ( ); 
                break;
           case  6: metodo06 ( ); 
                break;
           case  7: metodo07 ( ); 
                break;
           case  8: metodo08 ( ); 
                break;
           case  9: metodo09 ( ); 
                break;
           case 10: metodo10 ( ); 
                break;
           default: printf ( "\n%s\n\n", "ERRO: Opcao invalida." );
                break;
        } // fim escolher
    }
    while ( opcao != 0 );

 // encerrar execucao
    printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
    getchar( );

    return 0;
 } // end main ( )


/*
----------------------------- documentacao complementar

----------------------------- notas / observacoes / comentarios

----------------------------- previsao de testes

----------------------------- historico

Versao	Data		      Modificacao
  0.1	__/__		      esboco

 ---------------------------- testes

Versao	Teste
  0.1	01. ( OK )	      identificacao de programa

*/