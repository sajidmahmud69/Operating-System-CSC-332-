#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	int child1;
	int child2;
	int status;
	char* args [] = {NULL};
	child1 = fork();
	if (child1 == 0){ // child 1 scope execute Process 1
		execv ("./Process_P1", args);
	}else{ // parent process wait for child 1 to finish and then wait for 5 seconds
		// then create child 2 process
		waitpid(child1, &status, 0);
		sleep(5);
		child2 = fork();
		
		if (child2 == 0){ // child 2 scope execute Process 2
			execv ("./Process_P2", args);
		}else{  // parent scope wait for child 2 to finish
			waitpid (child2, &status, 0);
		}
	}
	return 0;
}
