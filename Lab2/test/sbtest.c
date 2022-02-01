#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int size;
void* p0;
void dosth(){
	void* p2, *p1 = sbrk(16);
	p2 = sbrk(0);
	printf("This is the first pointer's address: %ld\n",(long int) p1);
	printf("This is the second pointer's address: %ld\n",(long int) p2);
	printf("This is the gap between 2 address: %ld\n", p2 - p1);
	return;

}

void* aligned_malloc(unsigned int size, unsigned int align){
	if (size == 0) return NULL;
	// Address p hold is the recent break poin)t
	void* p = sbrk(0);
	if ((long int) p % align != 0){
		int temp = align;
		while (temp > 0 && (long int) p % 2 == 0){
			p = (void*) ((long int)p/2);
			temp = temp/2;
		}
		p = (void*)((long int)p * align);
	}	
	int flag = brk(p);
	if (flag == -1){
		printf("Can't allocate memory\n");
		return NULL;
	}
	p = sbrk(size);
	return p;
}

void* aligned_free(void* ptr){
	p0 = sbrk(-size);
       	ptr = sbrk(0);	
	return ptr;
}

int main(int argc, char ** argv){
	int align;
	void* p;
	printf("Type in your size: ");
	scanf("%d", &size);
	printf("Type in your align: ");
	scanf("%d", &align);
	p = aligned_malloc(size, align);
	printf("This is the address of the arr: %p\n", p);
	printf("Dealocate the memory ...\n");
	p = aligned_free(p);
	printf("This is the address before dealloc: %p\n", p0);
	printf("After dealloc: %p\n", p);
	return 0;

}
