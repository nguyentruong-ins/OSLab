#include"ex1.h"
void* aligned_malloc(unsigned int size, unsigned int align){
	if (size == 0) return NULL;
	void* p = sbrk(0);
	if ((long int) p % align != 0){
		int temp = align;
		while (temp > 0 && (long int) p % 2 == 0){
			p = (void*)((long int) p/2);
			temp /= 2;
		}
		p = (void*)((long int) p * align);
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
