#include <stdio.h>

void inv (char vet[]){
	int i, j, c = 0, au;
	for(i = 0; vet[i] != '\0'; i++, c++);
	j = c - 1;
	for(i = 0; i < j; i++, j--){
		au = vet[i];
		vet[i] = vet[j];
		vet[j] = au;
	}
	vet[c] = '\0';
}
int pt(int num, int num2){
	int i, r = 1;
	for(i = 0; i < num2; i++, r*=num);
	return r;
}
int binde(char vet[]){
	inv(vet);
	int i, sm = 0;
	for(i = 0; vet[i] != '\0'; i++){
		if(vet[i] == '1'){
			sm += vet[i] * pt(2, i);
		}
	}
	return sm/49;
}
void debi(int q){
	int i, flag = 0, vet[256], j;
	j = q;
	for(i = 0; flag < 1; i++){
		vet[i] = j % 2;
		j /= 2;
		if(j == 0 || j == 1){
			vet[i + 1] = j;
			j = i + 1;
			flag++;
		}
	}
	printf("\nEle em binario:  ");
	for(j; j >= 0; j--){
		printf("%d", vet[j]);
	}
}
int main(){
	char bt[256];
	int opc =0, k;
	do{
		printf("\nEscolha uma opcao: \n1- Binario para decimal \n2- Binario para hexadecimal \n3- Hexadecimal para decimal");
		printf("\n4- Hexadecimal para binario \n5- Decimal para binario \n6- Decimal para hexadecimal \n7- Octal para decimal");
		printf("\n8- Decimal para octal \n9- Sair do programa \n\nDigite: ");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				printf("\nDigite um numero binario: ");
				scanf("%s", &bt[0]);
				printf("\nEle em decimal: %d", binde(bt));
				break;
			case 2:
				printf("\nDigite um numero binario: ");
				scanf("%s", &bt[0]);
				printf("\nEle em hexadecimal: %x", binde(bt));
				break;
			case 3:
				printf("\nDigite um numero hexadecimal: ");
				scanf("%x", &k);
				printf("\nEle em decimal: %d", k);
				break;
			case 4:
				printf("\nDigite um numero hexadecimal: ");
				scanf("%x", &k);
				debi(k);
				break;
			case 5:
				printf("\nDigite um numero decimal: ");
				scanf("%d", &k);
				debi(k);
				break;
			case 6:
				printf("\nDigite um numero decimal: ");
				scanf("%d", &k);
				printf("\nEle em hexadecimal: %x", k);
				break;
			case 7:
				printf("\nDigite um numero octal: ");
				scanf("%o", &k);
				printf("\nEle em decimal: %d", k);
				break;
			case 8:
				printf("\nDigite um numero decimal: ");
				scanf("%d", &k);
				printf("\nEle em octal: %o", k);
				break;
			default:
				if(opc != 9){
					printf("\nOpçao invalida");
				}
		}
	}while(opc != 9);
	return 0;
}
