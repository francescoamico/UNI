#include <stdio.h>
void main(){
	unsigned int r,q;
	float s=0;
	int i;
	
	printf("Inserire r :: ");
	scanf("%d", &r);
	
	printf("\nInserire q :: ");
	scanf("%d", &q);
	
	if (r > q){
		r = r ^ q;
		q = r ^ q;
		r = r ^ q;
	}
	if (r == 0)
		printf("\nImpossibile r e q devono essere diversi da 0", s);
	else{
		for (i=r ; i<=q ; i++)
			s += (float)1/i; //anche 1.0/i  casting implicito
		
		printf("\nS = %f", s);
	}
}