/*
 Guia_0101.v
 842527 - Gabriel Ferreira Pereira
 Questão 03c) 
*/

#include <stdio.h>
#include <string.h>

void dec2bin(int x, char *bin) 
{
    int i = 0;
    if (x == 0) 
    {
        strcpy(bin, "0");
        return;
    }
    bin[0] = '\0';

    while (x > 0) 
    {
        bin[i++] = (x % 2) + '0';
        x /= 2;
    }
    bin[i] = '\0';

    int len = strlen(bin);
    for (int j = 0; j < len/2; j++) 
    {
        char temp = bin[j];
        bin[j] = bin[len - 1 - j];
        bin[len - 1 - j] = temp;
    }
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
    int num;
    char bin[100], base4[100], base8[100], base16[100];

    printf("Digite um numero decimal: ");
    scanf("%d", &num);

    // binário
    dec2bin(num, bin);
    printf("Binario: %s\n", bin);

    // base 4
    dec2base(num, 4, base4);
    printf("Base 4: %s\n", base4);

    // base 8
    dec2base(num, 8, base8);
    printf("Octal (base 8): %s\n", base8);

    // base 16
    dec2base(num, 16, base16);
    printf("Hexadecimal (base 16): %s\n", base16);

    return 0;
}
