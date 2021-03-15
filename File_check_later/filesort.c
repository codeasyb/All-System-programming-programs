#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1000

struct node {
	void *data;
	struct node *next;
};

int
main(int argc, char const *argv[])
{

	// char str[100] = "Hello, my, name, is, Amir";
	const char s[2] = ",";
	char *token;


	printf("\nREAD FROM STRING.\n");
	//get the first token
	//token = strtok(str, s);
	//printf("First token: %s\n", token);

	// while(token != NULL)
	// {
	// 	printf("%s\n", token);

	// 	token = strtok(NULL, s);
	// }
	printf("file name: %s\n",argv[1]);
	int fd, flag;
	// char buffer[BUFSIZE];

	// char *print_tokens;
	// int token_idx;
	
	char read_char;

	struct node *p, *q, *head, *item = NULL;
	//int i, n;
	
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		return -1;
	}

	// create the first node 
	q = (struct node *)malloc(sizeof(struct node));  
	q->data = item;									 
	q->next = NULL;	
	if (q == NULL)
	{
		printf("The first NODE did not allocate\n");
	}	

	head = q;
	p = head;							 

	printf("\nREAD FROM FILE.\n");


	while((flag = read(fd, &read_char, BUFSIZE)) > 0)
	{

		token = strtok(&read_char, s);
		if (token == NULL)
		{
			printf("The token is NULL\n");
		}

		printf("Token: %s\n", token);
		
		// create a node and point the value to the node
		q = (struct node *)malloc(sizeof(struct node));
		q->data = token;
		q->next = NULL;
		if (q == NULL)
		{
			printf("The NODE is NULL\n");
		}

		printf("Token q: %s\n", q->data);


		p->next = q;
		p = p->next;
		printf("Token p: %s\n", p->data);
		if(p->next == NULL)
		{
			break;
		}
		// while(token != NULL)
		// {
		// 	printf("%s\n", token);

		// 	token = strtok(NULL, s);

		// }
		// break;
		
	}

	printf("Printing the nodes.\n");

	p = head;

	while(p != NULL)
	{
		printf("%s\n", p->data);
		p = p->next;
	}

	return 0;
}

//comparator function for strings
int compare(char *str1, char *str2) {
  while (*str1 && *str1 == *str2) {
    str1++;
    str2++;
  }
  return *str1 - *str2;
}







