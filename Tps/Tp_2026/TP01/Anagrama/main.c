// Questao 06
// Autor: Gabriel Ferreira Pereira

#include<stdio.h>

/**
 * @author Gabriel Ferreira Pereira
 *
 * @param char string int x
 *
 * @reason  funcao recebe uma string e um inteiro e ordena a cadeia de caracteres
 *          
 */
void sort( char string[], int x ) 
{
    for (int i = 0; i < x - 1; i++)
    {
        for (int j = x - 1; j > i; j--)
        {
            if (string[j] < string[j-1])
            {
                int tmp = string[j];
                string[j] = string[j - 1];
                string[j - 1] = tmp;
            }
            
        }
    }
}

/**
 * @author Gabriel Ferreira Pereira
 *
 * @param char string char string 2 
 *
 * @reason  funcao recebe 2 strings descubra se é anagrama e retorna SIM ou NAO
 *          
 */

int anagrama( char a[], char b[], int x, int y )
{
    if ( x != y ) 
    {
        return 0;
    }

    for (int i = 0; i < x; i++)
    {
        if (a[i] != b[i]) 
        {
            return 0;
        }
    }  

    return 1;
}


int main ()
{
    char string[100];
    scanf(" %[^\n]", string);

	while (!( string[0] == 'F' && string[1] == 'I' && string[2] == 'M' )) 
	{
        int resultado = 0;
        int x = 0, y = 0;
        char a[100];
        char b[100];

        for (int i = 0; string[i] != ' ' && string[i] != '\0'; i++)
        {
            if (string[i] >= 65 && string[i] <= 90)
            {
                a[x] = string[i] + 32;
            }

            else
            {
                a[x] = string[i];
            }

            x++;
        }

        for (int i = x + 1; string[i] != '\0'; i++)
        {
            if (string[i] >= 65 && string[i] <= 90)
            {
                b[y] = string[i] + 32;
            }
            
            else
            {
                b[y] = string[i];
            }

            y++;
        }
        
        sort(a, x);
        sort(b, y);
        
        resultado = anagrama(a, b, x, y);
        
        if ( resultado == 1 ) 
        {
            printf("SIM\n");
        }

        else 
        {
            printf("NAO\n");
        }
        
        scanf(" %[^\n]", string);
    }
}