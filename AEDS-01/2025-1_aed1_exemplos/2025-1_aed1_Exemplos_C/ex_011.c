// 999999_AED1
// Repeticao com teste no inicio (decrescente)
#include <stdio.h>

/*
  Funcao principal.
 */
int main(void) 
{
  // definir dado
  int x = 5;
  
  // mostrar mensagem com formato 
  printf ("%s\n","999999_AED1"); 
  
  // repetir enquanto condicao verdadeira
  while(x > 0)
  {
   // mostrar valor atual
      printf("%d\n", x);
   // passar ao seguinte (em ordem decrescente)  
      x = x-1;   
  }

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}

