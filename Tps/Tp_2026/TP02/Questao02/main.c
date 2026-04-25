#include <stdio.h>
#include "ColecaoRestaurante.h"

int main()
{
    ColecaoRestaurante colecao = lerCsv();
    Restaurante *restaurantes = getRestaurantes(&colecao);
    char buffer[500];
    int id;

    while (scanf("%d", &id) && id != -1)
    {
        for (int i = 0; i < getTamanho(&colecao); i++)
        {
            if (restaurantes[i].id == id)
            {
                formatar_restaurante(&restaurantes[i], buffer);
                printf("%s\n", buffer);
            }
        }
    }

    return 0;
}