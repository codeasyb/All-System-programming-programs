#include <stdio.h>

int main()
{
	int guess = 5;
	int guessCount = 0;
	
	printf("Welcome to guess game, You have three guesses.\n");
	while(1)
	{
		printf("Enter number: ");
		scanf("%d", &guess);
		if(guess == 5)
		{
			printf("You got it right.");
			break;
		}
		guessCount++;
		if(guessCount == 3)
		{
			printf("\nYou lost.");
			break;
		}
	}
	return 0;
}
