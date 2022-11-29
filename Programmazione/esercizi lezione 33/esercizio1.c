#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inverti(const char *s);

void main(){
	char *s = malloc(20*sizeof(char));  

	printf("Inserire s :: ");
	gets(s);

	char *i = inverti(s);

	printf("Stringa invertita :: %s",i);
	
	free(s);
	free(i);
}

char *inverti(const char *s){
	
	int l = strlen(s);
	char *inv = malloc((l+1)*sizeof(char));
	inv+=l;
	*inv--=0;
	for(;*s;*inv--=*s++);
	return (inv+1);
}