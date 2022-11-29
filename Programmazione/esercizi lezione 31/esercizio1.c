#include <stdio.h>

unsigned char lessicografico(char s[],char t[]);

void main(){
	char s[]="casale";
	char t[]="casa";
	printf("0)%s > %s\n1)%s < %s\n%d", s,t,s,t,lessicografico(s,t));
}

unsigned char lessicografico(char s[],char t[]){
	unsigned int i;
	for(i=0;(s[i]&&t[i])&&(s[i]==t[i]);i++);
	return (s[i]<t[i]);
}