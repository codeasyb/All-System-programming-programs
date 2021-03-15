#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
// #include "cs214.h"
#define BUFSIZE 1000

int isDelimiter(char c);

enum boolean {
	true = 1,
	false = 0,
};

int 
main(int argc, char *argv[])
{

	enum boolean flag;
	flag = true;

	int fd = open(argv[1], O_RDONLY);

	printf("file descriptor: %d\n", fd);

	char buffer[BUFSIZE] = { };
	int buff_idx = 0;

	char *arr_tokens[100];
	int token_idx = 0;

	char read_char;
	
	int num_bytes;

	// printf("argc: %d\n", argc);

	// for (int i = 0; i < argc; i++)
	// {
	// 	printf("%s ", argv[i]);
	// }
	// printf("\n");

	// while(a < argc)
	// {
	// 	printf("a: %d\n", a);
	// 	if(2 < argc)
	// 	{
	// 		printf("Explore\n");
	// 		printf("./output -i file || ./output -q file\n");
	// 		printf("-i = insertion sort\n");
	// 		printf("-q for quicksort\n");
	// 		printf("try it. The results may be interesting.\n");
	// 	}else if(argv[1][0] != '-')
	// 	{
	// 		printf("Fatal Error: Expected two arguments, had one\n");
	// 		exit(1);
	// 	}
	// 	printf("how the fuck 3 is not greater than 2!!\n");
	// 	if(argc > 2)
	// 	{
	// 		printf("wtf boy\n");
	// 		if (argv[2][0] == "-")
	// 		{
	// 			printf("Fatal Error: file '%s' does not exist\n", argv[2]);
	// 			exit(1);
		
	// 		}
	// 	}
	// }

	//looping over ever character in the file
	while(flag)
	{
		num_bytes = read(fd, &read_char, flag);

		if(isDelimiter(read_char) || num_bytes == 0)
		{
			arr_tokens[token_idx] = malloc((sizeof(char)*(buff_idx+1)));	

			for (int i = 0; i < buff_idx; ++i)
			{
				arr_tokens[token_idx][i] = buffer[i];
			}

			//here the tokens are strings
			arr_tokens[token_idx][buff_idx] = '\0';
			token_idx++;

			//means the buffer is empty
			buff_idx = 0;

			//exit if there are no bytes left to read
			if (num_bytes == 0)
			{
				break;
			}
		} else 
		{
			//if it is not a comma
			buffer[buff_idx] = read_char;
			buff_idx++;
		}
	}

	printf("buffer index: %d\n", buff_idx);

	int c;

	// process the tokens into integers
	// allocate the space before you convert the strings into integer
	int *arr_int = malloc(token_idx * sizeof(int));

	for (int i = 0; i < token_idx; ++i)
	{
		// taking the strings and converting them into integers
		arr_int[i] = atoi(arr_tokens[i]);
	}

	// Print the tokens
	for (int i = 0; i < token_idx; ++i)
	{
		printf("%d %d\n", i, arr_int[i]);
		free(arr_tokens[i]);
	}

	while((c = getopt(argc, argv, "iqw:")) != -1)
	{
		switch(c)
		{
			case 'i':
					// insertionsort(*arr_tokens, token_idx);
					// printarray(*arr_tokens, token_idx);
				break;
			case 'q':
				printf("Going to work on quick sort.\n");
				break;
			default:
				abort();
		}
	}



	close(fd);
	return 0;
}


int isDelimiter(char c)
{
	if(c == ',')
	{
		return 1;
	} else {
		return 0;
	}
}