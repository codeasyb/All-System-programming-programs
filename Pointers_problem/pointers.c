#include <stdio.h>

int main(int argc, char const *argv[])
{

	int var = 28;
	printf("%d\n", var);    //this will print the value

	printf("%p\n", &var);   //this will print the address in memory

	//creating a pointer to point to var address and print out the value
	int *ptr;
	ptr = &var;
	printf("%d\n", *ptr);
	printf("%p\n", &ptr);


	printf("-------\n");
	int* c, s;
	s = 28;
	c = &s;
	printf("%d\n", *c);
	printf("%p\n", &c);


	printf("-------\n");
	int* a, b;
	b = 21;
	a = &b;
	//b = 22;
	printf("%d\n", *a);
	printf("%p\n", &a);
	b = 22;
	printf("%d\n", b);


	return 0;
}