// 999999_AED1
// Funcoes matematicas
#include <stdio.h>
#include <math.h>  // para funcoes matematicas

#define M_PI 3.14

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

/*
  Funcao principal.
 */
int main(void) 
{
  // definir dados
  int    x =  0 ;
  double y = 1.5;
  
  // iniciar
  printf ("%s\n","999999_AED1"); 

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
  return (0);
}


