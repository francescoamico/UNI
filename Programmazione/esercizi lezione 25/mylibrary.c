#include <stdio.h>
#include "mylibrary.h"
void triangolare_inferiore(int N)
{
	int i,j,k=0;
	for (i=1 ; i<=N ; i++){
		for (j=1 ; j<=i ; j++)
			printf("%d,",k++);
		printf("\n");
	}
}

void diagonale(int N)
{
	int i;
	for (i=0; i<N*N; i++)
	{
		if (i-((i/N)*N)-i/N)
			printf("-");
		else
		{
			printf("%d\n",(i/N)+1);
			i=i+N-(i/N)-1;
		}
	}	
}

void griglia(int N)
{
	int i;
	for (i=1; i<=N*N; i++)
		!(i%N) ? printf("%d\n",i):printf("%d-",i);
}