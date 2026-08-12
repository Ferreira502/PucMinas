// 999999_AED1
// Funcoes literais
#include <stdio.h>
#include <stdlib.h> // para funcoes padroes: calloc, malloc
#include <string.h> // para funcoes com caracteres

/*
  Funcao principal.
 */
int main(void) 
{
  // definir dados
  char  s1 [  ] = "abc" ;// cadeia de caracteres
  char  s2 [10] ;        // espaco para cadeia de caracteres
  strcpy   (s2  , "def");// copiar caracteres
  char *s3      = "ghi" ;// apontar para constante 
  
  // iniciar
  printf ("%s\n","999999_AED1"); 

  // aplicar funcoes
  pritnf ("\nAplicar funcoes\n");
  // mostrar valor e tamanho
  printf ("s1 = [%s] (%d)\n", s1, strlen(s1) );
  printf ("s2 = [%s] (%d)\n", s2, strlen(s2) );
  printf ("s3 = [%s] (%d)\n", s3, strlen(s3) );
  printf ("\n");
  
  // mostrar valor apontado
  s3 = &s1[0];  // obter endereco do primeiro caractere
  printf ("s1 = [%s] (%d)\n", s3, strlen(s3));
  s3 = &s2[0];  // obter endereco do primeiro caractere
  printf ("s2 = [%s] (%d)\n", s3, strlen(s3));
  printf ("\n");
  
  strcat(s2,s1);   // concatenar
  printf ("s1 = [%s] (%d)\n", s1, strlen(s1));
  printf ("s2 = [%s] (%d)\n", s2, strlen(s2));
  printf ("\n");
  
  s3 = s1;         // identicos
  printf ("s1 = [%s] (%d) (%p)\n", 
           s1, strlen(s1), &s1[0]);
  printf ("s3 = [%s] (%d) (%p)\n", 
           s3, strlen(s3), s3    );
  printf ("\n");

  // reservar area para armazenar
  s3 = calloc(strlen(s1)+1, sizeof(char));
  strcpy(s3,s1);   // copiar conteudo
  
  printf ("s1 = [%s] (%d) (%p)\n", 
           s1, strlen(s1), &s1[0]);
  printf ("s3 = [%s] (%d) (%p)\n", 
           s3, strlen(s3), s3    );
  printf ("\n");

  s3 = strdup(s1); // duplicar
  printf ("s1 = [%s] (%d) (%p)\n", 
           s1, strlen(s1), &s1[0]);
  printf ("s3 = [%s] (%d) (%p)\n", 
           s3, strlen(s3), s3    );
  printf ("\n");

  // comparar
  if (strcmp(s1,s3) == 0) // pela igualdade
     printf("%s igual a %s\n"   , s1, s3);
  if (strcmp(s1,s3) != 0) // pela diferenca
     printf("%s igual a %s\n"   , s1, s3);
  if (strcmp(s1,s2) <  0) // antecessor
     printf("%s antecede a %s\n", s1, s2);
  if (strcmp(s2,s1) >  0) // sucessor
     printf("%s sucede a %s\n"  , s2, s1);
  printf ("\n");

  // mostrar cada letra separadamente
  for (int x=0; x < strlen(s1); ++x)
      printf("%c ", s1[x]);
  printf ("\n");
	  
  // mostrar cada letra separadamente 
  // com apontador
  for (int x=0; x < strlen(s1); x++)
      printf("%c ", *(s1+x));
  printf ("\n");
	  
  // mostrar cada letra separadamente 
  // com apontador operado aritmeticamente
  s3 = &s1[0];
  while ( *s3 )
  {
     printf("%c ", *s3);
	 s3++;
  }
  printf ("\n");
	    
  // mostrar cada letra separadamente
  // em ordem inversa, com indexador
  for (int x=strlen(s1)-1; x>=0; --x)
      printf("%c ", s1[x]);
  printf ("\n");
  printf ("\n");
	  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
  return (0);
}


