#include <stdio.h>
#include <assert.h>

void main(){
	
	float n1,n2;
	char op;
	char *ins;
	
	printf("Inserire operazione ::");
	scanf("%s",ins);
	
	sscanf(ins,"%f",&n1);
	
	for(;*ins;ins++){
		if(*ins=='+' || *ins=='-' || *ins=='*' || *ins=='/'){
			op=*ins;
			sscanf(ins+1,"%f",&n2);
		}
	}
	
	switch(op){
		case '+':
			printf("\n%f %c %f = %f",n1,op,n2,n1+n2);
			break;
		case '-':
			printf("\n%f %c %f = %f",n1,op,n2,n1-n2);
			break;
		case '*':
			printf("\n%f %c %f = %f",n1,op,n2,n1*n2);
			break;
		case '/':
			assert(n2!=0);
			printf("\n%f %c %f = %f",n1,op,n2,n1/n2);
			break;
		default:
			printf("Inserimento errato");
			break;
	}
}