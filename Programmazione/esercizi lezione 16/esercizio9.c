#include <stdio.h>
void main(){

	int n,m,c,d,u;
	
	printf("Inserire n ::");
	scanf("%d", &n);
	
	m = n / 1000;
	c = n - (m*1000) ;
	c = c / 100;
	d = n - (m*1000) - (c*100);
	d = d / 10;
	u= n - (m*1000) - (c*100) - (d*10);
	
	printf("\nM :: %d", m);
	printf("\nC :: %d", c);
	printf("\nD :: %d", d);
	printf("\nU :: %d", u);
	
}