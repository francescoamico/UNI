#include <stdio.h>
#include <stdlib.h>
void trasforma(char s[]);

void main(){
	
	char *s=(char *)malloc(12*sizeof(char));
	printf("Inserire stringa :: ");
	gets(s);
	trasforma(s);
	printf("Stringa trasformata = %s",s);
}

void trasforma(char *s){
	unsigned int i;
	for(i=0;s[i];i++)
		s[i] -= ((s[i]>='a')&(s[i]<='z'))*('a'-'A'); //('a'-'A')=32 ==> offset tra lettera maiuscola e minucola in ASCII
}