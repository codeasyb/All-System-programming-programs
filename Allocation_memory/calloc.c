#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

	int* ptr, i, n, sum = 0;

	printf("Enter limit: ");
	scanf("%d\n", &n);

	// Allocating the memory dynamically 
	ptr = (int*) calloc(n, sizeof(int));

	if(ptr == NULL)
	{
		printf("Error! not Allocated.\n");
		exit(0);
	}

	for(i =0; i < n; i++)
	{
		printf("Enter: ");
		scanf("%d", ptr + i);
		//derefernce
		sum += *(ptr + i);
	}

	printf("Sum: %d\n", sum);

	free(ptr);

	return 0;
}