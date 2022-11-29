#include <stdio.h>
#include <stdlib.h>

void trasposta(double **MA,double **MB,int n,int m);
void prodotto(double **A, double **B, double **C, int N, int M);
double prodscal(double *a, double *b, int dim);

void main(){
	unsigned int i,j,N=2,M=4;
	double A[][4]={{10.0,0.0,4.0,6.0},{9.0,1.0,3.0,9.0}};
	double B[][2]={{1.0,2.0},{1.0,1.0},{0.0,1.0},{1.0,1.0}};
	double T[N][M];
	double C[N][N];
	double *pa=&A[0][0];
	double *pb=&B[0][0];
	double *pc=&C[0][0];
	double *pt=&T[0][0];
	
	trasposta(&pb,&pt,M,N);
	prodotto(&pa,&pt,&pc,N,M);
	
	printf("\n--Prodotto riga-colonna--\n\n");
	for (i=0;i<N;i++){
		for(j=0;j<N;j++,pc++)
			printf("%f ",*pc);
		printf("\n");
	}
	
}

void trasposta(double **MA,double **MB,int n,int m){
	double *t=malloc((n*m)*sizeof(double*));
	unsigned int i,j;
	for (i=0;i<m;i++){
		for(j=0;j<n;j++,t++)
			*t=*(*MA+j*m+i);
	}
	t-=n*m;
	*MB=t;
}

double prodscal(double *a, double *b, int dim){
	double p=0;
	for(;dim;dim--,p+=(*a++)*(*b++));
	return p;
}

void prodotto(double **A, double **B, double **C, int N, int M){
	double *p=malloc((N*N)*sizeof(double*));
	unsigned int i,j;

	for(i=0;i<N;i++){
		for(j=0;j<N;j++,p++){
			*p=prodscal(*A+i*M,*B+j*M,M);
		}
	}
	p-=N*N;
	*C=p;
}