#include <stdio.h>

#define MAX 10

// ---

int main() {
    int array[MAX];
    int aux = 0, contador = 0;

    for (int i = 0; i < MAX; i++)
    {
        printf("\nDigite o valores do array: ");
        scanf("%d", &array[i]);
    }

    printf("\nOrdem atual dos arrays: ");
    getchar();

    for (int i = 0; i < MAX; i++)
    {
        printf(" %d ", array[i]);
    }
    getchar();

    for (int i = 1; i < MAX; i++)
    {
        for (int j = 0; j < MAX - 1; j++)
        {
            if (array [j] > array[j + 1])
            {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
            
        }
        
    }
    
    printf("\nOrdem Bubble sort (Ordenado)");
    
    for (int i = 0; i < MAX; i++)
    {
        printf(" %d ", array[i]);
    }
    
}
