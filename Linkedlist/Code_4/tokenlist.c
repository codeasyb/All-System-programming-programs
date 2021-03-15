#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXC 1024u  /* if you need a constant, define one (or more) */

int isDelimiter(char c);

typedef struct Node {
    char *data;
    struct Node *next;
} node_t;

node_t *addnode (node_t **head, char *word)
{
    size_t len = strlen (word);             /* length of word */
    node_t  *node = malloc (sizeof *node),  /* allocate new node */
            *iter = *head;      /* temp iterator for in-order insert */

    if (!node) {                    /* validate EVERY allocation */
        perror ("malloc-node");     /* handle error */
        return NULL;
    }

    node->next = NULL;
    node->data = malloc (len + 1);  /* allocate storage for word */

    if (!node->data) {              /* ditto! */
        free (node);                /* free node - word allocation failed */
        perror ("malloc-node->data");
        return NULL;
    }

    memcpy (node->data, word, len + 1); /* copy with nul-character */

    if (!*head)                     /* are we the first node? */
        return (*head = node);      /* just set *head = node */

    while (iter->next)              /* while next is not NULL */
        iter = iter->next;          /* advance iter to next node */

    return (iter->next = node);     /* new node at end */
}

void prn_list (node_t *node)
{
    puts ("\nlinked list:\n");

    while (node) {              /* iterate over each node */
        puts (node->data);      /* outputting node->data */
        node = node->next;      /* advance to next node */
    }
}

void free_list (node_t *node)
{
    while (node) {              /* iterate over each node */
        node_t *victim = node;  /* save node to free as victim */
        node = node->next;      /* advance to next before freeing current */
        free (victim->data);    /* free node word */
        free (victim);          /* free node */
    }
}

int 
main (int argc, char **argv) {

    char buffer[MAXC] = { };        /* buffer to hold each word */
    // FILE *filep;            /* FILE not File */
    int *fd, flag;
    node_t *head = NULL;    /* node to beginning of list */

    if (argc < 2) { /* check that at least 2 arguments available */
        printf (stderr, "error: insufficient arguments.\n"
                "usage: %s filename\n", argv[0]);
        return 1;
    }

    int buff_idx = 0;
    char *arr_tokens[100];
    int token_idx = 0;

    char read_char;
    int num_bytes; 

    // filep = fopen (argv[1], "r");   /* open file given as 1st argument */
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {                   /* validate file is open for reading */
        perror ("file does not exists.");
        return 1;
    }

    printf("File read: %s\n", argv[1]);

    while(flag)
    {
        num_bytes = read(fd, &read_char, flag);
        printf("Number of bytes read: %d\n", num_bytes);

        if(isDelimiter(read_char) || num_bytes == 0)
        {
            arr_tokens[token_idx] = malloc((sizeof(char)*(buff_idx+1)));    

            for (int i = 0; i < buff_idx; ++i)
            {
                arr_tokens[token_idx][i] = buffer[i];
                printf("%s\n", arr_tokens[i]);
            }

            //here the tokens are strings
            arr_tokens[token_idx][buff_idx] = '\0';
            token_idx++;

            //means the buffer is empty
            buff_idx = 0;

            //exit if there are no bytes left to read
            if (num_bytes == 0)
            {
                break;
            }
        } else 
        {
            //if it is not a comma
            buffer[buff_idx] = read_char;
            buff_idx++;   
        }
    }

    printf("Printing ...\n");
    printf("BUffer_Index: %d\n", buff_idx);

    for (int i = 0; i < buff_idx; ++i)
    {
        printf("%s\n", buffer[i]);
    }

    // while((flag = read(fd, buffer, 1000) ) > 0)
    // {

    // }

    // while (fscanf (filep, "%s", word) != EOF)   /* read each word */
    //     addnode (&head, word);                  /* add to list */
    // fclose (filep);                 /* close file, done reading */

    // prn_list (head);    /* print list */
    // free_list (head);   /* free all allocated memory */
}

int isDelimiter(char c)
{
    if (c == ','){
        return 1;
    } else {
        return 0;
    }
}











