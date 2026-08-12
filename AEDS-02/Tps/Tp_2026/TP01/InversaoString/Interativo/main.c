//QUESTAO 04 DO TP01
//Autor: Gabriel Ferreira Pereira

#include<stdio.h>

void inversao(char string[])
{
	int x = 0;

	for ( int i = 0; string[i] != '\0'; i++ )
	{
        x++;
	}

    for ( int j = x - 1; j >= 0; j-- )
    {
		printf("%c", string[j]);
	}

    printf("\n");
}

int main ()
{
	char string[100];
	int fim = 0;

    scanf(" %[^\n]", string);

	while (!(string[0] == 'F' && string[1] == 'I' && string[2] == 'M')) 
	{
        inversao(string);
        scanf(" %[^\n]", string);
    }
    
	return 0;
}