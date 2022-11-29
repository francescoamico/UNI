#include <stdio.h>
#include <string.h>

void main(){
	size_t i=0,j;
	char buf[80];
	char *s;
	float v[80];
	FILE *fp;
	
	fp=fopen("vettore.txt", "r");
	
	while(fgets(buf, 80, fp)!=NULL){
		s=buf;
		for(;*s;s++){
			if(*(s-1)==' ' || s==&buf[0]){
				sscanf(s,"%f",&v[i]);
				i++;
			}
		}
	}
	
	for(j=0;j<i;printf("%f ",v[j]),j++);
	
	fclose(fp);
}
