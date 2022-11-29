#include <stdio.h>
void main(){

	int n,p;

	printf("\nInserire n (n>0) :: ");
	scanf("%d" ,&n);
	printf("\nInserire p (p>0) :: ");
	scanf("%d" ,&p);
	
	if(n>0 && p>0){
		if((1<<p <= n)&&(1<<p+1 > n))
			printf("\nVERO");
		else
			printf("\nFALSO");
	}

}