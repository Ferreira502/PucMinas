#include<stdio.h>

int maiusculaRec (char palavra[], int i, int y)
{
	if (palavra[i] == '\0')
	{
		return y;
	}
	else if (palavra[i] >= 'A' && palavra[i] = < 'Z')
	{
	       y++;	
	       return maiusculaRec(palavra, i + 1, y);	
	}
	else 
	{
		return maiusculaRec(palavra, i + 1, y);
	}
}

int maiuscula(char palavra[], int i, int y)
{
	return maiusculaRec (palavra, 0, 0);
}

int main () 
{
	char palavra[100];
	int x = 0, i = 0, y = 0;

	while(scanf(" %[^\n] " , palavra))
	{
		printf("\n", maiuscula(palavra, i, y));
	}
}
