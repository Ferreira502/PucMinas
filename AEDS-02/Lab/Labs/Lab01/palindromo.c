//Algoritmo para solucionar o problema de palindromo, de forma interativa e de forma recursiva
//Complexidade: O(n)

#include<stdio.h>
#include<string.h>

// Palindromo de forma interativa

// int palindromo(char palavra[])
// {
// //     printf("\nentrei aqui");
// //     printf("\nnome da palavra: %s", palavra);
// //     printf("\ntamanho: %d", tamanho);
    
//     int i = 0;
//     int j = strlen(palavra) - 1;
//     int palindromo = 1;
    
//     while(i < j && palindromo)
//         {
//             if(palavra[i] != palavra[j])
//             {
//                 palindromo = 0;
//             }
//             i++;
//             j--;
//         }
//     return palindromo;
// }

// Palindromo de forma Recursiva

int palindromoRec(char palavra[], int i, int j)
{
    int resposta = 1;
    
    if ( i >= j)
    {
        resposta;
    }
    else if ( palavra[i] != palavra[j] )
    {
        resposta = 0;
    }
    else 
    {
        return palindromo(palavra,i + 1,j - 1);
    }
    return resposta;
}

int palindromo(char palavra[])
{
    return palindromoRec (palavra, 0, strlen(palavra) - 1);
}

int main()
{
    int n = 0;
    char palavra[80];
    scanf("%[^\n]", palavra);    //entrada de string com scanf e nao pega /n
    // fgets(palavra, 80, stdin);
    // scanf("%s", &palavra);
    
    int i = 0;
    int j = strlen(palavra) - 1;
    printf("\n%d", palindromo(palavra, i, j));

    return 0;
}
