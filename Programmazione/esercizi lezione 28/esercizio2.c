#include <stdio.h>

unsigned char confronto(unsigned int N,int a[]);
void main(){
	
	int array[10]={1,1,1,1,1,1,1,1,1,1};
	printf("Uguali (1)\nDiversi (0)\n%d",confronto(10,array));
	
}

unsigned char confronto(unsigned int N,int a[]){
	int i;
	for (i=1;(i<N)&&(a[i-1]==a[i]);i++);
	return (i==N);	
}
