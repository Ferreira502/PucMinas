/*
 Exercicio04 - v0.0. - 10 / 03 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exercicio04 exercicio04.c
 Windows: gcc -o exercicio04 exercicio04.c
 Para executar em terminal (janela de comandos):
 Linux : ./exercicio04
 Windows: exercicio04
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
void metodo01(void) 
{
// Identificar
   printf("\n%s\n", "\n\tMetodo0411");
   double min = 0.0, max = 0.0, x = 0.0;
   int n = 0;

    do {
      printf("\nDigite o valor mininmo: ");
      scanf("%lf", &min);
      printf("Digite o valor maximo: ");
      scanf("%lf", &max);

      if (min >= max) {
         printf("\nErro: 'min' deve ser menor que 'max'");
      }
   } while (min >= max);

   printf("\nDigite a quantidade de valores a serem testados (n): ");
   scanf("%d", &n);

   printf("\nInsira os %d valores:\n", n);
   for (int i = 0; i < n; i++) {
       printf("Valor %d: ", i + 1);
       scanf("%lf", &x);

       if ( x >= min && x <= max)
       {
           printf("\n(%.2lf) Pertence ao intervalo\n", x);
       }
       else 
       {
           printf("\n(%.2lf) Nao pertence ao intervalo\n", x);
       }
   }
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
   printf("\n%s\n", "\n\tMetodo0412");
   char palavra[MAX]; 

   printf("\nDigite uma Palavra: ");
   fgets(palavra, MAX, stdin);

   for (int i = 0; palavra[i] != '\0'; i++) 
   {  
      if (palavra[i] >= 'c' && palavra[i] <= 'p') 
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

void posicaoCadeia (char palavra [MAX]) 
{
    for (int i = 0; palavra[i] != '\0'; i++) 
    {  
      if (palavra[i] >= 'c' && palavra[i] <= 'p') 
      {  
         printf("\nPosicao %d: [%c]", i, palavra[i]);
      }
   }
   getchar();
} 

void metodo03 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0413");
   char palavra[MAX]; 

   printf("\nDigite uma Palavra: ");
   fgets(palavra, MAX, stdin);

   posicaoCadeia(palavra);

// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo03 ( )

/**
  * Metodo04.
  */

void separarCadeia(char palavra [MAX]) 
{
    char palavra_2[MAX];
    int j = 0;
    
     for (int i = 0; palavra[i] != '\0'; i++) {
        palavra_2[j++] = palavra[i];
    }
    palavra_2[j] = '\0';

    for (int i = 0; palavra_2[i] != '\0'; i++) {
        if (palavra_2[i] >= 'c' && palavra_2[i] <= 'p') {
            printf("\nPosicao %d: [%c]", i, palavra_2[i]);
        }
    }

    getchar();
}

void metodo04 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0414");
   char palavra[MAX]; 

   printf("\nDigite uma Palavra: ");
   fgets(palavra, MAX, stdin);

   separarCadeia(palavra);

// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo04 ( )

/**
  * Metodo05.
  */

void separarCadeia_2 (char palavra [MAX]) 
{
    char palavra_2[MAX];
    int j = 0;
    
     for (int i = 0; palavra[i] != '\0'; i++) {
        palavra_2[j++] = palavra[i];
    }
    palavra_2[j] = '\0';

    for (int i = 0; palavra_2[i] != '\0'; i++) {
        if (palavra_2[i] >= 'c' && palavra_2[i] <= 'p' || palavra_2[i] >= 'C' && palavra[i] <= 'P') {
            printf("\nPosicao %d: [%c]", i, palavra_2[i]);
        }
    }

    getchar();
}

void metodo05 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0415");
   char palavra[MAX];

   printf("\nDigite uma Palavra: ");
   fgets(palavra, MAX, stdin);

   separarCadeia_2(palavra);

// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo05 ( )

/**
  * Metodo06.
  */

