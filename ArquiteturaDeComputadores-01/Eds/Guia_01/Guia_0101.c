/*
 Guia_0101.v
 842527 - Gabriel Ferreira Pereira
 Questão 01c) 
*/

#include <stdio.h>

void dec2bin ( int x ) 
{
    int bin[32];
    int i = 0;

    while (x > 0) 
    {
        bin[i] = x % 2;
        x = x / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) 
    {
        printf("%d", bin[j]);
    }
    printf("\n");
    getchar();
}

int main() 
{
    int decimal = 0;
    printf("\nDigite um numero decimal: ");
    scanf("%d", &decimal);
    dec2bin(decimal);

    return 0;
}
