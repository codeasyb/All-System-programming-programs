#include <stdio.h>

int myFunc(int n);
int secondFunc(int n);

int main(void)
{
	int n = myFunc(10);
	printf("First Function: %d\n", n);
	printf("%d\n", &n);
	//printf("%d\n", *n);
	for(int i =0; i < n; i++)
	{
		printf("first: %i ", i);
	}
	for(int i =0; i < n; i++)
	{
		printf("Second: %i ", &i);
	}
	int num = secondFunc(10);
	printf("\nSecond Function: %d\n", num);
	
	
}


// pre sum function
int myFunc(int n)
{
	int i, sum = 0;
	for(i =0; i < n; ++i)
	{
		sum += i;
	}
	return sum;
}

// post sum function
int secondFunc(int n)
{
	int i, sum = 0;
	for(i = 0; i < n; i++)
	{
		sum += i;
	}		
	return sum;
}
