/**
  * ------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Trabalho pratico: Exemplo00M0
  *
  * Objetivo:
  * Modelo de programa para a disciplina AED I
  * Sugestao para montar um trabalho pratico
  *
  * Autor:   Matricula: 842527  Nome: Gabriel Ferreira Pereira
  * Versao:  1.0                Data: 10/02/20025
  *
  * Dados:
  * - opcao de execucao escolhida pelo usuario
  *
  * Resultados:
  * - execucao de um teste de cada vez a escolha do usuario
  *
  * Condicoes:
  * - so' aceitara' as opcoes oferecidas.
  *
  * Arquivos:
  *
  * - Exemplo00M0.c
  * - Exemplo00M0     ( no Linux   )
  * - Exemplo00M0.exe ( no Windows )
  *
  * Forma de compilacao:
  * - acionar o compilador no modo console 
  *   (terminal/janela de comandos):
  *
  *   Linux  : gcc -o ./Exemplo00M0 ./Exemplo00M0.c -lm
  *   Windows: gcc -o   Exemplo00M0   Exemplo00M0.c
  *
  * Forma de uso:
  * - acionar o programa   no modo console
  *   (terminal/janela de comandos):
  *
  *   Linux  :  ./Exemplo00M0
  *   Windows:    Exemplo00M0
  *
  * Referencias:
  * - Exemplos mostrados em sala de aula
  * - Apostila: Fundamentos de Programacao - Notas de aulas
  *
  */

// -------------------------- classes nativas
//                            ou auxiliares

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <iso646.h>  // biblioteca para not, and, or, xor

// -------------------------- definicao de classe

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

#define M_PI 3.14

// -------------------------- definicao de armazenadores globais

// -------------------------- definicao de prototipos

// methods - only headers/signatures (prototypes)
void print_header(const char* message);
void print_footer(const char* message);

// -------------------------- definicao de metodos

/**
  * Metodo01.
  */
void metodo01 ( void )
{
  // identificar
  printf ( "\n%s\n", "Metodo01" );
  // mostrar mensagem com identificacao 
  printf("842527_AED1\n");
  // encerrar
  printf ( "\n%s\n", "Apertar ENTER para continuar." );
  getchar( );
} // fim metodo01 ( )

/**
  * Metodo02.
  */
void metodo02 ( void )
{
  // identificar
  printf ( "\n%s\n", "Metodo02" );
  // mostrar mensagem com formato 
  printf("%s\n","842527_AED1"); 
  
  // encerrar com pausa
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
} // fim metodo02 ( )

/**
  * Metodo03.
  */
void metodo03 ( void )
{
  // identificar
  printf ( "\n%s\n", "Metodo03" );
  // tipos de dados
  bool   status   = false; // logico
  int    contador =     0; // inteiro
  float  valor_1  = 0.00f; // real de precisao simples
  double valor_2  =  0.00; // real de precisao dupla
  char   letra    =   'A'; // caracteres 

  // mostrar mensagem  
  printf("%s\n","842527_AED1"); 

  // mostrar valores 
  printf("status  : %d \n", status  );  
  printf("contador: %d \n", contador);
  printf("valor_1 : %f \n", valor_1 );
  printf("valor_2 : %lf\n", valor_2 );
  printf("letra   : %c \n", letra   );

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
} // fim metodo03 ( )

/**
  * Metodo04.
  */
