#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>



struct node
{
    void *data;
    struct node *next;
};
//for comparing the flag
int compare_argu(void *a, void *b)
{
	char *acast = (char*) a;
	char *bcast = (char*) b;
	if(*acast == *bcast){
        return 1;
    } else {
        return 0;
    }
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

void swap(void *toSwap, int (*cmp)(void *, void *))
{
	int response;

	struct node* first_addr = (struct node*) toSwap;
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
    struct node *first = (struct node*)head;
    struct node *second = first->next;
    struct node *temp;
    while(first != NULL)
    {
      temp = first->data;
      if(temp->data > second->data)
      {
        temp->data = second->data;
      }
      first = first->next;
      second = second->next;
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

void freeMalloc(struct node *head)
{
	struct node *p = head;
	while(p != NULL)
	{
		free(p->data);
		p = p->next;
	}
}

int
main(int argc, char **argv)
{
    int fd = -1;
    char buffer[100] = {0};
    int ret = 0;
    const char del[] = " ,";
    fd = open(argv[2], O_RDONLY | O_NONBLOCK);
    //function pointer
    // int (*comparator)(void*, void*);
    // comparator = &compare;

    struct node *head = NULL, *last = NULL;

    while((ret = read(fd, (void *)buffer, sizeof(buffer)) > 0))
    {
        char *token = strtok(buffer, del);
        for ( ; token != NULL; token = strtok(NULL, del)) {
            // append token to list
            struct node *q = malloc(sizeof(struct node));
            q->data = strdup(token);
            q->next = NULL;
            if (last == NULL)
                head = last = q;
            else
                last = last->next = q;
        }
    }

    if (argc < 2)
    {
        printf("Please provide an argument for the flag and file to read\n");
        exit(EXIT_FAILURE);
    }

        if (compare_argu(argv[1], "-i") && !argv[2])
        {
            printf("Fatal Error: expected two arguments, had one\n");
            exit(EXIT_FAILURE);
        } else {
            if ((argv[1] == argv[1]) && (compare_argu(argv[2], "-i")))
            {
                printf("Fatal Error: %s is not a valid sort flag\n", argv[1]);
                exit(EXIT_FAILURE);
            }
        }


    if (compare_argu(argv[1], "-i") && argv[2])
    {
        struct node *p = head;
        insertionsort(p, compare_str);
        freeMalloc(p);
    }

    if(compare_argu(argv[1], "-q") && argv[2])
    {
        if (fd == -1)
        {
            printf("Error in operating the file error\n");
            exit(EXIT_FAILURE);
        }
    }


    close(fd);
    return EXIT_SUCCESS;
}
