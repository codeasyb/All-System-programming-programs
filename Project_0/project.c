#include <stdio.h>
# include <stdlib.h>

void insertionsort(int a[], int n);
void printarray(int arr[], int n);

int main(int argc, char const *argv[])
{
	int arr[7] = {5, 4, 3, 7, 8, 9, 1};
	size_t n = sizeof(arr)/sizeof(int);
	printf("Size: %zu\n", n);
	
	while(argc > 1 && argv[1][0] == "-")
	{
		if(argv[1][1] == "i")
		{
			printf("Sorting the array\n");
			insertionsort(arr, n);
			printarray(arr, n);
		} else
		{
			printf("Shit didnt works\n");
		}
		argc--;
	}
	return 0;
}

void insertionsort(int a[], int n)
{
	int i, key, j;
	for (int i = 0; i < n; ++i)
	{
		key = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > key)
		{
			a[j+1] = a[j];
			j = j - 1;
		}
		a[j+1] = key;
	}
}

void printarray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", arr[i]);
	}
}