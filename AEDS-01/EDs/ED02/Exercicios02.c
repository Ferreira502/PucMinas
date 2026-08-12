/*
 Exercicio02 - v0.0. - 13 / 02 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exercicio02 exercicio02.c
 Windows: gcc -o exercicio02 exercicio02.c
 Para executar em terminal (janela de comandos):
 Linux : ./exercicio02
 Windows: exercicio02
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// -------------------------- definicao de classe

/**
  * Metodo01.
  */
void metodo01 ( void )
{
 // identificar
    printf ( "\n%s\n", "\n\tMetodo0211" );
    int numero = 0;

    printf("\nDigite um numero: ");
    scanf("%d", &numero);

    if ( numero % 2 == 0 || numero == 0 )
    {
        printf("\n(%d) e par", numero);
    } else 
    {
        printf("\n(%d) e impar", numero);
    }
    
    if (numero >= 0)
    {
        printf("\n(%d) e positivo", numero);
    } else 
    {
        printf("\n(%d) e negativo", numero);
    }
    getchar( );
    
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo01 ( )

/**
  * Metodo02.
  */
void metodo02 ( void )
{
 // identificar
    printf ( "\n%s\n", "\n\tMetodo0212" );
    int numero = 0;

    printf("\nDigite um numero: ");
    scanf("%d", &numero);

    if ( numero % 2 == 0 || numero == 0 )
    {
        printf("\n(%d) e par", numero);
    } else 
    {
        printf("\n(%d) e impar", numero);
    }

    if (numero <= -25)
    {
        printf("\n(%d) e menor que 25", numero);
    } else if (numero >= 25)
    {
        printf("\n(%d) e maior que 25", numero);
    } else 
    {
        printf("\n(%d) entre -25 e 25", numero);
    }
    getchar( );
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo02 ( )

/**
  * Metodo03.
  */
void metodo03 ( void )
{   
 // identificar
    printf ( "\n%s\n", "\n\tMetodo0213" );
    int numero = 0;

    printf("\nDigite um numero: ");
    scanf("%d", &numero);

    if (numero > 20 && numero < 55)
    {
        printf("\n(%d) entre 20 e 55", numero);
    }
    else {
        printf("\n(%d) nao esta entre 20 e 55", numero);
    }
    getchar( );

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
    printf ( "\n%s\n", "\n\tMetodo0214" );
    int numero = 0;

    printf("\nDigite um numero: ");
    scanf("%d", &numero);

    if (numero >= 20 && numero <= 55)
    {
        printf("\n(%d) entre 20 e 55", numero);
    }
    else {
        printf("\n(%d) nao esta entre 20 e 55", numero);
    }
    getchar( );
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
    printf ( "\n%s\n", "\n\tMetodo0215" );
    int numero = 0;

    printf("\nDigite um numero: ");
    scanf("%d", &numero);

    if (numero >= 10 && numero <= 30)
    {
        printf("\n(%d) pertence no intervalo entre [10:30]", numero);
    }
    else if (numero > 20 && numero < 40)
    {
        printf("\n(%d) pertence no intervalo entre (20:40)", numero);
    }
    else {
        printf("\n(%d) nao pertence a nenhum intervalo", numero);
    }
    getchar( );
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
    printf ( "\n%s\n", "\n\tMetodo0216" );
    int numero = 0, numero_1;

    printf("\nDigite dois numeros: ");
    scanf("%d%d", &numero, &numero_1);
    
    if (numero % 2 == 0 || numero == 0)
    {
       printf("\n(%d) e par", numero);
    }
    else 
    {
       printf("\n(%d) e impar", numero);
    }
    
    if (numero_1 % 2 == 0 || numero_1 == 0)
    {
        printf("\n(%d) e par", numero_1);
    }
    else 
    {
        printf("\n(%d) e impar", numero_1);
    }
    getchar( );

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
    printf ( "\n%s\n", "\n\tMetodo0217" );
    int numero = 0, numero_1;

    printf("\nDigite dois numeros: ");
    scanf("%d%d", &numero, &numero_1);
    
    if ( ( numero % 2 == 0 || numero == 0 )  && numero >= 0 )
    {
       printf("\n(%d) e par positivo ", numero);
    }
    else if ( ( numero % 2 == 0 || numero == 0 )  && numero < 0 )
    {
        printf("\n(%d) e par negativo ", numero);
    }
    else if ( ( numero % 2 != 0 ) && numero >= 0)
    {
       printf("\n(%d) e impar positivo", numero);
    }
    else if ( ( numero % 2 != 0 ) && numero < 0)
    {
        printf("\n(%d) e impar negativo", numero);
    }
    
    if ( ( numero_1 % 2 == 0 || numero_1 == 0 )  && numero_1 >= 0 )
    {
       printf("\n(%d) e par positivo ", numero_1);
    }
    else if ( ( numero_1 % 2 == 0 || numero_1 == 0 )  && numero_1 < 0 )
    {
        printf("\n(%d) e par negativo ", numero_1);
    }
    else if ( ( numero_1 % 2 != 0 ) && numero_1 >= 0)
    {
       printf("\n(%d) e impar positivo", numero_1);
    }
    else if ( ( numero_1 % 2 != 0 ) && numero_1 < 0)
    {
        printf("\n(%d) e impar negativo", numero_1);
    }
    getchar( );

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
    printf("\n%s\n", "\n\tMetodo0218");

    double numero = 0.0, numero_1 = 0.0;
    double numero_novo = 0.0;

    printf("\nDigite os dois numeros: ");
    scanf("%lf%lf", &numero, &numero_1);

    numero_novo = numero_1 / 4;

    if (numero > numero_novo) {
        printf("\n(%.2lf) e maior que 1/4 de (%.2lf)\n", numero, numero_1);
    } else if (numero < numero_novo) {
        printf("\n(%.2lf) e menor que 1/4 de (%.2lf)\n", numero, numero_1);
    } else {
        printf("\n(%.2lf) e igual a 1/4 de (%.2lf)\n", numero, numero_1);
    }
    getchar();
    
    // Encerrar
    printf("\n%s\n", "Apertar ENTER para continuar.");
    getchar();

} // fim metodo08 ( )

/**
  * Metodo09.
  */
void metodo09 ( void )
{
 // identificar
    printf ( "\n%s\n", "\n\tMetodo0219" );
    double numero = 0.0, numero_1 = 0.0, numero_2 = 0.0;
    printf("\nDigite os valores dos 3 numeros: ");
    scanf("%lf%lf%lf", &numero,&numero_1,&numero_2);

    if ( numero != numero_2 )
    {
      if ( numero_1 < numero || numero_1 < numero_2 )
      {
        printf("\n (%.2lf) esta entre os outros numeros", numero_1);
      }
      else 
      {
        printf("\n (%.2lf) nao esta entre os outros numeros", numero_1);
      }
    }
    else 
    {
      printf("\nOs numeros nao sao diferentes entre si");
    }
    getchar( );
 
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
    printf ( "\n%s\n", "\n\tMetodo0220" );
    double numero = 0.0, numero_1 = 0.0, numero_2 = 0.0;
    printf("\nDigite os valores dos 3 numeros: ");
    scanf("%lf%lf%lf", &numero,&numero_1,&numero_2);

    if ( numero != numero_2 )
    {
      if ((numero_1 > numero && numero_1 < numero_2) || (numero_1 > numero_2 && numero_1 < numero))
      {
        printf("\n (%.2lf) esta entre os outros numeros", numero_1);
      }
      else 
      {
        printf("\n (%.2lf) nao esta entre os outros numeros", numero_1);
      }
    }
    else 
    {
      printf("\nOs numeros nao sao diferentes entre si");
    }
    getchar( );
 
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
    printf ( "\n%s\n", "\n\tMetodo02E1" );
    char letra, letra_1, letra_2;
    
    printf("\nDigite as 3 letras separadas por espaco: ");
    scanf(" %c %c %c", &letra, &letra_1, &letra_2);
    
    if (letra == letra_1 || letra == letra_2) 
    {
      printf("\nO primeiro caractere (%c) e igual a um dos outros", letra);
    } 
    else if ((letra > letra_1 && letra < letra_2) || (letra > letra_2 && letra < letra_1)) 
    {
      printf("\nO primeiro caractere (%c) esta entre os outros dois", letra);
    } 
    else 
    {
      printf("\nO primeiro caractere (%c) nao esta entre os outros dois", letra);
    }

    getchar( );

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
    printf ( "\n%s\n", "\n\tMetodo02E2" );
    char letra, letra_1, letra_2;
    
    printf("\nDigite as 3 letras separadas por espaco: ");
    scanf(" %c %c %c", &letra, &letra_1, &letra_2);
    
    if (letra == letra_1 || letra == letra_2) 
    {
      printf("\nO primeiro caractere (%c) e igual a um dos outros", letra);
    } 
    else if ((letra > letra_1 && letra < letra_2) || (letra > letra_2 && letra < letra_1)) 
    {
      printf("\nO primeiro caractere (%c) esta entre os outros dois", letra);
    } 
    else 
    {
      printf("\nO primeiro caractere (%c) esta fora do intervalo definido pelos outros dois", letra);
    }

    getchar( );
    
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

} // fim metodo12 ( )

// identificar
menuOpcoes ( void ) 
{
   printf ( "\n" );             // para saltar linha
   printf ( "%s\n", "Exercicio01 - v.0.0 - 13/02/2025"       );
   printf ( "%s\n", "Matricula: 842527 Nome: Gabriel Ferreira Pereira" );

// mostrar opcoes
   printf ( "%s\n", "Opcoes:   "     );
   printf ( "%s\n", " 0 - parar"     );
   printf ( "%s\n", " 1 - metodo 0211" );
   printf ( "%s\n", " 2 - metodo 0212" );
   printf ( "%s\n", " 3 - metodo 0213" );
   printf ( "%s\n", " 4 - metodo 0214" );
   printf ( "%s\n", " 5 - metodo 0215" );
   printf ( "%s\n", " 6 - metodo 0216" );
   printf ( "%s\n", " 7 - metodo 0217" );
   printf ( "%s\n", " 8 - metodo 0218" );
   printf ( "%s\n", " 9 - metodo 0219" );
   printf ( "%s\n", " 10- metodo 0220" );
   printf ( "%s\n", " 11- metodo 02E1" );
   printf ( "%s\n", " 12- metodo 02E2" );
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