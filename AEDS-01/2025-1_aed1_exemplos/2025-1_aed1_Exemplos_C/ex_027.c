// 999999_AED1
// Apontador para matriz em estrutura
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// definir novo tipo 
typedef
 struct s_matrix // descritor do tipo
 {
  int   rows;
  int   columns;
  int **data;  
 }
Matrix;          // nome do tipo

/*
  Funcao principal.
 */
int main(void) 
{
  // definir dados
  Matrix *a = NULL;
  
  // mostrar mensagem  
  printf("%s\n","999999_AED1"); 

  // reservar espaco para descritor 
  a = malloc(1 * sizeof(Matrix));
  // testar se ha' espaco reservado 
  if(a == NULL)
  {
    // mostrar codigo de erro    
    printf("Erro = %d\n", errno);
    perror("Error");
  }
  else 
  {
    // reservar espaco para guardar linhas
    a->rows    = 2;
    a->columns = 3;
    a->data    = malloc(a->rows * sizeof(int*));
    // testar se ha' espaco para guardar dados
    if (a->data != NULL)
    {
       // reservar espaco para guardar colunas
       for(int x=0; x<2; x=x+1)
       {
          a->data[x] = malloc(a->columns * sizeof(int));
          if (a->data[x])
          {  // ler dados com apontadores
             printf("\nDados para a linha %d matriz:\n", x);       
             for(int y = 0; y < a->columns; y = y+1)
             {  scanf("%d", &a->data[x][y]);  }
          }
       }
  
       // mostrar valores
       printf("\nDados guardados:\n");       
       for(int x = 0; x < a->rows; x = x+1)
       {
          for(int y = 0; y < a->columns; y = y+1)
          {  printf("%2d\t", a->data[x][y]); }
          printf("\n");
       }
	}
  }
  printf("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}
