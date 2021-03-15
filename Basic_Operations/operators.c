#include <stdio.h>

int main(int argc, char const *argv[])
{
	
	int a = 1;

	// post increment increase 
	
	// printf("%d\n", a);
	// a--;
	// printf("%d\n", a);

	int i = 42;
	int j;

	// 

	j = (++i + 10);
	printf("%d\n", i);
	printf("%d\n", j);
	if (i < j)
		printf("%d\n", i);
	else		
		printf("%d\n", j);


	// // pre increment increase

	// int *ptr;

	// ptr = a;

	// ptr++;
	// printf("%d\n", ptr);

	// ++ptr;
	// printf("%d\n", ptr);

	// printf("End.\n");

	return 0;
}