#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

enum boolean {true = 1, false = 0};

int  main(void)
{

	enum boolean flag;
	flag = true;
	
	int* numbers = NULL;
	int capacity = 0;

	int size = 0;
	while(flag)
	{
		printf("Enter: ");
		int number;
		scanf("%d", &number);

		if (number == INT_MAX)
		{
			break;
		}

		if (size == capacity)
		{
			numbers = realloc(numbers, sizeof(int) * (size + 1));
			capacity++;
		}

		numbers[size] = number;
		size++;
	}

	for (int i =0; i < size; i++)
	{
		printf("You inputted %i\n", numbers[i]);
	}

	free(numbers);
}