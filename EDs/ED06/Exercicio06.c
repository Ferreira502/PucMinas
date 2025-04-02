/*
 Exercicio06 - v0.0. - 01 / 04 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exercicio06 exercicio06.c
 Windows: gcc -o exercicio06 exercicio06.c
 Para executar em terminal (janela de comandos):
 Linux : ./exercicio06
 Windows: exercicio06
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

int multiplos_3_recursivo( int x )
{
   return ( x += 3);
}

void metodo01( void ) 
{
// Identificar
   printf("\n%s\n", "\n\tMetodo0611");
   int n = 0, x = 0, y = 0;
   printf("\nQuantos valores: ");
   scanf("%d", &n);

   for (int i = 0; i < n; i++)
   {
      x = x +  multiplos_3_recursivo( y );
      printf("\n%d", x);
   }
   getchar();
          
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo01 ( )

/**
  * Metodo02.
  */

int multiplos_3_recursivo_dec( int x )
{
    if (x == 1) return 3; 
   return multiplos_3_recursivo_dec( x - 1 ) + 3;
}


void metodo02 ( void )
{
// Identificar
   printf("\n%s\n", "\n\tMetodo0612");
   int n = 0;
   printf("\nQuantos valores: ");
   scanf("%d", &n);

   for (int i = n; i > 0; i--)
   {
      printf("\n%d", multiplos_3_recursivo_dec(i));
   }
    getchar();
    
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo02 ( )

/**
  * Metodo03.
  */

int multiplos3_recursivo_a(int n, int atual, int incremento) {
    if (n == 0) return 1;

    printf("\n1/%d", atual);

    multiplos3_recursivo_a(n - 1, atual + incremento, 3);
}

void metodo03 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0613");
   int n = 0;
   printf("\nQuantos valores: ");
   scanf("%d", &n);

   printf("Sequencia: ");
   multiplos3_recursivo_a(n, 1, 2);
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
   printf("\n%s\n", "\n\tMetodo0614");
   int n = 0;
   printf("\nQuantos valores: ");
   scanf("%d", &n);

   for (int i = n; i > 0; i--)
   {
      printf("\n1/%d", multiplos_3_recursivo_dec(i));
      if ( i == 1 ) 
      {
          printf("\n1/1");
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

double impar ( int x ) 
{
    return( 2 * x - 1 );
}

void metodo05 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0615");
   int n = 0;
   int x = 0;
   int y = 3;

   printf("\nQuantos termos: ");
   scanf("%d",&n);

   for ( x = 1; x <= n; x = x + 1 )
       {
           printf("%d\t%d\n", x,y );
           y = y + impar ( x );
       }
   printf("\n");
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
   printf("\n%s\n", "\n\tMetodo0616");
   int n = 0;
   int x = 0;
   int y = 3;

   printf("\nQuantos termos: ");
   scanf("%d",&n);

   for ( x = 1; x <= n; x = x + 1 )
      {
         printf("%d\t1/%d\n", x,y );
         y = y + impar ( x );
      }
   printf("\n");
   // Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo06()

/**
  * Metodo07.
  */

char cadeia_recursiva(char palavra[], int index) {
    return palavra[index];
}

void metodo07(void) {
    printf("\n%s\n", "\n\tMetodo0617");
    char palavra[MAX];
    int count = 0;
    
    
    printf("\nDigite uma Palavra: ");
    fgets(palavra, MAX, stdin);
    palavra[strcspn(palavra, "\n")] = 0;

    int x = strlen(palavra);
    while (count < x) {
        char letra = cadeia_recursiva(palavra, x - count - 1);
        
        if (letra != '\0') 
        { 
            printf("Caractere %d: %c\n", count + 1, letra);
            getchar();
        }
        
        count++;
    }

    // Encerrar
    printf("\n%s\n", "Apertar ENTER para continuar.");
    getchar();
}// fim metodo07()

/**
  * Metodo08.
  */

void metodo08(void) {
//Identificar
    printf("\n%s\n", "\n\tMetodo0617");
    char palavra[MAX];
    int count = 0;
    
    printf("\nDigite uma Palavra: ");
    fgets(palavra, MAX, stdin);
    palavra[strcspn(palavra, "\n")] = 0;

    while (count < strlen(palavra)) {
        char letra = cadeia_recursiva(palavra, count);
        
        if (letra != '\0') 
        { 
            if ( letra % 2 == 0)
            {
                printf("Caractere %d: %c\n", count + 1, letra);
                getchar();
            }
        }
        
        count++;
    }

    // Encerrar
    printf("\n%s\n", "Apertar ENTER para continuar.");
    getchar();
}// fim metodo08()
/**
  * Metodo09.
  */

 void metodo09 ( void )
 {
 // Identificar
   printf("\n%s\n", "\n\tMetodo0619");
   char palavra[MAX];
   int count = 0;
    
   printf("\nDigite uma Palavra: ");
   fgets(palavra, MAX, stdin);
   palavra[strcspn(palavra, "\n")] = 0;

   while (count < strlen(palavra)) {
       char letra = cadeia_recursiva(palavra, count);
        
       if (letra != '\0') 
       { 
           if ( letra >= 'C' && letra <= 'P')
           {
               printf("Caractere %d: %c\n", count + 1, letra);
               getchar();
           }
       }
        
       count++;
   }

// Encerrar
   printf("\n\n%s\n", "Apertar ENTER para continuar.");
   getchar();

 } // fim metodo09 ( )

/**
  * Metodo10.
  */

int fibonacci(int x, int n) 
{
    if ( x == n) return 0;
    return fibonacci(x + 1);
}

void metodo10( void ) 
{
// Identificar
   printf("\n%s\n", "\n\tMetodo620");
   int x = 1, n = 0, y = 0;

   printf("\nDigite a quantidade de valores: ");
   scanf("%d",&n);
    
   for (int i = 0; i < n; i++) 
    {
       y = fibonacci(x, n);
       if ( y % 2 == 0) 
       {
           printf("%d", y);
       }
    }

// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo10 ( )

/**
  * Metodo11.
  */
 void metodo11 ( void )
 {
  // identificar
   printf ( "\n%s\n", "\n\tMetodo06E1" );
  // encerrar
   printf ( "\n%s\n", "Apertar ENTER para continuar." );
   getchar( );
 
 } // fim metodo11 ( )

 
/**
  * Metodo12.
  */

void metodo12( void ) {
// Identificar
   printf("\n%s\n", "\n\tMetodo06E2");
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
}

// identificar
 void menuOpcoes ( void ) 
 {
   printf ( "\n" );             // para saltar linha
   printf ( "%s\n", "Exercicio06 - v.0.0 - 01/04/2025"       );
   printf ( "%s\n", "Matricula: 842527 Nome: Gabriel Ferreira Pereira" );

// mostrar opcoes
   printf ( "%s\n", "Opcoes:   "     );
   printf ( "%s\n", " 0 - parar"     );
   printf ( "%s\n", " 1 - metodo 0611" );
   printf ( "%s\n", " 2 - metodo 0612" );
   printf ( "%s\n", " 3 - metodo 0613" );
   printf ( "%s\n", " 4 - metodo 0614" );
   printf ( "%s\n", " 5 - metodo 0615" );
   printf ( "%s\n", " 6 - metodo 0616" );
   printf ( "%s\n", " 7 - metodo 0617" );
   printf ( "%s\n", " 8 - metodo 0618" );
   printf ( "%s\n", " 9 - metodo 0619" );
   printf ( "%s\n", " 10- metodo 0620" );
   printf ( "%s\n", " 11- metodo 06E1" );
   printf ( "%s\n", " 12- metodo 06E2" );
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