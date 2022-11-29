#include <stdio.h>
#include <stdlib.h>

void trasposta(double **MA,double **MB,int n,int m);

void main(){
	unsigned int i,j,N=2,M=3;
	double A[][3]={{10.7,0.1,4.5},{9.0,1.2,3.3}};
	double B[M][N];
	double *pa=&A[0][0];
	double *pb=&B[0][0];;

	trasposta(&pa,&pb,N,M);

	printf("\n--TRASPOSTA--\n\n");
	for (i=0;i<M;i++){
		for(j=0;j<N;j++,pb++)
			printf("%f ",*pb);
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