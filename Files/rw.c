#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

//const char *path = "out.txt";

int main(int argc, char *argv[])
{

	int fd_in, fd_out, flag;
	char buffer[1000];  //read in 1000 characters from the file

	// open the file and get the [ fd ]
	// S_IRUSR for file permission
	fd_in = open(argv[1], O_CREAT | O_RDONLY);
	printf("File name: %s\n", argv[1]);
	if(fd_in == -1)
	{
		return -1;
	}

	// open the file for write permission and return the [ fd ]
	fd_out = open("output.txt", O_WRONLY | O_CREAT);
	printf("File written to: %s\n", "output.txt");
	if (fd_out == -1)
	{
		return -1;
	}

	while((flag = read(fd_in, buffer, 1000)) > 0)
	{
		write(fd_out, buffer, flag);
	}

	close(fd_in);
	close(fd_out);

	return 0;
}