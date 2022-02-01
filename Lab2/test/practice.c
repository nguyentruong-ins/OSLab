#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define NUM_THREADS 5

void printHello (void *threadid){
	long tid;
	tid = (long) threadid;
	printf("Hello World! It's me, thread #%ld!\n", tid);
	pthread_exit(NULL);
}

void* printTest(void){
	printf("Hello for print test routine\n");
}

int main(int argc, char* argv[]){
	pthread_t threads [NUM_THREADS];
	int rc;
	long t;
	void *p=&printHello;
	for (t = 0; t<NUM_THREADS; t++){
		printf("In main: creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, p, (void*) t);
		if (rc){
			printf("ERROR; return from pthread create() is %d\n", rc);
			exit(-1);
		}
		pthread_exit(NULL);
	}
}
