#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char **argv[]){
	if (argc != 3){
		printf("incorrect number of args, formula is: ./sendsignal <PID> <signal>");
		return 1;
	}
	
	printf("%s %s",argv[1], argv[2]);
	kill((int)*argv[1], *argv[2]);
	return 0;
}
