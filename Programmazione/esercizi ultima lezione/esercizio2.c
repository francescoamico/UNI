#include <stdio.h>
#include <stdbool.h>
bool verifica(size_t a,size_t b,size_t c){
	return (a<b+c)&(b<a+c)&(c<a+b);
}
int tipo(size_t a,size_t b,size_t c){
	if(a==b && b==c)
		return 1;
	else{
		if(a==b || a==c || b==c)
			return 2;
		else
			return 3;
	}
}
void main(){
	
	size_t a=8,b=8,c=6;
	if(verifica(a,b,c))
		printf("1)equilatero\n2)iscoscele\n3)scaleno\n\na b c formano un triangolo di tipo :: %d",tipo(a,b,c));
	else
		printf("a b c non formano un triangolo");
}