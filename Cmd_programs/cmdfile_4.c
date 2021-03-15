#include <stdio.h>

int main(int argc, char **argv)
{
	
	if(argc != 2)
	{
		printf("usage %s filename", argv[0]);
	} else 
	{
		FILE *f = fopen(argv[1], "r");
		if(f == NULL)
		{
			printf("File does not exits.");
		} else
		{
			int x;
			while((x = fgetc(f)) != EOF)
			{
				printf("%c", x);
			}	
			fclose(f);
		} 				
	}	
	return 0;
}
