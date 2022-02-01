#include "ex1.h"

int main(int argc, char** argv){
	int align;
	void* p;
	printf("Type in your size: ");
	scanf("%d", &size);
	printf("Type in your align value: ");
	scanf("%d", &align);
	p = aligned_malloc(size, align);
	printf("This is the address of the arr: %p\n", p);
	printf("Deallocate the memory ...\n");
	p = aligned_free(p);
	printf("This is the address before dealloc: %p\n", p0);
	printf("After dealloc: %p\n", p);
	return 0;
}
