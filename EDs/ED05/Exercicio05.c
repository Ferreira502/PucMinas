/*
 Exercicio04 - v0.0. - 12 / 03 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exercicio05 exercicio05.c
 Windows: gcc -o exercicio05 exercicio05.c
 Para executar em terminal (janela de comandos):
 Linux : ./exercicio05
 Windows: exercicio05
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

int multiplos_de_3(int n)
{
   int num = 3;

   for (int i = 0; i <= n; i++)
   {
       printf("\n %d", num);
       num += 3;
   } 
    getchar();

}

void metodo01(void) 
{
// Identificar
   printf("\n%s\n", "\n\tMetodo0511");
   int x = 0;
   printf("\nDigite a quantidade de numeros: ");
   scanf("%d", &x);
   multiplos_de_3(x);
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo01 ( )

/**
  * Metodo02.
  */
void multiplos_de_3e5(int n)
{
   int num = 15;
   printf("\nDigite a quantidade de numeros: ");
   scanf("%d", &n);

   for (int i = 0; i <= n; i++)
   {
       printf("\n %d", num);
       num += 15;
   } 
    getchar();
}
void metodo02 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0512");
   int x = 0;
   multiplos_de_3e5(x);

// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo02 ( )

/**
  * Metodo03.
  */

void multiplos_de_4_decr(int n)
{
   int num = 0;
   printf("\nDigite a quantidade de numeros: ");
   scanf("%d", &n);

   for (int i = n-1; i >= 0; i--)
    {
        num = (int)pow(4, i);
        printf("\n%d", num);
    }
    getchar();
}

void metodo03 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0513");
   int x = 0;
   multiplos_de_4_decr(x);
    
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo03 ( )

/**
  * Metodo04.
  */

void multiplos_de_3_inverso(int n)
{
   int num = 3;
   printf("\nDigite a quantidade de numeros: ");
   scanf("%d", &n);

   for (int i = 0; i <= n; i++)
   {
       printf("\n 1/%d", num);
       num += 3;
   } 
    getchar();
}

void metodo04 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0514");
   int x = 0;
   multiplos_de_3_inverso(x);
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo04 ( )

/**
  * Metodo05.
  */

void potencias_crescente(double x, int n)
{
    int num = 0, expoente = 2;
    printf("Digite a Quantidade de numeros a ser gerado: ");
    scanf("%d", &n); getchar();
    printf("Digite um valor real para a base: ");
    scanf("%lf", &x); getchar();

    for (int i = 0; i <= n; i++ )
    {
        if ( i == 0)
        {
            printf("\n1");
            i++;
        }
        else if(i != 0)
        {
            num = pow(x,expoente);
            expoente = expoente + 2;
            printf("\n1/%d", num);
        }
    }
    getchar();
}

void metodo05 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0515");
   double a = 0.0;
   int b = 0;
   potencias_crescente(a,b);

  
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo05 ( )

/**
  * Metodo06.
  */

void multiplos_de_3_diferente_de_4(int n)
{
    int num = 0, i = 0;
    n = n + 1;
    
    while (i <= n)
    {
        if (num % 4 != 0)
        {
            printf("\n%d", num);
        }
        
        num += 3;
        i++;
    }
    printf("\n");
    getchar();
}

