#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

	int* ptr, i, n, sum = 0;

	printf("Enter limit: ");
	scanf("%d", &n);

	printf("Limit: %d\n", n);

	ptr = (int*) malloc(n * sizeof(int));

	// printf("Value: %d\n", *ptr);
	// case for checking if the memory did not allocate for some reason
	if(ptr == NULL)
	{
		printf("Error! Memory not allocated.\n");
		exit(0);
	}

	// suming the elements 
	for(i =0; i < n; i++)
	{
		printf("Enter: ");
		scanf("%d", ptr + i);
		sum += *(ptr + i);
	}

	printf("Sum: %d\n", sum);

	// freeing the space back to memory
	free(ptr);
	return 0;
}