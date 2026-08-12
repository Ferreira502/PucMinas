#include <stdio.h>

int f_07(char *nome_arquivo) {
    FILE *arq = fopen(nome_arquivo, "r");  // CORRIGIDO
    if (!arq) {
        printf("Erro ao abrir arquivo.\n");
        return -1;
    }

    int n;
    fscanf(arq, "%d", &n);
    int matriz[20][20];  // tamanho máximo

    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fscanf(arq, "%d", &matriz[i][j]);

    fclose(arq);

    int maior = matriz[0][0], menor = matriz[0][0];
    int i_maior = 0, j_maior = 0, i_menor = 0, j_menor = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                i_maior = i;
                j_maior = j;
            }
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
                i_menor = i;
                j_menor = j;
            }
        }
    }

    if (i_maior == i_menor || j_maior == j_menor) {
        return 1; // mesma linha ou coluna
    }

    return -1;
}

int main() {
    int r = f_07("MATRIZ.TXT");  // Usa o nome do arquivo aqui
    if (r == 1)
        printf("Maior e menor na mesma linha ou coluna.\n");
    else
        printf("Maior e menor em linhas e colunas diferentes.\n");
    return 0;
}
