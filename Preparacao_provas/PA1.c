/*
 Exercicio_Preparacao - v0.0. - 04 / 04 / 2025
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

#define PI 3.14

// -------------------------- definicao de classe

/**
  * method01.
  */
void method_01( void ) 
{
// Identificar
   printf("\n%s\n", "\n\tmethod_01");
   int a = 0, b = 0;
   double resultado = 0.0, resultado_novo = 0;

   do
   {
     printf("\nDigite 0.0 para encerrar\n");
     printf("\nDigite o valor do raio: ");
     scanf("%d", &a);
     printf("\nDigite o valor a ser dividido: ");
     scanf("%d", &b);
     if (a != 0 && b != 0)
     {
      resultado = 2 * PI * a;
      resultado_novo = resultado / b;
      printf("\nO comprimento (%d) da circunferencia de raio igual a (%d) e igual a = (%lf)\n", b , a , resultado_novo);
      getchar();  
     }
     else {
      printf("\nPrograma encerrado\n");
      getchar();  
     }
   } while (a != 0 && b != 0);

// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim method01 ( )

/**
  * method02.
  */

  void verificarCadeia(char a, char b, char c)
  {
      bool x = (a < b && b < c);
      if (x) 
      {
          printf("\nOs caracteres (%c) (%c) (%c) estao em ordem\n", a, b, c);
      }
      else
      {
         printf("\nOs caracteres (%c) (%c) (%c) nao estao em ordem\n", a, b, c);
      }
  }
  
  void method_02 ( void )
  {
  // Identificar
     printf("\n%s\n", "\n\tmethod_02");
     char a, b, c;
     int n = 0, i = 0;
      
     printf("\nDigite a quantidade de testes: ");
     scanf("%d", &n);
     getchar();
     
     while (i < n) 
     {
         printf("\nDigite o primeiro caracter: ");
         scanf("%c", &a);
         getchar();
         
         printf("\nDigite o segundo caracter: ");
         scanf("%c", &b);
         getchar();
  
         printf("\nDigite o terceiro caracter: ");
         scanf("%c", &c);
         getchar();
  
         verificarCadeia(a,b,c);
         i++;
     }
  // Encerrar
     printf("\n%s\n", "Apertar ENTER para continuar.");
     getchar();
  } // fim method02 ( )  

/**
  * method03.
  */

void method_03 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tmethod_03");
   int a = 0, b = 0, n = 0, x = 0, metade = 0 , dobro = 0;

   printf("\nDigite o limite inferior: ");
   scanf("%d", &a);
   printf("\nDigite o limite superior: ");
   scanf("%d", &b);
   printf("\nDigite a quantidade de numeros: ");
   scanf("%d", &n);

   for (int i = 0; i < n; i ++)
   {
      printf("\n%d:\t ", i + 1);
      scanf("%d", &x);

      if (x % 2 == 0)
      {
         metade = x / 2;
         dobro = x * 2;
         if (metade >= a && metade < b && dobro >= a && dobro < b)
         {
            printf("\nSeu dobro e sua metade esta contido no intervalo [%d:%d)\n", a, b);
            getchar();
         }
         else 
         {
            printf("\nSeu dobro e sua metade nao esta contido no intervalo [%d:%d)\n", a, b);
            getchar();
         }
         
      }
      else 
      {
         printf("\nO numero digitado nao e par\n");
         getchar();
      }
      
   }
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim method03 ( )

/**
  * method04.
  */

void method_04 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tmethod_04");
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim method04 ( )

/**
  * method05.
  */
void method_05 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tmethod_5");
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
    printf ( "%s\n", "Exercicio_Preparacao - Programa = v0.0" ); 
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