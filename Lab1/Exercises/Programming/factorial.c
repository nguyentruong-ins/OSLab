// factorial.c
#include"factorial.h"
#include<stdio.h>

int factorial(const int aNumber){
	long long ans=1;
	for (int i=1;i<=aNumber;i++){
		ans*=i;
	}
	return ans;
}
