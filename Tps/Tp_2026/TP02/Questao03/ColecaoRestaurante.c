#include "ColecaoRestaurante.h"
#include <stdio.h>
#include <string.h>

/**
 * @author Gabriel Ferreira Pereira
 * @param colecao objeto ColecaoRestaurante
 * @reason Retorna a quantidade de restaurantes da colecao
 * @return tamanho da colecao
 */
int getTamanho( ColecaoRestaurante *colecao )
{
    return colecao->tamanho;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param colecao, r
 * @reason Adiciona um restaurante na colecao
 */
void adicionar( ColecaoRestaurante *colecao, Restaurante r )
{
    colecao->restaurantes[colecao->tamanho] = r;
    colecao->tamanho++;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param colecao objeto ColecaoRestaurante
 * @reason Retorna o array de restaurantes da colecao
 * @return ponteiro para o array de restaurantes
 */
Restaurante* getRestaurantes( ColecaoRestaurante *colecao )
{
    return colecao->restaurantes;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param colecao objeto ColecaoRestaurante
 * @reason Imprime todos os restaurantes da colecao formatados
 */
void imprimir( ColecaoRestaurante *colecao )
{
    char saidaLinha[500];
    for (int i = 0; i < colecao->tamanho; i++)
    {
        formatar_restaurante(&colecao->restaurantes[i], saidaLinha);
        printf("%s\n", saidaLinha);
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Le o dataset do arquivo CSV e retorna a colecao de restaurantes
 * @return colecao de restaurantes
 */
ColecaoRestaurante lerCsv()
{
    ColecaoRestaurante colecao;
    colecao.tamanho = 0;

    FILE *f = fopen("restaurante.csv", "r");
    char linha[500];

    // pular cabecalho
    fgets(linha, 500, f);

    for (int i = 0; i < 500; i++)
    {
        fgets(linha, 500, f);
        linha[strcspn(linha, "\n")] = 0; // remover o \n do final
        Restaurante r = ler_restaurante(linha);
        adicionar(&colecao, r);
    }

    fclose(f);
    return colecao;
}