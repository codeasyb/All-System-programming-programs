#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#define BUFSIZE 1000

struct node{
	int data;
	struct node *next;
};

enum boolean{
	true = 1,
	false = 0,
};

int 
main(int argc, char const *argv[])
{
	
	enum boolean flag;
	flag = true;
	int i, n, item;
	struct node *p, *q, *head;

	char buffer[BUFSIZE];   //Enough characters to read from the file

	int fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		perror("File does not exits");
		exit(1);
	}

	q = (struct node *)malloc(sizeof(struct node));
	q->data = item;
	q->next = NULL;

	head = q;
	p = head;

	printf("How many Node you want to create: ");
	scanf("%d\n", &n);

	if (n > 0)
	{
		for (int i = 0; i < n; ++i)
		{
			printf("Enter next value: ");
			scanf("%d\n", &item);

			q = (struct node *)malloc(sizeof(struct node));
			q->data = item;
			q->next = NULL;

			p->next = q; //link the node
			p = p->next; //jump to the current node
		}
	}

	p = head;
	while(!p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}

	return 0;
}