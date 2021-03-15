#include <stdio.h>

struct Distance 
{
	int feet;
	float inch;
}dist1, dist2, sum;

enum suit
{
	club = 1,
	diamonds = 2,
	hearts = 3,
	spades = 4,
};

int main()
{
	
	printf("1st distance\n");
	printf("Enter feet ");
	scanf("%d\n", &dist1.feet);
	printf("Enter inch: ");
	scanf("%f\n", &dist1.inch);

	printf("2nd distance\n");
	printf("Enter feet: ");
	scanf("%d\n", &dist2.feet);
	printf("\nEnter inch: ");
	scanf("%f\n", &dist2.inch);

	printf("Float size: %lu\n", sizeof(float));
	printf("Int size: %lu\n", sizeof(int));

	printf("%lu\n", sizeof(dist1));
	printf("%lu\n", sizeof(dist2));
	printf("%lu\n", sizeof(sum));

	// adding feet
	sum.feet = dist1.feet + dist2.feet;
	// adding inches
	sum.inch = dist1.inch + dist2.inch;

	// changing to feet if inch is greater than 12
	while(sum.inch >= 12)
	{
		++sum.feet;
		sum.inch = sum.inch - 12;
	}

	// print
	printf("Sum of distances = %d\'-%.1f\n", sum.feet, sum.inch);

	return 0;

}
