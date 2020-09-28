#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

    int fd = open ("destination.txt", O_CREAT | O_RDONLY, 00400);

    if (fd == -1){
        perror ("open");
        close (fd);
        return 1;
    }
    else{
        printf("The file was opened\n");
    }
    close (fd);
    return 0;
}
