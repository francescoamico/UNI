#include <stdio.h>
unsigned int mystrlen(char s[]);
void copiastringa(char s[],char t[]);
void main(){
	
	char s[20];
	
	printf("Inserire stringa s :: ");
	gets(s); //aggiunge il marcatore di fine stringa in automatico
	char t[mystrlen(s)+1];
	copiastringa(s,t);
	printf("Stringa t = %s",t);


}

void copiastringa(char s[],char t[]){
	int i;
	for(i=0;s[i];t[i]=s[i],i++);
	t[i]=s[i]; //aggiungo il marcatore di fine stringa(t[i]=0)
}
unsigned int mystrlen(char s[]){
	unsigned int i=0;
	while(s[i])
		i++;
	return (i);
}
