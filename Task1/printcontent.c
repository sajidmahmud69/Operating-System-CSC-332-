#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char* argv[]){

    char* filepath = argv[1];
    char c;
    int returnval;
    int fd;

    if (argc != 2){
        printf("Invalid number of arguments provided\n" );
        return 1;
    }

    // check for file existence

    fd = open (filepath, O_RDONLY);                     // opens the file in read only mode
    if ( fd < 0){
        perror ("open");
        close (fd);
        return 0;
    }

    // check for read permission

    returnval = access (filepath, R_OK);

    if ( returnval != 0){
        printf("The file does not have read permission\n" );
    }
    else{
        while (read (fd, &c, 1) == 1){                      // the loop continues as long as read returns a 1 means that a new character has been found
            write (2, &c, 1);                               // 2 is for stdin
        }
        close (fd);
    }
    return 0;
}
