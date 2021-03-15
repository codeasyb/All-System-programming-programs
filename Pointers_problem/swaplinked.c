#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>


struct Node 
{
	void *data;
	struct Node* next;
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

// To print the Integes from the linkedlist
void printllInt(void* head)
{
	struct Node* node_ptr = head;
	while(node_ptr != NULL){
		printf("%d\n", *((int *) node_ptr->data));
		node_ptr = node_ptr->next;
	}	
	printf("\n");
}

// To print the Strings from the linkedlist
void printllStr(void* head)
{
	struct Node* node_ptr = head;
	while(node_ptr != NULL)
	{
		printf("%s\n", *((char *) node_ptr->data));
		node_ptr = node_ptr->next;
	}
}

void swap(void *toSwap, int (*cmp)(void *, void *))
{
	int response;

	struct Node* first_addr = (struct Node*) toSwap;
	struct Node* second_addr = first_addr->next;

	first_addr = first_addr->data;
	second_addr = second_addr->data;

	// now do the comparison
	response = cmp(first_addr, second_addr);
	struct Node temp_node;
	if (response == 1)
	{
		temp_node = *first_addr;
		*first_addr = *second_addr;
	}
}

int
main(int argc, char const *argv[])
{
	struct Node *first;	
	struct Node *second;

	first = (struct Node*)malloc(sizeof(struct Node));
	second  = (struct Node*)malloc(sizeof(struct Node));

	char *first_data = "World";
	char *second_data = "Hello";

	first->data = first_data;
	first->next = second;
	second->data = second_data;
	second->next = NULL;


	printf("Before.\n");
	printllStr(first);  // The node

	swap(first, compare_str);

	printf("After swap.\n");
	printllStr(second); // The Node

	return 0;
}