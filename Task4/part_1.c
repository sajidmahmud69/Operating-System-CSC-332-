#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){

    while (1){
        char quit [] = "quit";
        char commands[200];  // passed in by user from stdin
        char* token = NULL;
        char delimiter [] = " ";
        char* arguments[200];       // will be used by the exec function
        int index = 0;              // to keep track of position to put elements (token) into arguments
        int len = 0;                // length of arguments

        printf("Write the commands: \n");
        fgets (commands, 200, stdin);               // read in from the standard input
        commands [strlen(commands) - 1] = '\0';     // fgets puts a '\n' before '\0' this is to avoid that extra character

        token = strtok(commands, delimiter);

        if (strncmp(token, quit, 4) == 0) break;


        // string tokenization to separacte each string by a space
        // and put them into arguments character array
        while (token != NULL){

            *(arguments + index) = token;           // same as arguments[index] = token
            index++;
            len++;
            token = strtok(NULL, delimiter);
        }
        *(arguments + index) = token;

        int pid = fork();
        int status;
        if (pid != 0){
            waitpid (pid, &status, 0);
        }else{
            execvp (arguments[0], arguments);
        }
    }

    return 0;
}
