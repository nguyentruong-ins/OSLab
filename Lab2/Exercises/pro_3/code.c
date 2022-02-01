#include<stdio.h>
#include<pthread.h>
void* hello(void* tid){
	printf("Hello from thread %ld\n", (long int) tid);
	pthread_exit(0);
}

int main(int argc, char** argv){
	pthread_t tid[10];
	long int i;
	for (i = 0; i < 10; i++){
		pthread_create(&tid[i], NULL, hello, (void*) i);
		pthread_join(tid[i], NULL);
	}
	return 0;
}
