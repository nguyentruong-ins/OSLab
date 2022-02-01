#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

void *simple_malloc (size_t size){
	void *p;
	p = sprk(0);
	if (sbrk(size) = (void*) -1)
		return NULL;
	return p;
}

int main(int argc, char* argv[]){
	void * addr;
	int flag = brk(addr);
	//int n;
	//printf("Type your wanted memory space: ");
	//scanf("%d", &n);
	if (flag == 0 ) 
	{
		printf("Success in places a break\n");
		printf("This is the first address: %p\n", addr);
		addr = sbrk(4);
		printf("This is the second address: %p\n", addr);
	}
	else 
		printf("Not success in places a break\n");
	
	return 0;
}
