#include <stdio.h>

int MCD(int a, int b);

void main(){

	unsigned int a,b;
	
	printf("Inserire a :: ");
	scanf("%d",&a);
	printf("Inserire b :: ");
	scanf("%d",&b);
	
	printf("\nMCD :: %d", MCD(a,b));
	
}

int MCD(int a, int b){
	
	int r;
	while (b){
		r = a % b;
		a = b;
		b = r ;
	}
	return a;
}	
