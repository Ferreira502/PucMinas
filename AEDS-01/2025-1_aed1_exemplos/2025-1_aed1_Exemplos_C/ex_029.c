// 999999_AED1
// Definicao de tipo para enumeracao
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// definir novo tipo
typedef
  enum Semana   // descritor 
  { Domingo, Segunda, Terca, Quarta, Quinta, Sexta, Sabado }
Dias_da_Semana; // nome

/*
  Funcao principal.
 */
int main(void) 
{
  // definir dados
  char Semana_str[ ][8] // para guardar lista de nomes
  = {"Domingo", 
     "Segunda", 
     "Terca  ",
     "Quarta ",
     "Quinta ",
     "Sexta  ", 
     "Sabado "};

  // mostrar mensagem  
  printf("%s\n","999999_AED1"); 

  // mostrar valores 
  printf("\nMostrar dias da semana:\n");
  for(Dias_da_Semana dia=Domingo; dia<=Sabado; dia=dia+1)
  {
	 printf("%d: %s\n", dia, Semana_str[dia]);
  }  
  printf("\n");

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}
