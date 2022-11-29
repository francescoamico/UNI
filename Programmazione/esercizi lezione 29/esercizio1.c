#include <stdio.h>

unsigned int mystrlen(char s[]);
void main(){
	
	char s[]={'c','a','s','a','l','e','\0'};
	printf("Lunghezza :: %d ",mystrlen(s));
	
}

unsigned int mystrlen(char s[]){
	unsigned int i=0;
	while(s[i])
		i++;
	return (i);
}
