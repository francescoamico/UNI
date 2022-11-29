#include <stdio.h>
#include <math.h>
void main(){
	
	unsigned int n;
	int i,j,k;
	printf("Inserire n :: ");
	scanf("%d", &n);
	
	for (i=1 ; i<=n ; i++)
	{
		for (j=i+1 ; j<n ; j++)
		{
			k=sqrt(n);
			if((k<=n) && (k*k=i*i+j*j))	
				printf("\n(%d,%d,%d)",i,j,k);
		}
			
	}		
}