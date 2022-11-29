#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

void selection_sort(int array[],size_t N);
int findMinimum(int array[],size_t N);

void main(){
	int array[SIZE];
	
	srand(time(NULL));
	for(int i=0;i<SIZE;array[i]=rand()%90+10,i++);
	
	printf("array non ordinato :: ");
	for(int i=0;i<SIZE;printf("%d ",array[i]),i++);
	
	selection_sort(array,SIZE);
	
	printf("\narray ordinato :: ");
	for(int i=0;i<SIZE;printf("%d ",array[i]),i++);
}

void selection_sort(int array[],size_t N){
	int i,mi,tmp;
	if(N>1){
		mi=findMinimum(&array[0],N);
		tmp=*(array);
		*(array)=*(array+mi);
		*(array+mi)=tmp;
		selection_sort(&array[1],N-1);
	}
}

int findMinimum(int array[],size_t N){
	if(N==1) return 0;
	else{
		int min=array[0];
		int minp=1+findMinimum(&array[1],N-1);
		if(array[minp]<min) return minp;
		else return 0;
	}
}