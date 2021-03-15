//#include "stdafx.h"
//#include <iostream.h>
//#include <fstream.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define STRINGSIZE 128
int main(int argc, char *argv[])
{
	char ch;
	char *str;
	int c = 1;
	while (c < argc) {
		printf("arg %i - |%s|\n",c,argv[c]);
		if (argv[c][0] == '-') {
			printf("|%c|\n", argv[c][0]); // then show what it is 
	        if (strcmp( &argv[c][1], "Hello"))
	        {
	        	printf("%s\n", &argv[c][1]);
	        }
		}
		c++;
	}
	system("PAUSE");
	return 0;
}

