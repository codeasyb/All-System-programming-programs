#include <stdio.h>

int main(int argc, char const *argv[])
{



	int arr[5] = {5, 4, 3, 2, 1};

	size_t n = sizeof(arr)/sizeof(int);
	printf("Size of the array: %zu\n", n);
	for (int i = n-1; i > 0; i--)
	{
	 	printf("%d ", arr[i]);
	} 
	printf("\n");
	return 0;
}