#include <stdio.h>
#include <stdlib.h>

char *copia(char *src);

void main(){
	char *src = malloc(20*sizeof(char)); //casting implicito
	printf("Inserisci stringa :: ");
	gets(src);
	char *c = copia(src);
	printf("Stringa copiata :: %s",c);
	free(src);
	free(c);
}

char *copia(char *src){
	char *src2 = malloc(20*sizeof(char));
	unsigned int i;
	for(i=0; src[i];src2[i]=src[i],i++);
	src2[i]=0; //marcatore di fine stringa
	return src2;
}