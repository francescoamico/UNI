#include <stdio.h>
#include <stdlib.h>
#include "sort_library.h"

int compare(int *a, int *b){
	return(((*a-*b)>0)-((*a-*b)<0));
}

void main(){
	
	size_t i,dim=5;
	int array[5]={22,12,3,1,-1};
	void **V= (void **)malloc(dim*sizeof(int *));
	
	for (i=0;i<dim;i++)
		V[i]=&array[i];
		
	printf("1)Selection Sort\n2)Bubble sort\n3)Insertion Sort\n");
	scanf("%d",&i);

	switch(i){
		case 1:
			selection_sort(V,dim);
			printf("\n--Array ordinato--\n");
			break;
		case 2:
			bubble_sort(V,dim);
			printf("\n--Array ordinato--\n");
			break;
		case 3:
			insertion_sort(V,dim);
			printf("\n--Array ordinato--\n");
			break;
		default:
			printf("\n--Array non ordinato--\n");
			break;
	}	
	
	for (i=0;i<dim;i++)
		printf("%d ",*((int*)V[i]));
}





















