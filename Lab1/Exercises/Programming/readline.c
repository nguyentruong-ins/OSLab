#include"readline.h"
#include"string.h"
#include<stdio.h>
int read_line(char *str){
	//scanf("%s",str);
	fgets(str, sizeof(str), stdin);
	for (int i=0;i<strlen(str);i++){
		if (str[i]<'0'||str[i]>'9'){
			return 0;
		}
		return 1;
	}
}
