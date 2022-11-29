#include <stdio.h>
void main(){

	int a,b;
	
	printf("Inserire a :: ");
	scanf("%d" ,&a);
	printf("\nInserire b :: ");
	scanf("%d" ,&b);
	
	a=a^b;
	b=a^b;
	a=a^b;
	
	printf("\na :: %d", a);
	printf("\nb :: %d", b);
	
}