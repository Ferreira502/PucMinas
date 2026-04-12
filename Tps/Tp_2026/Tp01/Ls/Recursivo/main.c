//QUESTAO 10 TP01
// Autor: Gabriel Ferreira Pereira

#include <stdio.h>

int eVogal(char c) 
{
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
        c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
    {
        return 1;
    }
    return 0;
}

int eLetra(char c) 
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return 1;
    }
    return 0;
}

int somenteVogais(char p[], int i) 
{
    if (p[i] == '\0') 
    {
        return 1;
    }

    if (!eVogal(p[i])) 
    {
        return 0;
    }

    return somenteVogais(p, i + 1);
}

int somenteConsoantes(char p[], int i) 
{
    if (p[i] == '\0') 
    {
        return 1;
    }

    if (!eLetra(p[i])) 
    {
        return 0;
    }

    if (eVogal(p[i])) 
    {
        return 0;
    }

    return somenteConsoantes(p, i + 1);
}

int eInteiro(char p[], int i) 
{

    if (p[i] == '\0') 
    {
        return 1;
    }

    if (p[i] < '0' || p[i] > '9') 
    {
        return 0;
    }

    return eInteiro(p, i + 1);
}

int eReal(char p[], int i, int cont) 
{

    if (p[i] == '\0') 
    {
        if (cont == 1) 
        {
            return 1;
        }

        return 0;
    }
    
    if (p[i] == '.' || p[i] == ',') 
    {
        return eReal(p, i + 1, cont + 1);
    }

    if (p[i] < '0' || p[i] > '9') 
    {
        return 0;
    }

    return eReal(p, i + 1, cont);
}

int main() 
{
    char string[1000];

    scanf(" %[^\n]", string);

    while (!(string[0] == 'F' && string[1] == 'I' && string[2] == 'M')) 
    {
        int resultado = 0;

        resultado = somenteVogais(string, 0);
        
        if (resultado == 1)
        {
            printf("SIM ");
        }

        else
        {   
            printf("NAO ");
        }
        
        resultado = somenteConsoantes(string, 0);
        
        if (resultado == 1)
        {
            printf("SIM ");
        }

        else
        {   
            printf("NAO ");
        }

        resultado = eInteiro(string, 0);

        if (resultado == 1)
        {
            printf("SIM ");
        }

        else
        {   
            printf("NAO ");
        }

        resultado = eReal(string, 0, 0);
        
        if (resultado == 1)
        {
            printf("SIM\n");
        }

        else
        {   
            printf("NAO\n");
        }

        scanf(" %[^\n]", string);
    }
}