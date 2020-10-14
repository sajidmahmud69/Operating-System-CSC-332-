#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>


// Utility function to check a given file's existence and read/write permission
int file_access (char* file[]){
	// Check file's existence
	int fd;
	int returnval = access (file[0],F_OK);
	if (returnval != 0){
		perror ("Error");
		return 1;
	}
	// Check file's read or write permission
	returnval = access (file[0], W_OK);
	if (returnval != 0){
		perror ("Error");
		return 1;
	}else{
		if (file [0] == "source.txt")
			fd = open (file[0], O_RDONLY);
		else if (file[0] == "destination1.txt" || "destination2.txt")
			fd = open (file[0], O_WRONLY);
	}
	return fd;
}

int main(){
	char* dest1_file = "destination1.txt";
	int dest1_fd = file_access(&dest1_file);
	char* dest2_file = "destination2.txt";
	int dest2_fd = file_access (&dest2_file);
	char* src_file = "source.txt";
	int src_fd = file_access (&src_file);
	char c;
	int charCount = 0;
	while (read (src_fd, &c, 1) == 1){
		if (isdigit (c)){
			charCount++;
		}	
		// read 50 characters and put them into destination1.txt	  		
		if (charCount <= 50){
			if (c == '5' || c == '8'){
				write (dest1_fd, &c, 1);				}
		// read the next 100 characters and put them into destination2.txt
		}else if (charCount > 50 && charCount <= 150){
			write (dest2_fd, &c, 1);
			if (charCount == 150) charCount = 0;			}
		
	}
	close (src_fd);
	close (dest1_fd);
	close (dest2_fd); 		
	return 0;

}
