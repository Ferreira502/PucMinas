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
 // Identificar
   printf("\n%s\n", "\n\tMetodo0116");
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
} // fim metodo06 ( )

/**
  * Metodo07.
  */
void metodo07 ( void )
{
// Identificar
   printf("\n%s\n", "\n\tMetodo0117");
   int a = 0, b = 0, n = 0;
   int cont = 0, x = 0;
   
   printf("\nDigite o valor de a: ");
   scanf("%d", &a);
   printf("\nDigite o valor de b: ");
   scanf("%d", &b);

   printf("\nDigite a quantidade de valores a serem testados: ");
   scanf("%d", &n);

   printf("\nAgora, insira os %d valores: ", n);
   for (int i = 0; i < n; i++) {
       printf("Valor %d: ", i + 1);
       scanf("%d", &x);

       if (x >= a && x <= b && x % 3 == 0) {
           printf("\nO valor %d esta no intervalo [%d, %d] e multiplo de 3\n", x, a, b);
           cont++;
       }
   }
   
   if (cont == 0) 
   {
      printf("\nNenhum multiplo de 3 encontrado no intervalo");
   }
   
// Encerrar
   printf("\n\n%s\n", "Apertar ENTER para continuar.");
   getchar();

} // fim metodo07 ( )

/**
  * Metodo08.
  */
void metodo08 ( void )
{
 // Identificar
    printf("\n%s\n", "\n\tMetodo0118");
   int a = 0, b = 0, n = 0;
   int cont = 0, x = 0;
 
   printf("\nDigite o valor de a: ");
   scanf("%d", &a);
   printf("\nDigite o valor de b: ");
   scanf("%d", &b);

   printf("\nDigite a quantidade de valores a serem testados: ");
   scanf("%d", &n);

   printf("\nAgora, insira os %d valores: ", n);
   for (int i = 0; i < n; i++) {
       printf("Valor %d: ", i + 1);
       scanf("%d", &x);

       if (x >= a && x <= b && x % 4 == 0 && x % 3 != 0) {
           printf("\nO valor %d esta no intervalo [%d, %d] e multiplo de 3\n", x, a, b);
           cont++;
       }
   }
   
   if (cont == 0) 
   {
      printf("\nNenhum multiplo de 4 que nao forem tambem multiplo de 3");
   }
   
 
// Encerrar
   printf("\n\n%s\n", "Apertar ENTER para continuar.");
   getchar();

} // fim metodo08 ( )

/**
  * Metodo09.
  */
void metodo09 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0119");
   double a = 0.0, b = 0.0, x = 0.0;
   int n  = 0, cont = 0, parte_inteira = 0.0;
   

   do {
       printf("\nDigite o valor de a: ");
       scanf("%lf", &a);
       printf("Digite o valor de b: ");
       scanf("%lf", &b);

       if (a >= b) {
           printf("\nErro: 'a' deve ser menor que 'b'");
       }
   } while (a >= b);

   printf("\nDigite a quantidade de valores a serem testados (n): ");
   scanf("%d", &n);

   printf("\nInsira os %d valores:\n", n);
   for (int i = 0; i < n; i++) {
       printf("Valor %d: ", i + 1);
       scanf("%lf", &x);

       if (x > a && x < b) {
           parte_inteira = (int)x;

           if (parte_inteira % 2 == 0 && parte_inteira < 5) {
               printf("\nValor %.2lf pertence ao intervalo e sua parte inteira (%d) e par e menor que 5\n", x, parte_inteira);
               cont++;
           }
       }
   }

   if (cont == 0) {
       printf("\nNenhum valor no intervalo atendeu aos criterios\n");
   }
// Encerrar
   printf("\n\n%s\n", "Apertar ENTER para continuar.");
   getchar();

} // fim metodo09 ( )

/**
  * Metodo10.
  */
 void metodo10(void) {
   // Identificar
   printf("\n%s\n", "\n\tMetodo120");

   double a = 0.0, b = 0.0, x = 0.0, parte_fracionaria = 0.0;
   int n = 0, cont = 0;

   do {
      printf("\nDigite o valor de a: ");
      scanf("%lf", &a);
      printf("Digite o valor de b: ");
      scanf("%lf", &b);

       if (a >= b) {
         printf("\nErro: 'a' deve ser menor que 'b'. Tente novamente.\n");
       }
   } while (a >= b);

   printf("\nDigite a quantidade de valores a serem testados (n): ");
   scanf("%d", &n);

   printf("\nInsira os %d valores:\n", n);
   for (int i = 0; i < n; i++) 
   {
      printf("Valor %d: ", i + 1);
      scanf("%lf", &x);

      parte_fracionaria = x - (int)x;

       if (parte_fracionaria > a && parte_fracionaria < b) {
           printf("\nO valor %.2lf tem parte fracionaria %.2lf dentro do intervalo ]%.2lf:%.2lf[\n", x, parte_fracionaria, a, b);
           cont++;
       }
   }

   if (cont == 0) {
       printf("\nNenhum valor no intervalo atendeu aos critérios.\n");
   }

   // Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
}// fim metodo 10 ( )

/**
  * Metodo11.
  */
 void metodo11 ( void )
 {
  // identificar
   printf ( "\n%s\n", "\n\tMetodo01E1" );
   char palavra[MAX], palavra_1[MAX];
   int j = 0;

   printf("\nDigite uma linha de texto: ");
   fgets(palavra, MAX, stdin);
   palavra[strcspn(palavra, "\n")] = '\0';

   for (int i = 0; palavra[i] != '\0'; i++) 
   {
   if (!isalnum(palavra[i])) {
      palavra_1[j++] = palavra[i];
   }
  }
   palavra_1[j] = '\0';

   printf("\nCaracteres nao alfanumericos encontrados: \"%s\"\n", palavra_1);
  // encerrar
   printf ( "\n%s\n", "Apertar ENTER para continuar." );
   getchar( );
 
 } // fim metodo11 ( )

 /**
  * Metodo12.
  */
 void metodo12(void)
 {
   // identificar
     printf("\n%s\n", "\n\tMetodo01E2");
     char cadeia[MAX];
     int apenasSimbolos = 1;
 
     printf("\nDigite uma sequencia de caracteres: ");
     fgets(cadeia, MAX, stdin);
     cadeia[strcspn(cadeia, "\n")] = '\0';
 
     for (int i = 0; cadeia[i] != '\0'; i++) {
         if (isalnum(cadeia[i])) { 
             apenasSimbolos = 0;
             break;
         }
     }
 
     if (apenasSimbolos) {
         printf("\nA sequencia contem apenas simbolos\n");
     } else {
         printf("\nA sequencia contem letras ou numeros\n");
     }
   // encerrar
     printf("\n%s\n", "Apertar ENTER para continuar.");
     getchar();

 }// fim metodo12

// identificar
menuOpcoes ( void ) 
{
   printf ( "\n" );             // para saltar linha
   printf ( "%s\n", "Exercicio01 - v.0.0 - 21/02/2025"       );
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