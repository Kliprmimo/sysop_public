#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigintHandler(int sig_num) {
    signal(SIGINT, sigintHandler);
    printf("Caught signal SIGINT %d\n", sig_num);
}

int main() {
    signal(SIGINT, sigintHandler);
    
    while (1) {
	sleep(1);
    }

    return 0;
}
