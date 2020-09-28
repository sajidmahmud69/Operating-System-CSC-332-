#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[]){

    if (argc != 3){
        printf("The correct number of arguments are not specified\n");
        return 1;
    }

    char* srcFile = argv[1];                            // stores the source file location
    char* destFile = argv[2];                           // stores the destination file location
    char c;

    int returnval = access (srcFile, F_OK);
    int fd_src;
    int fd_dest;
    if (returnval != 0){
        perror("Error ");
        return 1;
    }
    else{
        fd_src = open (srcFile, O_RDONLY);
        if (fd_src < 0){
            perror ("Open ");
            close (fd_src);
            return 0;
        }
        fd_dest = open (destFile, O_CREAT | O_WRONLY, 00700);                        // if destFile exists open it in write mode otherwise create it
        returnval = access (destFile, W_OK);
        if ( returnval != 0){
            perror ("Error ");
            close (fd_dest);
            return 0;
        }
        while (read(fd_src, &c, 1) == 1){
            write (fd_dest, &c, 1);
        }
    }

    close(fd_src);
    close(fd_dest);

    return 0;
}
