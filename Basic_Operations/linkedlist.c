#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int capacity = 2;
	int number[capacity];

	int size = 0;
	while(size < capacity)
	{
		int temp;
		printf("Enter: ");
		scanf("%d\n", temp);
		number[size] = temp;
		size++;
	}
	for(int i =0; i < capacity; i++)
	{
		printf("Elements: %i\n", number[i]);
	}
	printf("Done\n");
}
