#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc , char *argv[]){
	char *argument[] = {"ls","-al",NULL};
	int id = fork();
	if (id != 0){
		wait(&id);
	}else{
		printf ("Child process forked successfully with id: %d\n", getpid());
		execvp ("ls",argument); // ls looks for the binary file in bin folder in the system
		printf ("EXECVP FAILED\n");
	}

	return 0;
}
