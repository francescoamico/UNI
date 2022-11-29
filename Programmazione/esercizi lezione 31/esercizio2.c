#include <stdio.h>

unsigned char stringanumero(char s[]);

void main(){
	char s[]="12345A";
	printf("Stringa numero = %d", stringanumero(s));
}

unsigned char stringanumero(char s[]){
	unsigned int i;
	for(i=0;s[i]&(s[i]>='0')&(s[i]<='9');i++);
	return (!s[i]);
}