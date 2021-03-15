#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("You passed no arguments after output file\n");
		exit(1);
	}

	char *endptr = NULL;
	errno = 0;
	long x = strtol(argv[1], &endptr, 10);

	if(*endptr != 0 || errno)
	{
		if(errno == EINVAL)
		{
			printf("NO conversion could be performed\n");
		} else if(errno == ERANGE)
		{
			printf("Conversion out of range\n");
			exit(1);
		}
		printf("Error occured at: %s\n", endptr);
		exit(1);
	}

	if(x > INT_MAX)
	{
		printf("passed values is too big for an int\n");
		exit(1);
	}
	printf("Successful, x is: %d\n", (int)x);
	return 0;
}
