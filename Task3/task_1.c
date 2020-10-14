#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	int id = fork();
	if (id != 0){
		wait(&id);
	}else{
		printf("Child process successfully forked with pid %d\n", getpid());
		execl ("/bin/date", argv[0], NULL);
		printf ("EXECL FAILED\n");
	}

	return 0;
}
