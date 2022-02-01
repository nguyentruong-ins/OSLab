#include<pthread.h>
#include<stdio.h>

int sum=0;
void *runner(void* t){
	printf("create thread\n");
	int i,upper=(long)t;
	for (i=1;i<=upper;i++)
		sum+=1;
	pthread_exit(0);
}

int main(){
	pthread_t threads[10];
	long t;
	for(t=0;t<10;t++){
		int rc=pthread_create(&threads[t], NULL, runner,(void*) 1);
		pthread_join(threads[t],NULL);
	}
	printf("%d\n", sum);
	return 0;
}
