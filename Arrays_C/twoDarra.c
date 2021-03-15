#include <stdio.h>

void show2dArray();


struct types { int i; float f}; // adds all types
union typeu {int i; float f};   // does not add all

int main(int argc, char* argv[])
{
	int myNumber[3][4] = {
			   {7, 3, 2},
			   {7, 8, 1},
			   {8, 1, 8, 9},
		          };
	int i, j;
	// for(i=0; i < 3; i++)	
	// {
	// 	for(j=0; j < 4; j++)
	// 	{
	// 		printf("%d ", myNumber[i][j]);
	// 	}
	// 	printf("\n");
	// }

	printf("\n");
	// show2dArray();


	int age[] = {21, 26, 25, 31, 34};

	printf("Size: %d\n", sizeof(age));

	struct types s; //size of all types in the struct
	printf("Struct size: %d\n", sizeof(s));

	union typeu u;  //size of only the most bytes type
	printf("Union size: %d\n", sizeof(u));

	// for(int i =0; i < age; i++)
	// {
	// 	printf("%i\n", age[i]);
	// }
	printf("\n");

	return 0;
}


void show2dArray()
{

	int array2d[4][4] = {
						{ 1,  2,  3,  4},
						{ 5,  6,  7,  8},
						{ 9, 10, 11, 12},
						{13, 14, 15, 16},
						};

	int i, j;

	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 4; ++j)
		{
			printf("%d  ", array2d[i][j]);
		}
		printf("\n");
	}
	printf("End.\n");
}























