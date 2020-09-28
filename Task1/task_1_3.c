#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int main(){

    int src_fd, dest_fd;
    int returnval;
    int charCount = 0;
    char* src_file = "source.txt";
    char* dest_file = "destination.txt";
    char c;

    // Check source file's existence

    returnval = access (src_file, F_OK);
    if (returnval != 0){
        if (errno == ENOENT){
            perror("Error ");
            return 1;
        }
        else if (errno == EACCES){
            perror("Error ");
            return 1;
        }
    }

    // Check dest file's existence

    returnval = access(dest_file, F_OK);
    if (returnval != 0){
        dest_fd = open (dest_file, O_CREAT | O_RDWR, 00700);
        printf("Destination file was created\n" );
    }

    // Check read permission of the source file

    returnval = access (src_file, R_OK);
    if (returnval == 0){
        src_fd = open (src_file, O_RDONLY);
    }
    else {
        perror ("Error ");
    }


    // Check write permission for destination file

    returnval = access (dest_file, W_OK);
    if (returnval == 0){
        dest_fd = open (dest_file, O_WRONLY);
        while (read (src_fd, &c, 1) == 1){

            if (isdigit(c)){
                charCount++;
            }
            if (c == '5'){
                c = 'O';
            }
            write (dest_fd, &c, 1);
            if (charCount == 75){
                write (dest_fd, "ABC", 3);
                charCount = 0;
            }
        }
        close (src_fd);
        close (dest_fd);
    }

    else {
        perror("Error ");
    }

    return 0;
}
