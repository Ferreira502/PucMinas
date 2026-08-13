/*
 Guia_0101.v
 842527 - Gabriel Ferreira Pereira
 Questão 04c) 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int bin2dec(const char *bin) 
{
    int dec = 0;
    int len = strlen(bin);
    for (int i = 0; i < len; i++) 
    {
        if (bin[i] == '1') 
        {
            dec = dec * 2 + 1;
        } else if (bin[i] == '0') 
        {
            dec = dec * 2;
        } else {
            printf("\nEntrada binaria invalida");
            return -1;
        }
    }
    return dec;
}

void dec2base(int x, int base, char *res) 
{
    char digits[] = "0123456789ABCDEF";
    int i = 0;
    if (x == 0) 
    {
        strcpy(res, "0");
        return;
    }
    res[0] = '\0';

    while (x > 0) 
    {
        res[i++] = digits[x % base];
        x /= base;
    }
    res[i] = '\0';

    int len = strlen(res);
    for (int j = 0; j < len/2; j++) 
    {
        char temp = res[j];
        res[j] = res[len - 1 - j];
        res[len - 1 - j] = temp;
    }
}

int main() 
{
    char bin[100];
    int dec;
    char base4[100], base8[100], base16[100];

    printf("Digite um numero binario: ");
    scanf("%64s", bin);

    dec = bin2dec(bin);
    if (dec == -1) 
    {
        return 1;
    }

    printf("\nDecimal: %d", dec);

    dec2base(dec, 4, base4);
    printf("\nBase 4: %s", base4);

    dec2base(dec, 8, base8);
    printf("\nOctal (base 8): %s", base8);

    dec2base(dec, 16, base16);
    printf("\nHexadecimal (base 16): %s", base16);

    return 0;
}
