#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void static_allocate(){
	double static_mem[(int)pow(10, 6)];
	scanf(" %*c");
}

void dynamic_allocate(){
	double* dynamic_mem = (double*)malloc(pow(10,6)*sizeof(double));
	scanf(" %*c");
	free(dynamic_mem);
}

int main(){
	static_allocate();
	scanf(" %*c");
	dynamic_allocate();
	return 0;
}
