// Questao 05 do Tp01
// Autor: Gabriel Ferreira Pereira

#include <stdio.h>

int somaDigitos(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    int soma = 0;

    while (n > 0) 
    {
        soma += n % 10;
        n /= 10;
    }
    
    return soma;
}

int main() 
{
    int num = 0;
    while (scanf("%d", &num) == 1) 
    {
        printf("%d\n", somaDigitos(num));
    }

    return 0;
}