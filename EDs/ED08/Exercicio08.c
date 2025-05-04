/*
 Exercicio07 - v0.0. - 29 / 04 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exercicio08 exercicio08.c
 Windows: gcc -o exercicio08 exercicio08.c
 Para executar em terminal (janela de comandos):
 Linux : ./exercicio08
 Windows: exercicio08
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

void lerPares(int tamanho, int  vet[])
{
    int x = 0;
    for(int i = 0; i < tamanho; i++)    
    {
        printf("\nDigite o valor da posicao %d do vetor: ", i + 1);
        scanf("%d", &x);

        if ( ( x % 2 == 0 ) && x > 0 ) 
        {
            vet[i] = x; 
        }
        else {
            vet[i] = 0;
        }
    }
}

void metodo01( void ) 
{
// Identificar
   printf("\n%s\n", "\n\tMetodo0811");
   int n = 0, vetor[MAX];

    printf("\nEscreva o tamanho do vetor: ");
    scanf("%d", &n);

    if (n > 0)   
    {
        lerPares(n, vetor);

        // Mostrar todo o vetor:
        printf("\nVetor preenchido:\n");
        for (int i = 0; i < n; i++) 
        {
            printf("%d ", vetor[i]);
        }
    } 
    else 
    {
        printf("\nDigite um valor de n maior que 0");
    }   
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo01 ( )

/**
  * Metodo02.
  */

void gravarParesPositivos(int n, int arranjo[], char* nomeArquivo) 
{
  FILE *arquivo = fopen(nomeArquivo, "w");
  if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo para escrita.\n");
      return;
  }

  int contador = 0;

   for (int i = 0; i < n; i++) {
       if (arranjo[i] > 0 && arranjo[i] % 2 == 0) {
           contador++;
       }
   }

   fprintf(arquivo, "%d\n", contador);

   for (int i = 0; i < n; i++) {
       if (arranjo[i] > 0 && arranjo[i] % 2 == 0) {
           fprintf(arquivo, "%d\n", arranjo[i]);
       }
   }
   getchar();

   fclose(arquivo);
}

