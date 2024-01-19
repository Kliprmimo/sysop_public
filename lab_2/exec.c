#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main(){
		
	printf("Hello, im exec program! my pid : %d\n", getpid());
	getchar();
	execlp("./another", "another", NULL);
	return 0;
}
