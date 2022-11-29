#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *inserisci(const char *s,const char *t,int k);

void main(){
	char s[] = "Ciao caro"; 
	char t[] = "amico "; 
	unsigned int k = 5;
	
	assert(k<strlen(s));

	char *c = inserisci(s,t,k);

	printf("Stringa :: %s",c);
	
	free(c);
}

char *inserisci(const char *s,const char *t,int k){
	
	int l = strlen(s)+strlen(t)+1;
	char *c = calloc(l*sizeof(char));
	strncpy(c,s,k);
	strcat(c,t);
	strcat(c,s+k);
	return (c);
}
