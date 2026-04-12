//  QUESTAO 09 DO TP01 
// AUTHOR: Gabriel Ferreira Pereira

#include <stdio.h>

/**
 * @author Gabriel Ferreira Pereira
 *
 * @param char string int n 
 *
 * @reason  funcao recebe 1 string e o seu tamanho e acrescenta mais 3 em cada valor
 *          
 */
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
    char string[1000];
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