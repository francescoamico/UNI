#include<stdio.h>

unsigned int incr(unsigned int n);

void main(){
	
	unsigned int n;
	printf("Inserire n::");
	scanf("%u",&n);
	
	/* versione iterativa
	for(int i=0; i<n ; i++)
		!(i%2) ? printf("%d\n",i):printf("%d\n",i+1);
	*/
	
	/* versione ricorsiva
	for(int i=0; i<n ; i++)
		printf("%u\n",incr(i));
	*/
}

unsigned int incr(unsigned int n){
	if(!(n%2)) return n;
	else incr(n+1);
}