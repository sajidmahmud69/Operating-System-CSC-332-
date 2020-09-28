/* There's a init process with ID = 1
	Every process forks from it.
	After forking the parent process will have
	its own process ID along with its children's ID.
	If you are in the child process its own ID will be 0
	but it will copy its parent's ID as it is, and that applies to all children.
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int child1, child2;
	int child1_exit_ID, child2_exit_ID;
	int status;

	printf ("The parent id: %d\n", getpid());

	child1 = fork();
	if (child1 != 0){
		child2 = fork();
	}

	if (child1 != 0 && child2 != 0){     					// parent scope
		child1_exit_ID = waitpid (child1, &status, 0);
		child2_exit_ID = waitpid (child2, &status, 0);
	}

	if (child1 == 0){										// child 1 scope
		printf ("I am child one, my pid is %d\n",getpid());
	}
	if (child2 == 0){										// child 2 scope
		printf ("I am child two, my pid is %d\n",getpid());
	}
	if (child1 != 0 && child2 != 0 && child1_exit_ID != -1){
	printf ("Child one terminated: %d\n", child1_exit_ID);
}
	if (child1 != 0 && child2 != 0 && child2_exit_ID != -1){
	printf ("Child two terminated: %d\n", child2_exit_ID);
}
	return 0;
}
