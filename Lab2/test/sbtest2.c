#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

void *my_malloc(size_t size){
	 void *p;
	  void *q;
	   p = sbrk(0);
	    /* If sbrk fails, we return NULL */
	    q = sbrk(0);
	     if(q == (void *)-1){
		       return NULL;
		        }
	      printf("\n size : %d  p : 0x%p q : 0x%p \n",(int)size,p,q);
	       return p;
}
int main(){
	 int *p;
	  p = my_malloc(5);
	   printf("\n p : 0x%p \n",p);
}
