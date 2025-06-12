/* 
   myarray.h  - v1.0 - 09 / 06 / 2025 
   Autor: Gabriel Ferreira Pereira
*/

#ifndef MYARRAY_H
#define MYARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 100

typedef struct {
    int* data;
    int length;
    int optional;
} Array;

// Criar array com tamanho e valor inicial
Array createArray(int length, int initial) 
{
    Array arr;

    if (length > 0) 
    {
        arr.length = length;
        arr.data = (int*) malloc(length * sizeof(int));
    } else 
    {
        arr.length = 0;
        arr.data = NULL;
    }

    arr.optional = initial;

    if (arr.data != NULL) 
    {
        for (int i = 0; i < length; i++) 
        {
            arr.data[i] = initial;
        }
    }

    return arr;
}

// Liberar memória
void freeArray(Array* arr) 
{
    if (arr->data != NULL) 
    {
        free(arr->data);
        arr->data = NULL;
        arr->length = 0;
    }
}

// Definir valor em uma posição
void set(Array* arr, int pos, int value) 
{
    if (pos >= 0 && pos < arr->length) 
    {
        arr->data[pos] = value;
    }
}

// Obter valor de uma posição
int get(Array* arr, int pos) {
    if (pos >= 0 && pos < arr->length)
    {
        return arr->data[pos];
    } else 
    {
        return arr->optional;
    }
}

// Imprimir o array
void printArray(Array* arr) 
{
    printf("\n");
    for (int i = 0; i < arr->length; i++) 
    {
        printf("%.3d : %9d\n", i, arr->data[i]);
    }
    printf("\n");
}

// Ler valores do teclado
void readArray(Array* arr) 
{
    printf("\n");
    for (int i = 0; i < arr->length; i++) 
    {
        printf("%3d : ", i);
        scanf("%d", &arr->data[i]);
    }
    printf("\n");
}

// Gravar array em arquivo
void fprintArray(Array* arr, const char* fileName) 
{
    FILE* file = fopen(fileName, "w");
    if (file != NULL) 
    {
        fprintf(file, "%d\n", arr->length);
        for (int i = 0; i < arr->length; i++) 
        {
            fprintf(file, "%d\n", arr->data[i]);
        }
        fclose(file);
    }
}

// Ler array de arquivo
void freadArray(Array* arr, const char* fileName)
{
    FILE* file = fopen(fileName, "r");
    int n = 0;

    if (file != NULL) 
    {
        fscanf(file, "%d", &n);
        if (n > 0) 
        {
            arr->data = (int*) malloc(n * sizeof(int));
            arr->length = n;
            for (int i = 0; i < n; i++) 
            {
                fscanf(file, "%d", &arr->data[i]);
            }
        } else 
        {
            printf("\nERRO: Tamanho invalido\n");
        }
        fclose(file);
    }
}

// Gerar números aleatórios
void generateRandom(Array* arr, int n, int inferior, int superior) 
{
    if (n <= 0 || inferior > superior) 
    {
        printf("\nERRO: Parametros invalidos\n");
        return;
    }

    if (arr->data != NULL) 
    {
        free(arr->data);
    }

    arr->length = n;
    arr->data = (int*) malloc(n * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < n; i++) 
    {
        arr->data[i] = inferior + rand() % (superior - inferior + 1);
    }
}

// Buscar maior ímpar
int searchFirstOdd(Array* arr) 
{
    int found = 0;
    int maior = arr->optional;

    for (int i = 0; i < arr->length; i++) 
    {
        if (arr->data[i] % 2 != 0) 
        {
            if (!found || arr->data[i] > maior) 
            {
                maior = arr->data[i];
                found = 1;
            }
        }
    }

    if (!found) {
        printf("\nNao ha valores impares no arranjo\n");
    }

    return maior;
}

