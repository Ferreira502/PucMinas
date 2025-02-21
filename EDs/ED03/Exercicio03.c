/*
 Exercicio03 - v0.0. - 21 / 02 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exercicio03 exercicio03.c
 Windows: gcc -o exercicio03 exercicio03.c
 Para executar em terminal (janela de comandos):
 Linux : ./exercicio03
 Windows: exercicio03
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
// #include <ctype.h>

#define MAX 100

// -------------------------- definicao de classe

/**
  * Metodo01.
  */
void metodo01(void) 
{
// Identificar
   printf("\n%s\n", "\n\tMetodo0111");
   char palavra[MAX]; 

   printf("\nDigite uma Palavra: ");
   scanf("%s", palavra);

   for (int i = 0; palavra[i] != '\0'; i++) 
   {  
      if (palavra[i] >= 'A' && palavra[i] <= 'Z' && palavra[i] > 'K') 
      {  
        printf("\nPosicao %d: [%c]", i, palavra[i]);
      }
  }
   getchar();

// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo01 ( )

/**
  * Metodo02.
  */
void metodo02 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0112");
   char palavra[MAX]; 

   printf("\nDigite uma Palavra: ");
   scanf("%s", palavra);

   for (int i = 0; palavra[i] != '\0'; i++) 
   {  
      if (palavra[i] >= 'a' && palavra[i] <= 'z' && palavra[i] < 'k') 
      {  
         printf("\nPosicao %d: [%c]", i, palavra[i]);
      }
   }
   getchar();

// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo02 ( )

/**
  * Metodo03.
  */
void metodo03 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0113");
   char palavra[MAX]; 

   printf("\nDigite uma Palavra: ");
   scanf("%s", palavra);

   int tamanho = strlen(palavra);

   for (int i = tamanho - 1; i >= 0; i--) 
   {  
      if (palavra[i] >= 'A' && palavra[i] <= 'Z' && palavra[i] > 'K') 
      {  
         printf("\nPosicao %d: [%c]", i, palavra[i]);
      }
   }
   getchar();

// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo03 ( )

/**
  * Metodo04.
  */
void metodo04 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0114");
   char palavra[MAX]; 

   printf("\nDigite uma Palavra: ");
   scanf("%s", palavra);

   for (int i = 0; palavra[i] != '\0'; i++) 
   {  
      if ((palavra[i] >= 65 && palavra[i] <= 90) || (palavra[i] >= 97 && palavra[i] <= 122))
      {  
         printf("\nPosicao %d: [%c]", i, palavra[i]);
      }
   }
   getchar();

// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo04 ( )

/**
  * Metodo05.
  */
void metodo05 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0115");
   char palavra[MAX]; 

   printf("\nDigite uma Palavra: ");
   scanf("%s", palavra);

   int tamanho = strlen(palavra);

   for (int i = tamanho - 1; i >= 0; i--) 
   {  
      if (palavra[i] > '0' && palavra [i] <= '9' && palavra [i] % 2 == 0) 
      {  
         printf("\nPosicao %d: [%c]", i, palavra[i]);
      }
   }
 getchar();

// Encerrar
 printf("\n%s\n", "Apertar ENTER para continuar.");
 getchar();
} // fim metodo05 ( )

/**
  * Metodo06.
  */
void metodo06 ( void )
{
 // identificar
    printf ( "\n%s\n", "\n\tMetodo0116" );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

} // fim metodo06 ( )

/**
  * Metodo07.
  */
void metodo07 ( void )
{
 // identificar
    printf ( "\n%s\n", "\n\tMetodo0117" );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

} // fim metodo07 ( )

/**
  * Metodo08.
  */
void metodo08 ( void )
{
 // identificar
    printf ( "\n%s\n", "\n\tMetodo0118" );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

} // fim metodo08 ( )

/**
  * Metodo09.
  */
void metodo09 ( void )
{
 // identificar
    printf ( "\n%s\n", "\n\tMetodo0119" );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

} // fim metodo09 ( )

/**
  * Metodo10.
  */
void metodo10 ( void )
{
 // identificar
    printf ( "\n%s\n", "\n\tMetodo120" );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

} // fim metodo10 ( )

/**
  * Metodo11.
  */
 void metodo11 ( void )
 {
  // identificar
    printf ( "\n%s\n", "\n\tMetodo01E1" );
  // encerrar
     printf ( "\n%s\n", "Apertar ENTER para continuar." );
     getchar( );
 
 } // fim metodo11 ( )

 /**
  * Metodo12.
  */
void metodo12 ( void )
{
 // identificar
    printf ( "\n%s\n", "\n\tMetodo01E2" );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

} // fim metodo12 ( )

// identificar
menuOpcoes ( void ) 
{
   printf ( "\n" );             // para saltar linha
   printf ( "%s\n", "Exercicio01 - v.0.0 - 11/02/2025"       );
   printf ( "%s\n", "Matricula: 842527 Nome: Gabriel Ferreira Pereira" );

// mostrar opcoes
   printf ( "%s\n", "Opcoes:   "     );
   printf ( "%s\n", " 0 - parar"     );
   printf ( "%s\n", " 1 - metodo 0111" );
   printf ( "%s\n", " 2 - metodo 0112" );
   printf ( "%s\n", " 3 - metodo 0113" );
   printf ( "%s\n", " 4 - metodo 0114" );
   printf ( "%s\n", " 5 - metodo 0115" );
   printf ( "%s\n", " 6 - metodo 0116" );
   printf ( "%s\n", " 7 - metodo 0117" );
   printf ( "%s\n", " 8 - metodo 0118" );
   printf ( "%s\n", " 9 - metodo 0119" );
   printf ( "%s\n", " 10- metodo 0120" );
   printf ( "%s\n", " 11- metodo 01E1" );
   printf ( "%s\n", " 12- metodo 01E2" );
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
           case 11: metodo11 ( );
                break;
           case 12: metodo12 ( );
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