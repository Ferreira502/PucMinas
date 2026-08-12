#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// -------------------------------
// QUESTÃO 01
// -------------------------------

void question_01( void ) 
{
    int n = 8, x = 4, y = n, z = 0;
    while (z < y)
    {
        x = x + 3 * z - 1;
        if (x % 7 == 0)
        {
            y = y + 1;
        } 
        else 
        {
            printf("%d\n", x);

        }
        z = z + 1;
    }
}

// -------------------------------
// QUESTÃO 02
// -------------------------------
void question_02 ( void )
{
    char s [] = "A12*3-d4+(B+C)/E5;";
    int x = 0;
    for (x = strlen(s)/2; x < strlen(s); x=x+1)
    {
        if ('A' <= s[x] && s[x] <= 'Z')
        {
            printf("\n%c", s[x]);
            x = x + 2;
        }
    }
    
}

// -------------------------------
// QUESTÃO 03
// -------------------------------
int f_03(int x)
{
    int y = x;
    if (x % 2 == 0)
        y = f_03(x - 1);
    else if (x > 2)
        y = y + f_03(x - 2);
    return y;
    printf("f_03(%d) = %d\n", 10, f_03(10));
}

void question_03(void) {
    printf("f_03(%d) = %d\n", 10, f_03(10));
}
// -------------------------------
// QUESTÃO 04
// -------------------------------
void question_04 ( void )
{
    int n = 123321, x = 0, y = 0,z = 0, p = 1;
    while (p<=n)
    {
        p = p * 10;
        z = z + 1;
    } 
    p = p / 10; 
    z = z / 2;
    while (x < z)
    {
        if (n / p == n % 10)
        {
            y = y + 1;
            n = n % p / 10;
            p = p / 100;
            x = x + 1;
        }
        else x = z;
    }
    printf("\ny = %d, z = %d", y, z);
    
}
// -------------------------------
// QUESTÃO 05
// -------------------------------
void question_05(void)
{
    int n = 5, y = 3, x = 1, impar = 1;

    printf("%d\t%d\n", x, y);
    x = x + 1;
    while (x < n + 2)
    {
        y = y + impar;
        printf("%d\t%d\n", x, y);
        impar = 2 * x - 1;
        x = x + 1;
    }
}
// -------------------------------
// QUESTÃO 06
// -------------------------------
bool is_Multiple_Of_7(int valor) {
    while (valor >= 10 || valor <= -10) {
        int ultimo = valor % 10;
        valor = valor / 10 - 2 * ultimo;
    }

    if (valor == 0 || valor == 7 || valor == -7 || valor == -14) {
        return true;
    } else {
        return false;
    }
}

void p_06(void) {
    int valores[] = {28, 30, 35, 91};
    int i;

    for (i = 0; i < 4; i++) {
        if (is_Multiple_Of_7(valores[i])) {
            printf("\n%d e multiplo de 7", valores[i]);
        } else {
            printf("\n%d nao e multiplo de 7", valores[i]);
        }
    }
}

// -------------------------------
// QUESTÃO 07
// -------------------------------
double soma(int n) {
    double total = 0.0;
    double anterior = 0.0;
    int sinal = 1;
    int i = 1;

    while (i <= n) {
        double termo = sinal * (1.0 / i);
        total += termo;

        if (i > 1) {
            double diferenca = total - anterior;
            if (diferenca < 0) {
                diferenca = -diferenca;
            }
            if (diferenca < 0.1) {
                i = n + 1;
            }
        }

        anterior = total;
        sinal = sinal * -1;
        i = i + 1;
    }

    return total;
}

void p_07(void) {
    int n = 100;
    double resultado = soma(n);
    printf("\nSoma com ate %d termos ou ate diferenca < 0.1: %.4lf", n, resultado);
}


// -------------------------------
// QUESTÃO 08
// -------------------------------

bool testar(char* t1, char* t2, int tam) {
    int len1 = strlen(t1);
    int len2 = strlen(t2);
    int i;
    bool igual = true;

    if (tam < 2 || len1 < tam || len2 < tam) {
        return false;
    }

    for (i = 0; i < tam; i++) {
        if (t1[len1 - tam + i] != t2[i]) {
            igual = false;
        }
    }

    if (igual) {
        return true;
    } else {
        return false;
    }
}

void p_08(void) {
    char palavra1[] = "regra";
    char palavra2[] = "gramatical";
    int tamanho = 3;

    if (testar(palavra1, palavra2, tamanho)) {
        printf("\nHa parequema com %d letras", tamanho);
    } else {
        printf("\nNao ha parequema com %d letras", tamanho);
    }
}

// -------------------------------
// MAIN
// -------------------------------
int main(void)
{
    int opcao = 0;

    do
    {
        printf("\nEscolha uma opcao:");
        printf("\n1 - question_01");
        printf("\n2 - question_02");
        printf("\n3 - question_03");
        printf("\n4 - question_04");
        printf("\n5 - question_05");
        printf("\n6 - p_06");
        printf("\n7 - p_07");
        printf("\n8 - p_08");
        printf("\n0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1: question_01(); break;
            case 2: question_02(); break;
            case 3: question_03();   break;
            case 4: question_04(); break;
            case 5: question_05(); break;
            case 6: p_06();        break;
            case 7: p_07();        break;
            case 8: p_08();        break;
            case 0: break;
            default: printf ( "\n%s\n\n", "ERRO: Opcao invalida." );
        }
    } while (opcao != 0);

    return 0;
}