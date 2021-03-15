#include <stdio.h>
#include <stdlib.h>

void f(void);

int main()
{
	f();
}

void f(void)
{
	int *x = malloc(10 * sizeof(int));

	printf("%d\n", x[10]);
	
	x[10] = 50;
	
	printf("Element: %i\n", x[10]);
}
