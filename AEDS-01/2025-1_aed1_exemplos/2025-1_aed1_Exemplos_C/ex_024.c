// 999999_AED1
// Definicao de tipo para arranjo
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// definir novo tipo 
typedef
 struct s_array // descritor do tipo
 {
  int  n;
  int *data;  
 }
Array;          // nome do tipo

/*
  Funcao principal.
 */
int main(void) 
{
  // definir dados
  FILE *a = fopen("DATA.TXT","r");
  Array b;
  
  // mostrar mensagem  
  printf("%s\n","999999_AED1"); 

  // ler valores 
  a = fopen("DATA.TXT","r");
  fscanf(a, "%d", &b.n);
  b.data = malloc(b.n * sizeof(int));
  for(int x = 0; x < b.n; x = x+1)
  {  fscanf(a, "%d", &b.data[x]);}
  fclose(a);
  
  // mostrar valores 
  printf("\nDados guardados:\n");
  for(int x = 0; x < b.n; x = x+1)
  {  printf("%2d\n", b.data[x]); }
  printf("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}
