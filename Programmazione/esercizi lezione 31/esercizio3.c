#include <stdio.h>

unsigned char converti(char s[], unsigned int *pn);

void main(){
	int n=0;
	char s[]="565";
	converti(s,&n) ?  printf("\nLa stringa %s corrisponde al decimale %d\n",s,n):printf("\n%s non e' una stringa numerica\n",s);
}

unsigned char converti(char s[], unsigned int *pn){
	unsigned int i;
	for(i=0;s[i]&&(s[i]>='0'&&s[i]<='9');i++)
		*pn = (*pn*10)+(s[i]-'0');
	return (!s[i]);
}