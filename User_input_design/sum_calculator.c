#include <stdio.h>

int average(int i, int limit);

int main(int argc, char const *argv[])
{
	
	int n, i, sum =0, average;

	printf("Sum Calculator.\n");
	printf("How many elements: \n");	
	scanf("%d", &n);

	int ele[n];

	for(i = 0; i < n; i++)
	{
		printf("Enter: ");
		scanf("%d", &ele[i]);

		sum += ele[i];
	}
	printf("Sum: %d\n", sum);

	average = sum/n;
	printf("Average: %d\n", average);

	return 0;
}

int average(int sum, int limit)
{
	return sum/limit;
}