void metodo04 ( void )
{
  // identificar
  printf ( "\n%s\n", "Metodo04" );
  // definir dados
  char   x = 'A';
  int    y =  5 ;
  double z = 1.2;
  
  // iniciar
  printf ("%s\n","842527_AED1"); 
    
  printf("\nOperacoes\n");
  // conformar tipos (type casting)
  y = (int) z;       // truncar para parte inteira
  printf ("z = %lf\t y = %d\n", z, y );
  y = (int) x;       // obter codigo do simbolo
  printf ("x = %c \t y = %d\n", x, y );
  y = x;             // conformacao implicita
  printf ("x = %c \t y = %d\n", x, y );
  printf ("\n");

  x = (char) (32+y); // obter simbolo a partir do codigo
  printf ("y = %d \t x = %c\n", y, x );
  x = (char) (48+(int) z);
  printf ("z = %lf\t x = %c\n", z, x );
  printf ("\n");
                     
  z = z - (int) z;   // isolar parte fracionaria
  printf ("z = %lf\n", z );
  z = (double) x;    // conformacao explicita
  printf ("z = %lf\t x = %c\n", z, x );
  z = 1.0 * x;       // conformacao implicita
  printf ("z = %lf\t x = %c\n", z, x );
  printf ("\n");
  
  z = x / 2;         // metade inteira 
  printf ("z = %lf\n", z );
  z = (double) (x/2);// metade real
  printf ("z = %lf\n", z );
  z = (double) x / 2;
  printf ("z = %lf\n", z );
  z = x / (double) 2;
  printf ("z = %lf\n", z );
  z = (double) x / (double) 2;
  printf ("z = %lf\n", z );
  printf ("\n");
    
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
} // fim metodo04 ( )

/**
  * Metodo05.
  */
void metodo05 ( void )
{
  // identificar
  printf ( "\n%s\n", "Metodo05" );
  // definir dado
  bool p = true ;
  bool q = false;
  bool r = false;
  char a =   'A';
  char b =   'a';
  int  x =    5 ;
  int  y =    7 ;
  
  // mostrar mensagem com formato 
  printf("%s\n","842527_AED1"); 
  
  printf("\nComparacoes\n");
  printf("   (%c==%c) = %d\n", a, a, (a==a));
  printf("   (%c!=%c) = %d\n", a, a, (a!=a));
  printf("\n");
  
  r =  !  (a==a);        // NOT - logical negation
  printf(" ! (%c==%c) = %d\n", a, a, r);
  r =  !  (a!=a);        // NOT - logical complement
  printf(" ! (%c!=%c) = %d\n", a, a, r);
  r = not (a==a);        // NOT - logical negation
  printf("not(%c==%c) = %d\n", a, a, r);
  printf("\n");

  r = (x<y)  &&  (x!=0); // AND - logical conjunction
  printf("(%d<%d)  && (%d!=0)= %d\n", x,y,x,r);
  r = (x<y)  and (x!=0); // AND - logical conjunction
  printf("(%d<%d) and (%d!=0)= %d\n", x,y,x,r);
  r = (x>=y) ||  (x!=0); // OR  - logical disjunction
  printf("(%d>=%d) || (%d!=0)= %d\n", x,y,x,r);
  r = (x>=y) or  (x!=0); // OR  - logical disjunction
  printf("(%d<%d)  or (%d!=0)= %d\n", x,y,x,r);
  r = (x<=y) &&  (x> 0); // AND - logical conjunction
  printf("(%d<%d)  && (%d> 0)= %d\n", x,y,x,r);
  r = (x<=y) and (x> 0); // AND - logical conjunction
  printf("(%d<%d) and (%d> 0)= %d\n", x,y,x,r);
  printf("\n");

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );

} // fim metodo05 ( )

/**
  * Metodo06.
  */
void metodo06 ( void )
{
  float pi = 3.14; // com nome e tipo (melhor)
  // identificar
  printf ( "\n%s\n", "Metodo06" );
  // definir dado
  bool p = true ;
  bool q = false;
  bool r = false;
  
  // mostrar mensagem com formato 
  printf("%s\n","842527_AED1"); 
  
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

} // fim metodo06 ( )

/**
  * Metodo07.
  */
void metodo07 ( void )
{
  // identificar
  printf ( "\n%s\n", "Metodo07" );
  // mostrar mensagem  
  printf("%s\n","842527_AED1"); 

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

} // fim metodo07 ( )

/**
  * Metodo08.
  */
void metodo08 ( void )
{
  // identificar
  printf ( "\n%s\n", "Metodo08" );
  // mostrar mensagem  
  printf("%s\n","842527_AED1"); 
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

} // fim metodo08 ( )

