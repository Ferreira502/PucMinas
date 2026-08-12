/*
 Exercicio01 - v0.0. - 11 / 02 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exercicio01 exercicio01.c
 Windows: gcc -o exercicio01 exercicio01.c
 Para executar em terminal (janela de comandos):
 Linux : ./exercicio01
 Windows: exercicio01
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define PI 3.14

// -------------------------- definicao de classe

/**
  * Metodo01.
  */
void metodo01 ( void )
{
 // identificar
    printf ( "\n%s\n", "\n\tMetodo0111" );
    double lado1 = 0.0, lado2 = 0.0, area = 0.0;
    
    printf ("\nDigite o valor do lado do quadrado: ");
    scanf("%lf", &lado1);

   area = lado1 * 2;

   printf("\nArea do quadrado digitado: %.2lf", area);

   area *= 3;

   printf("\nArea do quadrado digitado 3 vezes maior: %.2lf ", area);
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
    printf ( "\n%s\n", "\n\tMetodo0112" );
    double lado1 = 0.0, lado2 = 0.0, area = 0.0, perimetro = 0.0;
    
    printf ("\nDigite o valor do primeiro lado do quadrado: ");
    scanf("%lf", &lado1);

    area = ( ( lado1 * 2 ) / 2 );
    perimetro = lado1 * 2;

    printf("\nArea do quadrado com a metade do lado: %.2lf ", area);
    printf("\nPerimetro do quadrado com a metade do lado: %.2lf ", perimetro);
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
    printf ( "\n%s\n", "\n\tMetodo0113" );
    double lado1 = 0.0, lado2 = 0.0, area = 0.0;
    printf("\nDigite o Primeiro Lado do retangulo: ");
    scanf("%lf",&lado1);
    printf("\nDigite o Segundo Lado do retangulo: ");
    scanf("%lf",&lado2);

    area = ( (lado1 * 2) * (lado2 * 2) ) ;

    printf("\nArea do retangulo com valores aumentados em duas vezes cada: %.2lf", area);
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
    printf ( "\n%s\n", "\n\tMetodo0114" );
    double lado1 = 0.0, lado2 = 0.0, area = 0.0, perimetro = 0.0 ;
    printf("\nDigite o Primeiro Lado do retangulo: ");
    scanf("%lf",&lado1);
    printf("\nDigite o Segundo Lado do retangulo: ");
    scanf("%lf",&lado2);

    area = ( (lado1 / 4) * (lado2 / 4) );

    printf("\nArea do retangulo com um quarto dos tamanhos dos lados: %.2lf", area);
    getchar( );

    perimetro = ( (lado1 / 2 ) + (lado2 / 2 ) );
    
    printf("\nPerimetro do retangulo com um quarto dos tamanhos dos lados: %.2lf", perimetro);
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
    printf ( "\n%s\n", "\n\tMetodo0115" );
    double base = 0.0, altura = 0.0, area = 0.0;

   printf("\nDigite o valor da base: ", base);
   scanf("%lf", &base);
   printf("\nDigite o valor da altura: ", altura);
   scanf("%lf", &altura);

   area = (base * ( altura * 2)) / 2;

   printf("\nArea de um triangulo com o dobro da altura do mesmo: %2.lf", area);
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
    printf ( "\n%s\n", "\n\tMetodo0116" );
    double lado1 = 0.0, area = 0.0, perimetro = 0.0;
    
    printf ("\nDigite o valor do lado do quadrado: ");
    scanf("%lf", &lado1);
    
    area = ( ( lado1 * sqrt(3) ) / 4 ) / 3;
    perimetro = ( lado1 * 3 ) / 3;

    printf ("\nArea do triangulo com um terco do tamanho do lado: %2.lf", area);
    printf ("\nPerimetro do triangulo com um terco do tamanho do lado: %2.lf", perimetro);
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
    printf ( "\n%s\n", "\n\tMetodo0117" );
    double lado = 0.0, volume = 0.0;
    
    printf ("\nDigite o valor do lado do quadrado: ");
    scanf("%lf", &lado);
    
    volume =  ( pow(lado, 3) ) * 4;

    printf ("\nVolume do paralelepipedo com quatro vezes a medida do lado: %2.lf", volume);
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
    printf ( "\n%s\n", "\n\tMetodo0118" );
    double comprimento = 0.0, largura = 0.0, altura = 0.0, volume = 0.0;
    
    printf ("\nDigite o valor do comprimento: ");
    scanf("%lf", &comprimento);
    printf ("\nDigite o valor da altura: ");
    scanf("%lf", &altura);
    printf ("\nDigite o valor da largura: ");
    scanf("%lf", &largura);
    
    volume =  ( comprimento * altura * largura ) * 5; 

    printf ("\nVolume do paralelepipedo com cinco vezes a medida do lado: %2.lf", volume);
    getchar( );
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
    double raio = 0.0, area = 0.0;
    
    printf ("\nDigite o valor do raio: ");
    scanf("%lf", &raio);

    raio *= 4;  
    area = ( PI * ( raio * raio) ) / 2; 

    printf ("\nArea do semicirculo com quatro vezes a medida do raio: %2.lf", area);
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
    printf ( "\n%s\n", "\n\tMetodo120" );
    double raio = 0.0, volume = 0.0;
    
    printf ("\nDigite o valor do raio: ");
    scanf("%lf", &raio);

    raio *= 0.625;  
    volume = ( pow(raio, 3) * PI * 1.333 ); 

    printf ("\nVolume de uma esfera com cinco oitavos do raio: %2.lf", volume);
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
    printf ( "\n%s\n", "\n\tMetodo01E1" );
    double area = 0.0, raio = 0.0;
    
    printf ("\nDigite o valor do area: ");
    scanf("%lf", &area);
    
    area *= 7;
    raio = sqrt(area / PI); 

    printf ("\nRaio para sete vezes essa area: %2.lf", raio);
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
    printf ( "\n%s\n", "\n\tMetodo01E2" );
    double volume, novo_volume, raio, area_superficie;
    double FRACAO_VOLUME = 3.0 / 5.0;

    printf("Digite o valor do volume da esfera: ");
    scanf("%lf", &volume);

    novo_volume = FRACAO_VOLUME * volume;

    raio = cbrt((3.0 * novo_volume) / (4.0 * PI));

    area_superficie = 4.0 * PI * pow(raio, 2);

    printf("O raio correspondente a tres quintos do volume e: %.2lf\n", raio);
    printf("A area da superficie da esfera com esse raio e: %.2lf\n", area_superficie);
    getchar( );
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