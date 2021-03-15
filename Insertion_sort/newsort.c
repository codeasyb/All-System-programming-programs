#include <stdio.h>


void insertionSort(int array[], int n);


int main(int argc, char const *argv[])
{

	int array[10] = {5, 6, 3, 8, 6, 9, 1, 2, 3, 4};

	int n = sizeof(array)/sizeof(int);

	insertionSort(array, n);
	printf("%d\n", n);
	return 0;

}
void insertionSort(int a[], int n)
{
	int i , key, j;
	for (i = 1; i < n; ++i)
	{
		key = a[i]
		j = i - 1;
		while(j >= 0 && a[0] > key)
		{
			a[j+1] = a[j];
			j = j - 1;
		}
		a[j+1] = key;
	}
}