/**
  * Metodo09.
  */
void metodo09 ( void )
{
  // identificar
  printf ( "\n%s\n", "Metodo09" );
  // mostrar mensagem  
  printf("%s\n","842527_AED1"); 
  int opcao = 0;

  // repetir ate escolher zero e parar
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

} // fim metodo09 ( )

/**
  * Metodo10.
  */
void metodo10 ( void )
{
  // identificar
  printf ( "\n%s\n", "Metodo10" );
  // definir dado
  int x = 0;
  
  // mostrar mensagem com formato 
  printf ("%s\n","842527_AED1"); 
  
  // repetir enquanto condicao verdadeira
  while(x < 5)
  {
   // mostrar valor atual
      printf("%d\n", x);
   // passar ao seguinte (em ordem crescente)  
      x = x+1;   
  }

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
} // fim metodo10 ( )

/**
  * Metodo11.
  */
 void metodo11 ( void )
 {
  // identificar
  printf ( "\n%s\n", "Metodo11" );
  // definir dado
  int x = 5;
  
  // mostrar mensagem com formato 
  printf ("%s\n","842527_AED1"); 
  
  // repetir enquanto condicao verdadeira
  while(x > 0)
  {
  // mostrar valor atual
    printf("%d\n", x);
  // passar ao seguinte (em ordem decrescente)  
    x = x-1;   
  }

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
 
 } // fim metodo11 ( )

 /**
  * Metodo12.
  */
void metodo12 ( void )
{
  // identificar
  printf ( "\n%s\n", "Metodo12" );
  // definir dado
  int x = 0;
  
  // mostrar mensagem com formato 
  printf ("%s\n","842527_AED1"); 
  
  // repetir enquanto condicao verdadeira
  for(x=0; x < 5; x=x+1)
  {
   // mostrar valores em ordem crescente
    printf("%d\n", x);
  }

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );

} // fim metodo12 ( )

/**
  * Metodo13.
  */
 void metodo13 ( void )
 {
  // identificar
  printf ( "\n%s\n", "Metodo13" );
  // definir dado
  int x = 0;
  
  // mostrar mensagem com formato 
  printf ("%s\n","842527_AED1"); 
  
  // repetir enquanto condicao verdadeira
  for(x = 5; x > 0; x=x-1)
  {
   // mostrar valores em ordem decrescente
   printf("%d\n", x);
  }

  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
 
 } // fim metodo13 ( )

 /**
  * Metodo14.
  */

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

void metodo14 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo14" );
    // iniciar
    print_header ("842527_AED1"); 
  
 // mostrar mensagem com formato (local)
    printf ("%s\n", "de volta ao main()"); 
  

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

} // fim metodo14 ( )

/**
  * Metodo15.
  */
 
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

 void metodo15 ( void )
 {
  // identificar
  printf ( "\n%s\n", "Metodo15" );
  // iniciar
  print_header ("842527_AED1"); 
  
  // mostrar mensagem com formato (local)
  printf ("%s\n", "de volta ao main()"); 
  // encerrar
  printf ( "\n%s\n", "Apertar ENTER para continuar." );
  getchar( );
 
 } // fim metodo15 ( )

 /**
  * Metodo16.
  */

// functions
/*
   Funcao para determinar o maior valor.
   @return maior valor
   @param x - primeiro valor
   @param y - segundo  valor
 */
int max(int x, int y)
{
    int z = 0;
    if ( x > y )
	   z = x;
	else
	   z = y;
	return ( z );
}

/*
   Funcao para determinar o menor valor.
   @return menor valor
   @param x - primeiro valor
   @param y - segundo  valor
 */
int min(int x, int y)
{
    int z = x;
    if ( y < x )
	   z = y;
	return ( z );
}

