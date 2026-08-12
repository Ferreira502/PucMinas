//  QUESTAO 09 DO TP01 
// AUTHOR: Gabriel Ferreira Pereira

#include <stdio.h>

void ciframentoRec( char string[], int n )
{
    if ( string[n] == '\0')
    {
        return;
    }
    
    string[n] += 3;
    ciframentoRec(string, n + 1);
}

int main ()
{
    char string[1000];
    int i = 0;
    int espacos = 0;

    fgets(string, 1000, stdin);

    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '\n') 
        {
            string[i] = '\0';
        }
    }

    while (!(string[0] == 'F' && string[1] == 'I' && string[2] == 'M')) 
    {
        espacos = 1;

        for (i = 0; string[i] != '\0'; i++)
        {
            if (string[i] != ' ')
            {
                espacos = 0;
            }
        }

        if (espacos == 1)
        {
            printf("\n");
        }

        else
        {
            ciframentoRec(string, 0);
            printf("%s\n", string);
        }

        fgets(string, 1000, stdin);
        
        for (i = 0; string[i] != '\0'; i++)
        {
            if (string[i] == '\n') string[i] = '\0';
        }
    }
    return 0;
}