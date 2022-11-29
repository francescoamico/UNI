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
	
	if (a == 0)
		a = b;
	if (b == 0)
		b = a;
	while (a != b){
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}	
