#include <stdio.h>

enum boolean {
	true = 1,
	false = 0,
};

int 
main(int argc, char const *argv[])
{
    enum boolean true;
    true = 0;
    enum boolean false;
    false = 1;

    char *arr[] = {"F", "U", "C", "K", "Y", "O", "U", "\0"};

    size_t n = sizeof(arr)/sizeof(arr[0]);

    printf("%f\n", (float)n);

    printf("----------\n");

    int a = sizeof(arr)/sizeof(arr[0]);

    printf("%d\n", (int)a);    

    if (true)
    {

	printf("I am hungry.\n");	
    }

    while(false){
	printf("FUCKYOU\n");
	if(false){
		break;
	}
    }
    return 0;
}
