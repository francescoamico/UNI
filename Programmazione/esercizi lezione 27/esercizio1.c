#include <stdio.h>
#include <assert.h>

void main(){
	
	int n,i,a,b;
	int pos=0,nul=0,p=0,c=0,d=0;
	
	printf("\nQuanti numeri desidera inserire? ");
	scanf("%d",&n);
	assert(n>=2);
	
	printf("\nInserire n_1 :: ");
	scanf("%d",&a);
	nul += !a;
	pos += a>=1;
	p+=!(a%2);
	for(i=2 ; i<=n ; i++){
		
		b=a;
		printf("Inserire n_%d :: ",i);
		scanf("%d",&a); 
		nul += !a;
		pos += a>=1;
		p+=!(a%2);
		c+=a>=b;
		d+=a<=b;
		
	}

	printf("\nnumeri nulli :: %d",nul);
	printf("\nnumeri positivi :: %d",pos);
	printf("\nnumeri negativi :: %d",n-pos-nul);
	printf("\n\nnumeri pari :: %d",p);
	printf("\nnumeri dispari :: %d",n-p);
	printf("\n\nsequenza ne' crescente ne' decrescente :: %d",(c!=n-1) && (d!=n-1));
	printf("\nsequenza crescente :: %d",c==n-1);
	printf("\nsequenza decrescente :: %d\n",d==n-1);
	
}