void metodo06(void)
{
   // Identificar
   printf("\n%s\n", "\n\tMetodo0516");
   int x = 0;
    
   printf("\nDigite a quantidade de numeros a ser gerados: ");
   scanf("%d", &x);

   multiplos_de_3_diferente_de_4(x);

   // Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo06()

/**
  * Metodo07.
  */

void multiplos_de_4_diferente_de_5(int n)
{
    int num = 0, i = 0;
    n = n + 1;
    
    while (i <= n)
    {
        if (num % 5 != 0)
        {
            printf("\n1/%d", num);
        }
        
        num += 4;
        i++;
    }
   printf("\n");
   getchar();
}


void metodo07 ( void )
{
// Identificar
   printf("\n%s\n", "\n\tMetodo0517");
   int x = 0;
    
   printf("\nDigite a quantidade de numeros a ser gerados: ");
   scanf("%d", &x);

   multiplos_de_4_diferente_de_5(x);
// Encerrar
   printf("\n\n%s\n", "Apertar ENTER para continuar.");
   getchar();

} // fim metodo07 ( )

/**
  * Metodo08.
  */
int calcularSoma(int n) {
   int soma = 0, valor = 5, incremento = 1;

   for (int i = 0; i < n; i++) {
      soma += valor;
      valor += incremento;
      incremento++;
   }

   return soma;
}

void metodo08(void) {
// Identificar
   printf("\n%s\n", "\n\tMetodo08");
   int n;

   printf("Digite a quantidade de numeros a somar: ");
   scanf("%d", &n);

   if (n > 0) {
      printf("Soma para n = %d: %d\n", n, calcularSoma(n));
      getchar();
   } else {
      printf("O valor deve ser maior que zero\n");
   }

// Encerrar
   printf("\n\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo08

/**
  * Metodo09.
  */

  int calcularQuadrado(int n) {
   int soma = 0, valor = 25, incremento = 12;

   for (int i = 0; i < n; i++) {
      soma += valor;
      valor += incremento;
      incremento++;
   }

   return soma;
}

 void metodo09 ( void )
 {
 // Identificar
   printf("\n%s\n", "\n\tMetodo0519");
   int n;

   printf("Digite a quantidade de numeros a somar: ");
   scanf("%d", &n);

   if (n > 0) {
      printf("Soma para n = %d: %d\n", n, calcularQuadrado(n));
      getchar();
   } else {
      printf("O valor deve ser maior que zero\n");
   }
// Encerrar
   printf("\n\n%s\n", "Apertar ENTER para continuar.");
   getchar();

 } // fim metodo09 ( )

/**
  * Metodo10.
  */

double calcularSomaInversos(int n) {
   double soma = 0.0;
   int valor = 3;
   
   printf("\nValores: ");
   
   for (int i = 0; i < n; i++) {
       printf("1/%d ", valor);
       soma += 1.0 / valor;
       valor += (i + 1);
   }
   
   return soma;
}

void metodo10() 
{
// Identificar
   printf("\n%s\n", "\n\tMetodo520");
   int n = 0;

   printf("Digite a quantidade de numeros a somar: ");
   scanf("%d", &n);

   if (n > 0) {
      double soma = calcularSomaInversos(n);
       printf("\nSoma dos inversos: %.3lf\n", soma);
   } else {
       printf("O valor deve ser maior que zero\n");
   }

// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo10 ( )

/**
  * Metodo11.
  */

double fatorial(int n) {
   if (n == 0 || n == 1) {
      return 1;
   }
   return n * fatorial(n - 1);
}

 void metodo11 ( void )
 {
  // identificar
   printf ( "\n%s\n", "\n\tMetodo05E1" );
   
   int num;
    
   printf("Digite um numero para calcular o fatorial: ");
   scanf("%d", &num);
   
   if (num < 0) {
      printf("O fatorial nao esta definido para numeros negativos\n");
      getchar();
   } else {
      printf("Fatorial de %d e %.2lf\n", num, fatorial(num));
      getchar();
   }

  // encerrar
   printf ( "\n%s\n", "Apertar ENTER para continuar." );
   getchar( );
 
 } // fim metodo11 ( )

 
/**
  * Metodo12.
  */
 double calcularF(int n) {
   double resultado = 1.0;
   int numerador = 2;
   int denominador = 3;

   for (int i = 0; i < n; i++) {
       resultado *= (1 + (double)numerador / fatorial((double)denominador));
       numerador += 2;
       denominador += 2;
   }
   
   return resultado;
}

void metodo12(void) {
// Identificar
   printf("\n%s\n", "\n\tMetodo05E2");
   int n;

   printf("Digite a quantidade de termos (n): ");
   scanf("%d", &n);

   if (n <= 0) {
       printf("O valor de n deve ser maior que zero.\n");
   } else {
       double resultado = calcularF(n);
       printf("Resultado de f(%d) = %.6lf\n", n, resultado);
   }
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
}

// identificar
 void menuOpcoes ( void ) 
 {
   printf ( "\n" );             // para saltar linha
   printf ( "%s\n", "Exercicio05 - v.0.0 - 12/03/2025"       );
   printf ( "%s\n", "Matricula: 842527 Nome: Gabriel Ferreira Pereira" );

// mostrar opcoes
   printf ( "%s\n", "Opcoes:   "     );
   printf ( "%s\n", " 0 - parar"     );
   printf ( "%s\n", " 1 - metodo 0511" );
   printf ( "%s\n", " 2 - metodo 0512" );
   printf ( "%s\n", " 3 - metodo 0513" );
   printf ( "%s\n", " 4 - metodo 0514" );
   printf ( "%s\n", " 5 - metodo 0515" );
   printf ( "%s\n", " 6 - metodo 0516" );
   printf ( "%s\n", " 7 - metodo 0517" );
   printf ( "%s\n", " 8 - metodo 0518" );
   printf ( "%s\n", " 9 - metodo 0519" );
   printf ( "%s\n", " 10- metodo 0520" );
   printf ( "%s\n", " 11- metodo 05E1" );
   printf ( "%s\n", " 12- metodo 05E2" );
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