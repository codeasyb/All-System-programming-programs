# include <stdio.h>
#include <fcntl.h>  
#include <sys/types.h>                                                  
#include <sys/uio.h>                                                    
#include <unistd.h> 
#include <string.h>   

int main(int argc, char const *argv[])
{

	int fd = open("./test.c", O_RDONLY); // open and read the file
	char buffer[101];  //assigning the memory
	memset(buffer, '\0', 101);

	// read file if greater then 0, less than 0 then pop out
	int value = 1;
	int read = 0;
	do {
		value = read(fd, buffer, 100-read);
	}while(value > 0 && read < 100);



	return 0;
}