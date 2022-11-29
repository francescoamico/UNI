#include <stdio.h>
void main(){

	short int b,i;
	int ris;
	
	printf("\nInserire b :: ");
	scanf("%d" ,&b);
	printf("\nInserire i (i<=16) :: ");
	scanf("%d" ,&i);
	
	if(i<=16){
		ris = b << i;
		printf("\nrisultato = %d",ris);
	}
	else
		printf("\ni deve essere minore o uguale a 16");
	
	
}