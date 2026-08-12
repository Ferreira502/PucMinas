// 999999_AED1
// Conversoes e operacoes aritmeticas
#include <stdio.h>

/*
  Funcao principal.
 */
int main(void) 
{
  // definir dados
  char   x = 'A';
  int    y =  5 ;
  double z = 1.2;
  
  // iniciar
  printf ("%s\n","999999_AED1"); 
  
  printf("\nOperacoes\n");
  // conformar tipos (type casting)
  y = (int) z;       // truncar para parte inteira
  printf ("z = %lf\t y = %d\n", z, y );
  y = (int) x;       // obter codigo do simbolo
  printf ("x = %c \t y = %d\n", x, y );
  y = x;             // conformacao implicita
  printf ("x = %c \t y = %d\n", x, y );
  printf ("\n");

  x = (char) (32+y); // obter simbolo a partir do codigo
  printf ("y = %d \t x = %c\n", y, x );
  x = (char) (48+(int) z);
  printf ("z = %lf\t x = %c\n", z, x );
  printf ("\n");
                     
  z = z - (int) z;   // isolar parte fracionaria
  printf ("z = %lf\n", z );
  z = (double) x;    // conformacao explicita
  printf ("z = %lf\t x = %c\n", z, x );
  z = 1.0 * x;       // conformacao implicita
  printf ("z = %lf\t x = %c\n", z, x );
  printf ("\n");
  
  z = x / 2;         // metade inteira 
  printf ("z = %lf\n", z );
  z = (double) (x/2);// metade real
  printf ("z = %lf\n", z );
  z = (double) x / 2;
  printf ("z = %lf\n", z );
  z = x / (double) 2;
  printf ("z = %lf\n", z );
  z = (double) x / (double) 2;
  printf ("z = %lf\n", z );
  printf ("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}


