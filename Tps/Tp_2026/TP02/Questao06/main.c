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
 * @param selecionados, tamanho, nome, contadores
 * @reason Pesquisa binaria pelo nome do restaurante
 * @return 1 se encontrado, 0 caso contrario
 */
int pesq_bin( Restaurante *selecionados, int tamanho, char *nome, int *contadores )
{
    int resp = 0;
    int esq = 0;
    int dir = tamanho - 1;
    int meio;

    while ( esq <= dir )
    {
        meio = ( esq + dir ) / 2;
        contadores[0]++; // avanca comparacoes

        int cmp = comparar_nome(nome, selecionados[meio].nome);

        if ( cmp == 0 )
        {
            resp = 1;
            esq = dir + 1;
        }

        else if ( cmp > 0 )
        {
            esq = meio + 1;
        }

        else
        {
            dir = meio - 1;
        }
    }

    return resp;
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Metodo principal que busca e pesquisa restaurantes por nome
 */
int main()
{
    ColecaoRestaurante colecao = ler_csv();
    Restaurante *restaurantes = get_restaurantes(&colecao);
    Restaurante selecionados[500];
    int tamanho = 0;
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

    // Ordenar por nome antes de pesquisar
    for ( int i = 1; i < tamanho; i++ )
    {
        Restaurante tmp = selecionados[i];

        int j = i - 1;

        while ( j >= 0 && comparar_nome(selecionados[j].nome, tmp.nome) > 0 )
        {
            selecionados[j + 1] = selecionados[j];
            j--;
        }

        selecionados[j + 1] = tmp;
    }

    // Pesquisa binaria
    inicio = clock();
    char nome[100];

    scanf(" %[^\n]", nome);

    while ( !(nome[0] == 'F' && nome[1] == 'I' && nome[2] == 'M') )
    {
        if ( pesq_bin(selecionados, tamanho, nome, contadores) )
        {
            printf("SIM\n");
        }

        else
        {
            printf("NAO\n");
        }

        scanf(" %[^\n]", nome);
    }
    
    fim = clock();

    total = ((fim - inicio) / (double)CLOCKS_PER_SEC); // mostra o tempo em segundos

    // Salvar tempo e status em arquivo
    FILE *log = fopen("842527_binaria.txt", "w");
    fprintf(log, "Tempo para pesquisar: %f s\n", total);
    fprintf(log, "Comparacoes: %d\n", contadores[0]);
    fclose(log);

    return 0;
}