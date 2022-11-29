#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *elimina(const char *s, const char *t);

void main(){
	char *s = malloc(20*sizeof(char));
	char *t = malloc(20*sizeof(char));
	printf("Inserire s :: ");
	gets(s);
	printf("Inserire t :: ");
	gets(t);
	printf("\nStringa risultato eliminazione :: %s ",elimina(s,t));
	free(s);
	free(t);
}

char *elimina(const char *s, const char *t){
	unsigned char *map=calloc(256,sizeof(unsigned char));
	char *p = malloc((strlen(s)+1)*sizeof(char));
	char *q = p;
	
	for (;*t;*(map+*t)=1,t++);
	for (;*p=*s; p+=!(*(map+*s)), s++);
	*p=0;
	return(q);
}