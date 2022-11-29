#include <stdio.h>
#include "mylibrary.h"
void main()
{  
	int n;
	printf("Inserisci il valore di n ::");
	scanf("%d",&n);

	triangolare_inferiore(n);
	printf("\n");
	diagonale(n);
	printf("\n");
	griglia(n);

}