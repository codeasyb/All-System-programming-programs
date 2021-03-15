# include <stdio.h>

int main(int argc, char **argv){
	
	char name[256];

	printf("What is your name: ");
	//fflush(stdout);

	if(fgets(name, sizeof(name), stdin) != NULL){
		printf("Hello %s\n", name);
	}

	return 0;
}