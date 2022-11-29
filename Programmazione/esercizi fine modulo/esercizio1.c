#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int order(char **s,size_t n);

void main(){
	size_t i,n;
	int ord;
	printf("\nQuante stringhe desidera inserire? ");
	scanf("%d",&n);
	assert(n>0);

	char **s = (char **)malloc(n*sizeof(char *));
	for(i=0;i<n;i++){
		s[i]=(char *)malloc(20*sizeof(char));
		printf("Inserire stringa %d :: ",i+1);
		scanf("%s",s[i]);
	}
	ord=order(s,n);
	printf("\n0)nessun ordine\n1)crescente\n2)decrescente\n");
	ord==-1 ? printf("2"):printf("%d",ord);
	
	free(s);
}

int order(char **s,size_t n){
	size_t i,j,c=0,temp=0;

	for(i=1;i<n;i++){
		c=strcmp(s[i-1],s[i]);
		if(c!=temp && i!=1)
			return 0;
		temp=c;
	}
	return -c;
}
