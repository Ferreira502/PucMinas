#include<stdio.h>



int substring(char c[], int x)
{
    int y = 0;

    for (int i = 0; i < x; i++)
    {
        int tamanho = 1;

        for (int j = i + 1; j < x; j++)
        {
            int repetido = 0;

            for (int k = i; k < j; k++)
            {
                if (c[k] == c[j])
                {
                    repetido = 1;
                }
            }

            if (!repetido)
            {
                tamanho++;
            }

            else
            {
                j = x;
            }
        }

        if (tamanho > y)
        {
            y = tamanho;
        }
    }

    return y;
}

int main ()
{
	char string[100];

    scanf(" %[^\n]", string);

	while (!(string[0] == 'F' && string[1] == 'I' && string[2] == 'M')) 
	{
        int resultado = 0;
        int x = 0;

        for (int i = 0; string[i] != '\0'; i++)
        {
            x++;
        }
        
        resultado = substring(string, x);
        printf("%d\n", resultado);

        scanf(" %[^\n]", string);
    }
    
	return 0;
}