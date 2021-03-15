#include <stdio.h>
#include<stdlib.h>
#include<time.h>

struct MaxHeap
{
	int size;
	int* array;
};


int main( int argc, char *argv[] )
{
	clock_t tic = clock();
	FILE *file;
	FILE *fp;
	file=fopen(argv[2],"r");
	int a[100],i,t,j,d;
	for(i=0;i!=EOF;i++)
	{
		fscanf(file,"%d",&a[i]);
	}
	
	int len=i;
	int ch=argv[1];
	switch(ch)
	{
		case 0:
			//Bubble sorting algorithm
			for(i=len-2;i>=0;i--){
				for(j=0;j<=i;j++){
					if(a[j]>a[j+1]){
						t=a[j];
						a[j]=a[j+1];
						a[j+1]=t;
					}
				}
			}
			fp=fopen(argv[3],"w");
			for(i=0;i<len;i++)
			{
				fprintf(fp,"%d\t",a[len]);
			}
			fclose(fp);
			printf("\nBubblesort ");
			break;
		case 1:
			for(i= 1 ; i <= len - 1; i++) {
				j = i;

				while ( j> 0 && a[j] < a[j-1]) {
					t = a[j];
					a[j] = a[j-1];
					a[j-1] = t;

					j--;
				}
			}
			fp=fopen(argv[3],"w");
			for(i=0;i<len;i++)
			{
				fprintf(fp,"%d\t",a[len]);
			}
			fclose(fp);
			printf("\nInsertionsort ");
			break;
		case 2:

			for ( i = 0 ; i < ( len- 1 ) ; i++ )
			{
				int position = i;

				for ( d = i + 1 ; d< len ; d++ )
				{
					if ( a[position] > a[d] )
						position = d;
				}
				if ( position != i ){
					t = a[i];
					a[i] = a[position];
					a[position] = t;
				}
			}
			fp=fopen(argv[3],"w");
			for(i=0;i<len;i++)
			{
				fprintf(fp,"%d\t",a[len]);
			}
			fclose(fp);
			printf("\nSelectionsort ");
			break;
		case 3:
			mergesort(a,0,len-1);
			fp=fopen(argv[3],"w");
			for(i=0;i<len;i++)
			{
				fprintf(fp,"%d\t",a[len]);
			}
			fclose(fp);
			printf("\nMergesort ");
			break;
		case 4:
			heapSort(a,len);
			fp=fopen(argv[3],"w");
			for(i=0;i<len;i++)
			{
				fprintf(fp,"%d\t",a[len]);
			}
			printf("\nHeapsort ");
			break;
		case 5:
			quicksort(a,len);
			fp=fopen(argv[3],"w");
			for(i=0;i<len;i++)
			{
				fprintf(fp,"%d\t",a[len]);
			}
			printf("\nquicksort ");
			break;
	}
	clock_t toc = clock();

	printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
}


void mergesort(int a[],int i,int j)
{
	int mid;

	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(a,i,mid);
		mergesort(a,mid+1,j);
		merge(a,i,mid,mid+1,j);
	}
}

void merge(int a[],int i1,int j1,int i2,int j2)
{
	int temp[50];
	int i,j,k;
	i=i1;
	k=0;

	while(i<=j1 && j<=j2)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}

	while(i<=j1)
		temp[k++]=a[i++];

	while(j<=j2)
		temp[k++]=a[j++];


	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=temp[j];
}


void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }

void maxHeapify(struct MaxHeap* maxHeap, int idx)
{
	int largest = idx; // Initialize largest as root
	int left = (idx << 1) + 1; // left = 2*idx + 1
	int right = (idx + 1) << 1; // right = 2*idx + 2

	// See if left child of root exists and is greater than
	// root
	if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest])
		largest = left;

	// See if right child of root exists and is greater than
	// the largest so far
	if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest])
	largest = right;

	// Change root, if needed
	if (largest != idx)
	{
		swap(&maxHeap->array[largest], &maxHeap->array[idx]);
		maxHeapify(maxHeap, largest);
	}
}

// A utility function to create a max heap of given capacity
struct MaxHeap* createAndBuildHeap(int *array, int size)
{
	int i;
	struct MaxHeap* maxHeap = (struct MaxHeap*) malloc(sizeof(struct MaxHeap));

	maxHeap->size = size; // initialize size of heap
	maxHeap->array = array; // Assign address of first element of array

	// Start from bottommost and rightmost internal mode and heapify all
	// internal modes in bottom up way
	for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
		maxHeapify(maxHeap, i);
	return maxHeap;
}

// The main function to sort an array of given size
void heapSort(int* array, int size)
{
	// Build a heap from the input data.
	struct MaxHeap* maxHeap = createAndBuildHeap(array, size);

	// Repeat following steps while heap size is greater than 1.
	// The last element in max heap will be the minimum element
	while (maxHeap->size > 1)
	{
		// The largest item in Heap is stored at the root. Replace
		// it with the last item of the heap followed by reducing the
		// size of heap by 1.
		swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
			--maxHeap->size; // Reduce heap size

		// Finally, heapify the root of tree.
		maxHeapify(maxHeap, 0);
	}
}


void quicksort(int array[], int firstIndex, int lastIndex)
{
	//declaaring index variables
	int pivotIndex, temp, index1, index2;

	if(firstIndex < lastIndex)
	{
		//assigninh first element index as pivot element
		pivotIndex = firstIndex;
		index1 = firstIndex;
		index2 = lastIndex;

		//Sorting in Ascending order with quick sort
		while(index1 < index2)
		{
			while(array[index1] <= array[pivotIndex] && index1 < lastIndex)
			{
				index1++;
		}
		while(array[index2]>array[pivotIndex])
		{
			index2--;
		}

		if(index1<index2)
		{
			//Swapping opertation
			temp = array[index1];
			array[index1] = array[index2];
			array[index2] = temp;
		}
	}

	//At the end of first iteration, swap pivot element with index2 element
	temp = array[pivotIndex];
	array[pivotIndex] = array[index2];
	array[index2] = temp;

	//Recursive call for quick sort, with partiontioning
	quicksort(array, firstIndex, index2-1);
	quicksort(array, index2+1, lastIndex);
}
}