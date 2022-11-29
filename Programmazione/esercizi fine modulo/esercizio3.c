#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int *vet(char **s,size_t n);

void main(){
	
	size_t i,n;
	printf("\nQuante stringhe desidera inserire? ");
	scanf("%d",&n);
	assert(n>0);
	
	char **s = (char **)malloc(n*sizeof(char *));
	for(i=0;i<n;i++){
		s[i]=(char *)malloc(20*sizeof(char));
		printf("Inserire stringa %d :: ",i+1);
		scanf("%s",s[i]);
	}
	
	int *v=vet(s,n);
	printf("\nvettore :: ");
	for(i=0;i<n-1;i++)
		printf("%d ",*(v+i));
	
	free(s);
	
}

int *vet(char **s,size_t n){
	
	size_t i;
	int *v = (int *)malloc(n*sizeof(int));
	
	for(i=0;i<n-1;i++)
		v[i]=-strcmp(s[i],s[i+1]);
	
	return v;
}