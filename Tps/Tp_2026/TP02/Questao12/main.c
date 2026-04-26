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
 * @param selecionados, tamanho
 * @reason Retorna o maior valor de capacidade
 * @return maior capacidade
 */
int get_maior( Restaurante *selecionados, int tamanho )
{
    int maior = selecionados[0].capacidade;

    for ( int i = 1; i < tamanho; i++ )
    {
        int val = selecionados[i].capacidade;

        if ( val > maior )
        {
            maior = val;
        }
    }

    return maior;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param selecionados, tamanho, contadores
 * @reason Ordena o array de restaurantes por capacidade usando counting sort
 *         e desempata por nome usando insercao
 */
void counting_sort( Restaurante *selecionados, int tamanho, int *contadores )
{
    int tam_count = get_maior(selecionados, tamanho) + 1;
    int count[tam_count];
    Restaurante ordenado[tamanho];

    // inicializar contagem
    for ( int i = 0; i < tam_count; i++ )
    {
        count[i] = 0;
    }

    // contar ocorrencias
    for ( int i = 0; i < tamanho; i++ )
    {
        contadores[0]++; // avanca comparacoes
        count[selecionados[i].capacidade]++;
    }

    // acumular contagem
    for ( int i = 1; i < tam_count; i++ )
    {
        count[i] += count[i - 1];
    }

    // ordenar
    for ( int i = tamanho - 1; i >= 0; i-- )
    {
        int idx = selecionados[i].capacidade;
        ordenado[count[idx] - 1] = selecionados[i];
        count[idx]--;
        contadores[1]++; // avanca movimentacoes
    }

    // copiar para o array original
    for ( int i = 0; i < tamanho; i++ )
    {
        selecionados[i] = ordenado[i];
    }

    // desempate por nome usando insercao
    for ( int i = 1; i < tamanho; i++ )
    {
        Restaurante tmp = selecionados[i];
        int j = i - 1;
        while ( j >= 0 && selecionados[j].capacidade == tmp.capacidade &&
                comparar_nome(selecionados[j].nome, tmp.nome) > 0 )
        {
            contadores[0]++; // avanca comparacoes
            selecionados[j + 1] = selecionados[j];
            contadores[1]++; // avanca movimentacoes
            j--;
        }
        selecionados[j + 1] = tmp;
    }
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
    counting_sort(selecionados, tamanho, contadores);
    fim = clock();
    total = ((fim - inicio) / (double)CLOCKS_PER_SEC) * 1000.0;

    // Salvar tempo e status em arquivo
    FILE *log = fopen("842527_countingsort.txt", "w");
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