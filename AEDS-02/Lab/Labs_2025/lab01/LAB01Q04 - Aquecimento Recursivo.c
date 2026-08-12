#include <stdio.h>
#include <string.h>

#define MAX 100

// <--------  QUESTAO - 04 -------->

int comparaString(char *palavra)
{
    return strcmp(palavra, "FIM");
}


void palavraMaiusculaRecursiva( void )
{
    char palavra[MAX];

    fgets(palavra, MAX, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    if (comparaString(palavra) == 0)
    {
        printf("\nFIM do programa\n");
    }
    else
    {
        int cont = 0;
        for (int i = 0; palavra[i] != '\0'; i++)
        {
            if (palavra[i] >= 'A' && palavra[i] <= 'Z')
            {
                cont++;
            }
        }

        printf("\n%d\n", cont);

        palavraMaiusculaRecursiva();
    }
}

int main ( void )
{
    palavraMaiusculaRecursiva();
    return 0;
}