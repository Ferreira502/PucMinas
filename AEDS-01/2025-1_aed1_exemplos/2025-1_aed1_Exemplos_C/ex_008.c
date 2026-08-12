// 999999_AED1
// Alternativas multiplas
#include <stdio.h>
#include <stdbool.h>

/*
  Funcao principal.
 */
int main(void) 
{
  // mostrar mensagem  
  printf("%s\n","999999_AED1"); 
  int opcao = 0;

  // entrar com a opcao
  printf("%s", "Opcao: ");
  scanf("%d", &opcao);  getchar( );

  // escolher acao dependente da opcao
  switch(opcao)
  {
    case 0: 
      printf("%s\n", "Opcao 0 escolhida");
      break;

    case 1: 
      printf("%s\n", "Opcao 1 escolhida");
      break;

    case 2: 
      printf("%s\n", "Opcao 2 escolhida");
      break;

    default: // caso for outra opcao
      printf("%s\n", "Outra opcao escolhida");
      break;
  }

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}
