#include <stdio.h>
#include <stdlib.h>

unsigned int contamaiuscole(char s[]);

void main(){
	
	char *s=(char *)malloc(12*sizeof(char));
	printf("Inserire stringa :: ");
	gets(s);
	printf("Numero maiuscole = %d",contamaiuscole(s));
}

unsigned int contamaiuscole(char *s){
	unsigned int i,m=0;
	for(i=0;s[i];i++)
		m += (s[i]>='A')&(s[i]<='Z');
	return (m);
}