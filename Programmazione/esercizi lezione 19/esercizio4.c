#include <stdio.h>
void main(){
	
	unsigned int k;
	float t,s=0;
	int i,j;
	
	printf("Inserire k :: ");
	scanf("%d", &k);

	for (i=1 ; i<=k ; i++){
		t=0;
		for (j=1 ; j<=i ; j++)
			t += (float)1/(i+j);
		s = s+t*t;
	}
	printf("\nS = %f", s);
	
}