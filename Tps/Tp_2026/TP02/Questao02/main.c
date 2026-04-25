#include <stdio.h>
#include "ColecaoRestaurante.h"

int main()
{
    ColecaoRestaurante colecao = lerCsv();
    Restaurante *restaurantes = getRestaurantes(&colecao);

    char saidaLinha[500];
    int id = 0;

    while (scanf("%d", &id) && id != -1)
    {
        for (int i = 0; i < getTamanho(&colecao); i++)
        {
            if (restaurantes[i].id == id)
            {
                formatar_restaurante(&restaurantes[i], saidaLinha);
                printf("%s\n", saidaLinha);
            }
        }
    }

    return 0;
}