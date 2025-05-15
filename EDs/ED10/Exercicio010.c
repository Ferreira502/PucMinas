/*
 Exercicio10 - v0.0. - 13 / 05 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux :  gcc -o exercicio10 exercicio10.c
 Windows: gcc -o exercicio10 exercicio10.c
 Para executar em terminal (janela de comandos):
 Linux : ./exercicio10
 Windows: exercicio10
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
int RandomIntGenerate(int inferior, int superior) 
{
  int limite = (superior - inferior + 1);
  if (limite > 106) limite = 106;
  return inferior + rand() % limite;
}

void metodo01( void ) 
{
// Identificar
  printf("\n%s\n", "\n\tMetodo1011");
  int inferior = 0, superior = 0, n = 0;

    printf("\nInforme o valor inferior do intervalo: ");
    scanf("%d", &inferior);

    printf("\nInforme o valor superior do intervalo: ");
    scanf("%d", &superior);

    if (inferior > superior) {
        printf("\nLimite inferior maior que superior");
        return;
    }

    printf("\nInforme a quantidade de numeros a serem gerados: ");
    scanf("%d", &n);

    int valores[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        valores[i] = RandomIntGenerate(inferior, superior);
    }

    FILE *arquivo = fopen("DADOS.TXT", "w");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo");
        return;
    }

    fprintf(arquivo, "%d\n", n);

    for (int i = 0; i < n; i++) 
    {
        fprintf(arquivo, "%d\n", valores[i]);
    }

    fclose(arquivo);

    printf("Valores gravados com sucesso no arquivo DADOS.TXT\n");
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
  printf("\n%s\n", "\n\tMetodo1012");
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
   printf("\n%s\n", "\n\tMetodo1013");
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
   printf("\n%s\n", "\n\tMetodo1014");
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
   printf("\n%s\n", "\n\tMetodo1015");
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
  printf("\n%s\n", "\n\tMetodo1016");
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo06 ( )

/**
  * Metodo07.
  */

void metodo07( void ) {
//identificar
  printf("\n%s\n", "\n\tMetodo1017");
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo07 ( )

/**
  * Metodo08.
  */

void metodo08( void ) {
//Identificar
  printf("\n%s\n", "\n\tMetodo1018");
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
  printf("\n%s\n", "\n\tMetodo1019");
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
  printf("\n%s\n", "\n\tMetodo1020");
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
  printf("\n%s\n", "\n\tMetodo10E1");
// Encerrar
  printf("\n\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo 11 ( )

 
/**
  * Metodo12.
  */

void metodo12( void ) {
// Identificar
  printf("\n%s\n", "\n\tMetodo10E2");
// Encerrar
  printf("\n\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo 12 ( )

// identificar
 void menuOpcoes ( void ) 
 {
   printf ( "\n" );             // para saltar linha
   printf ( "%s\n", "Exercicio09 - v.0.0 - 13/05/2025"       );
   printf ( "%s\n", "Matricula: 842527 Nome: Gabriel Ferreira Pereira" );

// mostrar opcoes
   printf ( "%s\n", "Opcoes:   "     );
   printf ( "%s\n", " 0 - parar"     );
   printf ( "%s\n", " 1 - metodo 1011" );
   printf ( "%s\n", " 2 - metodo 1012" );
   printf ( "%s\n", " 3 - metodo 1013" );
   printf ( "%s\n", " 4 - metodo 1014" );
   printf ( "%s\n", " 5 - metodo 1015" );
   printf ( "%s\n", " 6 - metodo 1016" );
   printf ( "%s\n", " 7 - metodo 1017" );
   printf ( "%s\n", " 8 - metodo 1018" );
   printf ( "%s\n", " 9 - metodo 1019" );
   printf ( "%s\n", " 10- metodo 1020" );
   printf ( "%s\n", " 11- metodo 10E1" );
   printf ( "%s\n", " 12- metodo 10E2" );
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