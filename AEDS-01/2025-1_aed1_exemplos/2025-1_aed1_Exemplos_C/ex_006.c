// 999999_AED1
// Operacoes logicas
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>  

/*
  Funcao principal.
 */
int main(void) 
{
  // definir dado
  bool p = true ;
  bool q = false;
  bool r = false;
  
  // mostrar mensagem com formato 
  printf("%s\n","999999_AED1"); 
  
  printf("     p = %d\n", p);
  printf("     q = %d\n", q);
  printf("\n");
  
  printf("\nNegacao\n");
  r = ! p;    // NOT - logical negation
  printf(" !   p = %d\n", r);
  r = ! q;    // NOT - logical complement
  printf(" !   q = %d\n", r);
  r = not p;  // NOT - logical negation
  printf("not  p = %d\n", r);
  printf("\n");

  printf("\nConjuncao\n");
  printf("0 && 0 = %d\n", (0 && 0) );
  printf("0 && 1 = %d\n", (0 && 1) );
  printf("1 && 0 = %d\n", (1 && 0) );
  printf("1 && 1 = %d\n", (1 && 1) );
  printf("\n");

  printf("\nDisjuncao\n");
  printf("0 || 0 = %d\n", (0 || 0) );
  printf("0 || 1 = %d\n", (0 || 1) );
  printf("1 || 0 = %d\n", (1 || 0) );
  printf("1 || 1 = %d\n", (1 || 1) );
  printf("\n");

  printf("\nDisjuncao exclusiva\n");
  printf("0 ^  0 = %d\n", (0 ^  0) );
  printf("0 ^  1 = %d\n", (0 ^  1) );
  printf("1 ^  0 = %d\n", (1 ^  0) );
  printf("1 ^  1 = %d\n", (1 ^  1) );
  printf("\n");

  printf("\nOperacoes logicas\n");
  r = p &&  q; // AND - logical conjunction
  printf("p &&  q = %d\n", r);
  r = p and q; // AND - logical conjunction
  printf("p and q = %d\n", r);
  r = p ||  q; // OR  - logical disjunction
  printf("p ||  q = %d\n", r);
  r = p or  q; // AND - logical conjunction
  printf("p or  q = %d\n", r);
  printf("\n");

  r = p ^   q; // XOR - logical exclusive disjunction
  printf("p  ^  q = %d\n", r);
  r = p xor q; // XOR - logical exclusive disjunction
  printf("p xor q = %d\n", r);
  r = p ^   p; // XOR - logical exclusive disjunction
  printf("p  ^  p = %d\n", r);
  r = p xor p; // XOR - logical exclusive disjunction
  printf("p xor p = %d\n", r);
  printf("\n");

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}

