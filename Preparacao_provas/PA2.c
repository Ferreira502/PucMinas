/*
 Exercicio_Preparacao - v0.0. - 26 / 05 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exercicio_preparacao exercicio_preparacao.c
 Windows: gcc -o exercicio_preparacao exercicio_preparacao.c
 Para executar em terminal (janela de comandos):
 Linux : ./exercicio_preparacao
 Windows: exercicio_preparacao
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX 100

// -------------------------- definicao de classe

/**
  * method01.
  */

typedef struct {
    int x;
    int y;
} Ponto;


void method_01( void ) 
{
// Identificar
   printf("\n%s\n", "\n\tmethod_01");
   FILE *entrada = fopen("DADOS_1.txt", "r");
   FILE *saida = fopen("SAIDA_1.txt", "w");

   if (entrada == NULL || saida == NULL) {
       printf("Erro ao abrir arquivo.\n");
       return;
   }

   Ponto atual, anterior;
   int primeiro = 1;
   while (fscanf(entrada, "%d %d", &atual.x, &atual.y) == 2)
       {
   
       if (atual.x == 0 && atual.y == 0)
           break;

       if (primeiro) {
           anterior = atual;
           primeiro = 0;
       } else {
           double distancia = sqrt(pow((double)(atual.x - anterior.x), 2.0) +
                                    pow((double)(atual.y - anterior.y), 2.0));
           fprintf(saida, "%.4lf\n", distancia);
           anterior = atual;
           printf("\nDados guardados no arquivo");
           getchar();
       }
   }

   fclose(entrada);
   fclose(saida);
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim method01 ( )

/**
  * method02.
  */

double maiorDistancia ( double arr[], int n )
{
    double maior = arr[0];
    for (int i = 1; i < n; i++)
        {
            if ( arr[i] > maior)
            {
                maior = arr[i];
            }
        }
    return maior;

}

double menorDistancia ( double arr [], int n )
{
    double menor = arr[0];
    for (int i = 1; i < n; i++)
        {
            if (arr[i] < menor)
            {
                menor = arr[i];
            }
        }
    return menor;
}

void method_02 ( void )
  {
  // Identificar
    printf("\n%s\n", "\n\tmethod_02");
    FILE *saida = fopen("SAIDA_1.txt", "r");

    double distancia[MAX];
    int total = 0;
      
    if (saida == NULL) 
    {
        printf("Erro ao abrir o arquivo SAIDA_1.TXT\n");
    } 

    

    while (fscanf(saida, "%lf", &distancia[total]) == 1 && total < MAX) {
        total++;
    }

    fclose(saida);

    if (total == 0) {
        printf("\nNenhuma distancia encontrada no arquivo");
        return;
    }

    double maior = maiorDistancia(distancia, total);
    double menor = menorDistancia(distancia, total);

    printf("Maior distancia: %.4lf\n", maior);
    printf("Menor distancia: %.4lf\n", menor);  
  // Encerrar
     printf("\n%s\n", "Apertar ENTER para continuar.");
     getchar();
  } // fim method02 ( )  
/**
  * method03.
  */
double mediaSemExtremos(double arr[], int n) {
    if (n < 3) return -1.0;

    double maior = maiorDistancia(arr, n);
    double menor = menorDistancia(arr, n);
    double soma = 0.0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != maior && arr[i] != menor) {
            soma += arr[i];
            count++;
        }
    }

    if (count == 0) return -1.0;

    return soma / count;
}

void method_03 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tmethod_03");
   FILE *arquivo = fopen("SAIDA_1.TXT", "r");
   if (arquivo == NULL) {
       printf("Erro ao abrir o arquivo SAIDA_1.TXT\n");
       return;
   }

   double distancias[MAX];
   int total = 0;

   while (fscanf(arquivo, "%lf", &distancias[total]) == 1 && total < MAX) {
       total++;
   }

   fclose(arquivo);

   if (total < 3) {
       printf("\nNao ha distancias suficientes para calcular a media sem extremos");
       return;
   }

   double media = mediaSemExtremos(distancias, total);
   
   if (media == -1.0) {
       printf("\nNao foi possivel calcular a media");
   } else {
       printf("\nMedia das distancias: %.4lf", media);
   }

// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim method03 ( )

/**
  * method04.
  */

void trocarLinhas(double matriz[MAX][2], int i, int j) 
{
    double temp0 = matriz[i][0];
    double temp1 = matriz[i][1];

    matriz[i][0] = matriz[j][0];
    matriz[i][1] = matriz[j][1];

    matriz[j][0] = temp0;
    matriz[j][1] = temp1;
}

