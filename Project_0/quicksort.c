#include <stdio.h>

int partition(int arr[], int low, int high);
void swap(int *a, int *b);
void printarray(int arr[], int n);

int main(int argc, char const *argv[])
{
	
	int arr[9] = {7, 1, 2, 9, 8, 13, 5, 4, 3};	
	size_t n = sizeof(arr)/sizeof(int);
	printf("Array size: %zu\n", n);

	quicksort(arr, 0, n-1);
	printarray(arr, n);

	return 0;
}

int quicksort(int arr[], int low, int high)
{
	if(low < high)
	{	
		int pi = partition(arr, low, high);  // get the partition 
		quicksort(arr, low, pi -1);			 // sort the right side of the array
		quicksort(arr, pi + 1, high);		 // sort the left side of the arrayh
	}
}

/**
	pivot = the starting of the list
	pivot = low[7] at index 0
	arr = {7, 1, 2, 9, 8, 13, 5, 4, 3}
		   i 					    j	
	pivot = 7
	i is going to be greater than 7 and 
	j will be less than 7

	once the j crosses the index i 

*/
int partition(int arr[], int low, int high)
{
	int pivot = arr[low];  //this holds the value 7 
	int i = arr[low - 1];  //this is the index -1 
	for(int j = high-1; j > low; j--)
	{
		if(arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], arr[]);
	return (i+1);
}

int partition2(int arr[], int low, int high)
{
	/**

		pivot = the end of the list
		i is negative and so will travese through the list from 
		index 0
		then while 0 is less than end of the list
		check if the array index 0 is less than the pivot
		increment the the i and then swap the elements of array 
		index i and the array index j
		do until i pass j 
		exit and then swap the j with the pivot
		and then return the pivot poistion

	*/	
	int pivot = arr[high];
	int i  = (low - 1);
	for (int j = low; j < high; ++j)
	{
		if(arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return (i+1);
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printarray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}







