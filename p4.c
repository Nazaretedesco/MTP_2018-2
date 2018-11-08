#include <stdio.h>

int A(int,int);
int main(){
	int m,n;
	printf("Digite os valores de m e n, respectivamente: ");
	scanf("%d%d",&m,&n);
	printf("Resultado: %d", A(m,n));		
	return 0;
	}
	
int A(int m, int n){
		if(m == 0){
		return n+1;
		}
		else if(n == 0 && m>0){
		return A(m - 1, 1);
	    }
		else{
		return A(m - 1, A (m, n - 1));
		}
    }
