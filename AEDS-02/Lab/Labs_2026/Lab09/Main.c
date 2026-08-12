#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[51];
    int peso;
} Atleta;

int main()
{
    Atleta atletas[100];
    int cont = 0;

    while (scanf("%s %d", atletas[cont].nome, &atletas[cont].peso) != EOF)
    {
        cont++;
    }

    for (int i = 0; i < cont - 1; i++)
    {
        for (int j = 0; j < cont - i - 1; j++)
        {
            if (atletas[j].peso < atletas[j+1].peso)
            {
                Atleta tmp = atletas[j];
                atletas[j] = atletas[j+1];
                atletas[j+1] = tmp;
            }

            else if (atletas[j].peso == atletas[j+1].peso)
            {
                if (strcmp(atletas[j].nome, atletas[j+1].nome) > 0)
                {
                    Atleta tmp = atletas[j];
                    atletas[j] = atletas[j+1];
                    atletas[j+1] = tmp;
                }
            }
        }
    }

    for (int i = 0; i < cont; i++)
    {
        printf("%s %d\n", atletas[i].nome, atletas[i].peso);
    }
}