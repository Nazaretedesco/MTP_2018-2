#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	float x;
	float y;
}pnt;
pnt*gerarpnts(int N){
	pnt * p = (pnt*)
	calloc(N, sizeof(pnt));
	int i;
	for(i=0; i<N; i++){
		p[i].x = cos(i*2.0*M_PI/(N-1));
		p[i].y = sin(i*2.0*M_PI/(N-1));
	}
	return p;
}
void mostrar(pnt*p_ini, pnt*p_fim){
	if(p_ini < p_fim){
		printf("(%.3f, %.3f)\n", p_ini->x, p_ini->y);
		mostrar(p_ini+1, p_fim);
	}
}
int main(){
	unsigned int N;
	pnt*p;
	printf("Digite o numero de pontos desejados: ");
	scanf("%u", &N);
	getchar();
	p = gerarpnts(N);
	mostrar(p, p+N);
	free(p);
	return 0;
}
