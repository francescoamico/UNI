#include <stdio.h>
#include <stdlib.h>
#include "sort_library.h"

extern int compare();

void scambia(void **a, void **b){
	*a=(void *)((int)(*a)^(int)(*b));
	*b=(void *)((int)(*a)^(int)(*b));
	*a=(void *)((int)(*a)^(int)(*b));
}

void selection_sort(void **array,int N){
	size_t i,j,mi;
	for (i=0;i<N-1;i++){ 
	  mi=i;
	  for (j=i+1;j<N;j++)
		if (compare(array[j],array[mi])==-1) mi=j;
	  if (mi!=i)
		scambia(&array[i],&array[mi]);
	}
}

void bubble_sort(void **array,int N){
	size_t j,swap=1,d=N;
	while(swap){
		swap = 0;	 
		for (j=0;j<N-1;j++)
			if (compare(array[j],array[j+1])==1){
				scambia(&array[j],&array[j+1]);
				swap=1;
			}
		N=N-1;
	}
}

void insertion_sort(void **array,int N){
	int i,j;
	void *v;
	for (i=0;i<N;i++){
		v=array[i];
		for (j=i-1;(j>=0)&&(compare(array[j],v)==1);j--)
			array[j+1]=array[j];
		array[j+1]=v;
	}
}
