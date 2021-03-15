#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{

	// Add numbers using the arguments passed at compile time 
	if(argc > 1)
	{
		int sum =0;
		for (int i = 1; i < argc; ++i)
		{
			sum += atoi(argv[i]);
		}
		printf("Sum of all elements:%d\n", sum);
	}
	return 0;
}