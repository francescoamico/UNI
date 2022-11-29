#include <stdio.h>
void main(){
	
	unsigned int n;
	int i,j,k=0;
	
	printf("Inserire n :: ");
	scanf("%d", &n);

	for (i=1 ; i<=n ; i++){
		for (j=1 ; j<=i ; j++)
			printf("%d,",k++);
		printf("\n");
	}
	
}