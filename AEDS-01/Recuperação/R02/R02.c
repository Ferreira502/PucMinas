/*
 R02 - v0.0. - 09 / 06 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : g++ -o R02 R02.c
 Windows: g++ -o R02 R02.c

 Para executar em terminal (janela de comandos):
 Linux : ./R02
 Windows: R02
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "myarray.h"
#include "mymatrix.h"

#define MAX 100


// -------------------------- definicao de metodos

// --------------- METODO01-----------------
void metodo01() 
{
    printf("\n\tMetodo01\n");

    Array arr;
    freadArray(&arr, "DADOS1.TXT");

    printf("\nArranjo original:\n");
    printArray(&arr);

    sort(&arr);

    printf("\nArranjo em ordem decrescente:\n");
    printArray(&arr);

    FILE* arquivo = fopen("CRESCENTE.TXT", "w");

    if (arquivo != NULL) 
    {
        fprintf(arquivo, "%d\n", arr.length);
        for (int i = 0; i < arr.length; i++) 
        {
            fprintf(arquivo, "%d\n", arr.data[i]);
        }
        fclose(arquivo);
        printf("Dados gravados com sucesso\n");
    } 
    else 
    {
        printf("Nao foi possivel abrir o arquivo\n");
    }

    getchar();
    printf("\nApertar ENTER para continuar.\n");
    getchar();

    freeArray(&arr);
}

// --------------- METODO02-----------------
void metodo02() 
{
    printf("\n\tmetodo02\n");

    Array arr;
    freadArray(&arr, "CRESCENTE.TXT");

    printf("\nArranjo original:\n");
    printArray(&arr);

    inverterArray(&arr);

    printf("\nArranjo invertido:\n");
    printArray(&arr);

    FILE* arquivo = fopen("INVERTIDOS.TXT", "w");

    if (arquivo != NULL) 
    {
        fprintf(arquivo, "%d\n", arr.length);
        for (int i = 0; i < arr.length; i++) 
        {
            fprintf(arquivo, "%d\n", arr.data[i]);
        }
        fclose(arquivo);
        printf("Dados invertidos gravados com sucesso no arquivo INVERTIDOS.TXT\n");
    } 
    else 
    {
        printf("Nao foi possivel abrir o arquivo INVERTIDOS.TXT\n");
    }

    freeArray(&arr);
    getchar();
    printf("\nApertar ENTER para continuar.\n");
    getchar();
}


// --------------- METODO03-----------------

// Funcao para achar a mediana
double arranjo_mediana(Array* arr, int tamanho) 
{
    if (tamanho <= 0) return 0;

    
    double soma = 0.0;
    for (int i = 0; i < tamanho; i++) 
    {
        soma += arr->data[i];
    }
    double media = soma / tamanho;

    double menor_diferenca = fabs(arr->data[0] - media);
    int mais_proximo1 = arr->data[0];
    int mais_proximo2 = arr->data[0];
    int empate = 0;

    for (int i = 1; i < tamanho; i++) 
    {
        double diferenca = fabs(arr->data[i] - media);
        if (diferenca < menor_diferenca) 
        {
            menor_diferenca = diferenca;
            mais_proximo1 = arr->data[i];
            empate = 0;
        } else if (diferenca == menor_diferenca && arr->data[i] != mais_proximo1) 
        {
            mais_proximo2 = arr->data[i];
            empate = 1;
        }
    }

    if (empate) 
    {
        return (mais_proximo1 + mais_proximo2) / 2.0;
    } 
    else 
    {
        return (double)mais_proximo1;
    }
}

// Funcao para achar a moda
int arranjo_moda(Array* arr) 
{
    if (arr->length == 0) return 0;

    typedef struct {
        int valor;
        int frequencia;
    } Freq;

    Freq* freqArray = malloc(sizeof(Freq) * arr->length);
    int freqCount = 0;

    for (int i = 0; i < arr->length; i++) 
    {
        int val = arr->data[i];
        int j;
        for (j = 0; j < freqCount; j++) 
        {
            if (freqArray[j].valor == val) 
            {
                freqArray[j].frequencia++;
                break;
            }
        }
        if (j == freqCount)
         {
            freqArray[freqCount].valor = val;
            freqArray[freqCount].frequencia = 1;
            freqCount++;
        }
    }

    int moda_valor = freqArray[0].valor;
    int maior_frequencia = freqArray[0].frequencia;

    for (int i = 1; i < freqCount; i++) 
    {
        if (freqArray[i].frequencia > maior_frequencia) 
        {
            maior_frequencia = freqArray[i].frequencia;
            moda_valor = freqArray[i].valor;
        }
    }

    return moda_valor;
}


void metodo03() 
{
    printf("\n\tmetodo03\n");
    Array arr;
    int tamanho = 0;

    freadArray(&arr, "DADOS1.TXT");
    tamanho = arranjo_tamanho(&arr);

    printf("Arranjo:\n");
    printArray(&arr);

    double mediana = arranjo_mediana(&arr, tamanho);
    printf("\nMediana personalizada: %.2lf\n", mediana);

    int moda = arranjo_moda(&arr);
    printf("Moda: %d\n", moda);

    printf("\nApertar ENTER para continuar.\n");
    getchar();
}


// --------------- METODO04-----------------
void metodo04() 
{
    printf("\n\tmetodo04\n");

    Array arranjo1;
    Array arranjo2;
    Array arranjo3;

    freadArray(&arranjo1, "DADOS1.TXT");
    freadArray(&arranjo2, "DADOS2.TXT");

    arranjo3.data = (int*) malloc(MAX * sizeof(int));
    arranjo3.length = 0;
    arranjo3.optional = 0;

    printf("\nArranjo 1:\n");
    printArray(&arranjo1);

    printf("\nArranjo 2:\n");
    printArray(&arranjo2);

    arranjo_filtrar(&arranjo3, &arranjo1, &arranjo2);

    printf("\nElementos comuns sem repeticao:\n");
    printArray(&arranjo3);

    fprintArray(&arranjo3, "FILTRADOS.TXT");

    printf("\nApertar ENTER para continuar.\n");
    getchar();
}

// --------------- METODO05-----------------

// Funcao para verificar se a string contem apenas '0' e '1'
int ehBinarioValido(char *linha) 
{
    for (int i = 0; linha[i] != '\0' && linha[i] != '\n'; i++) 
    {
        if (linha[i] != '0' && linha[i] != '1') 
        {
            return 0;
        }
    }
    return 1;
}

// Funcao para converter vetor binario em numero decimal
int arranjo_paraDecimal(int binario[], int tamanho) 
{
    int decimal = 0;
    for (int i = 0; i < tamanho; i++) 
    {
        decimal = decimal * 2 + binario[i];
    }
    return decimal;
}

void metodo05() 
{
    printf("\n\tmetodo05\n");
    FILE *arquivo = fopen("BINARIOS1.TXT", "r");
    if (arquivo == NULL) 
    {
        printf("\nErro ao abrir o arquivo.\n");
        return;
    }

    char linha[100];
    int binario[100];
    int tamanho = 0;

    printf("\nConvertendo binarios validos do arquivo:\n\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL) 
    {
        linha[strcspn(linha, "\n")] = '\0';

        if (ehBinarioValido(linha)) 
        {
            tamanho = strlen(linha);
            for (int i = 0; i < tamanho; i++) 
            {
                binario[i] = linha[i] - '0';
            }

            int decimal = arranjo_paraDecimal(binario, tamanho);
            printf("Binario: %s => Decimal: %d\n", linha, decimal);
        } else {
            printf("Invalido: %s\n", linha);
        }
    }

    fclose(arquivo);
    
    getchar();
    printf("\nApertar ENTER para continuar.\n");
    getchar();
}

// --------------- METODO06-----------------

Matrix* createTridiagonalMatrix(int n) 
{
    if (n <= 0) return NULL;

    Matrix* mat = createMatrix(n, n, 0.0);
    if (!mat) return NULL;

    int total = 3 * n - 2;
    int val = total;

    for (int i = 0; i < n; i++) 
    {
        setMatrixValue(mat, i, i, val--);

        if (i < n - 1) 
        {
            setMatrixValue(mat, i, i + 1, val--);
        }

        if (i > 0) 
        {
            setMatrixValue(mat, i, i - 1, val--);
        }
    }

    return mat;
}


void metodo06() 
{
    printf("\n\tmetodo06\n");
    Matrix* mat1 = loadMatrixFromFile("MATRIZ1.TXT");
    if (!mat1) 
    {
        printf("\nErro ao carregar MATRIZ1.TXT\n");
    } else 
    {
        printf("\nMatriz lida de MATRIZ1.TXT:\n");
        printMatrix(mat1);
        freeMatrix(mat1);
    }

    int N = 0;
    printf("\nDigite o tamanho N da matriz quadrada: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Valor invalido para N\n");
    }

    Matrix* triMat = createTridiagonalMatrix(N);
    if (!triMat) 
    {
        printf("\nErro ao criar a matriz tridiagonal\n");
    }

    printf("\nMatriz tridiagonal crescente:\n");
    printMatrix(triMat);

    if (!saveMatrixToFile(triMat, "MATRIZ2.TXT")) 
    {
        printf("\nErro ao salvar MATRIZ2.TXT\n");
    } else 
    {
        printf("\nMatriz salva em MATRIZ2.TXT com sucesso\n");
    }

    freeMatrix(triMat);
    printf("\nApertar ENTER para continuar.\n");
    getchar();
}

// --------------- METODO07-----------------
void metodo07() 
{
    printf("\n\tmetodo07\n");
     Matrix* original = loadMatrixFromFile("MATRIZ1.TXT");
    if (!original) {
        printf("\nErro ao carregar MATRIZ1.TXT\n");
    }

    int N = 0;
    printf("\nigite o tamanho N da matriz quadrada: ");
    scanf("%d", &N);

    if (N <= 0) 
    {
        printf("\nTamanho invalido\n");
    }

    Matrix* mat = createMatrix(N, N, 0.0);
    if (!mat) 
    {
        printf("\nErro ao criar a matriz\n");
    }

    int value = N * 2; 

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (i + j == N - 1 || i + j == N - 2 || i + j == N) 
            {
                setMatrixValue(mat, i, j, value--);
            }
        }
    }

    printf("\nMatriz tridiagonal secundaria decrescente:\n");
    printMatrix(mat);

    if (saveMatrixToFile(mat, "MATRIZ2.TXT")) 
    {
        printf("\nMatriz salva em MATRIZ2.TXT com sucesso\n");
    } else 
    {
        printf("\nErro ao salvar MATRIZ2.TXT.\n");
    }

    freeMatrix(mat);
    if (original) freeMatrix(original);
    printf("\nApertar ENTER para continuar.\n");
    getchar();
}

// --------------- METODO08-----------------

// Função para verificar se a coluna j é uma sequência de potências de algum base
bool isColumnPower(Matrix* mat, int col)
{
    int rows = getRowCount(mat);
    if (rows < 2) return false;

    double base;
    if (!getMatrixValue(mat, 1, col, &base)) return false;

    if (base <= 0.0) return false;

    for (int i = 0; i < rows; i++)
    {
        double actual;
        if (!getMatrixValue(mat, i, col, &actual)) return false;

        double expected = pow(base, i);

        if (fabs(expected - actual) > 0.001)
        {
            return false;
        }
    }
    return true;
}



// Verifica se todas as colunas sao potencias crescentes
bool isPowerByColumns(Matrix* mat) 
{
    int cols = getColumnCount(mat);
    for (int j = 0; j < cols; j++) 
    {
        if (!isColumnPower(mat, j)) 
        {
            return false;
        }
    }
    return true;
}

void metodo08() 
{
    printf("\n\tmetodo08\n");
     Matrix* mat = loadMatrixFromFile("MATRIZ3.TXT");
    if (!mat) 
    {
        printf("\nErro ao carregar MATRIZ3.TXT\n");
    }

    printf("Matriz lida:\n");
    printMatrix(mat);

    if (isPowerByColumns(mat)) 
    {
        printf("\nA matriz apresenta a caracteristica: potencias por colunas\n");
    } else 
    {
        printf("\nA matriz NAO apresenta a caracteristica desejada\n");
    }

    freeMatrix(mat);
    printf("\nApertar ENTER para continuar.\n");
    getchar();
}

// --------------- METODO09-----------------

// Verifica se a coluna segue potências decrescentes
bool isColumnPowerDescending(const Matrix* mat, int col) 
{
    int rows = mat->rows;
    if (rows < 2) return false;

    double top, second;
    if (!getMatrixValue(mat, 0, col, &top) || !getMatrixValue(mat, 1, col, &second)) return false;
    if (second == 0) return false;

    double base = top / second;

    for (int i = 0; i < rows; i++) 
    {
        double expected = pow(base, rows - 1 - i);
        double actual;
        if (!getMatrixValue(mat, i, col, &actual)) return false;
        if (fabs(expected - actual) > 0.001) {
            return false;
        }
    }

    return true;
}

void metodo09() 
{
    printf("\n\tmetodo09\n");
    
    Matrix* mat = readMatrix("MATRIZ4.TXT");
    if (!mat) 
    {
        printf("Erro ao ler o arquivo MATRIZ4.TXT\n");
    }

    printf("Matriz lida:\n");
    printMatrix(mat);

    bool allColsValid = true;

    for (int j = 0; j < mat->cols; j++) 
    {
        if (!isColumnPowerDescending(mat, j)) 
        {
            allColsValid = false;
        }
    }

    if (allColsValid) 
    {
        printf("\nA matriz APRESENTA a caracteristica desejada\n");
    } else {
        printf("\nA matriz NAO apresenta a caracteristica desejada\n");
    }

    getchar();
    freeMatrix(mat);
    printf("\nApertar ENTER para continuar.\n");
    getchar();
}

// --------------- METODO10-----------------

typedef struct 
{
    char nome[MAX];
    int codigo;
    double preco;
} Supermercado;


void metodo10() 
{
    printf("\n\tmetodo10\n");
    FILE* arquivo = fopen("DADOS3.TXT", "r");
    if (arquivo == NULL) 
    {
        printf("\nErro ao abrir o arquivo\n");
    }

    int N;
    fscanf(arquivo, "%d", &N);

    if (N < 2) {
        printf("\nE necessario pelo menos dois supermercados.\n");
        fclose(arquivo);
        return;
    }

    Supermercado lista[MAX];
    for (int i = 0; i < N; i++) 
    {
        fscanf(arquivo, "%s %d", lista[i].nome, &lista[i].codigo);
    }

    for (int i = 0; i < N; i++) 
    {
        fscanf(arquivo, "%lf", &lista[i].preco);
    }

    fclose(arquivo);

    double soma = 0.0;
    for (int i = 0; i < N; i++) 
    {
        soma += lista[i].preco;
    }
    double media = soma / N;

    printf("\nPreco medio: %.2lf\n", media);

    printf("\nSupermercados com precos abaixo da media:\n");
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (lista[i].preco < media) {
            printf("- %s (Codigo: %d) -> R$ %.2lf\n", lista[i].nome, lista[i].codigo, lista[i].preco);
            count++;
        }
    }

    if (count < 2) {
        printf("\nApenas %d supermercado com preco abaixo da media\n", count);
    }

    printf("\nApertar ENTER para continuar.\n");
    getchar();
}

// identificar
 void menuOpcoes ( void ) 
 {
   printf ( "\n" );             // para saltar linha
   printf ( "%s\n", "R02 - v.0.0 - 09/06/2025"       );
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