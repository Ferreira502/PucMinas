// /**
//   Program v0.0
//   @author
//   @version
//   @date
// */

// // lista de dependencias
// #include <cstdio>      // para entradas e saida
// #include <cstdlib>     // para a biblioteca padrao
// #include <cstring>     // para cadeias de caracteres
// #include <cmath>       // para definicoes matematicas
// #include <time.h>      // para medir tempo

// #include <iostream>
// #include <iomanip>
// #include <fstream>
// #include <sstream>
// #include <string>

// /**
//   Acao principal.
// */
// // identificar
//  void menuOpcoes ( void ) 
//  {
//    printf ( "\n" );             // para saltar linha
//    printf ( "%s\n", "Exercicio10 - v.0.0 - 13/05/2025"       );
//    printf ( "%s\n", "Matricula: 842527 Nome: Gabriel Ferreira Pereira" );

// // mostrar opcoes
//    printf ( "%s\n", "Opcoes:   "     );
//    printf ( "%s\n", " 0 - parar"     );
//    printf ( "%s\n", " 1 - metodo 1011" );
//    printf ( "%s\n", " 2 - metodo 1012" );
//    printf ( "%s\n", " 3 - metodo 1013" );
//    printf ( "%s\n", " 4 - metodo 1014" );
//    printf ( "%s\n", " 5 - metodo 1015" );
//    printf ( "%s\n", " 6 - metodo 1016" );
//    printf ( "%s\n", " 7 - metodo 1017" );
//    printf ( "%s\n", " 8 - metodo 1018" );
//    printf ( "%s\n", " 9 - metodo 1019" );
//    printf ( "%s\n", " 10- metodo 1020" );
//    printf ( "%s\n", " 11- metodo 10E1" );
//    printf ( "%s\n", " 12- metodo 10E2" );
//    printf ( "%s\n", "" );        // para saltar linha
//  }


// // -------------------------- definicao do metodo principal

//  int main ( void )
//  {
//  // definir dados/resultados
//     int opcao = 0;

//  // repetir ate' desejar parar
//     do
//     {
//       menuOpcoes();
//      // ler opcao
//         printf ( "%s", "Qual a sua opcao? " );
//         scanf  ( "%d", &opcao ); getchar ( );
//         printf ( "%d",  opcao );

//      // escolher acao
//         switch ( opcao )
//         {
//            case  0:               
//                 break;
//            case  1: metodo01 ( ); 
//                 break;
//            case  2: metodo02 ( ); 
//                 break;
//            case  3: metodo03 ( );
//                 break;
//            case  4: metodo04 ( ); 
//                 break;
//            case  5: metodo05 ( ); 
//                 break;
//            case  6: metodo06 ( ); 
//                 break;
//            case  7: metodo07 ( ); 
//                 break;
//            case  8: metodo08 ( ); 
//                 break;
//            case  9: metodo09 ( ); 
//                 break;
//            case 10: metodo10 ( ); 
//                 break;
//            case 11: metodo11 ( );
//                 break;
//            case 12: metodo12 ( );
//                 break;
//            default: printf ( "\n%s\n\n", "ERRO: Opcao invalida." );
//                 break;
//         } // fim escolher
//     }
//     while ( opcao != 0 );

//  // encerrar execucao
//     printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
//     getchar( );

//     return 0;
//  } // end main ( )