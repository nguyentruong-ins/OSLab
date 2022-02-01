#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

int odd=0,even=0;

int main(){
	FILE* ptr1,* ptr2;
	char str[1000];

	// Opening file in reading mode
	ptr1=fopen("number.txt","r");
	ptr2=fopen("number.txt","r");
	
	pid_t pid;
	pid = fork();
	if (pid == 0){
		while (fgets(str, sizeof(str), ptr1)!=NULL){
			int temp = atoi(str);
			if (temp%3 == 0) odd++;
//			printf("%d\n", temp);
		}
		printf("%d\n", odd);

	}
	if (pid > 0){
		while (fgets(str, sizeof(str), ptr2) != NULL)
		{
			int temp = atoi(str);
			if (temp%2==0) even++;
//			printf("%d\n", temp);
		}
		printf("%d\n", even);
	}
	return 0;
}

