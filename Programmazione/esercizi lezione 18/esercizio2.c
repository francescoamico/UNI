#include <stdio.h>
void main(){
	
	unsigned int n,b;
	
	printf("Inserire numero intero positivo decimale :: ");
	scanf("%d",&n);
	
	printf("\nNumero in binario :: ");
	while(n){
		b = n%2;
		printf("%d", b);
		n = n>>1;
	}
	
}