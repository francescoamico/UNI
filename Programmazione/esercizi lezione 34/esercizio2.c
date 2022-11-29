#include <stdio.h>
#include <stdlib.h>

double *somma(double *a, double *b, int dim);

void main(){
	size_t dim=5;
	double a[]={1.0,7.3,4.4,8.0,0.0};
	double b[]={3.2,4.9,7.4,2.1,8.6};
	
	double *s=somma(a,b,dim);
	
	printf("Vettore somma :: ");
	for(;dim;dim--,s++)
		printf("%f ",*s);
		
	free(s);
}

double *somma(double *a, double *b, int dim){
	double *v = malloc(dim*sizeof(char));
	double *p=v;
	for(;dim;dim--,*v++=(*a++)+(*b++));
	return p;
}