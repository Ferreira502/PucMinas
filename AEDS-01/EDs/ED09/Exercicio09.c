/*
 Exercicio09 - v0.0. - 09 / 05 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exercicio09 exercicio09.c
 Windows: gcc -o exercicio09 exercicio09.c
 Para executar em terminal (janela de comandos):
 Linux : ./exercicio9
 Windows: exercicio09
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 100

// -------------------------- definicao de classe


void readPositiveDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) 
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double value;
            do {
                printf("\nDigite o valor positivo para matriz[%d][%d]: ", i, j);
                scanf("%lf", &value);
                if (value < 0) {
                    printf("\nErro: Valor negativo");
                }
            } while (value < 0);
            matrix[i][j] = value;
        }
    }
}

void printDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) 
{
    printf("\nMatriz lida: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
    getchar();
}

void fprintDoubleMatrix(char filename[], int rows, int cols, double matrix[MAX][MAX]) 
{
  FILE *file = fopen(filename, "w");
  int i, j;

  if (file != NULL) {
      fprintf(file, "%d %d\n", rows, cols);
      for (i = 0; i < rows; i++) {
          for (j = 0; j < cols; j++) {
              fprintf(file, "%.2lf ", matrix[i][j]);
          }
          fprintf(file, "\n");
      }
      fclose(file);
      printf("\nMatriz gravada com sucesso no arquivo '%s'", filename);
  } else {
      printf("\nErro ao abrir o arquivo");
  }
}
/**
  * Metodo01.
  */

void metodo01( void ) 
{
// Identificar
  printf("\n%s\n", "\n\tMetodo0911");
  int rows = 0, cols = 0;
  double positiveMatrix[MAX][MAX];

  
  do {
      printf("\nDigite a quantidade de linhas: ");
      scanf("%d", &rows);
      if (rows <= 0 || rows > MAX) {
          printf("\nQuantidade invalida de linhas");
      }
  } while (rows <= 0 || rows > MAX);

  do {
      printf("\nDigite a quantidade de colunas: ");
      scanf("%d", &cols);
      if (cols <= 0 || cols > MAX) {
          printf("\nQuantidade invalida de colunas");
      }
  } while (cols <= 0 || cols > MAX);

  readPositiveDoubleMatrix(rows, cols, positiveMatrix);
  printDoubleMatrix(rows, cols, positiveMatrix);
  getchar();
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo01 ( )

/**
  * Metodo02.
  */

void freadDoubleMatrix(char filename[], int *rows, int *cols, double matrix[MAX][MAX]) 
{
  FILE *file = fopen(filename, "r");
  int i, j;

  if (file != NULL) {
      fscanf(file, "%d %d", rows, cols);
      for (i = 0; i < *rows; i++) {
          for (j = 0; j < *cols; j++) {
              fscanf(file, "%lf", &matrix[i][j]);
          }
      }
      fclose(file);
  } else {
      printf("\nErro ao abrir o arquivo para leitura");
  }
}

void metodo02 ( void )
{
// Identificar
  printf("\n%s\n", "\n\tMetodo0912");
  int rows = 0, cols;
  double matriz[MAX][MAX];
  double matrizLida[MAX][MAX];

  printf("\nInforme o numero de linhas: ", MAX);
  scanf("%d", &rows);
  printf("\nInforme o numero de colunas: ", MAX);
  scanf("%d", &cols);
  getchar();

  if (rows > 0 && cols > 0 && rows <= MAX && cols <= MAX) {
      readPositiveDoubleMatrix(rows, cols, matriz);
      fprintDoubleMatrix("MATRIX_01.TXT", rows, cols, matriz);
      freadDoubleMatrix("MATRIX_01.TXT", &rows, &cols, matrizLida);
      printDoubleMatrix(rows, cols, matrizLida);
  } else {
      printf("\nDimensoes invalidas");
  }
   
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo02 ( )

/**
  * Metodo03.
  */

void printDiagonalDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) 
{

  printf("\nDiagonal principal: \n");
  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
          if (i == j) {
              printf("%.2lf ", matrix[i][j]);
          } else {
              printf("   --  ");
          }
      }
      printf("\n");
  }
}
void metodo03 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0913");
   int rows = 0, cols = 0;
   double matriz[MAX][MAX];
  
   printf("\nDigite a quantidade de linhas: ");
   scanf("%d", &rows);
   printf("\nDigite a quantidade de colunas: ");
   scanf("%d", &cols);
   getchar();

   if (rows == cols)
   {
      readPositiveDoubleMatrix(rows, cols, matriz);
      printDoubleMatrix(rows, cols, matriz);
      printDiagonalDoubleMatrix(rows, cols, matriz); 
   }
   else
   {
    printf("\nA matriz nao e quadrada");
   }
   getchar();
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo03 ( )