void separarCadeia_3 (char palavra [MAX]) 
{
   char palavra_2[MAX];
   int j = 0;
    
   for (int i = 0; palavra[i] != '\0'; i++) {
       palavra_2[j++] = palavra[i];
   }
    palavra_2[j] = '\0';

   for (int i = 0; palavra_2[i] != '\0'; i++) {
       if (palavra_2[i] >= 'c' && palavra_2[i] <= 'p' || palavra_2[i] >= 'C' && palavra[i] <= 'P') {
           printf("\nPosicao %d: [%c]", i, palavra_2[i]);
       }
   }

    getchar();
}

void metodo06 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0416");
   char palavra[MAX];

   printf("\nDigite uma Palavra: ");
   fgets(palavra, MAX, stdin);

   separarCadeia_3(palavra);
    
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo06 ( )

/**
  * Metodo07.
  */

void cadeia_pares (char palavra [MAX])
{
   char palavra_2[MAX];
   int j = 0, parte_inteira = 0;
    
   for (int i = 0; palavra[i] != '\0'; i++) {
       palavra_2[j++] = palavra[i];
   }
    palavra_2[j] = '\0';

   for (int i = 0; palavra_2[i] != '\0'; i++) {
       parte_inteira = (int)palavra_2[i];
       if (parte_inteira % 2 == 0) {
           printf("\nPosicao %d: [%c]", i, palavra_2[i]);
       }
   }

    getchar();
}

void metodo07 ( void )
{
// Identificar
   printf("\n%s\n", "\n\tMetodo0417");
   char palavra[MAX];

   printf("\nDigite uma Palavra: ");
   fgets(palavra, MAX, stdin);

   cadeia_pares(palavra);
   
// Encerrar
   printf("\n\n%s\n", "Apertar ENTER para continuar.");
   getchar();

} // fim metodo07 ( )

/**
  * Metodo08.
  */
void nao_alfanumericos (char palavra [MAX]) 
{
   char palavra_2[MAX];
   int j = 0;
    
   for (int i = 0; palavra[i] != '\0'; i++) {
       palavra_2[j++] = palavra[i];
   }
    palavra_2[j] = '\0';

   for (int i = 0; palavra_2[i] != '\0'; i++) {
       if (!isalnum(palavra_2[i])) {
           printf("\nPosicao %d: [%c]", i, palavra_2[i]);
       }
   }

    getchar();
}
void metodo08 ( void )
{
 // Identificar
  printf("\n%s\n", "\n\tMetodo0418");
  char palavra [MAX];
    
  printf("\nDigite uma Palavra: ");
  fgets(palavra, MAX, stdin);

  nao_alfanumericos(palavra);
    
// Encerrar
   printf("\n\n%s\n", "Apertar ENTER para continuar.");
   getchar();

} // fim metodo08 ( )

/**
  * Metodo09.
  */

void alfanumericos (char palavra [MAX]) 
{
   char palavra_2[MAX];
   int j = 0;
    
   for (int i = 0; palavra[i] != '\0'; i++) {
       palavra_2[j++] = palavra[i];
   }
    palavra_2[j] = '\0';

   for (int i = 0; palavra_2[i] != '\0'; i++) {
       if (isalnum(palavra[i])) {
           printf("\nPosicao %d: [%c]", i, palavra_2[i]);
       }
   }

    getchar();
}

 void metodo09 ( void )
 {
 // Identificar
   printf("\n%s\n", "\n\tMetodo0419");
   char palavra [MAX];
    
   printf("\nDigite uma Palavra: ");
   fgets(palavra, MAX, stdin);

   alfanumericos(palavra);
    
// Encerrar
   printf("\n\n%s\n", "Apertar ENTER para continuar.");
   getchar();

 } // fim metodo09 ( )

