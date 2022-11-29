#include <stdio.h>
#include <assert.h>

void griglia(int n);

void main(){
	
	int n;
	
	printf("Inserire n :: ");
	scanf("%d", &n);
	assert(n>0); 
	
	griglia(n);
	
}

void griglia(int n){
	
	int i,j;
	for (i=1 ; i<=n ; i++){
		for (j=1 ; j<i ; j++)
			printf("-");
		printf("%d\n",j++);
	}
}


