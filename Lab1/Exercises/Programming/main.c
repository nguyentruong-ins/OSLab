#include"factorial.h"
#include<stdio.h>
#include"readline.h"
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[]){
//	int a=factorial(5);
//	printf("%d\n",a);
	int a;
	char str[50];
	while (str[0]!='*'){
		if (read_line(str)){
			a=factorial(atoi(str));
			printf("%d\n",a);
		}
		else
			printf("-1\n");
//		printf("%s\n", str);
//		a=atoi(str);
	}
	return 0;
}

