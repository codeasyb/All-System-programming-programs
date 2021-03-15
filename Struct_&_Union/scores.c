#include <stdio.h>

const int COUNT = 3;

void chart(int score);

int main(void)
{
	int scores[COUNT];
	for(int i =0; i < COUNT; i++)
	{
		scores[i] = scanf("%d");
	}
	printf("\n");
	for(int i =0; i < COUNT; i++)
	{
		printf("Score: %i", 1 + 1);
		chart(scores[i]);
	}
}

void chart(int score)
{
	for(int i =0; i < score; i++)
	{
		printf("#");
	}
	printf("\n");
}
