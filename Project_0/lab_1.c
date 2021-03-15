#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cs214.h"
#define BUFSIZE 1000

int main(int argc, char *argv[])
{

	int array[10] = {2, 5, 4, 7, 5, 8, 9, 0, 1, 3};
	size_t n = sizeof(array)/sizeof(int);
	insertionsort(array, n);
	printarray(array, n);

	// File arguments
	FILE *filename;
	char buffer[BUFSIZE];
	filename = fopen(argv[1], "r");
	while(fgets(buffer, BUFSIZE - 1, filename) != NULL)
	{
		printf("%s\n", buffer);
		for (int i = 1; i < argc; i++)
		{
			printf("%s\n", argv[i]);
			if (argv[1] == "-i")
			{
				printf("hello\n");
				printf("%s \n", buffer);
			}
		}
	}
	fclose(filename);

	if (argc > 0)
	{
		printf("Argument passed: %s\n", argv[1]);
		
	} else if( argc > 2)
	{
		printf("Error processing argument.\n");
	} 
	return 0;
}
