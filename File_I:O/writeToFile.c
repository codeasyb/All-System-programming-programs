#include <stdio.h>

int main()
{
	FILE * fPointer = fopen("../Files/quotes.txt", "w");	

	//fPointer = fopen("quotes.txt", "a");
	fprintf(fPointer, "Life is not a game to play with.\n");
	fprintf(fPointer, "Life is short but leaving a legacy,\n");
	fprintf(fPointer, "what humans should look forward too.\n");

	fclose(fPointer);
	return 0;
}
