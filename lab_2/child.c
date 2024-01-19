#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main(){
		
	printf("Parent pid : %d\n", getpid());
	char a;
	getchar();
	
	int fork_pid = fork();
	if (fork_pid != 0){
		wait(NULL);
	}
	if (fork_pid == 0){
		printf("Child pid : %d\n", getpid());
		printf("Parent pid : %d\n", getppid());
		char ch = getchar();
		while(ch == '\n')
		ch = getchar();
	}
	return 0;
}
