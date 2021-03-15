#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cs214.h"

#define BUFSIZE 1000

int main(int argc, char *argv[])
{
	int arr[5] = {4, 2, 3, 6, 7};
	size_t n = sizeof(arr)/sizeof(int);

	printf("%s\n", argv[2]);
	for (int i = 0; i < argc; ++i)
	{
		printf("%s, ", argv[i]);
	}
	printf("\n");
	printf("Your array size: %zu\n", n);

	FILE *file;
	char buffer[BUFSIZE];
	int fd = open(argv[2], O_RDONLY);

	


	return (0);
}

// while (((argc > 1) && (argv[1][0] == '-')) || (fgets(buffer, BUFSIZE-1, filename) != NULL))
// 	{
// 		switch (argv[1][1])
// 		{
// 			case 'i':
// 				while(fgets(buffer, BUFSIZE-1, filename) != NULL)
// 				{
					
// 				}
// 			case 'q':
// 				printf("hello quicksort\n");	

// 				// printf("%s\n",&argv[1][2]);
// 				// printf("%s\n",&argv[1][2]);
// 				break;

// 			default:
// 				printf("Wrong Argument: %s\n", argv[1]);
// 				break;
// 		}

// 		++argv;
// 		--argc;
// 	}













