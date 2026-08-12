// EXERCICIO DE LABORATORIOS DE SEMESTRE PASSADO 
// FEITO POR GABRIEL FERREIRA PEREIRA'

#include<stdio.h>
#include<string.h>

void juntarPalavra(char parte1[], char parte2[], int tamanho)
{
    char parte3[80];
    int i = 0, j = 0, k = 0;

    while (parte1[i] != '\0' || parte2[j] != '\0')
    {
        if (parte1[i] != '\0')
            parte3[k++] = parte1[i++];

        if (parte2[j] != '\0')
            parte3[k++] = parte2[j++];
    }

    parte3[k] = '\0';

    printf("\nParte final: %s", parte3);
}

int main ()
{
    char palavra[80];
    char parte1[80];
    char parte2[80];
    char parte3[80];
    
    scanf("%[^\n]", palavra);

    int tamanho = strlen(palavra);

    int i = 0, j = 0;

    while (palavra[i] != ' ' && palavra[i] != '\0') {
        parte1[i] = palavra[i];
        i++;
    }

    parte1[i] = '\0';

    i++;

    while (palavra[i] != '\0') {
        parte2[j] = palavra[i];
        i++;
        j++;
    }
    parte2[j] = '\0';

    printf("\nParte 1: %s", parte1);
    getchar();

    printf("\nParte 2: %s", parte2);
    getchar();

    juntarPalavra(parte1, parte2, tamanho);
}
