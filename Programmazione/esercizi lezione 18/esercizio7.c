#include <stdio.h>
void main(){
	
	unsigned int x,y;
	
	printf("Inserire x :: ");
	scanf("%d",&x);
	printf("\nInserire y :: ");
	scanf("%d",&y);
	
	if(x>y){
		x = x^y;
		y = x^y;
		x = x^y;
	}
	
	y = y / x;
	y = y * x;
	
	while(y >= x){
		printf("\n%d", y);
		y -= x;
	}
	
}