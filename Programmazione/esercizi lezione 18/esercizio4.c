#include <stdio.h>
void main(){
	
	unsigned int n,i;
	
	printf("Inserire numero intero positivo ::");
	scanf("%d",&n);
	
	printf("\nNumeri pari <= n :: ");
	i = 0;
	while(i<=n){
		printf("%d ",i);
		i += 2;
	}
	
}