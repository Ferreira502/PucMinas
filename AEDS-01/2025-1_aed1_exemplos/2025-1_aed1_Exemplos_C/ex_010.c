// 999999_AED1
// Repeticao com teste no inicio (crescente)
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
  while(x < 5)
  {
   // mostrar valor atual
      printf("%d\n", x);
   // passar ao seguinte (em ordem crescente)  
      x = x+1;   
  }

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}
