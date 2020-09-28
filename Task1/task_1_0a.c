#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){

    char* filepath = argv[1];
    int returnval;


    // Check file existence

    returnval = access (filepath, F_OK);
    if (returnval == 0){
        printf("\n %s exists\n", filepath);
    }
    else{
        if (errno == ENOENT){
            printf("\n %s does not exist\n",filepath);
            return 1;
        }
        else if(errno == EACCES){
            printf("%s is not accessible\n", filepath);
            return 0;
        }
    }

    // check read access of the file

    returnval = access (filepath, R_OK);
    if (returnval == 0){
        printf("The file has read access\n");
    }
    else{
        printf("The file does not have read access\n");
    }


    // check write access

    returnval = access (filepath, W_OK);

    if (returnval == 0){
        printf("The file has write access\n");
    }
    else{
        printf("The file does not have write access\n");
    }

    return 0;
}
