#include <stdio.h>
#include <stdbool.h>

bool compareGreater(int, int);
bool compareLess(int, int);
void compareNumberFunction(int *, int, int, bool (*p)(int, int));

int main()
{
	int arrayNumber[7] = {34, 45, 67, 89, 54, 89, 22};
	int compareNumber = 50;

	printf("compare numbers for greater\n");
	compareNumberFunction(arrayNumber, 7, compareNumber, compareGreater);

	printf("\ncompare numbers for less\n");
	compareNumberFunction(arrayNumber, 7, compareNumber, compareLess);
}

void compareNumberFunction(int *arrayNumber, int count, int compareNumber, bool (*p)(int, int))
{

	for (int i = 0; i < count; i++)
	{
		// printf("%d, %d <---\n", *arrayNumber, compareNumber);
		if(p(*(arrayNumber+i), compareNumber))
		{
			printf("%d\n", (compareNumber+i));
		}
	}
}

bool compareGreater(int number, int compareNumber)
{
	return number > compareNumber;
}

bool compareLess(int number, int compareNumber)
{
	return number < compareNumber;
}

