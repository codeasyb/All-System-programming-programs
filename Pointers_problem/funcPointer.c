#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 8

int compare(const void *, const void *);
// void toSort(char *, int,  int (*cmp)(void*, void*));
void swap(char *, char *, size_t);
void print_array (char **, int );
int insertionsort(void *, size_t, size_t, int (*comparator)(void*, void*));

int
main(int argc, char const *argv[])
{
	//build an array
	char *array[BUFSIZE] = {"a", "b", "c", "d", "e", "f", "\0"};

  char arr[5000];
  char 
  
  size_t numb = sizeof(arr)/sizeof(arr[0]);
  printf("%d\n", numb);

	int n = sizeof(array)/sizeof(array[0]);
	if(n == -1)
	{
		printf("Error getting the size of the array\n");
	}

	// printf("Size of the array: %d\n", n);

	// printf("Sorting the array.\n");
	// insertionsort(array, n, n, compare);
	// print_array(array, n);
	// printf("\n");

	return 0;
}

// This should not modify any what the arguments point at
int compare( const void *a, const void *b) 
{
   int val1 = *(int*)a;
   int val2 = *(int*)b;

   return ( val1 - val2 ); 
}

int insertionsort(void *array, size_t nitems, size_t size, int (*cmp)(void*, void*))
{
    size_t i, j;
    for ( i = 1; i < nitems; i++ )
    {
        j = i;
        while ( j > 0 && cmp( (char*)array+j-1, (char*)array+j ) > 0 )
                      // ^^^ call of cmp instead of operator >
        {
            swap( (char*)array+j-1, (char*)array+j, size );
            j--;
        }
    }
    return 0;
}

void swap(char *to, char *from, size_t len)
{
    unsigned char *uc_to   = to;
    unsigned char *uc_from = from;
    unsigned char tmp;
    printf("swapping.\n");
    for (size_t i = 0; i < len; i++)
    {
        tmp = uc_to[i];
        uc_to[i] = uc_from[i];
        uc_from[i] = tmp;
    }
}

int insertionsort(void *head, int (*cmp)(void*, void*))
{
  int size = 0;
  for(struct node *p = head ; p != NULL; p = p->next)
  {
    size += 1;
  }
    size_t i, j;
    for ( i = 1; i < size; i++ )
    {
        j = i;
        while ( j > 0 && cmp( (void*)head+j-1, (void*)head+j ) > 0 )
        {
            swap( (char*)head+j-1, (char*)head+j, size );
            j--;
        }
    }

    for(struct node *p = head; p != NULL; p = p->next)
    {
      printf("%s\n", p->data);
    }
    return 0;
}

// int insertionsort(void *, int (*comparator)(void*, void*))
// {


//     return 0;

// }

void swap(char *to, char *from, size_t len)
{
    unsigned char *uc_to   = to;
    unsigned char *uc_from = from;
    unsigned char tmp;

    for (size_t i = 0; i < len; i++)
    {
        tmp = uc_to[i];
        uc_to[i] = uc_from[i];
        uc_from[i] = tmp;
    }
}

void print_array (char **array, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        printf ("%d: %s\n", i, array[i]);
    }
}

