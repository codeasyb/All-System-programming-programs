#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>

struct node {
    void *data;
    struct node *next;
};

int 
main(int argc, char **argv)
{
    struct node *head = NULL, *q, *p;
    int i, n = 3, item = 2;
    char *word = "hello";

    //created the first node
    q = (struct node*)malloc(sizeof(struct node));
    q->data = item;
    q->next = NULL;

    head = q;
    p = head;

    printf("%d\n", p->data);

    if(n > 0)
    {
        for(i = 0; i < n; i++)
        {
            q = (struct node*)malloc(sizeof(struct node));
            q->data = word;
            q->next = NULL;

            p->next = q;
            p = p->next;
        }
    }

   for(struct node *p = head; p != NULL; p = p->next)
   {
       printf("%d\n", &p->data);
   }
}

