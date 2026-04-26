#include <stdio.h>
#include <time.h>
#include "ColecaoRestaurante.h"

/**
 * @author Gabriel Ferreira Pereira
 * @param a, b
 * @reason Compara dois nomes caractere por caractere
 * @return positivo se a > b, negativo se a < b, zero se iguais
 */
int comparar_nome( char *a, char *b )
{
    int i = 0;
    int cmp = 0;

    while ( a[i] != '\0' && b[i] != '\0' && cmp == 0 )
    {
        if ( a[i] > b[i] )
        {
            cmp = 1;
        }

        else if ( a[i] < b[i] )
        {
            cmp = -1;
        }
        i++;

    }

    return cmp;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param a, b
 * @reason Compara dois restaurantes por avaliacao e desempata por nome
 * @return positivo se a > b, negativo se a < b, zero se iguais
 */
int comparar( Restaurante *a, Restaurante *b )
{
    int cmp = 0;

    if ( a->avaliacao > b->avaliacao )
    {
        cmp = 1;
    }

    else if ( a->avaliacao < b->avaliacao )
    {
        cmp = -1;
    }

    else
    {
        cmp = comparar_nome(a->nome, b->nome);
    }

    return cmp;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param selecionados, esq, dir, contadores
 * @reason Funcao recursiva do quicksort
 */
void quicksort_rec( Restaurante *selecionados, int esq, int dir, int *contadores )
{
    int i = esq;
    int j = dir;

    Restaurante pivo = selecionados[( esq + dir ) / 2];

    while ( i <= j )
    {
        while ( comparar(&selecionados[i], &pivo) < 0 )
        {
            contadores[0]++; // avanca comparacoes
            i++;
        }

        while ( comparar(&selecionados[j], &pivo) > 0 )
        {
            contadores[0]++; // avanca comparacoes
            j--;
        }

        if ( i <= j )
        {
            Restaurante tmp = selecionados[i];
            selecionados[i] = selecionados[j];
            selecionados[j] = tmp;
            contadores[1]++; // avanca movimentacoes
            i++;
            j--;
        }
    }

    if ( esq < j )
    {
        quicksort_rec(selecionados, esq, j, contadores);
    }
    
    if ( i < dir )
    {
        quicksort_rec(selecionados, i, dir, contadores);
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @param selecionados, tamanho, contadores
 * @reason Ordena o array de restaurantes por avaliacao e desempata por nome
 */
void quicksort( Restaurante *selecionados, int tamanho, int *contadores )
{
    quicksort_rec(selecionados, 0, tamanho - 1, contadores);
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Metodo principal que busca, ordena e exibe restaurantes
 */
int main()
{
    ColecaoRestaurante colecao = ler_csv();
    Restaurante *restaurantes = get_restaurantes(&colecao);
    Restaurante selecionados[500];

    int tamanho = 0;
    char saida_linha[500];
    int id = 0;
    int contadores[2] = {0, 0};
    clock_t inicio, fim;
    double total = 0.0;

    while ( scanf("%d", &id) && id != -1 )
    {
        for ( int i = 0; i < get_tamanho(&colecao); i++ )
        {
            if ( restaurantes[i].id == id )
            {
                selecionados[tamanho] = restaurantes[i];
                tamanho++;
            }
        }
    }

    // Execucao do algoritmo de ordenacao
    inicio = clock();
    quicksort(selecionados, tamanho, contadores);
    fim = clock();
    total = ((fim - inicio) / (double)CLOCKS_PER_SEC) * 1000.0;

    // Salvar tempo e status em arquivo
    FILE *log = fopen("842527_quicksort.txt", "w");
    fprintf(log, "Tempo para ordenar: %f s\n", total);
    fprintf(log, "Comparacoes: %d\n", contadores[0]);
    fprintf(log, "Movimentacoes: %d\n", contadores[1]);
    fclose(log);

    for ( int i = 0; i < tamanho; i++ )
    {
        formatar_restaurante(&selecionados[i], saida_linha);
        printf("%s\n", saida_linha);
    }

    return 0;
}