void metodo16 ( void )
{
  // identificar
    printf ( "\n%s\n", "Metodo16" );
  // definir dados
  int    x =  3 ;
  int    y =  5 ;
  int    z =  7 ;
  
  // iniciar
  printf ("%s\n","842527_AED1"); 

  // aplicar funcoes
  pritnf ("\nAplicar funcoes\n");
  printf ("maior(%d,%d) = %d\n", 
           x, y, max(x,y));  
  printf ("\n");
  printf ("maior(%d,%d,%d) = %d\n", 
           x, y, z, max(x,max(y,z)));  
  printf ("\n");
  printf ("menor(%d,%d) = %d\n", 
           x, y, min(x,y));  
  printf ("\n");
  printf ("menor(%d,%d,%d) = %d\n", 
           x, y, z, min(min(x,y),z));  
  printf ("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );

} // fim metodo16 ( )

/**
  * Metodo17.
  */
 
  /*
  Funcao para elevar ao quadrado.
  @return quadrado do valor
  @para x - valor com o qual calcular
 */
double sqr(double x)
{  return(x*x);      }

/*
  Funcao para calcular o logaritmo base 2.
  @return logaritmo base 2 do valor
  @para x - valor com o qual calcular
 */
double lg (double x)
{  return(log10(x)/log10(2.0)); }

 void metodo17 ( void )
 {
  // identificar
    printf ( "\n%s\n", "Metodo17" );
  // definir dados
  int    x =  0 ;
  double y = 1.5;
  
  // iniciar
  printf ("%s\n","842527_AED1"); 

  // aplicar funcoes
  pritnf ("\nAplicar funcoes\n");
  printf ("floor(%lf) = %lf\n", 
           y, floor(y));     // piso
  printf ("\n");
  printf ("ceil(%lf)  = %lf\n", 
           y, ceil(y) );     // teto 
  printf ("\n");
  x = trunc(y);              // truncar
  printf ("trunc(%lf) = %d\n", 
           y, x);  
  printf ("\n");
  x = round(y);              // arredondar
  printf ("round(%lf) = %d\n", 
           y, x);  
  printf ("\n");
  
  // funcoes trigonometricas em radianos
  y = sin(30.0*M_PI/180.0);  // seno
  printf ("sin(30) = %5.2lf\n", y );
  y = cos(60.0*M_PI/180.0);  // cosseno
  printf ("cos(60) = %5.2lf\n", y );
  y = atan(1.00)*180.0/M_PI; // arco tangente
  printf ("atan(1) = %5.2lf\n", y );
  printf ("\n");
  
  y = pow(2.0,3.0);          // potencia
  printf ("pow(2,3) = %5.0lf\n", y );
  y = lg(y);                 // logaritmo base 2
  printf ("lg(8,2)  = %5.0lf\n", y );
  printf ("\n");

  y = sqr(2.0);              // quadrado
  printf ("sqr(2)   = %5.0lf\n", y );
  y = sqrt(y);               // raiz quadrada
  printf ("sqrt(4)  = %5.0lf\n", y );
  printf ("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
 
 } // fim metodo17 ( )

 /**
  * Metodo18.
  */
void metodo18 ( void )
{
  // identificar
  printf ( "\n%s\n", "Metodo18" );
  // definir dados
  char  s1 [  ] = "abc" ;// cadeia de caracteres
  char  s2 [10] ;        // espaco para cadeia de caracteres
  strcpy   (s2  , "def");// copiar caracteres
  char *s3      = "ghi" ;// apontar para constante 
  
  // iniciar
  printf ("%s\n","842527_AED1"); 

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

} // fim metodo18 ( )

/**
  * Metodo19.
  */

/*
  Procedimento para mostrar arranjo de inteiros.
  @param n - quantidade de dados
  @param v - apontador para arranjo de inteiros
*/
void print_array(int n, int *v)
{
  for(int x=0; x < n; x=x+1)
  {  printf("%d ", v[x]);  }
  printf("\n");
}

/*
  Procedimento para ler arranjo de inteiros.
  @param n - quantidade de dados
  @param v - apontador para arranjo de inteiros
*/
void scan_array(int n, int *v)
{
  for(int x=0; x < n; x=x+1)
  {  scanf("%d", &v[x]); getchar( );  }
  printf("\n");  
}

 void metodo19 ( void )
 {
  // identificar
  printf ( "\n%s\n", "Metodo19" );
  // definir dados
  int a [ ] = {1,2,3};  // arranjo com valores
  int b [3];            // espaco para arranjo
                        // definir valores iniciais
  b[0] = 4; b[1] = 5; b[2] = 6;
                        // reservar espaco
  int *c    = malloc(3 * sizeof(int));
                        // definir valores iniciais
  if ( c )              // se houver espaco reservado
    for(int x=0; x < 3; x=x+1)
    { c[x] = (x+1)*10; }
  
  // mostrar mensagem  
  printf("%s\n","842527_AED1"); 

  // aplicar metodos sobre em arranjos
  printf("\nOperacoes com arranjos\n");
  printf("a:\n");
  print_array(3, a);
  printf("\n");
  
  printf("b:\n");
  print_array(3, b);
  printf("\n");

  printf("c:\n");
  print_array(3, c);
  printf("\n");

  // ler     dados para arranjo
  printf("Entrar dados:\n");
  scan_array(3, c);
  printf("c:\n");
  // mostrar dados em   arranjo
  printf("\nDados lidos (c):\n");
  print_array(3, c);
  printf("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
 
 } // fim metodo19 ( )

 /**
  * Metodo20.
  */

  /*
  Procedimento para mostrar matriz.
  @param m - quantidade de linhas
  @param n - quantidade de colunas
  @param v - referencia para matriz de inteiros
 */
void print_matrix(int m, int n, int v[][n])
{
  for(int x=0; x < m; x=x+1)
  {
    for(int y=0; y < n; y=y+1)
    {  printf("%d ", v[x][y]);  }
    printf("\n");
  }	
}

/*
  Procedimento para ler matriz.
  @param m - quantidade de linhas
  @param n - quantidade de colunas
  @param v - referencia para matriz de inteiros
*/
void scan_matrix(int m, int n, int v[][n])
{
  for(int x=0; x < m; x=x+1)
  {
    for(int y=0; y < n; y=y+1)
    {  scanf("%d", &v[x][y]); getchar( );  }
    printf("\n");
  }	
  printf("\n");  
}

void metodo20 ( void )
{
// identificar
printf ( "\n%s\n", "Metodo20" );
// definir dados
int a [ ][3] = {{1,2,3},  // definir com valores
{4,5,6}};
int b [2][3];             // espaco para matriz
            // definir valores iniciais
b[0][0] = 6; b[0][1] = 5; b[0][2] = 4;
b[1][0] = 3; b[1][1] = 2; b[1][2] = 1;

// mostrar mensagem  
printf("%s\n","842527_AED1"); 

// aplicar metodos sobre em matrizeos
printf("\nOperacoes com matrizes\n");
// mostrar dados
printf("a:\n");
print_matrix(2,3, a);
printf("\n");

printf("b:\n");
print_matrix(2,3, b);
printf("\n");

// ler dados para matriz
printf("Entrar dados:\n");
scan_matrix(2,3, a);
printf("a:\n");
print_matrix(2,3, a);
printf("\n");

// encerrar
printf("%s\n","Apertar ENTER para terminar.");
getchar( );

} // fim metodo20 ( )

 /**
  * Metodo21.
  */
 void metodo21 ( void )
 {
  // identificar
  printf ( "\n%s\n", "Metodo21" );
  // definir dados
  srand(time(NULL)); // semear aleatoriedade
  FILE *a = fopen("DATA.TXT","w"); // abrir para gravar
  int   n = 5;
  int   b = 0;  
  
  // mostrar mensagem  
  printf("%s\n","842527_AED1"); 

  // gravar valores
  fprintf(a, "%d\n", n);      // guardar a quantidade
  for(int x = 0; x < n; x = x+1)
  {  fprintf(a, "%d\n", rand()%100); }
  fclose(a);                  // fechar (INDISPENSAVEL)
	 
  // ler valores 
  a = fopen("DATA.TXT","r");  // abrir para ler
  fscanf(a, "%d", &n);        // obter  a quantidade
  // ler e mostrar dados
  printf("\nDados em arquivo:\n");
  for(int x = 0; x < n; x = x+1)
  {  
   fscanf(a, "%d", &b);   
	 printf("%d\n", b); 
  }
  fclose(a);                  // fechar (RECOMNDAVEL)
  
  printf("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
 
 } // fim metodo21 ( )

  /**
  * Metodo22.
  */
void metodo22 ( void )
{
  // identificar
  printf ( "\n%s\n", "Metodo22" );
  // definir dados
  FILE *a = fopen("DATA.TXT","r");
  int   n = 0;
  int  *b = NULL;  
  
  // mostrar mensagem  
  printf("%s\n","842527_AED1"); 

  // ler valores 
  a = fopen("DATA.TXT","r");
  fscanf(a, "%d", &n);
  // reservar espaco para guardar dados
  b = malloc(n * sizeof(int));
  for(int x = 0; x < n; x = x+1)
  {  fscanf(a, "%d", &b[x]);   }
  fclose(a);
  
  // mostrar dados
  printf("\nDados em arquivo:\n");
  for(int x = 0; x < n; x = x+1)
  {  printf("%2d\n", b[x]);   }
  printf("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );

} // fim metodo22 ( )


 /**
  * Metodo23.
  */

  // definir estrutura de dados
struct s_array
{
  int  n;   // tamanho
  int *data;// referencia para espaco de armazenamento  
};

 void metodo23 ( void )
 {
  // identificar
  printf ( "\n%s\n", "Metodo23" );
  // definir dados
  FILE *a = fopen("DATA.TXT","r");
  struct s_array b;
  
  // mostrar mensagem  
  printf("%s\n","842527_AED1"); 

  // ler valores 
  a = fopen("DATA.TXT","r");
  fscanf(a, "%d", &b.n);
  b.data = malloc(b.n * sizeof(int));
  for(int x = 0; x < b.n; x = x+1)
  {  fscanf(a, "%d", &b.data[x]);   }
  fclose(a);
  
  // mostrar valores 
  printf("\nDados guardados:\n");
  for(int x = 0; x < b.n; x = x+1)
  {  printf("%2d\n", b.data[x]);   }
  printf("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
 
 } // fim metodo23 ( )


  /**
  * Metodo24.
  */

  // definir novo tipo 
typedef
struct s_array // descritor do tipo
{
 int  n;
 int *data;  
}
Array;          // nome do tipo

void metodo24 ( void )
{
  // identificar
  printf ( "\n%s\n", "Metodo24" );
  // definir dados
  FILE *a = fopen("DATA.TXT","r");
  Array b;
  
  // mostrar mensagem  
  printf("%s\n","842527_AED1"); 

  // ler valores 
  a = fopen("DATA.TXT","r");
  fscanf(a, "%d", &b.n);
  b.data = malloc(b.n * sizeof(int));
  for(int x = 0; x < b.n; x = x+1)
  {  fscanf(a, "%d", &b.data[x]);}
  fclose(a);
  
  // mostrar valores 
  printf("\nDados guardados:\n");
  for(int x = 0; x < b.n; x = x+1)
  {  printf("%2d\n", b.data[x]); }
  printf("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );

} // fim metodo24 ( )


 /**
  * Metodo25.
  */

  // definir novo tipo 
typedef
struct s_array // descritor do tipo
{
 int  n;
 int *data;  
}
Array;          // nome do tipo

 void metodo25 ( void )
 {
  // identificar
  printf ( "\n%s\n", "Metodo25" );
  // definir dados
  FILE  *a = fopen("DATA.TXT","r");
  Array *b = NULL;
  
  // mostrar mensagem  
  printf("%s\n","842527_AED1"); 

  // ler valores 
  a = fopen("DATA.TXT","r");
  b = malloc(1 * sizeof(Array));
  // testar se ha' espaco para guardar dados
  if (b != NULL)
  {
     // ler dados com apontadores
     fscanf(a, "%d", &(*b).n);
     (*b).data = malloc((*b).n * sizeof(int));
     for(int x = 0; x < (*b).n; x = x+1)
     {  fscanf(a, "%d", &(*b).data[x]);}
  
     // mostrar valores
     printf("\nDados guardados:\n");
     for(int x = 0; x < (*b).n; x = x+1)
     {  printf("%2d\n", (*b).data[x]); }
  }
  fclose(a);
  printf("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
 
 } // fim metodo25 ( )


  /**
  * Metodo26.
  */

  // definir novo tipo 
typedef
struct s_array // descritor do tipo
{
 int  n;
 int *data;  
}
Array;          // nome do tipo

void metodo26 ( void )
{
  // identificar
  printf ( "\n%s\n", "Metodo26" );
  // definir dados
  FILE  *a = fopen("DATA.TXT","r");
  Array *b = NULL;
  
  // mostrar mensagem  
  printf("%s\n","842527_AED1"); 

  // ler valores 
  a = fopen("DATA.TXT","r");
  // reservar espaco para guardar dados
  b = malloc(1 * sizeof(Array));
  // testar se ha' espaco para guardar dados
  if (b != NULL)
  {
     // ler dados com apontadores (outra notacao)
     fscanf(a, "%d", &b->n);
     b->data = malloc(b->n * sizeof(int));
     for(int x = 0; x < b->n; x = x+1)
     {  fscanf(a, "%d", &b->data[x]);}
  
     // mostrar valores           (outra notacao)
     printf("\nDados guardados:\n");
     for(int x = 0; x < b->n; x = x+1)
     {  printf("%2d\n", b->data[x]); }
  }
  fclose(a);
  printf("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );

} // fim metodo26 ( )

  /**
  * Metodo27.
  */

  // definir novo tipo 
typedef
struct s_matrix // descritor do tipo
{
 int   rows;
 int   columns;
 int **data;  
}
Matrix;          // nome do tipo

 void metodo27 ( void )
 {
  // identificar
  printf ( "\n%s\n", "Metodo27" );
  // definir dados
  Matrix *a = NULL;
  
  // mostrar mensagem  
  printf("%s\n","842527_AED1"); 

  // reservar espaco para descritor 
  a = malloc(1 * sizeof(Matrix));
  // testar se ha' espaco reservado 
  if(a == NULL)
  {
    // mostrar codigo de erro    
    printf("Erro = %d\n", errno);
    perror("Error");
  }
  else 
  {
    // reservar espaco para guardar linhas
    a->rows    = 2;
    a->columns = 3;
    a->data    = malloc(a->rows * sizeof(int*));
    // testar se ha' espaco para guardar dados
    if (a->data != NULL)
    {
       // reservar espaco para guardar colunas
       for(int x=0; x<2; x=x+1)
       {
          a->data[x] = malloc(a->columns * sizeof(int));
          if (a->data[x])
          {  // ler dados com apontadores
             printf("\nDados para a linha %d matriz:\n", x);       
             for(int y = 0; y < a->columns; y = y+1)
             {  scanf("%d", &a->data[x][y]);  }
          }
       }
  
       // mostrar valores
       printf("\nDados guardados:\n");       
       for(int x = 0; x < a->rows; x = x+1)
       {
          for(int y = 0; y < a->columns; y = y+1)
          {  printf("%2d\t", a->data[x][y]); }
          printf("\n");
       }
	}
  }
  printf("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );
 
 } // fim metodo27 ( )

   /**
  * Metodo28.
  */

  // definir enumeracao (constantes em sequencia)
enum Semana 
{ Domingo, Segunda, Terca, Quarta, Quinta, Sexta, Sabado };

void metodo28 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo28" );
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
  printf("%s\n","842527_AED1"); 

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

} // fim metodo28 ( )

  /**
  * Metodo29.
  */

  // definir novo tipo
typedef
enum Semana   // descritor 
{ Domingo, Segunda, Terca, Quarta, Quinta, Sexta, Sabado }
Dias_da_Semana; // nome


 void metodo29 ( void )
 {
  // identificar
  printf ( "\n%s\n", "Metodo29" );
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
  printf("%s\n","842527_AED1"); 

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
 
 } // fim metodo29 ( )

   /**
  * Metodo30.
  */
void metodo30 ( void )
{
  // identificar
  printf ( "\n%s\n", "Metodo30" );
  // mostrar mensagem  
  printf("%s\n","842527_AED1"); 

  // mostrar valores 
  printf("\nQuantidade de argumentos: %d\n", argc);
  printf("\nArgumentos:\n");
  for(int x = 0; x < argc; x = x+1)
  {  printf("%d: %s\n", x, argv[x]); }
  printf("\n");
  
  // encerrar
  printf("%s\n","Apertar ENTER para terminar.");
  getchar( );

} // fim metodo30 ( )

// -------------------------- definicao do metodo principal

int main ( void )
{
 // definir dados/resultados
    int opcao = 0;

 // repetir ate' desejar parar
    do
    {
     // identificar
        printf ( "\n" );             // para saltar linha
        printf ( "%s\n", "Lista_00 - v.0.0 - 10/02/2025"       );
        printf ( "%s\n", "Matricula: 842527 Nome: Gabriel Ferreira Pereira" );

     // mostrar opcoes
        printf ( "%s\n", "Opcoes:"         );
        printf ( "%s\n", " 0 - parar"      );
        printf ( "%s\n", " 1 - metodo 01   2 - metodo 02" );
        printf ( "%s\n", " 3 - metodo 03   4 - metodo 04" );
        printf ( "%s\n", " 5 - metodo 05   6 - metodo 06" );
        printf ( "%s\n", " 7 - metodo 07   8 - metodo 08" );
        printf ( "%s\n", " 9 - metodo 09  10 - metodo 10" );
        printf ( "%s\n", " 11- metodo 11  12 - metodo 12" );
        printf ( "%s\n", " 13- metodo 13  14 - metodo 14" );
        printf ( "%s\n", " 15- metodo 15  16 - metodo 16" );
        printf ( "%s\n", " 17- metodo 17  18 - metodo 18" );
        printf ( "%s\n", " 19- metodo 19  20 - metodo 20" );
        printf ( "%s\n", " 21- metodo 21  22 - metodo 22" );
        printf ( "%s\n", " 23- metodo 23  24 - metodo 24" );
        printf ( "%s\n", " 24- metodo 25  26 - metodo 26" );
        printf ( "%s\n", " 25- metodo 27  28 - metodo 28" );
        printf ( "%s\n", " 26- metodo 29  30 - metodo 30" );
        printf ( "%s\n", "" );        // para saltar linha

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
            case 12: metodo12( ); 
                break;
            case 13: metodo13 ( ); 
                break;
            case 14: metodo14 ( );
                break;
            case 15: metodo15 ( ); 
                break;
            case 16: metodo16 ( ); 
                break;
            case 17: metodo17 ( ); 
                break;
            case 18: metodo18 ( ); 
                break;
            case 19: metodo19 ( ); 
                break;
            case 20: metodo20 ( ); 
                break;
            case 21: metodo21 ( ); 
                break;
            case 22: metodo22 ( );      
                break;
            case 23: metodo23 ( ); 
                break;
            case 24: metodo24 ( ); 
                break;
            case 25: metodo25 ( );
                break;
            case 26: metodo26 ( ); 
                break;
            case 27: metodo27 ( ); 
                break;
            case 28: metodo28 ( ); 
                break;
            case 29: metodo29 ( ); 
                break;
            case 30: metodo30 ( ); 
                break;
            default: printf ( "\n%s\n\n", "ERRO: Opcao invalida." );
                break;
        } // fim escolher
    }
    while ( opcao != 0 );

 // encerrar execucao
    printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
    getchar( );

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