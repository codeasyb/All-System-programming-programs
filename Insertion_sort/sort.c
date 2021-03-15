#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

typedef struct node 
{
	void *data;
	struct node *next;
}node;

int compare_str(void *a, void *b)
{
	char *acast = a;
	char *bcast = b;
	while(*acast != "\0")
	{
		if(*bcast == "\0") return 1;
		if ((*acast) < (*bcast)) return -1;
		if (*acast > *bcast) return 1;
		
		acast += 1;
		bcast += 1;
	}
	if(*bcast != "\0") return 0;

	return 0;
}

void insertionsort(void *head, int(*cmp)(void*, void*))
{

    node *first = (node*)head;
    node *second = first->next;

    while(first != NULL)
    {
    	printf("test1\n");
    	if(((cmp)(first->data, second->data)))
	    {
	    	printf("test2\n");
	    	if (second->data == "\0")
	    	{
	    		break;
	    	}
	    	node *temp = first->data;
	    	first->data = second->data;
	    	second->data = temp->data;
	    }
	    // printf("test1%s\n");
	    //first = first->next;
	    // second = second->next;
    }
}

void printtokens(node *head)
{
	node *p = head;
	while (p != NULL)
	{
		printf("%s\n", p->data);
		p = p->next;
	}
}

int 
main(int argc, char const *argv[])
{

	char str[] = "hello, friends, just, checking";
	char del[2] = " ,";
	int size_str = sizeof(str);

	struct node *head = NULL, *p, *q;
	
	char *tokens = strtok(str, del);

	q = (node*)malloc(sizeof(node));

	head = q;

	while(tokens != NULL)
	{
		int n = n + 1;
		q->next = (node*)malloc(sizeof( node));
		q = q->next;
		q->data = strdup(tokens);
		// q->next = NULL;
		printf("Token %d, %s\n", n, q->data);

		tokens = strtok(NULL, " ,");
	}
	printf("-----------\n");

	printtokens(head->next);

	printf("-----------\n");

	printf("-----------\n" );

	insertionsort(head->next, compare_str);

	printtokens(head->next);
	printf("-----------\n" );
	return 0;
}