// 999999_AED1
// Alternativas simples e duplas
#include <stdio.h>   // para printf(), scanf()
#include <stdbool.h>

/*
  Funcao principal.
 */
int main(void) 
{
  // mostrar mensagem  
  printf("%s\n","999999_AED1"); 

  int valor = 0;

  // entrar dado
  printf("Enter a number: ");
  scanf("%d", &valor); getchar( ); // ler e limpar

  // testar se valor negativo
  if(valor < 0) 
  {
    printf("%d -> negativo\n", valor); 
  }
  
  // testar se valor menor que 100
  if(valor < 100) 
  {
    printf("%d menor que 100\n", valor); 
  }
  else 
  {
   // testar se igual a 100
    if(valor == 100) 
    {
      printf("%d igual a cem\n", valor);
    }
    else 
    {
      printf("%d diferente de 100\n", valor ); 
    }
  }

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}