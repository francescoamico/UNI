#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

char *conc(char **M, size_t i1, size_t i2, size_t n, size_t m);

void main(){
	
	size_t i,i2,i1,N,n,m;
	printf("\nQuante stringhe desidera inserire? ");
	scanf("%d",&N);
	assert(N>0);
	
	char **M = (char **)malloc(N*sizeof(char *));
	for(i=0;i<N;i++){
		M[i]=(char *)malloc(20*sizeof(char));
		printf("Inserire stringa %d :: ",i+1);
		scanf("%s",M[i]);
	}
	
	printf("Inserire i1 :: ");
	scanf("%d",&i1);
	assert(i1>=0 && i1<N);
	
	printf("Inserire i2 :: ");
	scanf("%d",&i2);
	assert(i2>=0 && i2<N);
	
	printf("Inserire n :: ");
	scanf("%d",&n);
	assert(n>=0 && n<=strlen(M[i1]));
	
	printf("Inserire m :: ");
	scanf("%d",&m);
	assert(m>=0 && m<=strlen(M[i2]));

	char *s=conc(M,i1,i2,n,m);
	printf("Stringa :: ");
	for(;*s;s++)
		printf("%c",*s);
		
	free(M);
	
}

char *conc(char **M, size_t i1, size_t i2, size_t n, size_t m){
	
	char *c=(char *)malloc((n+m+1)*sizeof(char));
	
	strncpy(c,M[i1],n);
	c[n]=0;
	M[i2]+=strlen(M[i2])-m;
	
	return strcat(c,M[i2]);
	
}








