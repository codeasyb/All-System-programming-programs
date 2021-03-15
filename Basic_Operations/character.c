#include<stdio.h>
#include <string.h>
int main()
{
	char a[40];

	char b[40] = "Arjunyouarefuckingannoying.";

	b[9] = 0;

	printf("%s\n", strncpy(a, b, 12));
	
	return 0;
}
