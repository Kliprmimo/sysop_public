#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main(){
		
	printf("Hello, im another program! my pid : %d\n", getpid());
	getchar();
	
	return 0;
}
