/**
  * ------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Trabalho pratico: R01
  *
  * Objetivo:
  * Modelo de programa para a disciplina AED I
  * Sugestao para montar um trabalho pratico
  *
  * Autor:   Matricula: 842527  Nome: Gabriel Ferreira Pereira
  * Versao:  1.0                Data: 05/05/2025
  *
  * Dados:
  * - opcao de execucao escolhida pelo usuario
  *
  * Resultados:
  * - execucao de um teste de cada vez a escolha do usuario
  *
  * Condicoes:
  * - so' aceitara' as opcoes oferecidas.
  *
  * Arquivos:
  *
  * - R01.c
  * - R01_00     ( no Linux   )
  * - R01_00.exe ( no Windows )
  *
  * Forma de compilacao:
  * - acionar o compilador no modo console 
  *   (terminal/janela de comandos):
  *
  *   Linux  : gcc -o ./R01 ./R01.c -lm
  *   Windows: gcc -o   R01   R01.c
  *
  * Forma de uso:
  * - acionar o programa   no modo console
  *   (terminal/janela de comandos):
  *
  *   Linux  :  ./R01
  *   Windows:    R01
  *
  * Referencias:
  * - Exemplos mostrados em sala de aula
  * - Apostila: Fundamentos de Programacao - Notas de aulas
  *
  */

// -------------------------- classes nativas
//                            ou auxiliares

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX 100
// -------------------------- definicao de classe

/**
  * Modelo para definir exemplo de um programa.
  * Obs.: E' recomendado ter o nome do programa
  *       sem espacos em branco, acentos ou cedilha.
  */

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

// -------------------------- definicao de armazenadores globais

// -------------------------- definicao de prototipos

// -------------------------- definicao de metodos

/**
  * Metodo01.
  */

  int soma_divisores_pares(int valor) {
    int soma = 0;
    for (int i = 1; i <= valor; i++) 
    {
        if (valor % i == 0 && i % 2 == 0) 
        {
            soma++;
        }
    }
    return soma;
}

/**
 * Somar divisores ímpares de um número.
 */
int soma_divisores_impares(int valor) {
    int soma = 0;
    for (int i = 1; i <= valor; i++) 
    {
        if (valor % i == 0 && i % 2 != 0) 
        {
            soma++;
        }
    }
    return soma;
}

int verificaDivisores(int valor) {
    int pares = soma_divisores_pares(valor);
    int impares = soma_divisores_impares(valor);

    if (pares > impares) 
    {
        return 1;
    } else if (impares > pares) 
    {
        return -1;
    } else 
    {
        return 0;
    }
}

