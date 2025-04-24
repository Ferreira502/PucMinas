/*
 Exercicio07 - v0.0. - 10 / 04 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exercicio07 exercicio07.c
 Windows: gcc -o exercicio07 exercicio07.c
 Para executar em terminal (janela de comandos):
 Linux : ./exercicio07
 Windows: exercicio07
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// -------------------------- definicao de classe

/**
  * Metodo01.
  */

void metodo01( void ) 
{
// Identificar
  printf("\n%s\n", "\n\tMetodo0711");
  int n = 0, x = 0;
  FILE * arquivo = fopen( "MULTIPLOS_4.TXT", "w");
  
  if (arquivo == NULL) 
  {
    printf("Erro ao abrir o arquivo\n");
    getchar();
  }

  printf("\nDigite a quantidade de numeros: ");
  scanf("%d", &n);
  getchar();

  for (int i = 1; i <= n; i++)
  {
    x = 4 * i;
    printf("%d\n", x);            
    fprintf(arquivo, "%d\n", x);
    
  }
  getchar();
  fclose(arquivo);
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo01 ( )

/**
  * Metodo02.
  */

void metodo02(void)
{
// Identificar
  printf("\n%s\n", "\tMetodo0712");

  int n;
  int count = 0;

  printf("Informe a quantidade de valores: ");
  scanf("%d", &n);
  getchar();

  int value = 15 * (2 * n);

  while (count < n && value >= 30)
  {
      if (value % 15 == 0 && value % 2 == 0)
      {
        printf("%d ", value);
        count++;
      }
      value -= 1;
  }

  getchar();
// Encerrar
  printf("\n\n%s\n", "Apertar ENTER para continuar.");
  getchar();
  } // fim metodo02

/**
  * Metodo03.
  */

void metodo03 ( void )
{
// Identificar
  printf("\n%s\n", "\n\tMetodo0713");
  int n = 0, x = 0;
  FILE * arquivo = fopen( "MULTIPLOS_3.TXT", "w");
  
  if (arquivo == NULL) 
  {
    printf("Erro ao abrir o arquivo\n");
  }

  printf("\nDigite a quantidade de numeros: ");
  scanf("%d", &n);
  getchar();

  for (int i = 0; i < n; i++)
  {
    x = pow(3, i);
    printf("%d\n", x);            
    fprintf(arquivo, "%d\n", x);
    
  }
  
  getchar();
  fclose(arquivo);
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
  printf("\n%s\n", "\n\tMetodo0714");
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo04 ( )

/**
  * Metodo05.
  */

  int f_a(int b, int exp, int n, FILE *arquivo) 
  {
      if (n <= 0) 
      {
          return 1;
      }
  
      int potencia = (int)pow(b, exp);
      printf("1/%d^%d = 1/%d\n", b, exp, potencia);                 // Exibe na tela
      fprintf(arquivo, "1/%d^%d = 1/%d\n", b, exp, potencia);       // Grava no arquivo
  
      return f_a(b, exp + 2, n - 1, arquivo);
  }
  
  void metodo05(void)
  {
      // Identificar
      printf("\n%s\n", "\n\tMetodo0715");
      int base = 0, n = 0;
      FILE *arquivo = fopen("POTENCIAS.TXT", "w");
    
      if (arquivo == NULL) 
      {
          printf("Erro ao abrir o arquivo\n");
          return;
      }
  
      printf("\nDigite a base: ");
      scanf("%d", &base);
      printf("Digite a quantidade de termos: ");
      scanf("%d", &n);
  
      printf("\nPotencias calculadas:\n");
      f_a(base, 1, n, arquivo);
  
      fclose(arquivo); 
  
      getchar();
      printf("\n%s\n", "Apertar ENTER para continuar.");
      getchar();
  } // fim metodo05

/**
  * Metodo06.
  */

void metodo06( void )
{
// Identificar
  printf("\n%s\n", "\n\tMetodo0716");
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo06()

/**
  * Metodo07.
  */

void metodo07( void ) 
{
// Identificar
  printf("\n%s\n", "\n\tMetodo0717");
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo07()

/**
  * Metodo08.
  */

void metodo08( void ) 
{
//Identificar
  printf("\n%s\n", "\n\tMetodo0718");
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
    printf("\n%s\n", "\n\tMetodo0719");
    FILE * arquivo = fopen( "RESULTADO09.TXT", "w");
    char cadeia[80];
 
    printf("\nDigite a cadeia de palavras: ");  
    fgets(cadeia, 80 - 1, stdin);
 
    int tamanho = strlen(cadeia);
      
    for (int i = 0; i <= tamanho; i++)
    {
        if (cadeia[i] >= 'A' && cadeia[i] <= 'Z')
            {
                fprintf(arquivo, "%c\n", cadeia[i]);            
            }
    }
    printf("\nValores gravados no arquivo");
    getchar();
    
    fclose(arquivo);
  // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar( );
 
  } // fim metodo09 ( )
 
 /**
   * Metodo10.
   */
 
 void metodo10(void) 
 {
 // Identificar
     printf("\n%s\n", "\n\tMetodo720");
     FILE * arquivo = fopen( "RESULTADO10.TXT", "w");
     char cadeia[80];
 
     printf("\nDigite a cadeia de palavras: ");  
     fgets(cadeia, 80 - 1, stdin);
 
     int tamanho = strlen(cadeia);
      
     for (int i = 0; i <= tamanho; i++)
     {
         if (cadeia[i] >= '3' && cadeia[i] <= '9')
             {
                 fprintf(arquivo, "%c\n", cadeia[i]);            
             }
     }
     printf("\nValores printados no arquivo");
     getchar();
    
     fclose(arquivo);
 // Encerrar
     printf("\n\n%s\n", "Apertar ENTER para continuar.");
     getchar();
 }// fim metodo 10 ()

/**
  * Metodo11.
  */

void metodo11( void ) 
{
// Identificar
  printf("\n%s\n", "\n\tMetodo07E1");
// Encerrar
  printf("\n\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}//

 
/**
  * Metodo12.
  */

void metodo12( void ) 
{
// Identificar
  printf("\n%s\n", "\n\tMetodo07E2");
// Encerrar
  printf("\n\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}

// identificar
void menuOpcoes ( void ) 
{
  printf ( "\n" );             // para saltar linha
  printf ( "%s\n", "Exercicio07 - v.0.0 - 10/04/2025"       );
  printf ( "%s\n", "Matricula: 842527 Nome: Gabriel Ferreira Pereira" );

// mostrar opcoes
  printf ( "%s\n", "Opcoes:   "     );
  printf ( "%s\n", " 0 - parar"     );
  printf ( "%s\n", " 1 - metodo 0711" );
  printf ( "%s\n", " 2 - metodo 0712" );
  printf ( "%s\n", " 3 - metodo 0713" );
  printf ( "%s\n", " 4 - metodo 0714" );
  printf ( "%s\n", " 5 - metodo 0715" );
  printf ( "%s\n", " 6 - metodo 0716" );
  printf ( "%s\n", " 7 - metodo 0717" );
  printf ( "%s\n", " 8 - metodo 0718" );
  printf ( "%s\n", " 9 - metodo 0719" );
  printf ( "%s\n", " 10- metodo 0720" );
  printf ( "%s\n", " 11- metodo 07E1" );
  printf ( "%s\n", " 12- metodo 07E2" );
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