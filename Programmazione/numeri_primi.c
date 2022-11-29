#include <stdio.h>
#include <math.h>
int primo();

void main(){
	
	unsigned int N,i;
	
	printf("Inserire numero :: ");
	scanf("%d",&N);
	
	printf("\nInteri minori di n primi :: ");
	for(i=0; i<=sqrt(N); i++){
		#ifdef DEBUG
				printf("\n%d %d ",i,primo(i));
		#else
		if(primo(i))
			printf("%d ",i);
		#endif
	}
	
}

int  primo(int n){
	int d;
	#ifdef DEBUG
		printf(" - %d ",n);
		for (d = 2;(n%d)&&(d<n); d++);
			printf("%d ",d);
			return d==n;
	#else
		for (d = 2;(n%d)&&(d<n); d++);
			return d==n;
	#endif
}