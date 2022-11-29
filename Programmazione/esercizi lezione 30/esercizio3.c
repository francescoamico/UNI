#include <stdio.h>

unsigned int occorrenze(char s[],char c);

void main(){
	char s[]="HelLo WorLD";
	char c = 'L';
	printf("Occorrenze di %c :: %d", c,occorrenze(s,c));
}

unsigned int occorrenze(char s[],char c){
	unsigned int i,j=0;
	for(i=0;s[i];i++)
		j += (s[i]==c);
	return (j);	
}