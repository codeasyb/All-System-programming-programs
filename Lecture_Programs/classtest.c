#include <stdio.h>
#include <dirent.h>
#include <signal.h>



int myFunc(int stuff);
int conertingDouble(double d);

int main(int argc, char* argv[])
{

	// int asInteger = 0;
	// double asDouble = 0.0;
	
	// char* ptr = (char*)&asInteger; 
	// int* ptr2 = (int*)&asInteger;

	// ptr[0] = 'h';
	// ptr[1] = 'i';
	// ptr[2] = '!';
	// ptr[3] = '\0';

	// ptr2 = 2;

	// printf("%s\n", ptr);
	// printf("%d\n", ptr2);


	// printf("%s\n");
	// int n = convertDouble(2.0);

	// printf("%d\n", n);

	int (*fnptr)(int) = myFunc;

	printf("%d\n", fnptr(130948));

	return 0;
}

/**

	This function is going to point it self and
	use it like a function.




*/
int myFunc(int stuff)
{

	// int (*fnptr)(int) = myFunc;


	return stuff;
}


/**
	this function will return an integer 
	after conerting to an integer and it 
	will take a double

*/
int convertDouble(double d)
{

	int* integer = (int*)&d;
	return integer;
}