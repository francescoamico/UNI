#include <stdio.h>
void main(){

	int a,b;
	
	printf("Inserire a :: ");
	scanf("%d" ,&a);
	printf("\nInserire b :: ");
	scanf("%d" ,&b);
	
	if(a>=b && (a==b*b || a==b*b*b))
		printf("maggiore quadrato o cubo minore");
	else{
		if (b==a*a || b==a*a*a)
			printf("maggiore quadrato o cubo minore");
		else
			printf("impossibile effettuare confronto");
	}	
}