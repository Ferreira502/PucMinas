#include <stdio.h>
#include <string.h>
#define MAX 100

// <--------  QUESTAO - 03 -------->

int comparaString( char *palavra )
{
    return strcmp(palavra, "FIM");
}

void palavraMaiuscula( void )
{
    char palavra[MAX];
    int resultado = 1;

    while (resultado != 0)
    {
        fgets(palavra, MAX, stdin);
        palavra[strcspn(palavra, "\n")] = '\0';

        resultado = comparaString(palavra);

        if (resultado != 0)
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
        }
    }

    printf("\nFIM do programa\n");
}


int main ( void )
{
    palavraMaiuscula( );
    return 0;
}