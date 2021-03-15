//Singly linked list
// corrected and simplified by H. Watson
//http://www.cprogramming.com/snippets/source-code/singly-linked-list-insert-remove-add-count
// in C:\Users\watsonh\Documents\Incoming\fiu\eel2880\ClassPrograms

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
};

struct node* head=NULL; // starting node of list

FILE* fp;
void OpenFileRead();
void AppendListFromFile();
void OpenFileWrite();
void CloseFile();
void WriteListToFile();
void RewindFile();
void CloseFile();




void append(int num)  //add to end of list
{
    struct node *temp,*right;
    // create a new temp node
    temp= (struct node *)malloc(sizeof(struct node)); //create temp node
    temp->data=num;  //set temp value
    temp->next=NULL; // set as end of list

    right= head;
    if (right==NULL)
    {
        // then no head node exists yet, so set temp as head
        head=temp;

    }
    else
    {
        // find end of current list
        while(right->next != NULL)
            right=right->next;
        // right is now the last node in list (next==NULL)
        // set temp as new next node
        right->next =temp;
    }

}

void add( int num )  // add to beginning of list
{
    struct node *temp;
    // create a new temp node
    temp=(struct node *)malloc(sizeof(struct node)); //create unnamed node and pointer
    temp->data=num;  //set temp data value
    temp->next=NULL;  // set as end of list

    if (head== NULL)
    {
        // then list empty, so set as head node
        head=temp;
        head->next=NULL;
    }
    else
    {
        // else add to left of list
        temp->next=head;
        head=temp;
    }
}


int delete(int num)
{
    struct node *temp, *prev;
    // start at first node
    temp=head;
    // loop until end of list
    while(temp!=NULL)
    {
        // does the data match?
        if(temp->data==num)
        {
            // yes, then is start or other node?
            if(temp==head)
            {
                // start node, so delete it
                head=temp->next;
                free(temp);
                return 1;
            }
            else
            {
                // node in list, so delete it
                prev->next=temp->next;
                free(temp);
                return 1;
            }
        }
        else
        {
            //continue search on down list
            prev=temp;
            temp= temp->next;
        }
    }
    return 0;
}


void  display(struct node *r)
{
    // list node contents from first to last
    r=head;
    int cnt = 0;

    if(r==NULL)
    {
        return;
    }
    while(r!=NULL)
    {
        if(cnt++!=10)
            printf("%d, ",r->data);
        else
        {
            printf("%d\n",r->data);
            cnt=0;
        }

        r=r->next;
    }
    printf("\n");
}


int count()
{
    // scan list and count how many nodes
    struct node *n;
    int c=0;
    n=head;
    while(n!=NULL)
    {
        n=n->next;
        c++;
    }
    return c;
}


int  main()
{
    int i,num;
    char ch;

    head=NULL;
    while(1)
    {

        puts("\nEnter your choice : (0: menu)");
        if(scanf("%d",&i)<=0)
        {
            printf("Enter only an Integer\n");
            exit(0);
        }
        else
        {
            switch(i)
            {
            case 1:
                printf("Enter the number to append to end : ");
                scanf("%d",&num);
                append(num);
                break;

            case 2:
                printf("Enter the number to add to beginning : ");
                scanf("%d",&num);
                add(num);
                break;
            case 3:
                if(head==NULL)
                {
                    printf("List is Empty\n");
                }
                else
                {
                    printf("Element(s) in the list are : \n");
                }
                display(head);
                break;
            case 4:
                printf("Size of the list is %d\n",count());
                break;
            case 5:
                if(head==NULL)
                    printf("List is Empty\n");
                else
                {
                    printf("Enter the number to delete : ");
                    scanf("%d",&num);
                    if(delete(num))
                        printf("%d deleted successfully\n",num);
                    else
                        printf("%d not found in the list\n",num);
                }
                break;
            case 6:
                return 0;
                break;

            case 7:
                OpenFileRead();
                break;

            case 8:
                AppendListFromFile();
                break;

            case 9:
                RewindFile();
                break;

            case 10:
                OpenFileWrite();
                break;

            case 11:
                WriteListToFile();
                break;

            case 12:
                CloseFile();
                break;


            default:
                puts("\nList Operations  ===============");
                puts("1.Append to end           2.Add at beginning      3.Display List");
                puts("4.List Size               5.Delete                6.Exit");
                puts("7.Open File Read          8.Append Open to List   9.Rewind File");
                puts("10.Open File Write        11.Write List to File   12.Close File");

            }
        }
    }
    return 0;
}


void OpenFileRead()
{
    char filename[20];
    //fflush(stdin);    /* flush keyboard buffer */
    puts("Enter name of text file to read: \n");
    scanf("%s",filename);

    /* Open the file for reading. - fp is global */
    if ( (fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
    }
    else
    {
        printf("%s Read file opened\n",filename);
    }

}


void OpenFileWrite()
{
    char filename[20];
    //fflush(stdin);    /* flush keyboard buffer */
    puts("Enter name of text file to write: \n");
    scanf("%s",filename);

    /* Open the file for reading. - fp is global */
    if ( (fp = fopen(filename, "w")) == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
    }
    else
    {
        printf("%s Write file opened\n",filename);
    }

}

void CloseFile()
{
    int result;
    result = fclose(fp);
    if(result != 0)
        printf ("File close failed\n");
    else
        printf("File closed successfully\n");
    return;
}

void RewindFile()
{
    rewind(fp);
    printf("File rewound to beginning\n");
}

void AppendListFromFile()
{
    char line[20];
    char* token;
    char s[]=",";
    int num;

    while(fgets(line, sizeof line, fp) != NULL)
    {
        /* get the first token */
        token = strtok(line, s);

        /* walk through other tokens */
        while( token != NULL )
        {
            //printf( " %s\n", token );
            sscanf(token, "%d", &num);  // scan scring for integer
            append(num); // add to end of list

            token = strtok(NULL, s);
            //printf(" Token =%p \n", token);
        }
    }

    printf("All element in the list are : \n");
    display(head);

    return;
}

void  WriteListToFile()
{
    // list node contents from first to last
    struct node *r=head;
    //r=head;
    int cnt = 0;

    if(r==NULL)
    {
        return;
    }
    while(r!=NULL)
    {
        if(cnt++!=10)
            fprintf(fp, "%d, ",r->data);
        else
        {
            fprintf(fp, "%d\n",r->data);
            cnt=0;
        }

        r=r->next;
    }
    fprintf(fp, "\n");
}