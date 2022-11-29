

#include <stdio.h>
#include <math.h>
void main(){
	
	unsigned int n,i;
	
	printf("Inserire numero intero positivo ::");
	scanf("%d",&n);
	
	printf("\nCoppie (n1,n2) tali che n1*n2 = n :: ");
	i = 2;
	while(i<=sqrt(n)){
		if(n%i == 0)
			printf("(%d,%d) ",i,n/i);
		i += 1;
	}
	
}