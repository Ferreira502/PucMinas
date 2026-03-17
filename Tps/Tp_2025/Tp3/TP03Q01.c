#include <stdio.h>

int eh_fim(char *str)
{
    if (str[0] == 'F' && str[1] == 'I' && str[2] == 'M' && str[3] == '\0')
        return 1;
    return 0;
}

int eh_vogal(char c)
{
    if (c >= 'A' && c <= 'Z') c += 32;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;
    return 0;
}

int eh_letra(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

int eh_digito(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}


int x1(char *str) // apenas vogais
{
    if (*str == '\0')
        return 1;                       
    if (!eh_vogal(*str))
        return 0;                   
    return x1(str + 1);                  
}

int x2(char *str) // apenas consoantes
{
    if (*str == '\0')
        return 1;
    if (!eh_letra(*str))
        return 0;
    if (eh_vogal(*str))
        return 0;
    return x2(str + 1);
}

int x3(char *str) // apenas dígitos inteiros
{
    if (*str == '\0')
        return 1;
    if (!eh_digito(*str))
        return 0;
    return x3(str + 1);
}

int x4_aux(char *str, int ponto) // real: um único ponto ou vírgula
{
    if (*str == '\0')
        return ponto;                   
    if (*str == '.' || *str == ',')
    {
        if (ponto)
            return 0;                  
        return x4_aux(str + 1, 1);
    }
    if (!eh_digito(*str))
        return 0;
    return x4_aux(str + 1, ponto);
}

int x4(char *str)
{
    if (*str == '\0')
        return 0;                       // vazio não é número real
    return x4_aux(str, 0);
}


int main()
{
    char str[1000];

    while (1)
    {
        if (!fgets(str, sizeof(str), stdin))
            break;


        int i = 0;
        while (str[i] != '\0' && str[i] != '\n')
            i++;
        str[i] = '\0';

        if (eh_fim(str))
            break;

        if (x1(str))
            printf("SIM ");
        else
            printf("NAO ");

        if (x2(str))
            printf("SIM ");
        else
            printf("NAO ");

        if (x3(str))
            printf("SIM ");
        else
            printf("NAO ");

        if (x4(str))
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}
