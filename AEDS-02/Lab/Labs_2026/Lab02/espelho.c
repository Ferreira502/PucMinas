#include<stdio.h>

int main ()
{
	int a = 0;
	int b = 0;
	int array[1000];
	
	scanf("%d", &a);
	scanf("%d", &b);
	int i = 0;

	while(a <= b)
	{
		array[i] = a;
		i++;
		a++;
	}

	for(int j = 0; j < i; j++)
    	{
        	printf("%d ", array[j]);
    	}

	for (int j = i - 1; j >= 0; j--)
    	{
        	printf("%d ", array[j]);
    	}


}
