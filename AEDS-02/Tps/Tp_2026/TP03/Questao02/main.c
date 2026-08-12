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
    
    while ( a[i] != '\0' && b[i] != '\0' )
    {
        if ( a[i] > b[i] )
        {
            return 1;
        }

        else if ( a[i] < b[i] )
        {
            return -1;
        }
      
        i++;
    }

    if ( a[i] == '\0' && b[i] == '\0' )
    {
        return 0;
    }

    if ( a[i] == '\0' )
    {
        return -1;
    }

    return 1;
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Metodo principal que busca e formata o restaurante com o ID fornecido
 *         e exibe na tela a lista de restaurantes selecionados
 */

void insercao_parcial( Restaurante* restaurantes, int tamanho, int k, int* contadores )
{
    // printf("entrei aqui");
    for ( int i = 1; i < tamanho; i++ )
    {
        Restaurante tmp = restaurantes[i];
        int j = 0;

        if ( i < k )
        {
            j = i - 1;
        }

        else
        {
            j = k - 1;
        }
        
        // printf("%d %d", i , j);
        while ( j >= 0 && comparar_nome(restaurantes[j].cidade, tmp.cidade) > 0 )
        {
            contadores[0]++;
            restaurantes[j + 1] = restaurantes[j];
            j--;
            contadores[1]++;
        }

        if ( j >= 0 )
        {
            contadores[0]++;
        }
        
        restaurantes[j + 1] = tmp;
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

    int k = 10;

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

    insercao_parcial(selecionados, tamanho, k, contadores );

    fim = clock();
    total = ((fim - inicio) / (double)CLOCKS_PER_SEC); // mostra o tempo em segundos

    // Salvar tempo e status em arquivo
    FILE *log = fopen("842527_insercao_parcial.txt", "w");
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
