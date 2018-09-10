/* P1.c*/
/* Adrielle */
/*11811EBI005*/

#include <stdio.h>

int main(){
	int est=0, i=0;
	char bits[256];
	printf("Digite o numero binario a ser avaliado: ");
	gets(bits);
	for(i=0; bits[i]!= '\0'; i++){
		if(est == 0 && bits[i] == '0'){
			est = 0;
		}
		else if(est == 0 && bits[i] == '1'){
			est = 1;
		}
		else if(est == 1 && bits[i] == '1'){
			est = 0;
		}
		else if(est == 1 && bits[i] == '0'){
			est = 2;
		}
		else if(est == 2 && bits[i] == '1'){
			est = 2;
		}
		else if(est == 2 && bits[i] == '0'){
			est = 1;
		}
	}
	printf("\nO estado e: %d\nA sequencia original e: %s", est, bits);
	if(est != 0){
		printf("\nO numero nao e multiplo de 3");
	}
	else{
		printf("\nO numero e multiplo de 3");
	}
	return 0;
}
