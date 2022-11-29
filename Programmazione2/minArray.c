#include<stdio.h>
#define size 10

size_t min(int *a, size_t start,size_t dim, size_t ind);

void main(){
	int array[size]={23,12,0,67,89,1,55,9,66,78};
	
	size_t ind=min(array,0,size,0);
	
	printf("numero minore in posizione %u = %d", ind,*(array+ind));
}

size_t min(int *a, size_t start, size_t dim, size_t ind){
	if(dim==1 || start==dim) return ind;
	if(start<dim){
		if(*(a+start)<*(a+ind)) return min(a,start+1,dim,start);
		else return min(a,start+1,dim,ind);
	}
}