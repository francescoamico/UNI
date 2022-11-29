#include <stdio.h>

void scambia(int *a, int *b);

void main(){
	
	int a,b;
	
	printf("Inserire a :: ");
	scanf("%d",&a);
	printf("Inserire b :: ");
	scanf("%d",&b);
	
	scambia(&a,&b);
	
	printf ("\na = %d",a);
	printf ("\nb = %d",b);
	
}

void scambia(int *a, int *b){
	
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
	
}