#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main() {

	srand(time(NULL));
	int f;
	int status;

	printf("InitMessage: Parent PID: %d\n", getpid());

	f = fork();

	if (f){
		f = fork();
	}


	if (!f){
        	printf("I am a Child: My PID: %d\n", getpid());
		int time = rand() % 9 + 2;
		sleep(time);
		printf("Child exited: My PID: %d\n", getpid());
		return time;

	}

	else{
		int c_pid = wait(&status);
		int time = WEXITSTATUS(status);
		printf("Child Exited: My PID: %d Sleep for %d\n", c_pid, time);
		printf("Parent process complete!\n");
		return 0;
		}

    return 0;
}
