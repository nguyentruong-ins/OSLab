#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

void *simple_malloc (size_t size){
	void *p;
	printf("%p\n",p);
	p = sbrk(size);
	if (sbrk(size) == (void*)-1)
		return NULL;
	return p;
}

int main (int argc, char* argv[]){
	void* p = simple_malloc(0);
	printf("%p\n", p);
	return 0;
}
