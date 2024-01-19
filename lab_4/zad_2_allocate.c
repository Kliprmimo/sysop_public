#include <stdio.h>
#include <stdlib.h>

struct list_2d{
	double list2d[1000][1000] ;
} struct_2dlist;


int main(int argc, char* argv[]){
	if(argc != 2){
	printf("usage: <./alocate> <number of 1kx1k arrays allocated>");
	return -1;
	}	
	
	int size = atoi(argv[1]);
	void* lists[size];
	for(int i =0; i<size;i++){
		lists[i] = (struct list_2d *)malloc(sizeof(struct list_2d));
	}
	scanf(" %*c");
}
