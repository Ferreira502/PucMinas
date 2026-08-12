#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// questao 01

void f_01(void) {
    printf("(a.) %d = %d\n", (4/(2+2)/1), (4/2+2/4));
    printf("(b.) %d = %d\n", ((4/2)+(2/4)), (2-(4/2)+2*(4/2/2)));
    printf("(c.) %d = %d\n", ((4+2)*2/4), (4*2+2/4));
    printf("(d.) %d = %d\n", ((4+2)/4) + (4*(4/2)/2), ((2+2*4)/(2+4)+2));
}


// questao 02

int f_02a(int x) {
    int y = 0, z = 0, p = x;
    while (p > 4) {
        if (p % 10 % 2 == 0) {
            y = y + p % 10 - 1;
        } else {
            z = z / 10 + p % 10 + 1;
        }
        p = p / 10;
    }
    return (y + z);
}

// questao 03

int f_03(char *text) {
    int a = 0, x = 0, t = strlen(text);
    if (t > 0) {
        a = (text[0] - 48 + text[t - 1] - 48);
        for (x = 0; x < t - 2; x++) {
            text[x] = text[x + 1];
        }
        text[x] = '\0';
        a = a + f_03(text);
    }
    return a;
}

// questao 04


int f_04(int a, int b) {
    while (a > 0 && b > 0 && a >= b) {
        a = a - b;
        if (a < b) {
            a = a + b;
            b = a - b;
            a = a - b;
        }
    }
    return a;
}

// questão 05

int f_05(int n) {
    int s = 0, z = 0;
    while (n > 0) {
        z = z + 4;
        if (z % 5 == 0)
            n = n + 1;
        else
            s = s + z;
        n = n - 1;
    }
    return s;
}

// questao 06

int bissexto(int ano) {
    int resto4 = ano;
    while (resto4 >= 4) {
        resto4 = resto4 - 4;
    }

    int resto100 = ano;
    while (resto100 >= 100) {
        resto100 = resto100 - 100;
    }

    int resto400 = ano;
    while (resto400 >= 400) {
        resto400 = resto400 - 400;
    }

    if (resto4 == 0) {
        if (resto100 == 0) {
            if (resto400 == 0) {
                return 1; // Bissexto
            } else {
                return 0;
            }
        } else {
            return 1; // Bissexto
        }
    }
    return 0;
}

void p_06(void) {
    int anos[] = {1800, 2000, 2024};
    for (int i = 0; i < 3; i++) {
        int ano = anos[i];
        if (bissexto(ano)) {
            printf("%d e bissexto\n", ano);
        } else {
            printf("%d NAO e bissexto\n", ano);
        }
    }
}

// questao 07

int soma_algarismos(int n) {
    return (n / 10) + (n % 10);
}

void amigos(void) {
    for (int x = 10; x <= 99; x++) {
        for (int y = 10; y <= 99; y++) {
            if (x != y) {
                int sx = soma_algarismos(x);
                int sy = soma_algarismos(y);

                if (sx * sx == y && sy * sy == x) {
                    printf("%d e %d sao quadrados amigos\n", x, y);
                }
            }
        }
    }
}

// questao 08

char testar (char x[] , char y[])
{
    int tamanho1 = strlen(x) / 2;
    int tamanho2 = strlen(y) / 2;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < tamanho1; i++)
    {
        if (x[i] == 'g' || x[i] == 'j' || x[i] =='p' || x[i] == 'q' || x[i] == 'y')
        {
            count1++;
        }
    }
    for (int j = 0; j < tamanho2; j++)
    {
        if (y[j] == 'g' || y[j] == 'j' || y[j] =='p' || y[j] == 'q' || y[j] == 'y')
        {
            count2++;
        }
    }
    if (count1 > count2)
    {
        printf("\nA palavra bagagem tem mais descendentes");
    }
    else{
        printf("\nA palavra papagaio tem mais descendentes");
    }
    
}

void p_08 ( void )
{
    char palavra1 [] = "bagagem";
    char palavra2 [] = "papagaio";
    testar(palavra1,palavra2);
    
}


int main() {
    printf("\n\tP_01\n");
    f_01();

    printf("\n\tP_02\n");
    printf("%d\n", f_02a(567890));

    printf("\n\tP_03\n");
    char text[] = "123456";
    printf("%d\n", f_03(text));

    printf("\n\tP_04\n");
    printf("%d\n", f_04(54, 24));

    printf("\n\tP_05\n");
    printf("f_05(7) = %d\n", f_05(7));   // 124
    printf("f_05(8) = %d\n", f_05(8));   // 160
    printf("f_05(9) = %d\n", f_05(9));   // 204
    printf("f_05(10) = %d\n", f_05(10));   // 252

    printf("\n\tP_06\n");
    p_06();

    printf("\n\tP_07\n");
    amigos();

    printf("\n\tP_08\n");
    p_08();
    
    return 0;
}