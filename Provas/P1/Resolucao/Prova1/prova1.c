#include<stdio.h>
#include<string.h>

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