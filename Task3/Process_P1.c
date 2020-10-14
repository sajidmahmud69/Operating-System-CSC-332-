#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	// create two files destination1.txt and destination2.txt
	
	int fd = creat ("destination1.txt", 00700);
	// if any problem happens the following block will execute and stop the program
	if (fd == -1){
		perror ("creat");
		close (fd);
		return 1;
	}
	fd = creat ("destination2.txt", 00700);
	// if any problem happens the following block will execute and stop the program
	if (fd == -1){
		perror ("creat");
		close (fd);
		return 1;
	}
	close (fd);
	return 0;
}
