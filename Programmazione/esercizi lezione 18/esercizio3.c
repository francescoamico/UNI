#include <stdio.h>
void main(){
	
	unsigned int n,i;
	
	printf("Inserire numero intero positivo ::");
	scanf("%d",&n);
	
	printf("\nNumeri dispari <= n :: ");
	i = 1;
	while(i<=n){
		printf("%d ",i);
		i += 2;
	}
	
}