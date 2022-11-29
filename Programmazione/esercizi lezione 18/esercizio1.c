#include <stdio.h>
void main(){
	
	int n,m,i;
	
	printf("Inserire numero :: ");
	scanf("%d",&m);
	
	i=0;
	n=m;
	
	while(n){
		n = n>>1;
		i += 1;
	}
	
	printf("\nNumero bit necessari per rappresentare %d in binario :: %d", m,i);
	
	
}