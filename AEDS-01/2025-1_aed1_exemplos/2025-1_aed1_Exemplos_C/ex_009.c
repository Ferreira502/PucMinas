// 999999_AED1
// Repeticao com teste no fim
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

  // repetir ate' escolher zero e parar
  do
  {
    // entrar com a opcao
    printf("%s", "Opcao: ");
    scanf("%d", &opcao);  getchar();

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

      default:
        printf("%s\n", "Outra opcao escolhida");
        break;
    }
  }
  while(opcao != 0);

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}
