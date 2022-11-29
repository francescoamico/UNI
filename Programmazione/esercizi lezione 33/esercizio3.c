#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *immettitesto();

void main(){
	printf("Immetti testo :: ");
	char *text = immettitesto();
	printf("Nuovo testo :: %s ",text);
	free(text);
}

char *immettitesto(){
	char *s = (char *) malloc(256*sizeof(char));
	char *t = s;
	while ((*t++=getchar())!='\n');
	*--t=0;
	*strstr(s,"fine.")=0; 
	return(s);
}
