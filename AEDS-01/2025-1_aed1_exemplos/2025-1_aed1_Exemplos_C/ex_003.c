// 999999_AED1
// Mostrar dados com formatos
#include <stdio.h>
#include <stdbool.h> // biblioteca para tipo logico

/*
  Funcao principal.
 */
int main(void) 
{
  // tipos de dados
  bool   status   = false; // logico
  int    contador =     0; // inteiro
  float  valor_1  = 0.00f; // real de precisao simples
  double valor_2  =  0.00; // real de precisao dupla
  char   letra    =   'A'; // caracteres 

  // mostrar mensagem  
  printf("%s\n","999999_AED1"); 

  // mostrar valores 
  printf("status  : %d \n", status  );  
  printf("contador: %d \n", contador);
  printf("valor_1 : %f \n", valor_1 );
  printf("valor_2 : %lf\n", valor_2 );
  printf("letra   : %c \n", letra   );

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}
