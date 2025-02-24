/*
 Exemplo0300 - v0.0. - 40 / 02 / 2025
 Author: Gabriel Ferreira Pereira
*/
// dependencias
#include "io.h" // para definicoes proprias
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define STR_SIZE 100
#define STR_EMPTY 0

/** 
   Method_01 - Repeticao para ler certa quantidade de valores. 
 */ 
void method_01 ( ) 
{ 
 // definir dado 
    int quantidade = 0; 
    int valor            = 0; 
    int controle      = 0; 
 
 // identificar 
    IO_id ( "Method 01 - v0.0" ); 
 
 // ler do teclado 
    quantidade = IO_readint ( "Entrar com uma quantidade: " ); 
 
 // repetir para a quantidade de vezes informada 
    controle = 1; 
    while ( controle <= quantidade ) 
    { 
     // ler valor do teclado 
        valor = IO_readint ( IO_concat (  
                                          IO_concat ( "", IO_toString_d ( controle ) ), 
                                          ": "  ) ); 
     // mostrar valor lido 
        printf ( "\n%s%d", "valor = ", valor ); 
     // passar ao proximo valor 
        controle = controle + 1; 
    } // end while 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_01 ( ) 

/** 
   Funcao para determinar se valor inteiro e' positivo. 
   @return true, se positivo; false, caso contrario 
   @param  x - valor a ser testado 
 */ 
bool positive ( int x ) 
{ 
 // definir dado local 
    bool result = false; 
 // testar a condicao 
    if ( x > 0 ) 
    { 
       result = true; 
    } // end if 
    return ( result ); 
} // end positive ( ) 
 
/** 
   Method_02 - Ler valores e contar positivos. 
 */ 
void method_02 ( ) 
{ 
 // definir dado 
    int quantidade = 0; 
    int valor            = 0; 
    int controle      = 0; 
    int contador     = 0; 
 
 // identificar 
    IO_id ( "Method02 - v0.0" ); 
 
 // ler do teclado 
    quantidade = IO_readint ( "Entrar com uma quantidade: " ); 
 
 // repetir para a quantidade de vezes informada 
    controle = 1; 
    while ( controle <= quantidade ) 
    { 
     // ler valor do teclado 
        valor = IO_readint ( IO_concat ( 
                                          IO_concat ( "", IO_toString_d ( controle ) ), 
                                          ": "  ) ); 
     // testar e contar se valor for positivo 
        if ( positive ( valor ) ) 
        { 
           contador = contador + 1; 
        } // end if 
 
     // passar ao proximo valor 
        controle = controle + 1; 
    } // end while 
 // mostrar a quantidade de valores positivos 
    IO_printf ( "%s%d\n", "Positivos = ", contador ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_02 ( ) 

/** 
   Funcao para determinar se valor inteiro pertence a intervalo aberto. 
   @return true, se pertencer; false, caso contrario 
   @param  x             - valor a ser testado 
   @param  inferior   - limite inferior   do intervalo 
   @param  superior - limite superior do intervalo 
 */ 
bool belongsTo ( int x, int inferior, int superior ) 
{ 
 // definir dado local 
    bool result = false; 
 // testar a condicao 
    if ( inferior < x && x < superior ) 
    { 
       result = true; 
    } // end if 
   return ( result ); 
} // end belongsTo ( ) 
 
/** 
   Method_03 - Ler valores e contar positivos menores que 100. 
 */ 
void method_03 ( ) 
{ 
 // definir dado 
    int quantidade = 0; 
    int valor            = 0; 
    int controle      = 0; 
    int contador     = 0; 
 
 // identificar 
    IO_id ( "Method_03 - v0.0" ); 
 
 // ler do teclado 
    quantidade = IO_readint ( "Entrar com uma quantidade: " ); 
 
 // repetir para a quantidade de vezes informada 
    controle = 1; 
    while ( controle <= quantidade ) 
    { 
     // ler valor do teclado 
        valor = IO_readint ( IO_concat ( 
                                          IO_concat ( "", IO_toString_d ( controle ) ), 
                                          ": "  ) ); 
     // testar e contar se valor for positivo 
        if ( belongsTo ( valor, 0, 100 ) ) 
        { 
           contador = contador + 1; 
        } // end if 
     // passar ao proximo valor 
        controle = controle + 1; 
    } // end while 
 // mostrar a quantidade de valores positivos 
    IO_printf ( "%s%d\n", "Positivos menores que 100 = ", contador ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_03 ( )

/** 
   Funcao para determinar se valor inteiro e' par. 
   @return true, se par; false, caso contrario 
   @param  x - valor a ser testado 
 */ 
bool even ( int x ) 
{ 
 // definir dado local 
    bool result = false; 
 // testar a condicao ( resto inteiro (%) da divisao por 2 igual a zero ) 
    if ( x % 2 == 0 ) 
    { 
       result = true; 
    } // end if 
   return ( result ); 
} // end even ( ) 
 
/** 
   Method_04 - Ler valores e contar positivos menores que 100 e pares. 
 */ 
void method_04 ( ) 
{ 
 // definir dado 
    int quantidade = 0; 
    int valor            = 0; 
    int controle      = 0; 
    int contador     = 0; 
 
 // identificar 
    IO_id ( "Method_04 - v0.0" ); 
 
 // ler do teclado 
    quantidade = IO_readint ( "Entrar com uma quantidade: " ); 
 
 
 
 // repetir para a quantidade de vezes informada 
    controle = 1; 
    while ( controle <= quantidade ) 
    { 
     // ler valor do teclado 
        valor = IO_readint ( IO_concat ( 
                                          IO_concat ( "", IO_toString_d ( controle ) ), 
                                          ": "  ) ); 
     // testar e contar se valor for positivo menor que 100 e par 
        if ( belongsTo ( valor, 0, 100 ) && even ( valor ) ) 
        { 
           contador = contador + 1; 
        } // end if 
 
     // passar ao proximo valor 
        controle = controle + 1; 
    } // end while 
 // mostrar a quantidade de valores positivos 
    IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_04 ( )

/** 
   Method05 - Ler valores e contar positivos menores que 100 e pares (alternativo). 
 */ 
void method05 ( ) 
{ 
 // definir dado 
    int  quantidade = 0; 
    int  valor            = 0; 
    int  controle       = 0; 
    int  contador      = 0; 
    bool ok               = false; 
 
 // identificar 
    IO_id ( "EXEMPLO0405 - Method05 - v0.0" ); 
 
 
 
 // ler do teclado 
    quantidade = IO_readint ( "Entrar com uma quantidade: " ); 
 
 // repetir para a quantidade de vezes informada 
    controle = 1; 
    while ( controle <= quantidade ) 
    { 
     // ler valor do teclado 
        valor = IO_readint ( IO_concat ( 
                                          IO_concat ( "", IO_toString_d ( controle ) ), 
                                          ": "  ) ); 
     // testar e contar se valor for positivo menor que 100 e par 
        ok = belongsTo ( valor, 0, 100 ); 
        ok = ok && even ( valor ); 
        if ( ok ) 
        { 
           contador = contador + 1; 
        } // end if 
 
     // passar ao proximo valor 
        controle = controle + 1; 
    } // end while 
 
 // mostrar a quantidade de valores positivos 
    IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_05 ( )

/** 
   Funcao para determinar se caractere e' letra minuscula. 
   @return true, se par; false, caso contrario 
   @param  x - valor a ser testado 
 */ 
bool isLowerCase ( char x ) 
{ 
 // definir dado local 
    bool result = false; 
 // testar a condicao 
    if ( 'a' <= x && x <= 'z' ) 
    { 
       result = true; 
    } // end if 
   return ( result ); 
} // end isLowerCase ( ) 
 
/** 
   Method_06 - Ler palavra e contar letras minusculas. 
 */ 
void method_06 ( ) 
{ 
 // definir dado 
    char palavra    = IO_new_chars ( STR_SIZE ); 
    int  tamanho  =  0; 
    int  posicao   =  0; 
    char simbolo    = '_'; 
    int  contador  =  0; 
 
 // identificar 
    IO_id ( "Method06 - v0.0" ); 
 
 // ler do teclado 
    palavra = IO_readstring ( "Entrar com uma palavra: " ); 
 
 // determinar a quantidade de simbolos na palavra 
    tamanho = strlen ( palavra ); 
 
 // repetir para a quantidade de vezes informada 
    for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 ) 
    { 
     // isolar um simbolo por vez 
        simbolo = palavra [ posicao ]; 
     // testar e contar se caractere e' letra minuscula  
       if ( isLowerCase ( simbolo ) ) 
        { 
           contador = contador + 1; 
        } // end if 
    } // end for 

 // mostrar a quantidade de minusculas 
    IO_printf ( "%s%d\n", "Minusculas = ", contador ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_06 ( ) 

/** 
   Method_07 - Ler palavra, contar e mostrar letras minusculas. 
 */ 
void method_07 ( ) 
{ 
 // definir dado 
    char palavra   = IO_new_chars ( STR_SIZE ); 
    int      tamanho =  0; 
    int      posicao  =  0; 
    char  simbolo   = '_'; 
    int     contador  =  0; 
 
 // identificar 
    IO_id ( "Method07 - v0.0" ); 
 
 // ler do teclado 
    palavra = IO_readstring ( "Entrar com uma palavra: " ); 
 
 // determinar a quantidade de simbolos na palavra 
    tamanho = strlen ( palavra ); 
 
 // repetir para a quantidade de vezes informada 
    for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 ) 
    { 
     // isolar um simbolo por vez 
        simbolo = palavra [ posicao ]; 
     // testar e contar se caractere e' letra minuscula 
        if ( isLowerCase ( simbolo ) ) 
        { 
         // mostrar 
            IO_printf ( "%c ", simbolo ); 
         // contar 
           contador = contador + 1; 
        } // end if 
    } // end for 
 
 // mostrar a quantidade de minusculas 
    IO_printf ( "\n%s%d\n", "Minusculas = ", contador ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_07 ( )

/** 
   Method_08 - Ler palavra, contar e mostrar letras minusculas (alternativo). 
 */ 
void method_08 ( ) 
{ 
 // definir dado 
    char palavra        = IO_new_chars ( STR_SIZE ); 
    int      tamanho      =  0; 
    int      posicao       =  0; 
    char   simbolo       = '_'; 
    int      contador      =  0; 
    char minusculas = IO_new_chars ( STR_SIZE ); 
 
    strcpy ( minusculas, STR_EMPTY );  // vazio 
 
 // identificar 
    IO_id ( "Method08 - v0.0" ); 
 
 
 
 // ler do teclado 
    palavra = IO_readstring ( "Entrar com uma palavra: " ); 
 
 // determinar a quantidade de simbolos na palavra 
    tamanho = strlen ( palavra ); 
 
 // repetir para a quantidade de vezes informada 
    for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 ) 
    { 
     // isolar um simbolo por vez 
        simbolo = palavra [ posicao ]; 
     // testar e contar as letras minusculas de uma palavra 
        if ( isLowerCase ( simbolo ) ) 
        { 
         // concatenar simbolo encontrado 
            minusculas = IO_concat ( minusculas, IO_toString_c ( simbolo ) ); 
         // contar 
           contador = contador + 1; 
        } // end if 
    } // end for 
 
 // mostrar a quantidade de minusculas 
    IO_printf ( "\n%s%d [%s]\n", "Minusculas = ", contador, minusculas ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_08 ( )

/** 
   Funcao para determinar se caractere e' digito. 
   @return true, se par; false, caso contrario 
   @param  x - valor a ser testado 
 */ 
bool isDigit ( char x ) 
{ 
 // definir dado local 
    bool result = false; 
 // testar a condicao 
    if ( '0' <= x && x <= '9' ) 
    { 
       result = true; 
    } // end if 
   return ( result ); 
} // end isDigit ( ) 
 
/** 
   Method_09 - Ler palavra e contar os algarismos. 
 */ 
void method_09 ( ) 
{ 
 // definir dado 
    char palavra    = IO_new_chars ( STR_SIZE ); 
    int      tamanho  =  0; 
    int      posicao   =  0; 
    char   simbolo   = '_'; 
    int      contador  =  0; 
 
 // identificar 
    IO_id ( "Method09 - v0.0" ); 
 
 // ler do teclado 
    palavra = IO_readstring ( "Entrar com caracteres: " ); 
 
 // determinar a quantidade de simbolos 
    tamanho = strlen ( palavra ); 
 
 // repetir para a quantidade de vezes informada 
    for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 ) 
    { 
     // isolar um simbolo por vez 
        simbolo = palavra [ posicao ]; 
     // testar e contar os algarismos em uma cadeia de caracteres 
        if ( isDigit ( simbolo ) ) 
        { 
         // mostrar 
            IO_printf ( "%c ", simbolo ); 
         // contar 
           contador = contador + 1; 
        } // end if 
    } // end for 
 
 // mostrar a quantidade de digitos 
    IO_printf ( "\n%s%d\n", "Algarismos = ", contador ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_09 ( )

/** 
   Funcao para determinar se caractere e' digito. 
   @return true, se par; false, caso contrario 
   @param  x - valor a ser testado 
 */ 
bool isADigit ( char x ) 
{ 
   return ( '0' <= x && x <= '9' ); 
} // end isADigit ( ) 
 
/** 
   Funcao para concatenar 'a cadeia de caracteres mais um digito. 
   @return  cadeia de caracteres acrescida de mais um digito 
   @param  digits - cadeia de caracteres 
   @param  digit   - simbolo a ser acrescentado 'a cadeia de caracteres 
*/ 
char concatADigit ( char string, char digit ) 
{ 
   return ( IO_concat ( string, IO_toString_c ( digit ) ) ); 
} // end concatADigit ( ) 
 
/** 
   Method_10. 
 */ 
void method_10 ( ) 
{ 
 // definir dado 
    char palavra    = IO_new_chars ( STR_SIZE ); 
    int      tamanho  =  0; 
    int      posicao   =  0; 
    char   simbolo   = '_'; 
    char digitos     = IO_new_chars ( STR_SIZE ); 
 
    strcpy ( digitos, STR_EMPTY );  // vazio 
 
 // identificar 
    IO_id ( "Method_10 - v0.0" ); 
 
 
 // ler do teclado 
    palavra = IO_readstring ( "Entrar com uma palavra: " ); 
 
 // determinar a quantidade de simbolos na palavra 
    tamanho = strlen ( palavra ); 
 
 // repetir para a quantidade de vezes informada 
    for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 ) 
    { 
     // isolar um simbolo por vez 
        simbolo = palavra [ posicao ]; 
     // testar e contar os algarismos em uma cadeia de caracteres 
        if ( isADigit ( simbolo ) ) 
        { 
         // concatenar simbolo encontrado 
            digitos = concatADigit ( digitos, simbolo ); 
        } // end if 
    } // end for 
 
 // mostrar a quantidade de digitos 
    IO_printf ( "\n%s%d [%s]\n", "Algarismos = ", strlen( digitos ), digitos ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_10 ( )

// identificar
menuOpcoes ( void ) 
{
   printf ( "\n" );             // para saltar linha
   printf ( "%s\n", "Exercicio01 - v.0.0 - 24/02/2025"       );
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
           case  1: method_01 ( ); 
                break;
           case  2: method_02 ( ); 
                break;
           case  3: method_03 ( );
                break;
           case  4: method_04 ( ); 
                break;
           case  5: method_05 ( ); 
                break;
           case  6: method_06 ( ); 
                break;
           case  7: method_07 ( ); 
                break;
           case  8: method_08 ( ); 
                break;
           case  9: method_09 ( ); 
                break;
           case 10: method_10 ( ); 
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
---------------------------------------------- documentacao complementar 
 
---------------------------------------------- notas / observacoes / comentarios 
 
---------------------------------------------- previsao de testes 
 
a.) -1 
b.)  0 
c.)  5 e { 1, 2, 3, 4, 5 } 
 
---------------------------------------------- historico 
 
Versao Data      Modificacao 
  0.1 __/__      esboco 
 
 ---------------------------------------------- testes 
 
Versao Teste 
  0.1 01. ( OK )  identificacao de programa 
 
*/