/**
  * Metodo10.
  */

 void cadeias_alfanumericos(char palavra[MAX])
 {
   int n = 0;
   printf("\nDigite a quantidade de valores a serem testados (n): ");
   scanf("%d", &n);

   printf("\nInsira os %d valores:", n);
   for (int i = 0; i < n; i++)
   {
       printf("\nDigite uma Palavra: ");
       fgets(palavra, MAX, stdin);
       
       for (int j = 0; palavra[j] != '\0'; j++) 
       {  
          if (isalnum(palavra[j])) 
          {  
            printf("\nPosicao %d: [%c]", j, palavra[j]);
          }
       }
   }
   // getchar();
 }

 void metodo10(void) {
   // Identificar
   printf("\n%s\n", "\n\tMetodo420");
   char palavra [MAX];

   cadeias_alfanumericos(palavra);

   // Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
 }// fim metodo 10 ( )

/**
  * Metodo11.
  */

 void contar_alfanumericos (char *str)
 {
    int cont = 0;

    while (*str != '\0') 
    {
        if(isalnum(*str) || isspace(*str))
        {
            printf("\nPosicao %d: [%c]", cont, *str);
            str++;
            cont ++;
        }
    }

    
    printf("\nNumero de alfanumericos:[%d]", cont);
    getchar();
 }

 void metodo11 ( void )
 {
  // identificar
   printf ( "\n%s\n", "\n\tMetodo04E1" );
   char palavra[MAX];
   printf("\nDigite uma Palavra: ");
   fgets(palavra, MAX, stdin);
     
   contar_alfanumericos (palavra);  
  // encerrar
   printf ( "\n%s\n", "Apertar ENTER para continuar." );
   getchar( );
 
 } // fim metodo11 ( )

 /**
  * Metodo12.
  */

 void calcular_tamanho (char *str, char *strAux)
 {
    int cont = 0, cont_1 = 0;
    while(*str != '\0')
    {
        str++;
        cont ++;
    }
    while(*strAux != '\0')
    {
        strAux++;
        cont_1++;
    }
    if(cont > cont_1)
    {
        printf("\nA primeira cadeia e maior que a segunda");
    }
    else if (cont_1 > cont)
    {
        printf("\nA segunda cadeia e maior que a primeira");
    }
    else 
    {
        printf("\nAs duas cadeias sao iguais");
    }
    
 }

 void metodo12(void)
 {
   // identificar
     printf("\n%s\n", "\n\tMetodo04E2");

     char palavra[MAX], palavra_1[MAX];
     printf("\nDigite a primeira palavra: ");
     fgets(palavra, MAX, stdin);
     printf("\nDigite a segunda palavra: ");
     fgets(palavra_1, MAX, stdin);

     calcular_tamanho(palavra, palavra_1);
     
   // encerrar
     printf("\n%s\n", "Apertar ENTER para continuar.");
     getchar();

 }// fim metodo12

// identificar
 void menuOpcoes ( void ) 
 {
   printf ( "\n" );             // para saltar linha
   printf ( "%s\n", "Exercicio04 - v.0.0 - 10/03/2025"       );
   printf ( "%s\n", "Matricula: 842527 Nome: Gabriel Ferreira Pereira" );

// mostrar opcoes
   printf ( "%s\n", "Opcoes:   "     );
   printf ( "%s\n", " 0 - parar"     );
   printf ( "%s\n", " 1 - metodo 0411" );
   printf ( "%s\n", " 2 - metodo 0412" );
   printf ( "%s\n", " 3 - metodo 0413" );
   printf ( "%s\n", " 4 - metodo 0414" );
   printf ( "%s\n", " 5 - metodo 0415" );
   printf ( "%s\n", " 6 - metodo 0416" );
   printf ( "%s\n", " 7 - metodo 0417" );
   printf ( "%s\n", " 8 - metodo 0418" );
   printf ( "%s\n", " 9 - metodo 0419" );
   printf ( "%s\n", " 10- metodo 0420" );
   printf ( "%s\n", " 11- metodo 04E1" );
   printf ( "%s\n", " 12- metodo 04E2" );
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