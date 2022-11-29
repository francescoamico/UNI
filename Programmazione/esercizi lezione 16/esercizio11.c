#include <stdio.h>
void main(){

	char c;
	
	printf("Inserire lettera  ::");
	scanf("%c", &c);
	
	if((c>='A')&&(c<='Z'))
		printf("\n%c = %c", c,c+32);
	else 
		printf("\n%c = %c", c,c-32);
}