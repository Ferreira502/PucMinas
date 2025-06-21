/*
 Exercicio10 - v0.0. - 20 / 06 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux :  gcc -o exercicio15 exercicio15.c
 Windows: gcc -o exercicio15 exercicio15.c
 Para executar em terminal (janela de comandos):
 Linux : ./exercicio15
 Windows: exercicio15
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 100

// -------------------------- definicao de classe

/**
  * Metodo01.
  */

char* str_push_back(char *s, char c) 
{
    size_t len = 0;

    if (s == NULL) 
    {
        s = (char*) malloc(2 * sizeof(char));
        if (s == NULL) return NULL;
        s[0] = c;
        s[1] = '\0';
        return s;
    }

    len = strlen(s);

    char* temp = (char*) realloc(s, (len + 2) * sizeof(char));
    if (temp == NULL) return s;

    temp[len] = c;
    temp[len + 1] = '\0';

    return temp;
}

void metodo01( void ) 
{
// Identificar
  printf("\n%s\n", "\n\tMetodo01");
  char *texto = NULL;

    texto = str_push_back(texto, 'A');
    texto = str_push_back(texto, 'B');
    texto = str_push_back(texto, 'C');

    printf("Resultado: %s\n", texto);

    free(texto);
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo01 ( )

/**
  * Metodo02.
  */

char* str_pop_back(char *s) 
{
    if (s == NULL) 
    {
      return NULL;
    }

    size_t len = strlen(s);

    if (len == 0) 
    {
      return s; 
    }

    s[len - 1] = '\0';

    char* temp = realloc(s, len * sizeof(char));
    if (temp != NULL) 
    {
      return temp;
    } 
    else 
    {
      return s;
    }
}  

void metodo02 ( void )
{
// Identificar
  printf("\n%s\n", "\n\tMetodo02");
   char *texto = malloc(strlen("OLA") + 1);
   if (texto == NULL)
   {
      printf("\nERRO");
   } 

   strcpy(texto, "OLA");

   printf("Antes: %s\n", texto);

   texto = str_pop_back(texto);
   printf("Depois: %s\n", texto);

   texto = str_pop_back(texto);
   printf("Depois: %s\n", texto);

   free(texto);
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo02 ( )

/**
  * Metodo03.
  */

char* str_push_front(char c, char *s) 
{
    size_t len = 0;

    if (s != NULL) 
    {
      len = strlen(s);
    }

    char *temp = (char*) malloc((len + 2) * sizeof(char));
    if (temp == NULL) 
    {
      return NULL;
    }

    temp[0] = c;

    if (s != NULL) 
    {
      strcpy(temp + 1, s);
      free(s);
    } else 
    {
      temp[1] = '\0';
    }

    return temp;
}  

void metodo03 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo03");
   char *texto = NULL;

   texto = str_push_front('C', texto);
   texto = str_push_front('B', texto);
   texto = str_push_front('A', texto);

   printf("Resultado: %s\n", texto);

   free(texto);
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo03 ( )

/**
  * Metodo04.
  */

char* str_pop_front(char *s) 
{
    if (s == NULL) 
    {
      return NULL;
    }

    size_t len = strlen(s);

    if (len == 0) 
    {
      return s;
    }

    for (size_t i = 0; i < len; i++) 
    {
      s[i] = s[i + 1];
    }

    char *temp = realloc(s, len * sizeof(char));
    if (temp != NULL) 
    {
        return temp;
    } else 
    {
      return s;
    }
}

void metodo04 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo04");
   char *texto = malloc(6);
   if (texto == NULL)
   {
      printf("\ERRO");
   }

   strcpy(texto, "Hello");

   printf("Antes: %s\n", texto);

   texto = str_pop_front(texto);
   printf("Depois: %s\n", texto);

   texto = str_pop_front(texto); 
   printf("Depois: %s\n", texto);

   free(texto);
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo04 ( )

/**
  * Metodo05.
  */

char* str_push_mid(char *s, char c) 
{
    if (s == NULL) 
    {
        return NULL;
    }

    size_t len = strlen(s);

    if (len < 2) 
    {
        return s;
    }

    size_t meio = len / 2;

    char *temp = (char *) malloc((len + 2) * sizeof(char));
    if (temp == NULL) 
    {
        return s;
    }

    for (size_t i = 0; i < meio; i++)
    {
        temp[i] = s[i];
    }

    temp[meio] = c;

    for (size_t i = meio; i <= len; i++) 
    {
        temp[i + 1] = s[i];
    }

    free(s);
    return temp;
}

void metodo05 ( void )
{
// Identificar
  printf("\n%s\n", "\n\tMetodo05");

  char *texto = malloc(strlen("Hello") + 1);

  if (texto == NULL)
  {
      printf("\nERRO");
  }

  strcpy(texto, "Hello");

  printf("Antes: %s\n", texto);

  texto = str_push_mid(texto, '-');

  printf("Depois: %s\n", texto);

  free(texto);
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo05 ( )

/**
  * Metodo06.
  */

char* str_pop_mid(char *s) 
{
    if (s == NULL) 
    {
        return NULL;
    }

    size_t len = strlen(s);

    if (len < 2) 
    {
        return s;
    }

    size_t meio = len / 2;

    for (size_t i = meio; i < len; i++) 
    {
        s[i] = s[i + 1];
    }

    char *temp = realloc(s, len * sizeof(char));
    if (temp != NULL) 
    {
        return temp;
    } 
    else 
    {
        return s;
    }
}
  
void metodo06( void )
{
// Identificar
  printf("\n%s\n", "\n\tMetodo06");
  char *texto = malloc(strlen("Hello") + 1);

  if (texto == NULL)
  {
    printf("\nERRO");
  }

  strcpy(texto, "Hello");

  printf("Antes: %s\n", texto);

  texto = str_pop_mid(texto);

  printf("Depois: %s\n", texto);

  free(texto);
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo06 ( )

/**
  * Metodo07.
  */

char* str_insert(char *s, char c, int index) 
{
  if (s == NULL) 
  {

      if (index == 0) 
      {
          char *temp = malloc(2);
            
          if (temp == NULL) return NULL;
            
          temp[0] = c;
          temp[1] = '\0';
          return temp;
      } 
      else 
      {
          return NULL;
      }
  }

  size_t len = strlen(s);

  if (index < 0 || index > (int)len) 
  {
      return s;
  }

  char *temp = realloc(s, len + 2);
  if (temp == NULL) 
  {
      return s;
  }

  for (size_t i = len; i >= (size_t)index; i--) 
  {
      temp[i + 1] = temp[i];
      if (i == 0) break;
  }

  temp[index] = c;

  return temp;
}

void metodo07( void ) 
{
//identificar
  printf("\n%s\n", "\n\tMetodo07");
  const char *origem = "Hello";
  char *texto = malloc(strlen(origem) + 1);
  if (texto == NULL) 
  {
    printf("\nERRO");
  }

  strcpy(texto, origem);
  strcpy(texto, "Hello");

  printf("Antes: %s\n", texto);

  texto = str_insert(texto, 'X', 2);

  printf("Depois: %s\n", texto);

  free(texto);
  
  getchar();
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo07 ( )

/**
  * Metodo08.
  */

char* str_remove(char *s, int index) 
{
    if (s == NULL) 
    {
        return NULL;
    }

    size_t len = strlen(s);

    if (index < 0 || index >= (int)len) 
    {
        return s;
    }

    for (size_t i = index; i < len; i++) 
    {
        s[i] = s[i + 1];
    }

    char *temp = realloc(s, len);
    if (temp != NULL) 
    {
        return temp;
    } 
    else 
    {
        return s;
    }
}  

void metodo08( void ) 
{
//Identificar
  printf("\n%s\n", "\n\tMetodo08");
  char *texto = malloc(strlen("Hello") + 1);
  if (texto == NULL) return 1;

  strcpy(texto, "Hello");

  printf("Antes: %s\n", texto);

  texto = str_remove(texto, 1);

  printf("Depois: %s\n", texto);

  free(texto);
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo08 ( )

/**
  * Metodo09.
  */

char* str_chr(char *s, char c) 
{
    if (s == NULL) 
    {
        return NULL;
    }

    while (*s != '\0') 
    {
        if (*s == c) 
        {
            return s;
        }
        s++;
    }

    return NULL;
}

void metodo09 ( void )
{
// Identificar
  printf("\n%s\n", "\n\tMetodo09");

  char texto[] = "Hello, world!";
  char c = 'o';

  char *p = str_chr(texto, c);

  if (p != NULL) 
  {
      printf("\nCaractere '%c' encontrado na posicao: %ld\n", c, p - texto);
  } else 
  {
      printf("\nCaractere '%c' nao encontrado\n", c);
  }

// encerrar
  printf("%s\n", "\nApertar ENTER para continuar\n");
  getchar( );

 } // fim metodo09 ( )

/**
  * Metodo10.
  */

char* str_tok(char *s, char delimiter) 
{
    if (s == NULL || *s == '\0') 
    {
        return NULL;
    }

    char *pos = NULL;
    pos = strchr(s, delimiter);

    size_t len;
    if (pos != NULL) 
    {
        len = pos - s;
    } 
    else 
    {
        len = strlen(s);
    }

    char *token = (char *)malloc(len + 1);
    if (token == NULL) 
    {
        return NULL; 
    }

    strncpy(token, s, len);
    token[len] = '\0';

    return token;
}  

void metodo10( void ) 
{
// Identificar
  printf("\n%s\n", "\n\tMetodo10");

  char texto[] = "abc,def,ghi";
  char delimiter = ',';

  char *token = str_tok(texto, delimiter);
  if (token != NULL) 
  {
      printf("Token: %s\n", token);
      free(token);
  } 
  else 
  {
      printf("Nenhum token encontrado.\n");
  }
// Encerrar
  printf("\n\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo 10 ( )

/**
  * Metodo11.
  */

char* str_prefix(char *prefix, char *s) 
{
    if (prefix == NULL || s == NULL) 
    {
        return NULL;
    }

    size_t prefix_len = strlen(prefix);

    if (strncmp(s, prefix, prefix_len) == 0) 
    {
        return s;
    } 
    else 
    {
        return NULL;
    }
}  

void metodo11( void ) 
{
// Identificar
  printf("\n%s\n", "\n\tMetodoE1");

  char texto[] = "Hello, world!";
  char prefixo[] = "Hello";

  char *res = str_prefix(prefixo, texto);

  if (res != NULL) 
  {
      printf("'%s' inicia com '%s'\n", texto, prefixo);
  } else 
  {
       printf("'%s' NAO inicia com '%s'\n", texto, prefixo);
  }
// Encerrar
  printf("\n\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo 11 ( )

 
/**
  * Metodo12.
  */

char* str_suffix_chr(char *s, char *suffix) 
{
    if (s == NULL || suffix == NULL) 
    {
        return NULL;
    }

    size_t len_s = strlen(s);
    size_t len_suffix = strlen(suffix);

    if (len_suffix > len_s) 
    {
        return NULL;
    }

    char *start = s + (len_s - len_suffix);

    if (strcmp(start, suffix) == 0) 
    {
        return start;
    } else 
    {
        return NULL;
    }
}  

void metodo12( void ) {
// Identificar
  printf("\n%s\n", "\n\tMetodoE2");
  char texto[] = "exercicio15.c";
  char sufixo[] = ".c";

  char *res = str_suffix_chr(texto, sufixo);

  if (res != NULL) 
  {
      printf("'%s' termina com '%s'\n", texto, sufixo);
  } else 
  {
      printf("'%s' nao termina com '%s'\n", texto, sufixo);
  }
// Encerrar
  printf("\n\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo 12 ( )

// identificar
 void menuOpcoes ( void ) 
 {
   printf ( "\n" );             // para saltar linha
   printf ( "%s\n", "Exercicio15 - v.0.0 - 20/06/2025"       );
   printf ( "%s\n", "Matricula: 842527 Nome: Gabriel Ferreira Pereira" );

// mostrar opcoes
   printf ( "%s\n", "Opcoes:   "     );
   printf ( "%s\n", " 0 - parar"     );
   printf ( "%s\n", " 1 - metodo 01" );
   printf ( "%s\n", " 2 - metodo 02" );
   printf ( "%s\n", " 3 - metodo 03" );
   printf ( "%s\n", " 4 - metodo 04" );
   printf ( "%s\n", " 5 - metodo 05" );
   printf ( "%s\n", " 6 - metodo 06" );
   printf ( "%s\n", " 7 - metodo 07" );
   printf ( "%s\n", " 8 - metodo 08" );
   printf ( "%s\n", " 9 - metodo 09" );
   printf ( "%s\n", " 10- metodo 10" );
   printf ( "%s\n", " 11- metodo E1" );
   printf ( "%s\n", " 12- metodo E2" );
   printf ( "%s\n", "" );        // para saltar linha
 }


// -------------------------- definicao do metodo principal

 int main ( void )
 {
 // definir dados/resultados
    int opcao = 0;

 // repetir ate' desejar parar
    do
    {
      menuOpcoes();
     // ler opcao
        printf ( "%s", "Qual a sua opcao? " );
        scanf  ( "%d", &opcao ); getchar ( );
        printf ( "%d",  opcao );

     // escolher acao
        switch ( opcao )
        {
           case  0:               
                break;
           case  1: metodo01 ( ); 
                break;
           case  2: metodo02 ( ); 
                break;
           case  3: metodo03 ( );
                break;
           case  4: metodo04 ( ); 
                break;
           case  5: metodo05 ( ); 
                break;
           case  6: metodo06 ( ); 
                break;
           case  7: metodo07 ( ); 
                break;
           case  8: metodo08 ( ); 
                break;
           case  9: metodo09 ( ); 
                break;
           case 10: metodo10 ( ); 
                break;
           case 11: metodo11 ( );
                break;
           case 12: metodo12 ( );
                break;
           default: printf ( "\n%s\n\n", "ERRO: Opcao invalida." );
                break;
        } // fim escolher
    }
    while ( opcao != 0 );

 // encerrar execucao
    printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
    getchar( );

    return 0;
 } // end main ( )


/*
----------------------------- documentacao complementar

----------------------------- notas / observacoes / comentarios

----------------------------- previsao de testes

----------------------------- historico

Versao	Data		      Modificacao
  0.1	__/__		      esboco

 ---------------------------- testes

Versao	Teste
  0.1	01. ( OK )	      identificacao de programa

*/