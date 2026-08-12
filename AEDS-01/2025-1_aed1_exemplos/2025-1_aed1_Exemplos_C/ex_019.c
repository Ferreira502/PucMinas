// 999999_AED1
// Arranjos
#include <stdio.h>
#include <stdlib.h>

/*
  Procedimento para mostrar arranjo de inteiros.
  @param n - quantidade de dados
  @param v - apontador para arranjo de inteiros
*/
void print_array(int n, int *v)
{
  for(int x=0; x < n; x=x+1)
  {  printf("%d ", v[x]);  }
  printf("\n");
}

/*
  Procedimento para ler arranjo de inteiros.
  @param n - quantidade de dados
  @param v - apontador para arranjo de inteiros
*/
void scan_array(int n, int *v)
{
  for(int x=0; x < n; x=x+1)
  {  scanf("%d", &v[x]); getchar( );  }
  printf("\n");  
}

/*
  Funcao principal.
 */
int main(void) 
{
  // definir dados
  int a [ ] = {1,2,3};  // arranjo com valores
  int b [3];            // espaco para arranjo
                        // definir valores iniciais
  b[0] = 4; b[1] = 5; b[2] = 6;
                        // reservar espaco
  int *c    = malloc(3 * sizeof(int));
                        // definir valores iniciais
  if ( c )              // se houver espaco reservado
    for(int x=0; x < 3; x=x+1)
    { c[x] = (x+1)*10; }
  
  // mostrar mensagem  
  printf("%s\n","999999_AED1"); 

  // aplicar metodos sobre em arranjos
  printf("\nOperacoes com arranjos\n");
  printf("a:\n");
  print_array(3, a);
  printf("\n");
  
  printf("b:\n");
  print_array(3, b);
  printf("\n");

  printf("c:\n");
  print_array(3, c);
  printf("\n");

  // ler     dados para arranjo
  printf("Entrar dados:\n");
  scan_array(3, c);
  printf("c:\n");
  // mostrar dados em   arranjo
  printf("\nDados lidos (c):\n");
  print_array(3, c);
  printf("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}
