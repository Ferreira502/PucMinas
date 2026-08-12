// 999999_AED1
// Passagens de argumentos em linha de comando
#include <stdio.h>
#include <stdbool.h>

/*
  Funcao principal.
  @return codigo de encerramento
  @param  argc - quantidade de argumentos
  @param  argv - lista      de argumentos
  Exemplo de uso:
          ex_030 false A 1 2.3 abc
 */
int main(int argc, char **argv) 
{
  // mostrar mensagem  
  printf("%s\n","999999_AED1"); 

  // mostrar valores 
  printf("\nQuantidade de argumentos: %d\n", argc);
  printf("\nArgumentos:\n");
  for(int x = 0; x < argc; x = x+1)
  {  printf("%d: %s\n", x, argv[x]); }
  printf("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}
/*
  Testes e observacoes:
1. Teste sem parametros:
999999_AED1

Quantidade de argumentos: 1

Argumentos:
0: ex_030
  
2. Teste com parametros:
999999_AED1

Quantidade de argumentos: 6

Argumentos:
0: ex_030
1: false
2: A
3: 1
4: 2.3
5: abc

Apertar ENTER para terminar.  

OBS.:
Em qualquer caso, o primeiro argumento
e' sempre o proprio nome  do programa.
*/

