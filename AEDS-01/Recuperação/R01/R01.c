/**
  * ------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Trabalho pratico: R01
  *
  * Objetivo:
  * Modelo de programa para a disciplina AED I
  * Sugestao para montar um trabalho pratico
  *
  * Autor:   Matricula: 842527  Nome: Gabriel Ferreira Pereira
  * Versao:  1.0                Data: 05/05/2025
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
  * - R01.c
  * - R01_00     ( no Linux   )
  * - R01_00.exe ( no Windows )
  *
  * Forma de compilacao:
  * - acionar o compilador no modo console 
  *   (terminal/janela de comandos):
  *
  *   Linux  : gcc -o ./R01 ./R01.c -lm
  *   Windows: gcc -o   R01   R01.c
  *
  * Forma de uso:
  * - acionar o programa   no modo console
  *   (terminal/janela de comandos):
  *
  *   Linux  :  ./R01
  *   Windows:    R01
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

#define MAX 100
// -------------------------- definicao de classe

/**
  * Modelo para definir exemplo de um programa.
  * Obs.: E' recomendado ter o nome do programa
  *       sem espacos em branco, acentos ou cedilha.
  */

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

// -------------------------- definicao de armazenadores globais

// -------------------------- definicao de prototipos

// -------------------------- definicao de metodos

/**
  * Metodo01.
  */

  int soma_divisores_pares(int valor) {
    int soma = 0;
    for (int i = 1; i <= valor; i++) 
    {
        if (valor % i == 0 && i % 2 == 0) 
        {
            soma++;
        }
    }
    return soma;
}

/**
 * Somar divisores ímpares de um número.
 */
int soma_divisores_impares(int valor) {
    int soma = 0;
    for (int i = 1; i <= valor; i++) 
    {
        if (valor % i == 0 && i % 2 != 0) 
        {
            soma++;
        }
    }
    return soma;
}

int verificaDivisores(int valor) {
    int pares = soma_divisores_pares(valor);
    int impares = soma_divisores_impares(valor);

    if (pares > impares) 
    {
        return 1;
    } else if (impares > pares) 
    {
        return -1;
    } else 
    {
        return 0;
    }
}

