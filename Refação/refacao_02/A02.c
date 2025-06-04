// 842527 - Gabriel Ferreira Pereira

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX 100

// -------------------------------
// QUESTÃO 01
// -------------------------------

void p_01(void)
{
    char s[MAX] = "abacate maduro barato";
    char r[MAX];
    
    int x = 0, y = 0, z = 0;
    r[0] = '\0';
    z = 0; 
    while ( z < strlen(s) && s[z] == ' ') z = z + 1;
    y = z;
    while ( y < strlen(s) && s[y] != ' ') y = y + 1;
    while ( x < y - z )
        {
            r [x] = s [ y - x - 1 ]; 
            x = x + 1;
        }
    r[y - z] = '\0';

    printf("\n%c", s[y]);
    getchar();
}

// -------------------------------
// QUESTÃO 02
// -------------------------------

int f_02(int a [], int b [], int n, int begin, int end)
{
    int m = 0;
    while ( 0 <= begin && begin <= end && end < n)
        {
            a[m] = b [begin]; 
            m++;
            ++begin;
        }
    return ( m );
}

void p_02(void) 
{
    int a [MAX] = {2,5,3,6,1,7,4};
    int b [10];
    int x = 0;
    
    x = f_02(b,a,7,2,5);

    for (int i = 0; i < x; i++) {
        printf("%d ", b[i]);
    }
    getchar();
}

// -------------------------------
// QUESTÃO 03
// -------------------------------

void matrix(int p, int q, int m, int n, int m1[][3]) 
{
    int z = 0;
    if (0 <= p && p < m && 0 <= q && q < n) 
    {
        for (int x = 0; x < m; x++) 
        {
            for (int y = n - 1; y >= 0; y--) 
            {
                z = m1[p][x];
                m1[p][x] = m1[q][x];
                m1[q][x] = z;
            }
        }
    }

    printf("Resultado da matriz:\n");
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
}

void p_03(void) {
    int m[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    matrix(0, 2, 3, 3, m);
}

// -------------------------------
// QUESTÃO 04
// -------------------------------

void f_04(int x, int y, int a[]) {
    if (x < y - 1) {
        a[x] = a[x] + a[y];
        f_04((x + y) / 2, y, a);
    } else {
        a[x] = 0;
    }
}

void p_04(void) 
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};

    f_04(0, 6, a);

    for (int i = 0; i < 7; i++) 
    {
        printf("\n%d", a[i]);
    }
}

// -------------------------------
// QUESTÃO 05
// -------------------------------

struct y 
{
    int a, b, c;
};

void f_05(struct y *r) 
{
    int d = r->a, e = r->c;

    if (d < e) 
    {
        (*r).a = e;
        (*r).c = d;
    }

    d = r->b;
    e = r->c;

    if (d < e) 
    {
        r->b = e;
        r->c = d;
    }

    d = (*r).a;
    e = r->b;

    if (d < e) 
    {
        r->a = e;
        (*r).b = d;
    }
}

void p_05 (void)
{
    struct y x = { .a = 2, .b = 1, .c = 3 };

    f_05(&x);
    printf("\n%d %d %d", x.a, x.b, x.c);

    getchar();
    getchar();

}

// -------------------------------
// QUESTÃO 06
// -------------------------------

void f_06(char s[]) 
{
    int i = 0, j = 0;
    int espaco = 0;

    while (s[i] != '\0') 
    {
        if (s[i] != ' ') 
        {
            s[j++] = s[i];
            espaco = 0;
        } else if (!espaco) 
        {
            s[j++] = s[i];
            espaco = 1;
        }
        i++;
    }

    s[j] = '\0';
}

void p_06 (void)
{
    char s[] = "  amarelo   branco   dourado   ";
    f_06(s);
    printf("\"%s\"\n", s);
    getchar();
    getchar();
}

// -------------------------------
// QUESTÃO 07
// -------------------------------

typedef struct 
{
    int l, c;
    int data[10][10];
} matriz;

void f_07(matriz *m) 
{
    int i = 0;
    while (i < m->l) 
    {
        int j = 0;
        while (j <= i) 
        {
            m->data[i][j] = (i + 1) * 10 + (j + 1);
            j++;
        }
        j = i + 1;
        while (j < m->c) {
            m->data[i][j] = 0;
            j++;
        }
        i++;
    }
}


void p_07 (void)
{
    matriz m;
    m.l = 3;
    m.c = 3;

    f_07(&m);

    for (int i = 0; i < m.l; i++) 
    {
        for (int j = 0; j < m.c; j++) 
        {
            printf("%2d ", m.data[i][j]);
        }
        printf("\n");
    }

    getchar();
    getchar();
}

// -------------------------------
// QUESTÃO 08
// -------------------------------
int f_08(int n, char *filename) 
{
    if (n <= 3) return 1;

    FILE *file = fopen(filename, "w");
    if (file == NULL) return 1;

    int i = 1;
    while (i < n) 
    {
        int j = 0;
        while (j < i) 
        {
            fprintf(file, "*");
            j++;
        }
        fprintf(file, "\n");
        i++;
    }

    i = n - 2;
    while (i > 0) 
    {
        int j = 0;
        while (j < i) 
        {
            fprintf(file, "*");
            j++;
        }
        fprintf(file, "\n");
        i--;
    }

    fclose(file);
    return 0;
}

void p_08(void) 
{
    int n = 4;
    char *filename = "QUESTAO08.TXT";

    int result = f_08(n, filename);

    if (result == 0)
        printf("\nArquivo gerado com sucesso");
    else
        printf("\nErro ao gerar arquivo");


    getchar();
    getchar();
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
        printf("\n1 - p_01");
        printf("\n2 - p_02");
        printf("\n3 - p_03");
        printf("\n4 - p_04");
        printf("\n5 - p_05");
        printf("\n6 - p_06");
        printf("\n7 - p_07");
        printf("\n8 - p_08");
        printf("\n0 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1: p_01();    	   break;
            case 2: p_02();        break;
            case 3: p_03();        break;
            case 4: p_04();        break;
            case 5: p_05();        break;
            case 6: p_06();        break;
            case 7: p_07();        break;
            case 8: p_08();        break;
            case 0: break;
            default: printf ( "\n%s\n\n", "ERRO: Opcao invalida." );
        }
    } while (opcao != 0);

    return 0;
}