void method_04 ( void )
{
  // Identificar
    printf("\n%s\n", "\n\tmethod_04");
    FILE *arquivo = fopen("DADOS_1.TXT", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo DADOS_1.TXT\n");
        return;
    }

    double matriz[MAX][2];
    int total = 0;
    double x = 1.0, y = 1.0;

    while (fscanf(arquivo, "%lf %lf", &x, &y) == 2 && total < MAX) {
        if (!(x == 0.0 && y == 0.0)) {
            matriz[total][0] = x;
            matriz[total][1] = y;
            total++;
        }
    }

    fclose(arquivo);

    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            int trocar = 0;

            if (matriz[j][0] > matriz[j + 1][0]) {
                trocar = 1;
            } else if (matriz[j][0] == matriz[j + 1][0] && matriz[j][1] > matriz[j + 1][1]) {
                trocar = 1;
            }

            if (trocar) {
                trocarLinhas(matriz, j, j + 1);
            }
        }
    }

    printf("Pares ordenados:\n");
    for (int i = 0; i < total; i++) {
        printf("(%.1lf, %.1lf)\n", matriz[i][0], matriz[i][1]);
    }
 // Encerrar
    printf("\n%s\n", "Apertar ENTER para continuar.");
    getchar();
 } // fim method04 ( )

/**
  * method05.
  */

double calcularDistanciaEntreExtremos(double matriz[][2], int linhas, int colunas) 
{
    double x1 = matriz[0][0];
    double y1 = matriz[0][1];
    double x2 = matriz[linhas - 1][0];
    double y2 = matriz[linhas - 1][1];

    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void method_05 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tmethod_5");
   FILE *arquivo = fopen("DADOS_1.TXT", "r");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo");
        return;
    }

    double matriz[MAX][2];
    int linhas = 0;

    while (fscanf(arquivo, "%lf %lf", &matriz[linhas][0], &matriz[linhas][1]) == 2 &&
           !(matriz[linhas][0] == 0 && matriz[linhas][1] == 0) &&
           linhas < MAX) {
        linhas++;
    }

    fclose(arquivo);

    for (int i = 0; i < linhas - 1; i++) {
        for (int j = 0; j < linhas - i - 1; j++) {
            if (matriz[j][0] > matriz[j + 1][0] ||
               (matriz[j][0] == matriz[j + 1][0] && matriz[j][1] > matriz[j + 1][1])) {
                // Trocar linhas
                double temp0 = matriz[j][0];
                double temp1 = matriz[j][1];
                matriz[j][0] = matriz[j + 1][0];
                matriz[j][1] = matriz[j + 1][1];
                matriz[j + 1][0] = temp0;
                matriz[j + 1][1] = temp1;
            }
        }
    }

    if (linhas > 1) {
        double distancia = calcularDistanciaEntreExtremos(matriz, linhas, 2);
        printf("\nDistancia entre o primeiro e o ultimo par ordenado: %.4lf", distancia);
    } else {
        printf("\nNao ha pares suficientes para calcular a distancia");
    }

// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim method05 ( )

/* 
  Funcao principal. 
  @return codigo de encerramento 
  @param argc - quantidade de parametros na linha de comandos 
  @param argv - arranjo com o grupo de parametros na linha de comandos 
*/ 
int main ( ) 
{ 
 // definir dado 
    int opcao = 0;
 
 // identificar 
    printf ( "%s\n", "Exercicio_Preparacao_2 - Programa = v0.0" ); 
    printf ( "%s\n", "Autor: Gabriel Ferreira Pereira" ); 
    printf ( "\n" ); // mudar de linha 
 
 // acoes 
 
 // repetir 
    do 
    { 
     // para mostrar opcoes 
        printf ( "\n%s\n", "Opcoes:"          ); 
        printf ( "\n%s"   , "0 - Terminar"    ); 
        printf ( "\n%s"   , "1 - Method_01" ); 
        printf ( "\n%s"   , "2 - Method_02" ); 
        printf ( "\n%s"   , "3 - Method_03" ); 
        printf ( "\n%s"   , "4 - Method_04" ); 
        printf ( "\n%s"   , "5 - Method_05" ); 
        printf ( "\n" ); 
 
     // ler a opcao do teclado 
        printf  ( "\n%s", "Opcao = " ); 
        scanf  ( "%d", &opcao ); 
        getchar( );  // para limpar a entrada de dados 
 
     // para mostrar a opcao lida 
        printf  ( "\n%s%d", "Opcao = ", opcao ); 
    // escolher acao dependente da opcao 
        switch ( opcao ) 
        { 
          case   0:  /* nao fazer nada */    break; 
          case   1:     method_01 ( );         break; 
          case   2:     method_02 ( );         break; 
          case   3:     method_03 ( );         break; 
          case   4:     method_04 ( );         break; 
          case   5:     method_05 ( );         break; 
          default: // comportamento padrao 
                           printf ( "\nERRO: Opcao invalida.\n" ); 
                           break; 
        } // end switch 
    } 
    while ( opcao != 0 ); 
 
 // encerrar 
    printf    ( "\n\nApertar ENTER para terminar." ); 
    getchar( );  // aguardar por ENTER 
    return   ( 0 ); // voltar ao SO (sem erros) 
} // end main ( ) 
 
/* 
---------------------------------------------- documentacao complementar 
 
---------------------------------------------- notas / observacoes / comentarios 
 
 
---------------------------------------------- previsao de testes 
 
a.) a 
b.) 4.2 
c.) 10 
d.) 1 
e.) abc def 
f .) abc def 
 
---------------------------------------------- historico 
 
Versao Data  Modificacao 
  0.1 __/__  esboco 
 
 ---------------------------------------------- testes 
 
Versao Teste 
  0.1 01. ( OK )  identificacao de programa 
 
*/ 