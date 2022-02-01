#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/wait.h>

int main (int argc, char** argv){
	clock_t begin=clock();
	srand(time(NULL));
//	int r = rand()%100;
	double nPoints, nCircle;
//	printf("Type the number of points you want: ");
//	scanf("%lf", &nPoints);
	nPoints=(double) atoi(argv[1]);
	double x,y, dis;
	for (int i=0;i<nPoints;i++){
		x=(rand()%10000)/10000.0;
		y=(rand()%10000)/10000.0;
		dis = x*x + y*y;
		if (dis<=1) nCircle++;
	}
	printf("Pi approxiate in Serial program: %lf\n", 4.0*nCircle/nPoints);
	clock_t end=clock();
	double time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
	printf("Total time in Serial program: %lf\n", time_spent);
	return 0;
}
