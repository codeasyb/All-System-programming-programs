#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <string.h>

struct node{
	void *data;
	struct node *next;
};

// To compare the Integers
int compare_int(void *a, void *b)
{
	int *acast = (int*) a;
	int *bcast = (int*) b;
	if ((*acast) < (*bcast))
	{
		return -1;
	} else if ((*acast) == (*bcast))
	{
		return 0;
	} else {
		return 1;
	}
}

// TO compare the strings 
int compare_str(void *a, void *b)
{
	char *acast = (char*) a;
	char *bcast = (char*) b;
	if ((*acast) > (*bcast))
	{
		return -1;
	} else if ((*acast) == (*bcast))
	{
		return 0;
	} else {
		return 1;
	}
}

void swap(void *first, void *second, int (*cmp)(void *, void *))
{
	int response;

	struct node* first_addr = (struct node*) first;
	struct node* second_addr = first_addr->next;

	first_addr = first_addr->data;
	second_addr = second_addr->data;

	// now do the comparison
	response = cmp(first_addr, second_addr);
	struct node temp_node;
	if (response == 1)
	{
		temp_node = *first_addr;
		*first_addr = *second_addr;
	}
}

//sorting function with a function pointer to compare two elements
void insertionsort(void *head, int(*cmp)(void*, void*))
{
	int len = 0;
	struct node *p = head;
	for( ; p != NULL; p = p->next)
	{
		len += 1;
	}
	printf("length: %d\n", len);


    struct node *first = (struct node*)head;
    printf("First node: %s\n", first->data);
    struct node *second = first->next;
    printf("Second node: %s\n", second->data);
    struct node *temp;
    for( ; first != NULL; first = first->next)
    {
    	// temp = second;
    	// printf("Temp node: %s\n", temp->data);
    	while(first != NULL)
    	{
    		if(((cmp)(first->data, second->data)) == 1)
	    	{
	    		first->data = second->data;
	    	}
	    	first = first->next;
    	}
    	first->data = temp->data;
    }
}


void freeMalloc(struct node *head)
{
	struct node *p = head;
	while(p != NULL)
	{
		free(p->data);
		p = p->next;
	}
}

void printllist(struct node *head)
{
	struct node *p = head;
	while(p != NULL)
	{
		printf("%s\n", p->data);
		p = p->next;
	}
}


int 
main(int argc, char *argv[])
{

	char word[] = "Hello, world, my, friends";
	char numbs[] = "10, 2, 6, 1, 8, 9, 3";
	const char s[3] = " ,";
	int len = 0;

	int fd = open(argv[1], O_RDONLY | O_NONBLOCK);

	struct node *head = NULL, *q = NULL, *p = NULL;

	q = (struct node*)malloc(sizeof(struct node));
	q->data = (char*)word;
	q->next = NULL;

	head = q;
	p = head;

	printf("Linkedlist tokens...\n");
	printf("List of token: %s\n", p->data);

	char *tokens = strtok(word, s);

	while(tokens != NULL)
	{
		q = (struct node*)malloc(sizeof(struct node));
		q->data = strdup(tokens);
		q->next = NULL;
		
		head = q;
		p = head;
 
		tokens = strtok(NULL, " ,");
			// printllist(p);	
		// for( ; p != NULL; p = p->next)
		// {
		// 	printf("%s\n", p->data);
		// 	len += 1;
		// }
		//printllist(p);
	}

	p = head;
	// insertionsort(p, compare_str);
	printllist(p);

	//printf("Length of the list: %d\n", len);
	for ( ; p != NULL; p = p->next)
	{
		freeMalloc(p);
	}
	

	freeMalloc(p);


	return 0;
}