void metodo01 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo01" );
    int n = 0, x = 0, resultado = 0;

    printf("\nDigite o valor de n: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) 
    {
        printf("\n%d: ", i + 1);
        scanf("%d", &x);
        getchar();

        resultado = verificaDivisores(x);

        if (resultado == 1) {
            printf("\nMais divisores pares");
        } else if (resultado == -1) {
            printf("\nMais divisores impares\n");
        } else {
            printf("\nQuantidade igual de divisores pares e impares");
        }
    }

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo01 ( )

/**
  * Metodo02.
  */
 
bool Primo(int x) 
{
   if (x < 1) 
   {
      return false;
   }
   if (x == 1)
   {
      return true;
   }

   for (int i = 2; i <= sqrt(x); i++) 
   {
       if (x % i == 0) {
           return false;
       }
   }

   return true;
}
void metodo02 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo02" );
    int n = 0, x = 0;

    printf("\nDigite o valor de n: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) 
    {
      printf("\n%d: ", i + 1);
      scanf("%d", &x);
      getchar();

      if (Primo(x)) {
         printf("\n%d e primo\n", x);
      } else {
         printf("\n%d nao e primo", x);
      }
    }
    
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo02 ( )

/**
  * Metodo03.
  */

int testar_simbolo_logico(char c) 
{
   int resultado = 0;
   switch (c) {
       case '&':
       case '|':
       case '!':
           resultado = 1;
           break;
       default:
           break;
   }
   return resultado;
}

int testar_simbolo_aritmetico(char c) 
{
   int resultado = 0;
   switch (c) {
       case '+':
       case '-':
       case '*':
       case '/':
       case '%':
           resultado = 1;
           break;
       default:
           break;
   }
   return resultado;
}

int testar_simbolo_relacional(char c) 
{
   int resultado = 0;
   switch (c) {
       case '>':
       case '<':
       case '=':
           resultado = 1;
           break;
       default:
           break;
   }
   return resultado;
}

int testar_simbolo_separador(char c) 
{
   int resultado = 0;
   switch (c) {
       case ' ':
       case '.':
       case ',':
       case ';':
       case ':':
       case '_':
           resultado = 1;
           break;
       default:
           break;
   }
}

void metodo03 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo03" );
    int tamanho = 0;
    char palavra [MAX];
    printf("\nDigite a cadeia de caracteres: ");
    fgets(palavra, MAX, stdin);
    getchar();

    tamanho = strlen(palavra);

    for (int i = 0; i < tamanho; i++)
    {
      char c = palavra[i];
      printf("\n'%c' -> ", c);

      if (testar_simbolo_logico(c)) {
          printf("Operador logico");
      } else if (testar_simbolo_aritmetico(c)) {
          printf("Operador aritmetico");
      } else if (testar_simbolo_relacional(c)) {
          printf("Operador relacional");
      } else if (testar_simbolo_separador(c)) {
          printf("Separador");
      } else {
          printf("Outro simbolo");
      }
    }
    getchar();
    
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo03 ( )

/**
  * Metodo04.
  */

int testar_tipo(char s[], int *maiusc, int *minusc, int *dig, int *op, int *sep) {
    *maiusc = *minusc = *dig = *op = *sep = 0;
    int total = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        total++;

        switch (1) {
            case 1:
                if (c >= 'A' && c <= 'Z') {
                    (*maiusc)++;
                } else if (c >= 'a' && c <= 'z') {
                    (*minusc)++;
                } else if (c >= '0' && c <= '9') {
                    (*dig)++;
                } else if (testar_simbolo_logico(c) || testar_simbolo_aritmetico(c) || testar_simbolo_relacional(c)) {
                    (*op)++;
                } else if (testar_simbolo_separador(c)) {
                    (*sep)++;
                }
                break;
        }
    }

    return total;
}

void metodo04 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo04" );
    char palavra[100];
    int maiusc = 0, minusc = 0, dig = 0, op = 0, sep = 0;

    printf("Digite uma cadeia de caracteres: ");
    fgets(palavra, sizeof(palavra), stdin);
    getchar();
    palavra[strcspn(palavra, "\n")] = '\0';

    int total = testar_tipo(palavra, &maiusc, &minusc, &dig, &op, &sep);

    printf("\nResultado:\n");
    printf("\nMaiusculas : %d", maiusc);
    printf("\nMinusculas : %d", minusc);
    printf("\nDigitos    : %d", dig);
    printf("\nOperadores : %d", op);
    printf("\nSeparadores: %d", sep);
    printf("\nTotal lidos: %d", total);
    getchar();
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo04 ( )

/**
  * Metodo05.
  */
 double maiorDeTres(double a, double b, double c) {
    double maior = a;
    if (b > maior) {
        maior = b;
    }
    if (c > maior) {
        maior = c;
    }
    return maior;
}

void metodo05 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo05" );
    int n = 0, i = 0;
    double x = 0.0;
    double soma1 = 0.0, soma2 = 0.0, soma3 = 0.0;
    int cont1 = 0, cont2 = 0, cont3 = 0;
    double media1 = 0.0, media2 = 0.0, media3 = 0.0;
    
    printf("Digite a quantidade de valores: ");
    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%lf", &x);
        
        if (x < -21.75) {
            soma1 += x;
            cont1++;
        } else if (x <= 71.25) {
            soma2 += x;
            cont2++;
        } else {
            soma3 += x;
            cont3++;
        }
    }

    if (cont1 > 0) {
        media1 = soma1 / cont1;
    }
    if (cont2 > 0) {
        media2 = soma2 / cont2;
    }
    if (cont3 > 0) {
        media3 = soma3 / cont3;
    }

    printf("\nMedia dos valores < -21.75: %.2lf\n", media1);
    printf("Media dos valores entre -21.75 e 71.25: %.2lf\n", media2);
    printf("Media dos valores > 71.25: %.2lf\n", media3);
    getchar();

    double maiorMedia = maiorDeTres(media1, media2, media3);
    printf("Maior media: %.2lf\n", maiorMedia);
    getchar();

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

} // fim metodo05 ( )

