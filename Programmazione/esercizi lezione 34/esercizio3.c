#include <stdio.h>
#include <stdlib.h>

void MaxMin(double *V,int dim,double **M,double **m);

void main(){
	double a[]={7.2,3.4,10.5,6.7};
	double *m,*M;
	MaxMin(a,4,&M,&m);
	printf("Minimo :: %f\n",*m);
	printf("Massimo :: %f\n",*M);
}

void MaxMin(double *V,int dim,double **M,double **m){
	*M=V;
	*m=V;
	for (;dim;dim--,V++){
		*m = (*V<**m) ? V : *m;
		*M = (*V>**M) ? V : *M;
	}
}