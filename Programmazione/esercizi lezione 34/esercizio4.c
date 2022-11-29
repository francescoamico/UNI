#include <stdio.h>
#include <stdlib.h>

void addSort(double *V,size_t dim,double a);

void main(){
	size_t dim = 5;
	double *p;
	double *a=malloc(dim*sizeof(double));
	*a++=1.2;
	*a++=2.5;
	*a++=3.4;
	*a++=6.7;
	*a++=9.0;
	a=a-dim;

	addSort(a,dim,1.8);
	printf("Vettore dopo l'inserimento :: ");
	for(p=a;p<a+6;p++)
		printf("%f ",*p);
}

void addSort(double *V,size_t dim,double a){
	double *p,*q;
	V=realloc(V,(dim+1)*sizeof(double));
	
	for (p=V;*p<=a && p<V+dim;p++);
	for (q=V+dim;q>p;q--) *q=*(q-1);
	*p=a;
}