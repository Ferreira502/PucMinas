#include "ColecaoRestaurante.h"
#include <stdio.h>
#include <string.h>

int getTamanho(ColecaoRestaurante *colecao)
{
    return colecao->tamanho;
}

void adicionar(ColecaoRestaurante *colecao, Restaurante r)
{
    colecao->restaurantes[colecao->tamanho] = r;
    colecao->tamanho++;
}

Restaurante* getRestaurantes(ColecaoRestaurante *colecao)
{
    return colecao->restaurantes;
}

void imprimir(ColecaoRestaurante *colecao)
{
    char buffer[500];
    for (int i = 0; i < colecao->tamanho; i++)
    {
        formatar_restaurante(&colecao->restaurantes[i], buffer);
        printf("%s\n", buffer);
    }
}

ColecaoRestaurante lerCsv()
{
    ColecaoRestaurante colecao;
    colecao.tamanho = 0;

    FILE *f = fopen("restaurante.csv", "r");
    char linha[500];

    // pular cabecalho
    fgets(linha, sizeof(linha), f);

    for (int i = 0; i < 500; i++)
    {
        fgets(linha, sizeof(linha), f);
        // remover o \n do final
        linha[strcspn(linha, "\n")] = 0;
        Restaurante r = ler_restaurante(linha);
        adicionar(&colecao, r);
    }

    fclose(f);
    return colecao;
}