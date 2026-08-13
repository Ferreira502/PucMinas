/*
 Guia_0101.v
 842527 - Gabriel Ferreira Pereira
 Questão 05c) 
*/


#include <stdio.h>
#include <string.h>
#define MAX  1000 

void ASCII2hex(const char *str) 
{
    printf("ASCII para HEX: ");
    for (int i = 0; i < strlen(str); i++) 
    {
        printf("%02X ", (unsigned char)str[i]);
    }
    printf("\n");
}

void hex2ASCII(const char *hexStr) 
{
    printf("HEX para ASCII: ");
    int value;
    while (sscanf(hexStr, "%2X", &value) == 1) 
    {
        printf("%c", (char)value);
        hexStr += 2;
        while (*hexStr == ' ') hexStr++;
    }
    printf("\n");
}

int main() 
{
    char texto[MAX];
    char hex[MAX];

    printf("Digite uma string: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = 0;

    ASCII2hex(texto);

    printf("Digite um valor hexadecimal: ");
    fgets(hex, sizeof(hex), stdin);
    hex[strcspn(hex, "\n")] = 0;

    hex2ASCII(hex);

    return 0;
}
