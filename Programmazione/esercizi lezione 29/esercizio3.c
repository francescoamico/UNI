#include <stdio.h>
#define N 20
unsigned int mystrlen(char s[]);
void copiastringa2(char s[], char t[]);
void main(){
	
	char s[N];
	
	printf("Inserire stringa s :: ");
	gets(s); //aggiunge il marcatore di fine stringa in automatico
	char t[(2*mystrlen(s))+1];
	copiastringa2(s,t);
	printf("Stringa t = %s",t);
}

void copiastringa2(char s[],char t[]){
	unsigned int i;
	for(i=0;s[i];i++){
		t[i<<1]=s[i];
		t[(i<<1)+1]=s[i];
	}
	t[i<<1]=0; //aggiungo il marcatore di fine stringa
}
unsigned int mystrlen(char s[]){
	unsigned int i=0;
	while(s[i])
		i++;
	return (i);
}