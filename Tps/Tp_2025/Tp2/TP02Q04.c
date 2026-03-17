#include <stdio.h>

// Função recursiva que retorna a soma dos dígitos de n
int somaDigitos(int n) 
{
    if (n < 0) 
    {
        n = -n;
    }

    if (n == 0) 
    {
        return 0;
    } 
    else 
    {
        int ultimoDigito = n % 10;
        int restante = n / 10;
        int somaRestante = somaDigitos(restante);
        int resultado = ultimoDigito + somaRestante;
        return resultado;
    }
}

int main() 
{
    int num;

    while (scanf("%d", &num) == 1) 
    {
        int soma = somaDigitos(num);
        printf("%d\n", soma);
    }

    return 0;
}
