/*p7.c*/
/*Adrielle*/
/*11811EBI005*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	float x;
	float y;
}pnt;

pnt * gerarpnts(int N) {
    pnt * p = (pnt *) calloc(N,sizeof(pnt));
    int i;
    for(i = 0; i < N; i++){
        p[i].x = cos(i*2.0*M_PI/(N-1));
		p[i].y = sin(i*2.0*M_PI/(N-1));
    }
    return p;
}

void mostrar(pnt * p_ini, pnt * p_fim) {
    if(p_ini < p_fim) {
        printf("(%.3f, %.3f)\n", p_ini->x, p_ini->y);
        mostrar(p_ini+1, p_fim);
    }
}

void gravarpnts(pnt * p_ini, int n){
  FILE * arquivo;
  arquivo = fopen("pontos.dat", "wb");
  fwrite(p_ini, n, sizeof(pnt), arquivo);
  fclose(arquivo);
  printf("Arquivo gravado");
}

pnt * lerarquivo(char *nome_arquivo, unsigned int * pn){
  pnt * p = (pnt *) malloc(sizeof(p));
  unsigned int n = 0;
  FILE * arquivo;
  arquivo = fopen(nome_arquivo, "rb");
  if(arquivo != NULL){
    while(1){
      fread(p, 1, sizeof(pnt), arquivo);
      if(feof(arquivo)) break;
      n++;
    }
    rewind(arquivo);
    p  = (pnt *) realloc(p, n*sizeof(pnt));
    fread(p, n, sizeof(pnt), arquivo);
    *pn = n;
    return p;
  }
  printf("Digite o numero de vezes em que o ciclo sera dividido.");
  return 0;
}


int main() {
    unsigned int N;
    int opc=0;
    pnt *p;
	do{printf("\nDigite o nmero de escolha:\n[1]Gerar arquivo com pontos \n[2]Recuperar pontos de arquivo.\n[3]Sair\n");
	scanf("%d",&opc);
	switch(opc){
		case 1:
		 { printf("Digite a quantidade de pontos: ");
		 	scanf("%u", &N);
		 	getchar();
            p = gerarpnts(N);
            gravarpnts(p, N);;
		 	break;
            }
	
		case 2:
		{ p= lerarquivo("pontos.dat", &N);
			mostrar(p, p+N);
			break;
			}

		break;
		
		default:
 	    {
 		if(opc!=3)
 		printf("Operacao invalida!\n");
 		break;
    }
  }	
}while(opc!=3);
    free(p);
    return 0;
}
