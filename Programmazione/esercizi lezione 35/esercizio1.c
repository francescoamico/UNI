#include <stdio.h>
#include <stdlib.h>

void MinMax(double *A, int N, int M, double **min, double **Max);

void main(){
	double A[][2]={{10.7,0.1},{9.0,11.2}};
	double *m,*M;
	MinMax(&A[0][0],2,2,&m,&M);
	
	printf("\nIndici minimo :: i=%d j=%d",(m-&A[0][0])/2,(m-&A[0][0])%2);
	printf("\nIndici massimo :: i=%d j=%d\n",(M-&A[0][0])/2,(M-&A[0][0])%2);
}

void MinMax(double *A, int N, int M, double **min, double **Max){
	*Max=A;
	*min=A;
	size_t i;
	for (i=0;i<N*M;i++,A++){
		*min = (*A<**min) ? A : *min;
		*Max = (*A>**Max) ? A : *Max;
	}
}