void metodo01 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo01" );
    int n = 0, x = 0, resultado = 0;

    printf("\nDigite o valor de n: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) 
    {
        printf("\n%d: ", i + 1);
        scanf("%d", &x);
        getchar();

        resultado = verificaDivisores(x);

        if (resultado == 1) {
            printf("\nMais divisores pares");
        } else if (resultado == -1) {
            printf("\nMais divisores impares\n");
        } else {
            printf("\nQuantidade igual de divisores pares e impares");
        }
    }

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo01 ( )

/**
  * Metodo02.
  */
 
bool Primo(int x) 
{
   if (x < 1) 
   {
      return false;
   }
   if (x == 1)
   {
      return true;
   }

   for (int i = 2; i <= sqrt(x); i++) 
   {
       if (x % i == 0) {
           return false;
       }
   }

   return true;
}
void metodo02 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo02" );
    int n = 0, x = 0;

    printf("\nDigite o valor de n: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) 
    {
      printf("\n%d: ", i + 1);
      scanf("%d", &x);
      getchar();

      if (Primo(x)) {
         printf("\n%d e primo\n", x);
      } else {
         printf("\n%d nao e primo", x);
      }
    }
    
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo02 ( )

/**
  * Metodo03.
  */

int testar_simbolo_logico(char c) 
{
   int resultado = 0;
   switch (c) {
       case '&':
       case '|':
       case '!':
           resultado = 1;
           break;
       default:
           break;
   }
   return resultado;
}

int testar_simbolo_aritmetico(char c) 
{
   int resultado = 0;
   switch (c) {
       case '+':
       case '-':
       case '*':
       case '/':
       case '%':
           resultado = 1;
           break;
       default:
           break;
   }
   return resultado;
}

int testar_simbolo_relacional(char c) 
{
   int resultado = 0;
   switch (c) {
       case '>':
       case '<':
       case '=':
           resultado = 1;
           break;
       default:
           break;
   }
   return resultado;
}

int testar_simbolo_separador(char c) 
{
   int resultado = 0;
   switch (c) {
       case ' ':
       case '.':
       case ',':
       case ';':
       case ':':
       case '_':
           resultado = 1;
           break;
       default:
           break;
   }
   return resultado;
}

void metodo03 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo03" );
    int tamanho = 0;
    char palavra [MAX];
    printf("\nDigite a cadeia de caracteres: ");
    fgets(palavra, MAX, stdin);
    getchar();

    tamanho = strlen(palavra);

    for (int i = 0; i < tamanho; i++)
    {
      char c = palavra[i];
      printf("\n'%c' -> ", c);

      if (testar_simbolo_logico(c)) {
          printf("Operador logico");
      } else if (testar_simbolo_aritmetico(c)) {
          printf("Operador aritmetico");
      } else if (testar_simbolo_relacional(c)) {
          printf("Operador relacional");
      } else if (testar_simbolo_separador(c)) {
          printf("Separador");
      } else {
          printf("Outro simbolo");
      }
    }
    getchar();
    
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo03 ( )

/**
  * Metodo04.
  */
void metodo04 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo04" );
    char palavra [MAX];
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo04 ( )

/**
  * Metodo05.
  */
void metodo05 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo05" );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

} // fim metodo05 ( )

/**
  * Metodo06.
  */
void metodo06 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo06" );
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
    printf ( "\n%s\n", "Metodo07" );
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
    printf ( "\n%s\n", "Metodo08" );
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
    printf ( "\n%s\n", "Metodo09" );
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
    printf ( "\n%s\n", "Metodo10" );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

} // fim metodo10 ( )


// -------------------------- definicao do metodo principal

int main ( void )
{
 // definir dados/resultados
    int opcao = 0;

 // repetir ate' desejar parar
    do
    {
     // identificar
        printf ( "\n" );             // para saltar linha
        printf ( "%s\n", "R01 - v.0.0 - 05/05/2025"       );
        printf ( "%s\n", "Matricula: 842527 Nome: Gabriel Ferreira Pereira" );

     // mostrar opcoes
        printf ( "%s\n", "Opcoes:"         );
        printf ( "%s\n", " 0 - parar"      );
        printf ( "%s\n", " 1 - metodo 01   2 - metodo 02" );
        printf ( "%s\n", " 3 - metodo 03   4 - metodo 04" );
        printf ( "%s\n", " 5 - metodo 05   6 - metodo 06" );
        printf ( "%s\n", " 7 - metodo 07   8 - metodo 08" );
        printf ( "%s\n", " 9 - metodo 09  10 - metodo 10" );
        printf ( "%s\n", "" );        // para saltar linha

     // ler opcao
        printf ( "%s", "Qual a sua opcao? " );
        scanf  ( "%d", &opcao ); getchar ( );
        printf ( "%d",  opcao );

     // escolher acao
        switch ( opcao )
        {
           case  0:               break;
           case  1: metodo01 ( ); break;
           case  2: metodo02 ( ); break;
           case  3: metodo03 ( ); break;
           case  4: metodo04 ( ); break;
           case  5: metodo05 ( ); break;
           case  6: metodo06 ( ); break;
           case  7: metodo07 ( ); break;
           case  8: metodo08 ( ); break;
           case  9: metodo09 ( ); break;
           case 10: metodo10 ( ); break;
           default:
                    printf ( "\n%s\n\n", "ERRO: Opcao invalida." );
                    break;
        } // fim escolher
    }
    while ( opcao != 0 );

 // encerrar execucao
    printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
    getchar( );

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
