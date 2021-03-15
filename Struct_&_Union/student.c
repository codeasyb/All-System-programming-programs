#include <stdio.h>
#define SIZE 3

typedef struct _student{
	char name[50];
	unsigned int mark;
} student;

void read_list(student list[], int size);
void print_list(student list[], int size);

int
main(int argc, char const *argv[])
{
	student list[SIZE];



	char chr;
    printf("Enter a character: ");
    scanf("%c",&chr);     
    printf("You entered %c.", chr);

	read_list(list, SIZE);
	print_list(list, SIZE);
	return 0;
}

void read_list(student list[], int size){

	printf("Please enter student information.\n");

	for (int i = 0; i < size; i++)
	{
		printf("\nStudent Name: ");
		scanf("%s\n", &list[i].name);

		printf("\nStudent mark: ");
		scanf("%d\n", &list[i].mark);
	}
}

void print_list(student list[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("Student Name: %s\nStudent Mark: %d\n", list[i].name, list[i].mark );
	}
}