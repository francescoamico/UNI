#include <stdio.h>
void main(){
	
	size_t i,j,a=8,b=4;
	for(i=0;i<a;i++)
		printf("* ");
		
	for(i=0;i<b-2;i++){
		printf("\n* ");
		for(j=0;j<a-2;j++)
			printf("  ");
		printf("*");
	}
	
	printf("\n");
	for(i=0;i<a;i++)
		printf("* ");
}