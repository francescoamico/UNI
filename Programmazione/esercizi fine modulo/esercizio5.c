#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t palindroma(char *s);

void main(){
	
	char *s = (char *)malloc(20*sizeof(char));
	printf("Inserire stringa :: ");
	gets(s);
	
	palindroma(s) ? printf("stringa ''%s'' non palindroma",s):printf("stringa ''%s'' palindroma",s);
	
	free(s);
	
}

size_t palindroma(char *s){
	
	size_t j=0,dim=strlen(s),i=dim-1;
	char *s2 = (char *)malloc((dim+1)*sizeof(char));
	
	for(;j<dim;*(s2+j)=*(s+i),i--,j++);
	*(s2+dim)=0;
	
	return strcmp(s,s2);
	
}