#include <stdio.h>

double prodscal(double *a, double *b, int dim);

void main(){
	const size_t dim=5;
	double a[]={1.0,7.3,4.4,8.0,0.0};
	double b[]={3.2,4.9,7.4,2.1,8.6};

	printf("Prodotto scalare = %f",prodscal(a,b,dim));
}

double prodscal(double *a, double *b, int dim){
	double p=0;
	for(;dim;dim--,p+=(*a++)*(*b++));
	return p;
}