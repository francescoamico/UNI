#include <stdio.h>
void main(){
	
	unsigned int n,r;
	
	printf("Inserire numero intero positivo :: ");
	scanf("%d",&n);
	
	r=2;
	
	while(r*r <= n)
		r += 1;
	
	printf("\nRadice intera di %d :: %d", n,r-1);
	
}