#include<stdio.h>

int main ()
{
	char string[100];
	int x = 0;
	int fim = 0;

	while (!fim) 
	{
        	x = 0;
        	scanf(" %[^\n]", string);

        if ( string[0] == 'F' && string[1] == 'I' && string[2] == 'M' ) 
	{
            fim = 1;
        } 

	else 
	{
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
    }

	return 0;
}
