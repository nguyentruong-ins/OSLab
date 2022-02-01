#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

// Share data
double nPoints, nCircle=0;

void* process(void* npt){
	double x,y,dis;
	for (long i=0;i<(long)npt;i++){
		x=(rand()%10000)/10000.0;
		y=(rand()%10000)/10000.0;
		dis = x*x + y*y;
		if (dis<=1) nCircle++;
	}
	pthread_exit(0);
}

int main(int argc, char** argv){
	clock_t begin=clock();
	srand(time(NULL));
	int N,rc;
	long point_per_thread;
//	printf("Type in the number of threads: ");
//	scanf("%d", &N);
	N = 10; // Number of threads
	pthread_t threads[N];
//	printf("Type in the number of point: ");
//	scanf("%lf", &nPoints);
	nPoints = (double) atoi(argv[1]);
	point_per_thread = nPoints/N;
//	printf("Number points per thread: %ld\n", point_per_thread);
	long i;
	for (i=0;i<N;i++){
		rc = pthread_create(&threads[i], NULL, process, (void*) point_per_thread);
		if (rc){
			printf("ERROR; return from pthread create() is %d\n", rc);
			exit(-1);
		}
		pthread_join(threads[i],NULL);
	}
	printf("Pi approximate in Multi-thread program: %lf\n", 4.0*nCircle/nPoints);
//	printf("Number of points: %lf\n", nPoints);
//	printf("Number of points fall into circle: %lf\n", nCircle);
	clock_t end=clock();
	double time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
	printf("Total time in Multi-thread program: %lf\n", time_spent);
	return 0;
}
