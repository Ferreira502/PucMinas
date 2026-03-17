#include <stdio.h>

int eh_fim(char *str) 
{
    return str[0] == 'F' && str[1] == 'I' && str[2] == 'M' && str[3] == '\0';
}

int eh_vogal(char c)
 {
    if (c >= 'A' && c <= 'Z') c = c + 32;
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int eh_letra(char c) 
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int eh_digito(char c) 
{
    return (c >= '0' && c <= '9');
}

int x1(char *str) 
{
    int i = 0;
    if (str[0] == '\0') return 0;

    while (str[i] != '\0') 
    {
        if (!eh_vogal(str[i])) 
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int x2(char *str) 
{
    int i = 0;
    if (str[0] == '\0') return 0;

    while (str[i] != '\0') 
    {
        if (!eh_letra(str[i])) 
        {
            return 0;
        }
        if (eh_vogal(str[i])) 
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int x3(char *str) 
{
    int i = 0;
    if (str[0] == '\0') return 0;

    while (str[i] != '\0') 
    {
        if (!eh_digito(str[i])) 
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int x4(char *str) 
{
    int i = 0;
    int ponto = 0;
    if (str[0] == '\0') return 0;

    while (str[i] != '\0') 
    {
        if (str[i] == '.' || str[i] == ',') 
        {
            if (ponto) return 0;
            ponto = 1;
        } 
        else if (!eh_digito(str[i])) 
        {
            return 0;
        }
        i++;
    }
    return ponto;
}

int main() 
{
    char str[1000];

    while (1) 
    {
        fgets(str, sizeof(str), stdin);

        int i = 0;
        while (str[i] != '\0' && str[i] != '\n') i++;
        str[i] = '\0';

        if (eh_fim(str)) break;

        if (x1(str)) printf("SIM ");
        else printf("NAO ");

        if (x2(str)) printf("SIM ");
        else printf("NAO ");

        if (x3(str)) printf("SIM ");
        else printf("NAO ");

        if (x4(str)) printf("SIM\n");
        else printf("NAO\n");
    }

    return 0;
}
