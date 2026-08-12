// 999999_AED1
// Prototipos
#include <stdio.h>

// methods - only headers/signatures (prototypes)
void print_header(const char* message);
void print_footer(const char* message);

/*
  Funcao principal.
 */
int main(void) 
{
  // iniciar
  print_header ("999999_AED1"); 
  
  // mostrar mensagem com formato (local)
  printf ("%s\n", "de volta ao main()"); 
  
  // encerrar
  print_footer ("Apertar ENTER para terminar.");
  return (0);
}

// methods - full descriptions

/*
  Procedimento para mostrar cabecalho.
  @param message - texto a ser mostrado
 */
void print_header(const char* message)
{
  // mostrar mensagem com formato 
  printf ("%s\n", message); 
}

/*
  Procedimento para mostrar rodape'.
  @param message - texto a ser mostrado
 */
void print_footer(const char* message)
{
  // mostrar mensagem com formato 
  printf("%s\n", message);
  getchar( );
}

