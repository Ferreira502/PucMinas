/*
 Exercicio10 - v0.0. - 20 / 06 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux :  gcc -o exercicio15 exercicio15.c
 Windows: gcc -o exercicio15 exercicio15.c
 Para executar em terminal (janela de comandos):
 Linux : ./exercicio15
 Windows: exercicio15
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 100

// -------------------------- definicao de classe

/**
  * Metodo01.
  */

void metodo01( void ) 
{
// Identificar
  printf("\n%s\n", "\n\tMetodo01");
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
  printf("\n%s\n", "\n\tMetodo02");
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
   printf("\n%s\n", "\n\tMetodo03");
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
   printf("\n%s\n", "\n\tMetodo04");
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
  printf("\n%s\n", "\n\tMetodo05");
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo05 ( )

/**
  * Metodo06.
  */

void metodo06( void )
{
// Identificar
  printf("\n%s\n", "\n\tMetodo06");
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo06 ( )

/**
  * Metodo07.
  */

void metodo07( void ) {
//identificar
  printf("\n%s\n", "\n\tMetodo07");
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo07 ( )

/**
  * Metodo08.
  */

void metodo08( void ) 
{
//Identificar
  printf("\n%s\n", "\n\tMetodo08");
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo08 ( )

/**
  * Metodo09.
  */

void metodo09 ( void )
{
// Identificar
  printf("\n%s\n", "\n\tMetodo09");
// encerrar
  printf("%s\n", "\nApertar ENTER para continuar\n");
  getchar( );

 } // fim metodo09 ( )

/**
  * Metodo10.
  */

void metodo10( void ) 
{
// Identificar
  printf("\n%s\n", "\n\tMetodo10");
// Encerrar
  printf("\n\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo 10 ( )

/**
  * Metodo11.
  */

void metodo11( void ) 
{
// Identificar
  printf("\n%s\n", "\n\tMetodoE1");
// Encerrar
  printf("\n\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo 11 ( )

 
/**
  * Metodo12.
  */

void metodo12( void ) {
// Identificar
  printf("\n%s\n", "\n\tMetodoE2");
// Encerrar
  printf("\n\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo 12 ( )

// identificar
 void menuOpcoes ( void ) 
 {
   printf ( "\n" );             // para saltar linha
   printf ( "%s\n", "Exercicio15 - v.0.0 - 20/06/2025"       );
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
   printf ( "%s\n", " 11- metodo E1" );
   printf ( "%s\n", " 12- metodo E2" );
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