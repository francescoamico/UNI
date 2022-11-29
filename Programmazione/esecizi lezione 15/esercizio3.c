#include <stdio.h>
#include <math.h>
void main(){

	float a,b,c,delta,s1,s2;

	printf("Inserire a :: ");
	scanf("%f" ,&a);
	printf("\nInserire b :: ");
	scanf("%f" ,&b);
	printf("\nInserire c :: ");
	scanf("%f" ,&c);
	
	delta=(b*b)-4*(a*c);
	
	if(delta<0)
		printf("\nNon esistono soluzioni");
	else{
		s1=(-b-sqrt(delta))/2*a;
		s2=(-b+sqrt(delta))/2*a;
		printf("\nLe soluzioni sono :: %f e %f", s1,s2);
	}
	
}