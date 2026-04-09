#include <stdio.h>

char * ciframentoRec( char string[], int n )
{
    if ( string[n] == '\0')
    {
        return string;
    }
    else
    {
        string[n] += 3;
        return ciframentoRec(string, n + 1);
    }

}

int main ()
{
    char string[100];
    int n = 0;

    scanf(" %[^\n]", string);

    while (!(string[0] == 'F' && string[1] == 'I' && string[2] == 'M')) 
    {
        char * resultado = ciframentoRec(string, 0);
        printf("%s\n", resultado);

        scanf(" %[^\n]", string);
    }

    return 0;
}