#include <stdio.h>
void main(){

	char c;
	
	printf("Inserire carattere ::");
	scanf("%c", &c);
	
	if((c>='0')&&(c<='9'))
		printf("\n%c = carattere numerico", c);
	else{
		if((c>='a')&&(c<='z')){
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				printf("\n%c = vocale", c);
			else
				printf("\n%c = consonante", c);
		}
		else
			printf("\n%c = carattere speciale", c);
	}
	
}