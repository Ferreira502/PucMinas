#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Função para obter o valor de cada letra baseado na tabela da questão
int valor_letra(char letra) {
    letra = toupper(letra); // garante maiúscula

    if (letra >= 'A' && letra <= 'I') {
        return (letra - 'A') % 9 + 1;
    } else if (letra >= 'J' && letra <= 'R') {
        return (letra - 'J') % 9 + 1;
    } else if (letra >= 'S' && letra <= 'Z') {
        return (letra - 'S') % 8 + 1;
    }

    return 0; // Ignora espaços e outros caracteres
}

// Função para somar os dígitos de um número
int somar_algarismos(int n) {
    int soma = 0;
    while (n > 0) {
        soma += n % 10;
        n /= 10;
    }
    return soma;
}

// Função principal para calcular o número do nome
int isopsefia(char nome[]) {
    int soma = 0;

    for (int i = 0; nome[i] != '\0'; i++) {
        soma += valor_letra(nome[i]);
    }

    // Reduzir a soma, exceto se for 11 ou 22
    while (soma > 9 && soma != 11 && soma != 22) {
        soma = somar_algarismos(soma);
    }

    return soma;
}

// Procedimento para testar a função
void method_06() {
    char nome[100];

    printf("Digite um nome: ");
    fgets(nome, sizeof(nome), stdin);

    // Remover quebra de linha, se houver
    nome[strcspn(nome, "\n")] = '\0';

    int resultado = isopsefia(nome);
    printf("Valor isopsefiano do nome \"%s\" = %d\n", nome, resultado);
}

int main() {
    method_06();
    return 0;
}