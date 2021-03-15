#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

typedef struct word{ 
    int length; 
    char *str; 
    struct word *left;
    struct word *right; 
    struct word *down;
}word;


void print_list(word **head){ 

    word *temp_traverse = *head;
    word *temp_down;

    for( ; temp_traverse!=NULL; temp_traverse = temp_traverse->right){ 
        temp_down = temp_traverse;
        for( ; temp_down!=NULL; temp_down = temp_down->down){ 
            printf("Count: %d, String: %s\n", temp_down->length, temp_down->str);
        }
    }

}


int is_empty(word **head, word **tail){ 

    if((*head == NULL)||(*tail == NULL))
        return 1;

    return 0;
}

void insert(word **head, word **tail, word *new_word){ 

    if(is_empty(head, tail)){
        (*head) = new_word; 
        (*tail) = new_word;
        return;
    }

    if((new_word->length)<((*head)->length)){ 
        new_word->right = (*head);
        (*head)->left = new_word;
        (*head) = new_word;
        return;
    }

    word *temp = *head;

    while(((temp->right)!=NULL) && ((temp->length)<(new_word->length))) 
        temp = temp->right;

    if((temp->length) == (new_word->length)){
        while(temp->down != NULL)
            temp = temp->down;
        temp->down = new_word;
        return;
    }

    if(temp->right == NULL){
        word* last = (*tail);
        last->right = new_word;
        new_word->left = last; 
        (*tail) = new_word;
        return;
    }

    word* next = temp->right;
    temp->right = new_word;
    next->left = new_word; 
    new_word->left = temp; 
    new_word->right = next;

    return;
}

void create(word **head, word **tail, char **str){ 

    word *new_word = (word*)malloc(sizeof(word));
    int length = strlen(*str);

    if(new_word == NULL){
            fprintf(stderr, "Error creating a new word node.\n");
            exit(0);
        }

    new_word->str = (char*)malloc(sizeof(*str));
    strncpy(new_word->str, *str, length);
    //new_word->str = *str;
    new_word->length = length;
    printf("%s ", new_word->str); //test print

    new_word->left = NULL;
    new_word->right = NULL;
    new_word->down = NULL;

    insert(head, tail, new_word);

    return;
}


void tokenize(word **head, word **tail, char words_buffer[]){ 

    char *cur; 

    cur = strtok(words_buffer, " .,;()\t\r\v\f\n");

    *cur++ = '\0';
    create(head, tail, &cur);

    /* tokenize the next string and reset the "duplicate" variable */
    while((cur = strtok(NULL, " .,;()\t\r\v\f\n")) != NULL){
        //cur = strtok(NULL, " .,;()\t\r\v\f\n"); 
        *cur++ = '\0';      
        if(cur){
            create(head, tail, &cur);
        }
    }

}

int main(int argc, char *argv[]){ 

    FILE *fp;
    word *head = NULL; 
    word *tail = NULL;

    /*if(argc<3){
        printf("Failure: not enough arguments");
        return -1; 
    }*/

    fp = fopen(argv[1], "r");
    fseek(fp, 0, SEEK_END);
    char words_buffer[ftell(fp)+1];
    fseek(fp, 0, SEEK_SET);

    if(fp==NULL){
        printf("Failure: unreadable file");
        return -1;
    }

    while(fgets(words_buffer, sizeof(words_buffer), fp)){
            if(strlen(words_buffer)>1)
                tokenize(&head, &tail, words_buffer);
    }

    //print_list(&head);

    fclose(fp);
    return 0;
} 
