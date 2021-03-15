#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct node{
    int value;
    struct node *next_ptr;
};

struct node *head;

void add_node(int data);
void print_nodes(void);

int main(int argc, char *argv[]){
    int c;
    long node_value;
    char *ptr;
    char *token;
    const char s[2] = " "; /*Split optarg based on this string*/

    while((c = getopt(argc, argv, "iq:")) != EOF){
        switch(c){
        case 'i':
            print_nodes();
            break;
        case 'q':
            token = strtok(optarg, s); /*Split the string*/
            while(token != NULL){
                node_value = strtol(token, &ptr, 10); /*Convert each string to integer*/
                if((*ptr) != 10 && (*ptr) != 0){ /*If it's not a newline or a null then invalid input*/
                    fprintf(stderr, "Invalid number: %c", *ptr);
                    exit(EXIT_FAILURE);
                }
                add_node(node_value);
                token = strtok(NULL, s);
            }
            break;
        default:
            fprintf(stderr, "Unknown option %c, available options are '-p' and 'a'", c);
            break;
        }
    }
    argc -= optind;
    argv += optind;

    return 0;
}

void add_node(int data){
    struct node *temp = head;

    if(temp == NULL){
        head = malloc(sizeof(struct node));
        head->value = data;
        head->next_ptr = NULL;
        return;
    }

    while(temp->next_ptr != NULL){
        temp = temp->next_ptr;
    }

    if((temp->next_ptr = malloc(sizeof(struct node))) == NULL){
        fprintf(stderr, "Out of memory");
        exit(EXIT_FAILURE);
    }


    temp = temp->next_ptr;
    temp->value = data;
    temp->next_ptr = NULL;
}

void print_nodes(void){
    struct node *temp = head;
    if(temp == NULL){
            printf("Linked list is empty\n");
    }
    for(temp = head; temp != NULL; temp = temp->next_ptr){
        printf("%i\n", temp->value);
    }
}