/**
  * Metodo06.
  */
 int pertenceIntervalo(int a, int b, int x) {
    return (x > a && x < b);
}

double soma_inverso_do_cubo(int x) {
    if (x == 0) return 0.0;
    return 1.0 / (x * x * x);
}

void metodo06 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo06" ); 
    int a = 0, b = 0, x = 0;
    double soma = 0.0;

    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);
    getchar();

    printf("\nDigite valores inteiros (fim com -1): ");

    do {
        scanf("%d", &x);

        if (x != -1 && pertenceIntervalo(a, b, x)) {
            if (x % 2 != 0 && x % 3 != 0 && x != 0) {
                soma += soma_inverso_do_cubo(x);
            }
        }

    } while (x != -1);

    printf("Soma dos cubos dos inversos dos impares nao multiplos de 3 no intervalo: %lf\n", soma);
    getchar();
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

} // fim metodo06 ( )

/**
  * Metodo07.
  */
int noIntervalo(double a, double b, double valor) {
    return (valor > a && valor < b);
}

void metodo07 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo07" );
    double a = 0.0, b = 0.0, valor = 0.0;
    int dentro = 0, foraAcima = 0, foraAbaixo = 0;
    int totalFora = 0;

    printf("\nDigite os valores de a e b (reais): ");
    scanf("%lf %lf", &a, &b);
    getchar();

    printf("\nDigite valores reais (0.0 encerra): ");
    do {
        scanf("%lf", &valor);

        if (valor != 0.0) {
            if (noIntervalo(a, b, valor)) {
                dentro++;
            } else {
                if (valor < a)
                    foraAbaixo++;
                else if (valor > b)
                    foraAcima++;
            }
        }

    } while (valor != 0.0);

    totalFora = foraAcima + foraAbaixo;

    double porcentagemAcima = 0.0, porcentagemAbaixo = 0.0;
    if (totalFora > 0) {
        porcentagemAcima = (foraAcima * 100.0) / totalFora;
        porcentagemAbaixo = (foraAbaixo * 100.0) / totalFora;
    }

    // Resultados
    printf("\nValores dentro do intervalo: %d", dentro);
    printf("\nValores fora do intervalo: %d (acima: %d, abaixo: %d)", totalFora, foraAcima, foraAbaixo);
    printf("\nPorcentagem acima: %.2lf%%", porcentagemAcima);
    printf("\nPorcentagem abaixo: %.2lf%%", porcentagemAbaixo);
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

} // fim metodo07 ( )

/**
  * Metodo08.
  */
 int crescente(double x, double y, double z) {
    return (x < y && y < z);
}

int decrescente(double x, double y, double z) {
    return (x > y && y > z);
}

double maior(double x, double y, double z) {
    double m = x;
    if (y > m) m = y;
    if (z > m) m = z;
    return m;
}

double menor(double x, double y, double z) {
    double m = x;
    if (y < m) m = y;
    if (z < m) m = z;
    return m;
}


void metodo08 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo08" );
     double x = 0.0, y = 0.0, z = 0.0;

    printf("\nDigite os valores de x, y e z: ");
    scanf("%lf %lf %lf", &x, &y, &z);
    getchar();

    if (crescente(x, y, z)) {
        printf("\nOs valores estao em ordem crescente");
    } else if (decrescente(x, y, z)) {
        printf("\nOs valores estao em ordem decrescente");
    } else {
        printf("\nOs valores nao estao em ordem");
        printf("\nMaior valor: %.2lf\n", maior(x, y, z));
        printf("\nMenor valor: %.2lf\n", menor(x, y, z));
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

} // fim metodo08 ( )

/**
  * Metodo09.
  */

