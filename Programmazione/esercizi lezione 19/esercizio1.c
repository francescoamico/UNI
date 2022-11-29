#include <stdio.h>
void main(){
	unsigned int n,f=1;
	int i;
	printf("Inserire n :: ");
	scanf("%d", &n);
	
	for (i=1 ; i<=n ; i++)
		f *= i;
	
	printf("\nFattoriale di %d :: %d", n,f);
}