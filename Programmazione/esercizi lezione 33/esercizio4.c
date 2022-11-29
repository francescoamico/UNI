#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define n 30
#define m 20

size_t occorrenze(const char *s, const char *t);

void main(){
	char *s = malloc(n*sizeof(char));
	char *t = malloc(m*sizeof(char));
	assert(n>=m);
	printf("Inserire s :: ");
	gets(s);
	printf("Inserire t :: ");
	gets(t);
	printf("\nOccorrenze di t in s :: %d ",occorrenze(s,t));
	free(s);
	free(t);
}

size_t occorrenze(const char *s, const char *t){
	size_t occ = 0;
	for(;s=strstr(s,t);s++,occ++);
	return occ;
}