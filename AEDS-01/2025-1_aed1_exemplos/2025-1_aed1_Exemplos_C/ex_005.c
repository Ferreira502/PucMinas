// 999999_AED1
// Comparacoes
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>  // biblioteca para not, and, or, xor

/*
  Funcao principal.
 */
int main(void) 
{
  // definir dado
  bool p = true ;
  bool q = false;
  bool r = false;
  char a =   'A';
  char b =   'a';
  int  x =    5 ;
  int  y =    7 ;
  
  // mostrar mensagem com formato 
  printf("%s\n","999999_AED1"); 
  
  printf("\nComparacoes\n");
  printf("   (%c==%c) = %d\n", a, a, (a==a));
  printf("   (%c!=%c) = %d\n", a, a, (a!=a));
  printf("\n");
  
  r =  !  (a==a);        // NOT - logical negation
  printf(" ! (%c==%c) = %d\n", a, a, r);
  r =  !  (a!=a);        // NOT - logical complement
  printf(" ! (%c!=%c) = %d\n", a, a, r);
  r = not (a==a);        // NOT - logical negation
  printf("not(%c==%c) = %d\n", a, a, r);
  printf("\n");

  r = (x<y)  &&  (x!=0); // AND - logical conjunction
  printf("(%d<%d)  && (%d!=0)= %d\n", x,y,x,r);
  r = (x<y)  and (x!=0); // AND - logical conjunction
  printf("(%d<%d) and (%d!=0)= %d\n", x,y,x,r);
  r = (x>=y) ||  (x!=0); // OR  - logical disjunction
  printf("(%d>=%d) || (%d!=0)= %d\n", x,y,x,r);
  r = (x>=y) or  (x!=0); // OR  - logical disjunction
  printf("(%d<%d)  or (%d!=0)= %d\n", x,y,x,r);
  r = (x<=y) &&  (x> 0); // AND - logical conjunction
  printf("(%d<%d)  && (%d> 0)= %d\n", x,y,x,r);
  r = (x<=y) and (x> 0); // AND - logical conjunction
  printf("(%d<%d) and (%d> 0)= %d\n", x,y,x,r);
  printf("\n");

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}


