#include <stdio.h>
#include <stdlib.h>

char *copian(char *src, size_t n);

void main(){
	char *src = malloc(20*sizeof(char)); //casting implicito
	unsigned int n = 5; //unsigned int = size_t
	
	printf("Inserisci stringa :: ");
	gets(src);
	char *c = copian(src,n);
	printf("Primi n caratteri :: %s",c);
	free(src);
	free(c);
}

char *copian(char *src, size_t n){
	char *src2 = malloc(n*sizeof(char));
	unsigned int i;
	for(i=0; src[i],i<n;src2[i]=src[i],i++);
	src2[i]=0; //marcatore di fine stringa
	return src2;
}