void metodo02 ( void )
{
// Identificar
   printf("\n%s\n", "\n\tMetodo0812");
   FILE *entrada;
   char nomeEntrada[] = "dados.txt";
   char nomeSaida[] = "pares_positivos.txt";
   int arr[100];
   int n = 0;

   entrada = fopen(nomeEntrada, "r");
   if (entrada == NULL) {
       printf("Erro ao abrir arquivo de entrada\n");
       getchar();
       return 1;
   }

   while (fscanf(entrada, "%d", &arr[n]) != EOF && n < 100) {
       n++;
   }
   fclose(entrada);

   gravarParesPositivos(n, arr, nomeSaida);

   printf("Dados gravados em '%s'\n", nomeSaida);
   getchar();
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo02 ( )

/**
  * Metodo03.
  */
void lerArquivo(int *n, int vetor[MAX], const char *nomeArquivo) 
{
   FILE *arquivo = fopen(nomeArquivo, "r");
   fscanf(arquivo, "%d", n);
   for (int i = 0; i < *n; i++) {
       fscanf(arquivo, "%d", &vetor[i]);
   }
   fclose(arquivo);
}

void metodo03 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0813");
   int inferior = 0, superior = 0, n = 0, vetor[MAX];
   FILE *arquivo = fopen("DADOS.TXT", "w");

    printf("Limite inferior: ");
    scanf("%d", &inferior);
    getchar();
    printf("Limite superior: ");
    scanf("%d", &superior);
    getchar();
    printf("Quantidade de numeros: ");
    scanf("%d", &n);
    getchar();

    fprintf(arquivo, "%d\n", n);
    for (int i = 0; i < n; i++) {
        vetor[i] = gerarInt(inferior, superior);
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    getchar();
    fclose(arquivo);
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo03 ( )

/**
  * Metodo04.
  */

int acharMenorPar(int n, int vetor[MAX]) 
{
    int menor = -1;
    for (int i = 0; i < n; i++) {
        if (vetor[i] % 2 == 0) {
            if (menor == -1 || vetor[i] < menor) 
            {
                menor = vetor[i];
            }
        }
    }
    getchar();
    return menor;
}

void metodo04 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo0814");
   int n = 0, vetor[MAX];
   lerArquivo(&n, vetor, "DADOS.TXT");
   int menor = acharMenorPar(n, vetor);
   printf("Menor valor par: %d\n", menor);
   getchar();

// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo04 ( )

/**
  * Metodo05.
  */
 
  int acharMaiorImparDivisivelPorTres(int n, int vetor[MAX]) 
{
  int maior = -1;
  for (int i = 0; i < n; i++) {
      if (vetor[i] % 2 == 1 && vetor[i] % 3 == 0) {
          if (maior == -1 || vetor[i] > maior) {
              maior = vetor[i];
          }
      }
  }
  getchar();
  return maior;
}

void metodo05 ( void )
{
 // Identificar
  printf("\n%s\n", "\n\tMetodo0815");
  int n = 0, vetor[MAX];
  lerArquivo(&n, vetor, "DADOS.TXT");
  int maior = acharMaiorImparDivisivelPorTres(n, vetor);
  printf("Maior impar multiplo de 3: %d\n", maior);

// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo05 ( )

/**
  * Metodo06.
  */

double acharMedia(int n, int vetor[MAX]) 
{
  if (n == 0) return 0;
  int soma = 0;
  for (int i = 0; i < n; i++) soma += vetor[i];
  getchar();
  return (double)soma / n; 
}

void metodo06( void )
{
// Identificar
   printf("\n%s\n", "\n\tMetodo0816");
   int n = 0, vetor[MAX];
   FILE *menorIgual, *maior;
   double media = 0;
   lerArquivo(&n, vetor, "DADOS.TXT");
   media = acharMedia(n, vetor);
   menorIgual = fopen("MENORES.TXT", "w");
   maior = fopen("MAIORES.TXT", "w");

   for (int i = 0; i < n; i++) {
       if (vetor[i] <= media) fprintf(menorIgual, "%d\n", vetor[i]);
       else fprintf(maior, "%d\n", vetor[i]);
   }

   fclose(menorIgual);
   fclose(maior);
   printf("Media: %.2lf\n", media);
   
   // Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo06()

/**
  * Metodo07.
  */

int estaOrdenadoDecrescente(int n, int vetor[MAX]) 
{
  for (int i = 0; i < n - 1; i++) {
      if (vetor[i] < vetor[i + 1]) return 0;
  }
  getchar();
  return 1;
}

void metodo07( void ) {
//identificar
    printf("\n%s\n", "\n\tMetodo0817");
    int n = 0, vetor[MAX];
    lerArquivo(&n, vetor, "DADOS.TXT");
    if (estaOrdenadoDecrescente(n, vetor)) printf("Ordenado decrescentemente.\n");
    else printf("Nao esta ordenado decrescentemente.\n");
    getchar();

// Encerrar
    printf("\n%s\n", "Apertar ENTER para continuar.");
    getchar();
}// fim metodo07()

/**
  * Metodo08.
  */

int acharValor(int valor, int inicio, int n, int vetor[MAX]) 
{
  for (int i = inicio; i < n; i++) 
  {
     if (vetor[i] == valor) return 1;
  }
  getchar();
  return 0;
}

void metodo08( void ) {
//Identificar
   printf("\n%s\n", "\n\tMetodo0818");
   int n = 0, vetor[MAX], valor = 0;
   lerArquivo(&n, vetor, "DADOS.TXT");
   printf("Valor a procurar: ");
   scanf("%d", &valor);
   getchar();
   
   if (acharValor(valor, 0, n, vetor)) printf("Valor encontrado.\n");
   else printf("Valor nao encontrado.\n");
   getchar();
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
}// fim metodo08()

/**
  * Metodo09.
  */

int acharPosicao(int valor, int inicio, int n, int vetor[MAX]) 
{
  for (int i = inicio; i < n; i++) 
  {
    if (vetor[i] == valor) return i;
  }
  getchar();
  return -1;
}

void metodo09 ( void )
{
// Identificar
   printf("\n%s\n", "\n\tMetodo0819");
   int n = 0, vetor[MAX], valor = 0;
   lerArquivo(&n, vetor, "DADOS.TXT");
   printf("Valor a procurar: ");
   scanf("%d", &valor);
   getchar();

   int pos = acharPosicao(valor, 0, n, vetor);
   if (pos >= 0) printf("Posicao: %d\n", pos);
   else printf("Valor nao encontrado.\n");
   getchar();
// encerrar
   printf("%s\n", "\nApertar ENTER para continuar\n");
   getchar( );

 } // fim metodo09 ( )

/**
  * Metodo10.
  */

int acharQuantos(int valor, int inicio, int n, int vetor[MAX]) 
{
  int count = 0;
  for (int i = inicio; i < n; i++) {
      if (vetor[i] == valor) count++;
  }
  getchar();
  return count;
}


void metodo10(void) 
{
// Identificar
    printf("\n%s\n", "\n\tMetodo820");
    int n = 0, vetor[MAX], valor = 0;
    lerArquivo(&n, vetor, "DADOS.TXT");
    printf("Valor a procurar: ");
    scanf("%d", &valor);
    getchar();

    int vezes = acharQuantos(valor, 0, n, vetor);
    printf("Quantidade: %d\n", vezes);
    getchar();
// Encerrar
    printf("\n\n%s\n", "Apertar ENTER para continuar.");
    getchar();
}// fim metodo 10 ()

/**
  * Metodo11.
  */

int divisoresPares(int x, int arr[MAX]) 
{
  int qtd = 0;
  for (int i = 1; i <= x; i++) {
      if (x % i == 0 && i % 2 == 0) {
          arr[qtd++] = i;
      }
  }
  getchar();
  return qtd;
}

void metodo11() {
// Identificar
    printf("\n%s\n", "\n\tMetodo08E1");
    int x = 0, qtd = 0, arr[MAX];
    FILE *f = fopen("DIVISORES.TXT", "w");

    printf("Digite um numero: ");
    scanf("%d", &x);
    getchar();

    qtd = divisoresPares(x, arr);
    for (int i = 0; i < qtd; i++) 
    {
      printf("%d ", arr[i]);
      fprintf(f, "%d\n", arr[i]);
    }
    printf("\n");
    getchar();
    
    fclose(f);
// Encerrar
    printf("\n\n%s\n", "Apertar ENTER para continuar.");
    getchar();
}//

 
/**
  * Metodo12.
  */

 int comecaOuTerminaComE(char *palavra) 
{
  int len = strlen(palavra);
  return (tolower(palavra[0]) == 'e' || tolower(palavra[len - 1]) == 'e');
}

void metodo12( void ) {
// Identificar
    printf("\n%s\n", "\n\tMetodo08E2");
    FILE *f = fopen("PALAVRAS.TXT", "r");
    char palavra[100];
    int count = 0;

    while (fscanf(f, "%s", palavra) != EOF && count < 10) 
    {
        if (!comecaOuTerminaComE(palavra)) 
        {
          printf("%s\n", palavra);
          count++;
        }
    }
    getchar();
    fclose(f);
// Encerrar
    printf("\n\n%s\n", "Apertar ENTER para continuar.");
    getchar();
}

// identificar
 void menuOpcoes ( void ) 
 {
   printf ( "\n" );             // para saltar linha
   printf ( "%s\n", "Exercicio08 - v.0.0 - 29/04/2025"       );
   printf ( "%s\n", "Matricula: 842527 Nome: Gabriel Ferreira Pereira" );

// mostrar opcoes
   printf ( "%s\n", "Opcoes:   "     );
   printf ( "%s\n", " 0 - parar"     );
   printf ( "%s\n", " 1 - metodo 0811" );
   printf ( "%s\n", " 2 - metodo 0812" );
   printf ( "%s\n", " 3 - metodo 0813" );
   printf ( "%s\n", " 4 - metodo 0814" );
   printf ( "%s\n", " 5 - metodo 0815" );
   printf ( "%s\n", " 6 - metodo 0816" );
   printf ( "%s\n", " 7 - metodo 0817" );
   printf ( "%s\n", " 8 - metodo 0818" );
   printf ( "%s\n", " 9 - metodo 0819" );
   printf ( "%s\n", " 10- metodo 0820" );
   printf ( "%s\n", " 11- metodo 08E1" );
   printf ( "%s\n", " 12- metodo 08E2" );
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