/**
  * Metodo04.
  */

void printSDiagonalDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) 
{

  printf("\nDiagonal secundaria: \n");
  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
          if (i + j == cols - 1) {
              printf("%.2lf ", matrix[i][j]);
          } else {
              printf("   --  ");
          }
      }
      printf("\n");
  }
}

void metodo04 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0914");
   int rows = 0, cols = 0;
   double matriz[MAX][MAX];

   printf("\nDigite a quantidade de linhas: ");
   scanf("%d", &rows);
   printf("\nDigite a quantidade de colunas: ");
   scanf("%d", &cols);
   getchar();

   if (rows == cols)
   {
      readPositiveDoubleMatrix(rows, cols, matriz);
      printDoubleMatrix(rows, cols, matriz);
      printSDiagonalDoubleMatrix(rows, cols, matriz); 
   }
   else
   {
    printf("\nA matriz nao e quadrada");
   }
   getchar();
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo04 ( )

/**
  * Metodo05.
  */
 void printLDTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) 
 {

    printf("\nAbaixo da diagonal principal: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > j) {
                printf("%6.2lf ", matrix[i][j]);
            } else {
                printf("   --  ");
            }
        }
        printf("\n");
    }
}

void metodo05 ( void )
{
// Identificar
   printf("\n%s\n", "\n\tMetodo0915");
   int rows = 0, cols = 0;
   double matriz[MAX][MAX];

   printf("\nDigite a quantidade de linhas: ");
   scanf("%d", &rows);
   printf("\nDigite a quantidade de colunas: ");
   scanf("%d", &cols);
   getchar();

   if (rows == cols)
   {
      readPositiveDoubleMatrix(rows, cols, matriz);
      printDoubleMatrix(rows, cols, matriz);
      printLDTriangleDoubleMatrix(rows, cols, matriz); 
   }
   else
   {
    printf("\nA matriz nao e quadrada");
   }
   getchar();
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo05 ( )

/**
  * Metodo06.
  */
void printLUTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) 
{
  printf("\nValores acima da diagonal principal: \n");
  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         if (j > i) {
              printf("%.2lf ", matrix[i][j]);
          } else {
              printf("   --  ");
          }
      }
      printf("\n");
  }
}
void metodo06( void )
{
// Identificar
  printf("\n%s\n", "\n\tMetodo0916");
  int rows = 0, cols = 0;
  double matriz[MAX][MAX];

   printf("\nDigite a quantidade de linhas: ");
   scanf("%d", &rows);
   printf("\nDigite a quantidade de colunas: ");
   scanf("%d", &cols);
   getchar();

   if (rows == cols)
   {
      readPositiveDoubleMatrix(rows, cols, matriz);
      printDoubleMatrix(rows, cols, matriz);
      printLUTriangleDoubleMatrix(rows, cols, matriz); 
   }
   else
   {
    printf("\nA matriz nao e quadrada");
   }
   getchar(); 
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo06()

/**
  * Metodo07.
  */
void printSLDTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) 
{
  printf("\nValores abaixo e na diagonal secundaria: \n");
  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
          if (i + j >= cols - 1) {
              printf("%.2lf", matrix[i][j]);
          } else {
              printf("   --  ");
          }
      }
      printf("\n");
  }
}

