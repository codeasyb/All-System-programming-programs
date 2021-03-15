#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int 
main(int argc, char const *argv[])
{
	int c;

	itn fd = open(argv[2], O_RDONLY);
	size_t size_of_args = sizeof(argc)/sizeof(int);
	printf("args size: %s\n", size_of_args);

	if(argc < 2)
	{
		printf("Explore\n");
		printf("./output -i file || ./output -q file\n");
		printf("-i = insertion sort\n");
		printf("-q for quicksort\n");
		printf("try it. The results may be interesting.\n");
	} 

	if(argc > 2)
	{
		if(argv[1] == NULL)
		{
			printf("\n");
		}
	}

	while((c = getopt(argc, argv, "iqw:")) != -1)
	{
		switch(c)
		{
			case 'i':
				printf("Going to work on insertion sort.\n");	
				break;
			case 'q':
				printf("Going to work on quick sort.\n");
				break;
			default:
				abort();
		}
	}

	printf("\nDone.\n");
	return 0;
}