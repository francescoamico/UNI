#include <stdio.h>
#include <stdlib.h>

char *unisci(char *a, char *b);

void main(){
	char *a = malloc(20*sizeof(char)); 
	char *b = malloc(20*sizeof(char)); 
	
	
	printf("Inserire a :: ");
	gets(a);
	printf("Inserire b :: ");
	gets(b);
	
	char *c = unisci(a,b);
	
	printf("Stringa concatenata :: %s",c);
	
	free(a);
	free(b);
	free(c);
}

char *unisci(char *a, char *b){
	char *conc = realloc(a,39*sizeof(char));
	unsigned int i;
	for(i=0; conc[i];i++);
	unsigned int j=i;
	for(i=0; b[i];conc[j]=b[i],j++,i++);
	conc[j]=0; 
	return conc;
}