// Buscar maior ímpar múltiplo de 3
int searchFirstOddx3(Array* arr) 
{
    int found = 0;
    int maior = arr->optional;

    for (int i = 0; i < arr->length; i++) 
    {
        if (arr->data[i] % 2 != 0 && arr->data[i] % 3 == 0) 
        {
            if (!found || arr->data[i] > maior) 
            {
                maior = arr->data[i];
                found = 1;
            }
        }
    }

    if (!found) {
        printf("\nNao ha impares multiplos de 3 no arranjo\n");
    }

    return maior;
}

// Soma valores no intervalo [start:end]
int addInterval(Array* arr, int start, int end) 
{
    int soma = 0;

    if (start < 0 || end >= arr->length || start > end) 
    {
        printf("\nERRO: Intervalo invalido\n");
        return 0;
    }

    for (int i = start; i <= end; i++) 
    {
        soma += arr->data[i];
    }

    return soma;
}

// Média dos valores no intervalo
double averageInterval(Array* arr, int start, int end) 
{
    int soma = 0;

    if (start < 0 || end >= arr->length || start > end) 
    {
        printf("\nERRO: Intervalo invalido\n");
        return 0.0;
    }

    for (int i = start; i <= end; i++) 
    {
        soma += arr->data[i];
    }

    return (double)soma / (end - start + 1);
}

// Adiciona elemento no final
void push_back(Array* arr, int value) 
{
    int* new_data = (int*) malloc((arr->length + 1) * sizeof(int));

    if (new_data != NULL) 
    {
        for (int i = 0; i < arr->length; i++) 
        {
            new_data[i] = arr->data[i];
        }

        new_data[arr->length] = value;

        if (arr->data != NULL) 
        {
            free(arr->data);
        }

        arr->data = new_data;
        arr->length += 1;
    }
}

// Remove elemento do final
void pop_back(Array* arr) 
{
    if (arr->length > 0)
    {
        int* new_data = NULL;

        if (arr->length > 1) 
        {
            new_data = (int*) malloc((arr->length - 1) * sizeof(int));

            for (int i = 0; i < arr->length - 1; i++) 
            {
                new_data[i] = arr->data[i];
            }
        }

        free(arr->data);
        arr->data = new_data;
        arr->length -= 1;
    }
}

// Ordenar em ordem decrescente (implementação manual)
void sort(Array* arr)
{
    for (int i = 0; i < arr->length - 1; i++) 
    {
        for (int j = i + 1; j < arr->length; j++) 
        {
            if (arr->data[i] < arr->data[j]) 
            {
                int temp = arr->data[i];
                arr->data[i] = arr->data[j];
                arr->data[j] = temp;
            }
        }
    }

}

//inverte os valores do arranjo
void inverterArray(Array* arr) 
{
    int temp;
    int i = 0;
    int j = arr->length - 1;

    while (i < j) 
    {
        temp = arr->data[i];
        arr->data[i] = arr->data[j];
        arr->data[j] = temp;
        i++;
        j--;
    }
}

// Filtra os elementos comuns sem repetição
void arranjo_filtrar(Array *resultado, Array *a1, Array *a2) {
    resultado->length = 0;

    for (int i = 0; i < a1->length; i++) {
        int valor = a1->data[i];

        // Verificar se o valor está em a2
        int encontrado = 0;
        for (int j = 0; j < a2->length; j++) {
            if (valor == a2->data[j]) {
                encontrado = 1;
                break;
            }
        }

        // Verificar se o valor já está no resultado
        int ja_existe = 0;
        for (int k = 0; k < resultado->length; k++) {
            if (valor == resultado->data[k]) {
                ja_existe = 1;
                break;
            }
        }

        // Adicionar valor ao resultado se encontrado e ainda não adicionado
        if (encontrado && !ja_existe) {
            resultado->data[resultado->length] = valor;
            resultado->length++;
        }
    }
}

int arranjo_tamanho(Array* arr) 
{
    return arr->length;
}




#endif