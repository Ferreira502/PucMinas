#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//questao 01

int f_01(char p[]) {
    int x = 0, y = 0;
    bool r = false, s = false, t = false;
    bool u = false, v = false, w = false;

    for (x = 0; x < strlen(p); x = x + 1) {
        r = ('a' <= p[x] && p[x] <= 'z');
        s = ('A' <= p[x] && p[x] <= 'Z');
        t = ('0' <= p[x] && p[x] <= '9');

        u = (r || s) && !w;
        v = !u && t;
        w = !v;

        if (u) y = y + 1;
        else if (v) y = y - 1;
    }

    return y;
}

//questao 02

int f_02(int a, int b) {
    if (a % 2 == 0 && b % 2 == 0) return f_02(a / 2, b / 2);
    else if (a % 2 != 0 && b % 2 == 0) return f_02(b % a, b / 2);
    else if (a % 2 == 0 && b % 2 != 0) return f_02(a / 2, a % b);
    return ((a - 1) % (b - 1) / 2);
}

//questao03
void p_03 ( void )
{
    int x = 0;
    printf("Primeira repeticao:\n");
    for (x = 1; x <= 5; x = x + 1) {
        printf("nx = %d ", 2 * x + 1);  // Resultado: 3 5 7 9 11
    }

    printf("\nSegunda repeticao:\n");
    int a = 3, b = 5 * 3;  // Correto: a = 1; b = 15;
    for (x = a; x <= b; x = x + 3) {
        printf("nx = %d ", (2 * x + 3) / 3);  // Resultado igual ao de cima
    }

    printf("\n");
}

//questao 04

void p_04( void ) {
    int x = 1, y = 1, v = 0, w = 0, m = 2, n = 0;

    printf("Digite o valor de n: ");
    scanf("%d", &n);  // Entrada do usuário
    getchar();

    printf("%d %d ", x, y);

    while (m < n) {
        v = x + y;
        m++;
        printf("%d ", v);
        if (m < n - 1) {
            w = x + y + v;
            m++;
            printf("%d ", w);
        }
        x = v;
        y = w;
    }

    printf("\n");
}

// Questão 05
int f_05(char *s) {
    int x = 0, y = strlen(s) - 1;
    while (x <= y && s[x] == s[y]) {
        x++;
        y--;
    }
    return (x - y + s[x] - s[y]);
}

void questao_05() {
    char s1[] = "14641";
    char s2[] = "abc";   // Não-palíndromo

    printf("\n--- Questao 05 ---\n");

    printf("Resultado para \"%s\": %d\n", s1, f_05(s1));  // Deve dar 0
    printf("Resultado para \"%s\": %d\n", s2, f_05(s2));  // Deve dar diferente de 0
}

// questao 06
int ehPrimo(int x) {
    int i, cont = 0;
    for (i = 1; i <= x; i++) {
        if (x % i == 0) {
            cont++;
        }
    }
    return (cont == 2);
}

int inverter(int x) {
    int dezena = x / 10;
    int unidade = x % 10;
    return unidade * 10 + dezena;
}

void p_06(void) {
    int i, espelhado, contador = 0;
    
    for (i = 11; i <= 99; i++) {
        espelhado = inverter(i);
        if (ehPrimo(i) && ehPrimo(espelhado)) {
            contador++;
            printf("Par de Sheldon: %d e %d\n", i, espelhado);
        }
    }

    printf("Total de candidatos a pares de Sheldon: %d\n", contador);
}

// questao 07
int f_07 (char cadeia [])
{
    int tamanho = strlen(cadeia);
    int dna = 0, rna = 0, erro = 0;
    
    for(int i = 0; i < tamanho; i++)
        {
            if (cadeia[i] == 'T')
               {
                   dna = 1;
               } else if (cadeia[i] == 'U') {
                   rna = 1;
               }
        }
     if (dna && !rna) return 1;
     if (!dna && rna) return 2; 
     if (!dna && !rna) return 0;
     return -1;
}


// questao 08
int testar (char cadeia [])
{
    int tamanho = strlen(cadeia);
    int soma1 = 0, soma2 = 0;

    for (int i = 0; i < tamanho; i++)
        {
            if (cadeia[i] >= '0' && cadeia[i] <= '9')
            {
                int dig = cadeia[i] - '0';
                soma1 += dig;      
                soma2 += dig * dig * dig;  
            }
        }
    if (soma1 * soma1 == soma2) {
        return 1;
    } else {
        return -1;
    }
}

void p_08 (void)
{
    char cadeia [80];
    int x = 0;
    printf("\nDigite a cadeia: ");
    fgets(cadeia, 80 - 1, stdin);

    x = testar(cadeia);
    printf("\n%d", x);
}

int main() {
    printf("\n\tP_01\n");
    printf("%d", f_01("5aP4+0_8r4nK0"));

    printf("\n\tP_02\n");
    printf("f_02(30, 72) = %d\n", f_02(30, 72));
    
    printf("\n\tP_03\n");
    p_03();

    printf("\n\tP_04\n");
    p_04();

    printf("\n\tP_05\n");
    questao_05();

    printf("\n\tP_06\n");
    p_06();

    printf("\n\tP_07\n");
    char seq[] = "TACAGATA";
    int tipo = f_07(seq);

    printf("Resultado da sequencia '%s': %d\n", seq, tipo);
    printf("\n\tP_08\n");
    p_08();
    
    return 0;
}