void metodo07( void ) {
//identificar
  printf("\n%s\n", "\n\tMetodo0917");
  int rows = 0, cols = 0;
  double matriz[MAX][MAX];

   printf("\nDigite a quantidade de linhas: ");
   scanf("%d", &rows);
   printf("\nDigite a quantidade de colunas: ");
   scanf("%d", &cols);
   getchar();

   if (rows == cols)
   {
      readPositiveDoubleMatrix(rows, cols, matriz);
      printDoubleMatrix(rows, cols, matriz);
      printSLDTriangleDoubleMatrix(rows, cols, matriz); 
   }
   else
   {
    printf("\nA matriz nao e quadrada");
   }
   getchar(); 
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo07()

/**
  * Metodo08.
  */
void printSLUTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) 
{
  printf("\nValores acima e na diagonal secundaria:\n");
  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
          if (i + j <= cols - 1) {
              printf("%.2lf ", matrix[i][j]);
          } else {
              printf("   --  ");
          }
      }
      printf("\n");
  }
}

void metodo08( void ) {
//Identificar
  printf("\n%s\n", "\n\tMetodo0918");
  int rows = 0, cols = 0;
  double matriz[MAX][MAX];

   printf("\nDigite a quantidade de linhas: ");
   scanf("%d", &rows);
   printf("\nDigite a quantidade de colunas: ");
   scanf("%d", &cols);
   getchar();

   if (rows == cols)
   {
      readPositiveDoubleMatrix(rows, cols, matriz);
      printDoubleMatrix(rows, cols, matriz);
      printSLUTriangleDoubleMatrix(rows, cols, matriz); 
   }
   else
   {
    printf("\nA matriz nao e quadrada");
   }
   getchar(); 
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo08()

/**
  * Metodo09.
  */

bool allZerosLTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) 
{
  for (int i = 1; i < rows; i++) {
      for (int j = 0; j < i; j++) {
          if (matrix[i][j] != 0.0) {
              return false;
          }
      }
  }
  return true;
}

void metodo09 ( void )
{
// Identificar
  printf("\n%s\n", "\n\tMetodo0919");
  int rows = 0, cols = 0;
  double matriz[MAX][MAX];

  printf("\nDigite a quantidade de linhas: ");
  scanf("%d", &rows);
  printf("\nDigite a quantidade de colunas: ");
  scanf("%d", &cols);
  getchar();

  if (rows == cols)
  {
    readPositiveDoubleMatrix(rows, cols, matriz);
    printDoubleMatrix(rows, cols, matriz);
    bool result = allZerosLTriangleDoubleMatrix(rows, cols, matriz);
    if (result) 
    {
      printf("\nTodos os valores abaixo da diagonal principal sao zero");
    } 
    else 
    {
      printf("\nHa pelo menos um valor diferente de zero abaixo da diagonal principal");
    }
  }
  else
  {
    printf("\nA matriz nao e quadrada");
  }
  getchar(); 

// encerrar
  printf("%s\n", "\nApertar ENTER para continuar\n");
  getchar( );

 } // fim metodo09 ( )

/**
  * Metodo10.
  */

bool allZerosUTriangleDoubleMatrix(int rows, int cols, double matrix[MAX][MAX]) 
{
  for (int i = 0; i < rows - 1; i++) {
      for (int j = i + 1; j < cols; j++) {
          if (matrix[i][j] != 0.0) {
              return false;
          }
      }
  }
  return true;
}

