#include <stdio.h>

/*

In C programming, an enumeration type (also called enum) is a data type that consists of integral constants. 
To define enums, the enum keyword is used.

*/
enum boolean {false, true};

enum week {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

enum suit {club = 0, diamonds = 10, hearts = 20, spades = 3} card;

enum designFlag {BOLD = 1, ITALICS = 2, UNDERLINE = 4};

int main(int argc, char const *argv[])
{
	
	enum boolean check;
	check = false;

	int i;
	double d;
	if(check){
		printf("%d\n", sizeof(i));
	}else
	{
		printf("%d\n", sizeof(d));
	}

	enum week today;
	today = Wednesday;
	printf("Day %d\n", today);

	card = diamonds;
	printf("Size of enum variable: %d\n", sizeof(card));


	int myDesign = BOLD | UNDERLINE;

	//		00000001
	//	|	00000100
	//  ____________
	//		00000101
	printf("%d\n", myDesign); 

	myDesign = 2;

	if (myDesign & ITALICS)
	{
		printf("%d\n", myDesign);
	}

	return 0;
}
