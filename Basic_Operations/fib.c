#include <stdio.h>

int Fib(int n);

int main(void)
{
	int n;
	printf("Enter n: ");
	scanf("%d\n", &n);
	int result = Fib(n);
	printf("?%d\n", result);
}

int Fib(int n)
{
	if(n <= 1)
	{
		return n;
	}
	return Fib(n-1)+Fib(n-2);
}