int sucessor(char x, char y) 
{
    return (y > x);
}

int crescenteChar(char x, char y, char z) 
{
    return (x < y && y < z);
}

int decrescenteChar(char x, char y, char z) 
{
    return (x > y && y > z);
}

void metodo09 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo09" );
     char x, y, z;

    printf("\nDigite tres caracteres (x, y, z): ");
    scanf(" %c %c %c", &x, &y, &z);
    getchar();

    if (crescenteChar(x, y, z)) {
        printf("\nOs caracteres estao em ordem alfabetica crescente");
    } else if (decrescenteChar(x, y, z)) {
        printf("\nOs caracteres estao em ordem alfabetica decrescente");
    } else {
        printf("\nOs caracteres nao estao em nenhuma ordem");
    }

    printf("\nx = '%c', y = '%c' e sucessor? ", x, y);
    if (sucessor(x, y)) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

} // fim metodo09 ( )

/**
  * Metodo10.
  */
int crescenteStr(char *x, char *y, char *z) 
{
    return (strcmp(x, y) < 0 && strcmp(y, z) < 0);
}

int decrescenteStr(char *x, char *y, char *z) 
{
    return (strcmp(x, y) > 0 && strcmp(y, z) > 0);
}

char* menorStr(char *x, char *y, char *z) 
{
    char *menor = x;
    if (strcmp(y, menor) < 0) menor = y;
    if (strcmp(z, menor) < 0) menor = z;
    return menor;
}

char* maiorStr(char *x, char *y, char *z)
{
    char *maior = x;
    if (strcmp(y, maior) > 0) maior = y;
    if (strcmp(z, maior) > 0) maior = z;
    return maior;
}


void metodo10 ( void )
{
 // identificar
    printf ( "\n%s\n", "Metodo10" );
    char x[50], y[50], z[50];

    printf("Digite tres cadeias de caracteres: ");
    scanf("%s %s %s", x, y, z);
    getchar();

    if (crescenteStr(x, y, z)) {
        printf("\nAs cadeias estao em ordem alfabetica crescente");
    } else if (decrescenteStr(x, y, z)) {
        printf("\nAs cadeias estao em ordem alfabetica decrescente");
    } else {
        printf("\nAs cadeias nao estao em nenhuma ordem");
        printf("\nMenor: %s", menorStr(x, y, z));
        printf("\nMaior: %s", maiorStr(x, y, z));
    }
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );

} // fim metodo10 ( )


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
        printf ( "%s\n", "R01 - v.0.0 - 05/05/2025"       );
        printf ( "%s\n", "Matricula: 842527 Nome: Gabriel Ferreira Pereira" );

     // mostrar opcoes
        printf ( "%s\n", "Opcoes:"         );
        printf ( "%s\n", " 0 - parar"      );
        printf ( "%s\n", " 1 - metodo 01   2 - metodo 02" );
        printf ( "%s\n", " 3 - metodo 03   4 - metodo 04" );
        printf ( "%s\n", " 5 - metodo 05   6 - metodo 06" );
        printf ( "%s\n", " 7 - metodo 07   8 - metodo 08" );
        printf ( "%s\n", " 9 - metodo 09  10 - metodo 10" );
        printf ( "%s\n", "" );        // para saltar linha

     // ler opcao
        printf ( "%s", "Qual a sua opcao? " );
        scanf  ( "%d", &opcao ); getchar ( );
        printf ( "%d",  opcao );

     // escolher acao
        switch ( opcao )
        {
           case  0:               break;
           case  1: metodo01 ( ); break;
           case  2: metodo02 ( ); break;
           case  3: metodo03 ( ); break;
           case  4: metodo04 ( ); break;
           case  5: metodo05 ( ); break;
           case  6: metodo06 ( ); break;
           case  7: metodo07 ( ); break;
           case  8: metodo08 ( ); break;
           case  9: metodo09 ( ); break;
           case 10: metodo10 ( ); break;
           default:
                    printf ( "\n%s\n\n", "ERRO: Opcao invalida." );
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