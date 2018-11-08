#include <stdio.h>

typedef
unsigned long long int
Bytes8;
typedef
struct LCG { Bytes8 a, c, m, rand_max, atual; }
LCG;

void semente(LCG * r, Bytes8 seed) {
// constantes do POSIX [de]rand48, glibc [de]rand48[_r]
// ULL transforma a constante ’int’ em ’unsigned long long int’
r->a = 0x5DEECE66DULL;
r->c = 11ULL;
r->m = (1ULL << 48);
r->rand_max = r->m - 1;
r->atual = seed;
}

Bytes8 lcg_rand(LCG * r) {
r->atual = (r->a * r->atual + r->c) % r->m;
return r->atual;
}

double lcg_rand_01(LCG * r) {
return ((double) lcg_rand(r))/(r->rand_max);
}

void gera_numeros(float * vetor, int tam,float min, float max, LCG * r) {
int i;
for(i = 0; i < tam; i++)
vetor[i] = (max-min)*lcg_rand_01(r) + min;
}

float somatorio(float * inicio_vetor,float * fim_vetor){
       return (inicio_vetor == fim_vetor+1)? 0 : * inicio_vetor + somatorio(inicio_vetor + 1, fim_vetor);
}
	    
float produtorio(float * inicio_vetor,float * fim_vetor){
	return (inicio_vetor == fim_vetor+1)? 1 : * inicio_vetor * produtorio(inicio_vetor + 1, fim_vetor);
}

int main(){
	LCG random;
    semente(&random,123456);
    int opc=0;
    float vet[50];
    int N = 50;
    gera_numeros(vet,N, 0.5, 1.5, &random);
    printf("O programa realizara operacoes com 50 numeros aleatorios.");
	do{printf("\nEscolha uma operacao:\n[1]Somatorio \n[2]Produtorio.\n[3]Sair\n");
	scanf("%d",&opc);
	switch(opc){
		case 1:
		printf("\nSomatorio : %f", somatorio( &vet[0],&vet[0] + N-1 ) );
		break;
		case 2:
		printf("\nProdutorio: %g", produtorio( &vet[0], &vet[0] + N-1) );
		break;
		default:
 	    {
 		if(opc!=3)
 		printf("Opcao invalida\n");
 		break;
    }
  }	
}while(opc!=3);
return 0 ;
}
