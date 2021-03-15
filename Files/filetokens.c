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

enum boolean{
	true = 1,
	false = 0,
};

int 
main(int argc, char *argv[])
{
	enum boolean flag;
	flag = true;

	int fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		perror("file not exist");
		exit(1);
	}

	char buffer[BUFSIZE] = { };
	int buff_idx = 0;

	char *arr_tokens[100];
	int token_idx = 0;

	char read_char;
	int num_bytes;

	while(flag)
	{
		num_bytes = read(fd, &read_char, flag);

		if(isDelimiter(read_char) || num_bytes == 0)
		{
			arr_tokens[token_idx] = malloc(sizeof(char)*(buff_idx+1));

			for (int i = 0; i < buff_idx; ++i)
			{
				arr_tokens[token_idx][i] = buffer[i];
			}

			arr_tokens[token_idx][buff_idx] = '\0';
			token_idx++;

			buff_idx = 0;
			if(num_bytes == 0)
			{
				break;
			}
		} else 
		{	
			buffer[buff_idx] = read_char;
			buff_idx++;
		}
	}

	int *arr_int = malloc(token_idx*sizeof(int));

	for (int i = 0; i < token_idx; ++i)
	{
		arr_int[i] = atoi(arr_tokens[i]);
	}

	for (int i = 0; i < token_idx; ++i)
	{
		printf("%d -> %d\n", i, arr_int[i]);
		free(arr_tokens[i]);
	}

	printf("\nAoti: %d\n", atoi("28"));

	close(fd);
	return 0;
}

int isDelimiter(char c)
{
	if(c == ','){
		return 1;
	} else{
		return 0;
	}
}

















