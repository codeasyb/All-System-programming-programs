# include <stdio.h>

#define MAX 10

void display_array(int *, const int);

int  
main(int argc, char const *argv[])
{
	int i, a[MAX], *pa;
	pa = a;

	for (int i = 0; i < MAX; ++i)
	{
		*(pa + i) = rand() % 100;
	}

	display_array(pa, MAX);

	display_array(a, MAX);

	return 0;
}

void display_array(int *p, const int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}