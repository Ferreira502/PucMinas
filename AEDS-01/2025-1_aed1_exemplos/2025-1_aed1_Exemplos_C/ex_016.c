// 999999_AED1
// Funcoes com comparacoes
#include <stdio.h>

// functions
/*
   Funcao para determinar o maior valor.
   @return maior valor
   @param x - primeiro valor
   @param y - segundo  valor
 */
int max(int x, int y)
{
    int z = 0;
    if ( x > y )
	   z = x;
	else
	   z = y;
	return ( z );
}

/*
   Funcao para determinar o menor valor.
   @return menor valor
   @param x - primeiro valor
   @param y - segundo  valor
 */
int min(int x, int y)
{
    int z = x;
    if ( y < x )
	   z = y;
	return ( z );
}

/*
  Funcao principal.
 */
int main(void) 
{
  // definir dados
  int    x =  3 ;
  int    y =  5 ;
  int    z =  7 ;
  
  // iniciar
  printf ("%s\n","999999_AED1"); 

  // aplicar funcoes
  pritnf ("\nAplicar funcoes\n");
  printf ("maior(%d,%d) = %d\n", 
           x, y, max(x,y));  
  printf ("\n");
  printf ("maior(%d,%d,%d) = %d\n", 
           x, y, z, max(x,max(y,z)));  
  printf ("\n");
  printf ("menor(%d,%d) = %d\n", 
           x, y, min(x,y));  
  printf ("\n");
  printf ("menor(%d,%d,%d) = %d\n", 
           x, y, z, min(min(x,y),z));  
  printf ("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}
