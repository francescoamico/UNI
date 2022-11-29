#include <stdio.h>
void main(){
	
	unsigned int n,i;
	
	printf("Inserire numero intero positivo ::");
	scanf("%d",&n);
	
	printf("\nCoppie (n1,n2) tali che n1+n2 = n :: ");
	i = 1;
	while(i<=n/2){
		printf("(%d,%d) ",i,n-i);
		i += 1;
	}
	
}