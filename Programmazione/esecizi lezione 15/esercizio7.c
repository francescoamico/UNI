#include <stdio.h>
void main(){

	long b;
	int i,resto=0;
	int quoziente;
	
	printf("\nInserire b :: ");
	scanf("%d" ,&b);
	printf("\nInserire i (i<=31) :: ");
	scanf("%d" ,&i);
	
	if(i<=31){
		quoziente = b >> i;
		resto = b - (quoziente << i);
		printf("\nquoziente = %d",quoziente);
		printf("\nresto = %d",resto);
	}
	else
		printf("\ni deve essere minore o uguale a 31");
	
	
}