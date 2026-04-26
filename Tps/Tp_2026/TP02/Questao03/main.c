#include <stdio.h>
#include <time.h>
#include "ColecaoRestaurante.h"

/**
 * @author Gabriel Ferreira Pereira
 * @param a, b
 * @reason Compara dois nomes caractere por caractere
 * @return positivo se a > b, negativo se a < b, zero se iguais
 */
int compararNome( char *a, char *b )
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
 * @param selecionados, tamanho, comparacoes, movimentacoes
 * @reason Ordena o array de restaurantes pelo nome usando selecao
 */
void selecao( Restaurante *selecionados, int tamanho, int *comparacoes )
{
    for ( int i = 0; i < tamanho - 1; i++ )
    {

        int menor = i;
        
        for ( int j = i + 1; j < tamanho; j++ )
        {
            comparacoes[0]++; // avanca comparacoes
            
            if ( compararNome(selecionados[menor].nome, selecionados[j].nome) > 0 )
            {
                menor = j;
            }
        }
        
        if ( menor != i )
        {
            Restaurante tmp = selecionados[menor];
            selecionados[menor] = selecionados[i];
            selecionados[i] = tmp;
            comparacoes[1]++; // avanca movimentacoes
        }
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Metodo principal que busca e formata o restaurante com o ID fornecido
 *         e exibe na tela a lista de restaurantes selecionados ordenados
 */
int main()
{
    ColecaoRestaurante colecao = lerCsv();
    Restaurante *restaurantes = getRestaurantes(&colecao);
    Restaurante selecionados[500];
    int tamanho = 0;
    char saidaLinha[500];
    int id = 0;
    int contadores[2] = {0, 0};
    clock_t inicio, fim;
    double total;

    while ( scanf("%d", &id) && id != -1 )
    {
        for ( int i = 0; i < getTamanho(&colecao); i++ )
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
    selecao(selecionados, tamanho, contadores);
    fim = clock();
    total = (double)(fim - inicio); // mostra o tempo em ms

    // Salvar tempo e status em arquivo
    FILE *log = fopen("842527_selecao.txt", "w");
    fprintf(log, "Tempo para ordenar: %f ms.\n", total);
    fprintf(log, "Comparacoes: %d\n", contadores[0]);
    fprintf(log, "Movimentacoes: %d\n", contadores[1]);
    fclose(log);

    for ( int i = 0; i < tamanho; i++ )
    {
        formatar_restaurante(&selecionados[i], saidaLinha);
        printf("%s\n", saidaLinha);
    }

    return 0;
}