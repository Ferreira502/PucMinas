#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

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

void p07(void) {
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
        printf("\n6 - p_06");
        printf("\n7 - p_07");
        printf("\n8 - p_08");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 6: p_06(); break;
            case 7: p_07(); break;
            case 8: p_08(); break;
            case 0: break;
            default: printf ( "\n%s\n\n", "ERRO: Opcao invalida." );
        }
    } while (opcao != 0);

    return 0;
}