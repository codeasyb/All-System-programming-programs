#include <stdio.h>
#include <math.h>

void insertsort(int a[], int n);
void printValues(int a[], int n);

int main()
{
	int array[] = {7, 3, 2, 8, 5, 1};
	size_t size = sizeof(array)/sizeof(array[0]);
	printf("Array size: %zu\n", size);
	insertsort(array, size);
	printf("\n");
	printValues(array, size);

	return 0;
}

void insertsort(int a[], int n)
{
	int i, key, j;
	for(i = 1; i < n; i++)
	{
		key = a[i]; 	// store the element at index
		j = i - 1; 		// current index - 1
		while(j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key; // store the value at right position
	}
}

void printValues(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
