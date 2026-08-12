/*
 Guia_0102.v
 842527 - Gabriel Ferreira Pereira
 Questão 02c) 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int bin2dec(const char *x) 
{
    int decimal = 0;
    int tamanho = strlen(x);

    for (int i = 0; i < tamanho; i++) 
    {
        if (x[i] == '1') 
        {
            decimal += pow(2, tamanho - 1 - i);
        }
    }
    return decimal;
}

int main() 
{
    char binario[100];
    printf("\nDigite um numero binario: ");
    scanf("%s", binario);

    printf("\nDecimal: %d", bin2dec(binario));
    return 0;
}
