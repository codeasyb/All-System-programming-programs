#include <stdio.h>
#include "academy.h"

int main(int argc, char const *argv[])
{
	int a = 10, b = 20;
	printf("Add: %d\n", add(a, b));
	printf("Minus: %d\n", minus(b, a));
	printf("Multiply: %d\n", multiply(a, b));
	printf("Divide: %d\n", divide(b, a));
	printf("Mod: %d\n", mod(b, a));

	return 0;
}

