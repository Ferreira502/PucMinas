// 999999_AED1
// Repeticao com variacao (decrescente)
#include <stdio.h>

/*
  Funcao principal.
 */
int main(void) 
{
  // definir dado
  int x = 0;
  
  // mostrar mensagem com formato 
  printf ("%s\n","999999_AED1"); 
  
  // repetir enquanto condicao verdadeira
  for(x = 5; x > 0; x=x-1)
  {
   // mostrar valores em ordem decrescente
      printf("%d\n", x);
  }

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}
