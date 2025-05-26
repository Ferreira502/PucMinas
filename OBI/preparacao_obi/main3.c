// 842527 - Gabriel Ferreira Pereira
// 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// ---

#define MAX 100

// ---

/*
  Função para ...
*/

int isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

char toUpperManual(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

int processar(char str[]) {
    int alteradas = 0;
    int tamanho = strlen(str);

    for (int i = 0; i < tamanho; i++) {
        if (isVowel(str[i]) && isVowel(str[i + 1])) {
            char original = str[i];
            str[i] = toUpperManual(str[i]);
            if (str[i] != original) {
                alteradas++;
            }
        }
    }

    return alteradas;
}

// ---

int main ( void )
{
    int n;
    char linha[MAX];

    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%s", linha) != 1) {

            return 1;
        }

        int qtd = processar(linha);
        printf("%d\n%s\n", qtd, linha);
    }

    return 0;
}
/*
    Testes - Comentarios - Observacoes
*/