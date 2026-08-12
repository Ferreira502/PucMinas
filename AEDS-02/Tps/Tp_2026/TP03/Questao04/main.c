#include <stdio.h>
#include <time.h>
#include "ColecaoRestaurante.h"

/**
 * @author Gabriel Ferreira Pereira
 * @param a, b
 * @reason Compara duas datas pela ordem ano, mes e dia
 * @return positivo se a > b, negativo se a < b, zero se iguais
 */
int comparar_data( Data a, Data b )
{
    if ( a.ano != b.ano )
    {
        return a.ano - b.ano;
    }

    if ( a.mes != b.mes )
    {
        return a.mes - b.mes;
    }

    return a.dia - b.dia;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param a, b
 * @reason Compara dois restaurantes pela data de abertura e desempata pelo nome
 * @return positivo se a > b, negativo se a < b, zero se iguais
 */
int comparar_restaurante( Restaurante *a, Restaurante *b )
{
    int cmp = comparar_data(a->data_abertura, b->data_abertura);

    if ( cmp != 0 )
    {
        return cmp;
    }

    return strcmp(a->nome, b->nome);
}

/**
 * @author Gabriel Ferreira Pereira
 * @param array, tamHeap, contadores
 * @reason Constroi o heap maximo inserindo um elemento por vez
 */
void construir( Restaurante *array, int tamHeap, int *contadores )
{
    for ( int i = tamHeap; i > 1; i /= 2 )
    {
        // printf("construir: comparando %s com pai %s\n", array[i].nome, array[i / 2].nome);
        contadores[0]++;

        if ( comparar_restaurante(&array[i], &array[i / 2]) > 0 )
        {
            // printf("construir: trocando %s com %s\n", array[i].nome, array[i / 2].nome);
            Restaurante temp = array[i];
            array[i] = array[i / 2];
            array[i / 2] = temp;
            contadores[1] += 3;
        }

        else
        {
            i = 1;
        }
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @param array, i, tamHeap, contadores
 * @reason Retorna o indice do maior filho de um no heap
 * @return indice do maior filho
 */
int getMaiorFilho( Restaurante *array, int i, int tamHeap, int *contadores )
{
    int filho;

    if ( 2 * i == tamHeap )
    {
        filho = 2 * i;
    }

    else
    {
        contadores[0]++;

        if ( comparar_restaurante(&array[2 * i], &array[2 * i + 1]) > 0 )
        {
            filho = 2 * i;
        }

        else
        {
            filho = 2 * i + 1;
        }
    }

    return filho;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param array, tamHeap, contadores
 * @reason Reconstroi o heap maximo apos a remocao da raiz
 */
void reconstruir( Restaurante *array, int tamHeap, int *contadores )
{
    int i = 1;

    while ( i <= ( tamHeap / 2 ) )
    {
        int filho = getMaiorFilho(array, i, tamHeap, contadores);
        // printf("reconstruir: pai %s, maior filho %s\n", array[i].nome, array[filho].nome);
        contadores[0]++;

        if ( comparar_restaurante(&array[filho], &array[i]) > 0 )
        {
            // printf("reconstruir: trocando %s com %s\n", array[i].nome, array[filho].nome);
            Restaurante temp = array[i];
            array[i] = array[filho];
            array[filho] = temp;
            contadores[1] += 3;
            i = filho;
        }

        else
        {
            i = tamHeap;
        }
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @param array, n, contadores
 * @reason Ordena o array de restaurantes com heapsort
 */
void heapsort( Restaurante *array, int n, int *contadores )
{
    Restaurante arrayTmp[501];

    for ( int i = 0; i < n; i++ )
    {
        arrayTmp[i + 1] = array[i];
        contadores[1]++;
    }

    for ( int tamHeap = 2; tamHeap <= n; tamHeap++ )
    {
        // printf("heapsort: construindo heap com tamanho %d\n", tamHeap);
        construir(arrayTmp, tamHeap, contadores);
    }

    for ( int tamHeap = n; tamHeap > 1; tamHeap-- )
    {
        // printf("heapsort: movendo %s para a posicao %d\n", arrayTmp[1].nome, tamHeap);
        Restaurante temp = arrayTmp[1];
        arrayTmp[1] = arrayTmp[tamHeap];
        arrayTmp[tamHeap] = temp;
        contadores[1] += 3;
        reconstruir(arrayTmp, tamHeap - 1, contadores);
    }

    for ( int i = 0; i < n; i++ )
    {
        array[i] = arrayTmp[i + 1];
        contadores[1]++;
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Metodo principal que busca e formata o restaurante com o ID fornecido
 *         e exibe na tela a lista de restaurantes selecionados ordenados
 */
int main()
{
    Colecao_restaurante colecao = ler_csv();
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

    inicio = clock();
    heapsort(selecionados, tamanho, contadores);
    fim = clock();
    total = ( fim - inicio ) / (double) CLOCKS_PER_SEC;

    FILE *log = fopen("842527_heapsort.txt", "w");
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
