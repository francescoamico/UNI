#include <stdio.h>

int indice(unsigned int N,int a[],unsigned int n);
void main(){
	
	int array[10]={12,2,23,56,4,1,0,29,11,99};
	printf("Indice :: %d",indice(10,array,0));
	
}

int indice(unsigned int N,int a[],unsigned int n){
	int i;
	for(i=N-1;(i>=0)&&(a[i]!=n);i--);
	return (i);
}
