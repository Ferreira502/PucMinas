#include <stdio.h>

int maiuscula(char palavra[])
{
	int x = 0;

	for (int i = 0; palavra[i] != '\0'; i++)
	{
		if(palavra[i] >= 'A' && palavra[i] <= 'Z')
		{
			x++;
		}
	}

	return x;
}

int main ()
{
	int x = 0;
	char string[100];

	while(scanf(" %[^\n] ", string) != EOF) // usar no scanf para ler ate o final da linha aonde ta o \n
	{
		x = maiuscula(string);
		printf("\n %d", x);
	}

}
