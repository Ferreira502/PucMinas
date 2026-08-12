// 999999_AED1
// Enumeracoes
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// definir enumeracao (constantes em sequencia)
enum Semana 
{ Domingo, Segunda, Terca, Quarta, Quinta, Sexta, Sabado };

/*
  Funcao principal.
 */
int main(void) 
{
  // definir dados
  char Semana_str[7][8]; // para guardar lista de nomes
  
  strcpy(Semana_str[Domingo], "Domingo");
  strcpy(Semana_str[Segunda], "Segunda");
  strcpy(Semana_str[Terca  ], "Terca  ");
  strcpy(Semana_str[Quarta ], "Quarta ");
  strcpy(Semana_str[Quinta ], "Quinta ");
  strcpy(Semana_str[Sexta  ], "Sexta  ");
  strcpy(Semana_str[Sabado ], "Sabado ");

  // mostrar mensagem  
  printf("%s\n","999999_AED1"); 

  // mostrar valores 
  printf("\nMostrar dias da semana:\n");
  for(enum Semana dia=Domingo; dia<=Sabado; dia=dia+1)
  {
	 printf("%d: %s\n", dia, Semana_str[dia]);
  }  
  printf("\n");

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}
