#include <stdio.h>

void scambia(int *a, int *b);
int MCD(int a, int b);

void main(){

	unsigned int a,b;
	
	printf("Inserire a :: ");
	scanf("%d",&a);
	printf("Inserire b :: ");
	scanf("%d",&b);
	
	if (b > a)
		scambia(&a,&b);
	
	printf("\nMCD :: %d", MCD(a,b));
	
}

void scambia(int *a, int *b){
	
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
	
}

int MCD(int a, int b){
	
	int MCD;
	if(!b)
		return a;
	for(MCD=b; (a%MCD) || (b%MCD); MCD--);
	return MCD;
	
	
	/*
	MCD=b;
	while((a%MCD) || (b%MCD)) 
		MCD--;
	return MCD;
	*/
}	
