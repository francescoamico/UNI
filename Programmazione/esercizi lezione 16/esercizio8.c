#include <stdio.h>
void main(){

	long b,m;
	int i,x;
	
	printf("\nInserire b :: ");
	scanf("%d" ,&b);
	printf("\nInserire i (i<=31) :: ");
	scanf("%d" ,&i);
	
	printf("\n\n1)i-mo bit a 0\n2)i-mo bit a 1\n3)complemento i_mo bit\n");
	scanf("%d" ,&x);
	
	switch(x){
		case 1:
			m = ~(1 << i);
			b = b & m;
			printf ("b :: %d",b);
			break;
		case 2:
			m = (1 << i);
			b = b | m;
			printf ("b :: %d",b);
			break;
		case 3:
			m = (1 << i);
			b = b ^ m;
			printf ("b :: %d",b);
			break;
		default:
			break;
	}		
}