void metodo10( void ) 
{
// Identificar
  printf("\n%s\n", "\n\tMetodo920");
  int rows = 0, cols = 0;
  double matriz[MAX][MAX];

  printf("\nDigite a quantidade de linhas: ");
  scanf("%d", &rows);
  printf("\nDigite a quantidade de colunas: ");
  scanf("%d", &cols);
  getchar();

  if (rows == cols)
  {
    readPositiveDoubleMatrix(rows, cols, matriz);
    printDoubleMatrix(rows, cols, matriz);
    bool result = allZerosUTriangleDoubleMatrix(rows, cols, matriz);
    if (result) 
    {
      printf("\nTodos os valores acima da diagonal principal sao zero");
    } 
    else 
    {
      printf("\nHa pelo menos um valor diferente de zero acima da diagonal principal");
    }
  }
  else
  {
    printf("\nA matriz nao e quadrada");
  }
  getchar(); 
// Encerrar
  printf("\n\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo 10 ()

/**
  * Metodo11.
  */

void generateMatrixE1(int rows, int cols, double matrix[100][100]) {
    int value = 1;
    for (int j = 0; j < cols; j++) 
    {        
        for (int i = 0; i < rows; i++) 
        {
            matrix[i][j] = value;
            value++;
        }
    }
}

void metodo11( void ) 
{
// Identificar
  printf("\n%s\n", "\n\tMetodo09E1");
  double matrix[MAX][MAX];
  int rows = 0, cols = 0;

  printf("\nDigite a quantidade de linhas: ");
  scanf("%d", &rows);
  printf("\nDigite a quantidade de colunas: ");
  scanf("%d", &cols);
  getchar();

  if (rows <= 0 || cols <= 0 || rows > MAX || cols > MAX) {
      printf("\nTamanho invalido");
      return 1;
  }
  getchar();
  generateMatrixE1(rows, cols, matrix);
  fprintDoubleMatrix("MATRIX_E1.TXT", rows, cols, matrix);
// Encerrar
  printf("\n\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}//

 
/**
  * Metodo12.
  */
void generateMatrixE2(int rows, int cols, double matrix[100][100]) {
    int value = 1;
    for (int i = rows - 1; i >= 0; i--) 
    {   
        for (int j = cols - 1; j >= 0; j--) 
        { 
            matrix[i][j] = value;
            value++;
        }
    }
}

void metodo12( void ) {
// Identificar
  printf("\n%s\n", "\n\tMetodo09E2");
  double matrix[MAX][MAX];
  int rows = 0, cols = 0;

  printf("\nDigite a quantidade de linhas: ");
  scanf("%d", &rows);
  printf("\nDigite a quantidade de colunas: ");
  scanf("%d", &cols);
  getchar();

  if (rows <= 0 || cols <= 0 || rows > MAX || cols > MAX) {
      printf("\nTamanho invalido");
      return 1;
  }
  getchar();
  generateMatrixE2(rows, cols, matrix);
  fprintDoubleMatrix("MATRIX_E2.TXT", rows, cols, matrix);
// Encerrar
  printf("\n\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}

// identificar
 void menuOpcoes ( void ) 
 {
   printf ( "\n" );             // para saltar linha
   printf ( "%s\n", "Exercicio09 - v.0.0 - 09/05/2025"       );
   printf ( "%s\n", "Matricula: 842527 Nome: Gabriel Ferreira Pereira" );

// mostrar opcoes
   printf ( "%s\n", "Opcoes:   "     );
   printf ( "%s\n", " 0 - parar"     );
   printf ( "%s\n", " 1 - metodo 0911" );
   printf ( "%s\n", " 2 - metodo 0912" );
   printf ( "%s\n", " 3 - metodo 0913" );
   printf ( "%s\n", " 4 - metodo 0914" );
   printf ( "%s\n", " 5 - metodo 0915" );
   printf ( "%s\n", " 6 - metodo 0916" );
   printf ( "%s\n", " 7 - metodo 0917" );
   printf ( "%s\n", " 8 - metodo 0918" );
   printf ( "%s\n", " 9 - metodo 0919" );
   printf ( "%s\n", " 10- metodo 0920" );
   printf ( "%s\n", " 11- metodo 09E1" );
   printf ( "%s\n", " 12- metodo 09E2" );
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