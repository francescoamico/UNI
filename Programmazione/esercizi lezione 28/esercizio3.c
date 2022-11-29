#include <stdio.h>

unsigned char ordine(unsigned int N,float a[]);
void main(){
	
	float array[10]={-1.4,0.2,1.7,2.9,3.1,5.0,6.0,7.3,8.8,9.9};
	printf("Ordine crescente?\nsi(1)  no(0)\n%d",ordine(10,array));
	
}

unsigned char ordine(unsigned int N,float a[]){
	int i;
	for(i=1;(i<N)&&(a[i]>=a[i-1]);i++)
	return (i==N);	
}
