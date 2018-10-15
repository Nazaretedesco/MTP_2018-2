#include <stdio.h>

int main(){
	int i,x=0;
	char num[256];
	printf("\nInsira um numero:");
	scanf("%s",num);
	printf("Apenas os numeros:");
	for(i=0;num[i]!='\0'; i++){
       if(num[i] >='0' && num[i] <='9' ){
       	printf("%d",num[i]-'0');
       	x++;
       }
	}
	if(x==0){
	printf("0");	
	}
	return 0;
    }
