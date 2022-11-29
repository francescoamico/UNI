#include <stdio.h>

void scambia(int *a, int *b);
int mcm(int a, int b);

void main(){

	unsigned int a,b;
	
	printf("Inserire a :: ");
	scanf("%d",&a);
	printf("Inserire b :: ");
	scanf("%d",&b);
	
	if (b > a)
		scambia(&a,&b);
	
	printf("\nmcm :: %d", mcm(a,b));
	
}

void scambia(int *a, int *b){
	
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
	
}

int mcm(int a, int b){
	
	int mcm;
	if(!b)
		return a;
	if(!b && !a)
		return 0;
	for(mcm=a; (mcm%a) || (mcm%b); mcm++);
	return mcm;
	
	/*
	mcm=a;
	while((mcm%a) || (mcm%b)) 
		mcm++;
	return mcm;
	*/
}	
