#include <stdio.h>
#include <signal.h>

void aSignalHandleFuntion(int signum);

int 
main(int argc, char **argv)
{	
	//lets make a sig handler 
	//this is invoked as the operating system calling it 
	signal(SIGSEGV, aSignalHandleFuntion);
	printf("%d\n", *((int*)0) );

	return 0;
}


void aSignalHandleFuntion(int signum)
{
	printf("Segfaulst are techy.\n");
	return;
}