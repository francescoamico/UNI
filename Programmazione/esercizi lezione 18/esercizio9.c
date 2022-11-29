#include <stdio.h>
void main(){
	
    float n=0,m=0;
	int i=0;
	
	while(n != -1){
		
		printf("Inserire numero :: ");
		scanf("%f",&n);
		m += n;
		i++;
	}
	if(m==-1) 
		printf("\nMedia :: 0");
	else
		printf("\nMedia :: %f", ++m/--i);
}