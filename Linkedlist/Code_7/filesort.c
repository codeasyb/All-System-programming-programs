#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1000

struct Node 
{
	void *data;
	struct Node* next;
};

int 
main(int argc, char const *argv[])
{

	char *flag_insertsort = "-i";
	char *flag_quicksort = "-q";

	if (argc == 3)
	{
		printf("too many arguments\n");
	}

	if(argc < 2){
		perror(" Did not open file or does not exists");
	} else{
		printf("hello\n");
		
		if (argv[2] == "-i")
		{
			printf("hmmm\n");
			if ((compare(argv[2], "-i")) == 0)
			{
				printf("Insertion sort\n");
			}
			
			if ((compare(argv[2],"-q")) == 0)
			{
				printf("Quicksort\n");
			}
		}
	}
	
	return 0;
}

int compare( const void *a, const void *b) 
{
   int val1 = *(int*)a;
   int val2 = *(int*)b;

   return ( val1 - val2 ); 
}



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