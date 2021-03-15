#include <stdio.h>

int min(int n1, int n2)
{
	int result;
	if(n1 < n2)
	{
		result = n1;
	} else
	{
		result = n2;
	}
	return result;
}

int main()
{
	int num1, num2;
	
	printf("Finding the smallest of two numbers");
	printf("\nEnter num1:");
	scanf("%d", &num1);
	printf("\nEnter num2:");
	scanf("%d", &num2);
	printf("\nMin: %d", min(num1, num2));
	
	return 0;
}
