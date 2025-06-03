#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX 100

// -------------------------------
// QUESTÃO 01
// -------------------------------

void p_01(void) s
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
}

// -------------------------------
// QUESTÃO 03
// -------------------------------

void p_03(void) 
{
   // i
}


// -------------------------------
// QUESTÃO 04
// -------------------------------

void p_04(void) 
{
    //c
}

// -------------------------------
// QUESTÃO 05
// -------------------------------

void p_05 (void)
{
    //a
}

// -------------------------------
// QUESTÃO 06
// -------------------------------

void p_06 (void)
{
   // a
}

// -------------------------------
// QUESTÃO 07
// -------------------------------

void p_07 (void)
{
   // a
}

// -------------------------------
// QUESTÃO 08
// -------------------------------

void p_08 (void)
{
   // a
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
        printf("0 - Sair\n");
        printf("Opcao: ");
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