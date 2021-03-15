#include <stdio.h>
#include <stdlib.h>

struct Employee {
	int enumber;
	char *ename;
	int esalary;
};

int main(int argc, char const *argv[])
{

	struct Employee e;

	if(argc > 1)
	{
		e.enumber = atoi(argv[1]);
		e.ename = argv[2];
		e.esalary = atoi(argv[3]);
	}
	for (int i = 0; i < argc; ++i)
	{
		printf("Command line arguments: %s\n", argv[i]);
	}

	printf("%d %s %d\n", e.enumber, e.ename, e.esalary);
	return 0;
}
