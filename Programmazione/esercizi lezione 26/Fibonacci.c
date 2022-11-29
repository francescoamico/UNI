#include <stdio.h>
#include <assert.h>
int fib(int n);
void main(){
	int n,i;
	printf("Inserire n ::");
	scanf("%d",&n);
	
	assert(n>=1);
	
	for(i=1;i<=n;printf("%d ",fib(i)),i++);
}

int fib(int n){
	
	int fn1=1,fn2=1,fn3=1,i;
	for(i=1;i<n-1;i++){
		fn3=fn1+fn2;
		fn1=fn2;
		fn2=fn3;
	}
	return fn3;
}