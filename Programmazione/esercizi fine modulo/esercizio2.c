#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void add(char **s,int n);
void max(char **s,int n);
void min(char **s,int n);
void delete(char **s,int n);
void search(char **s,int n);
void pos(char **s,int n);

void main(){
	size_t i,n,x=0;
	printf("\nQuante stringhe desidera inserire? ");
	scanf("%d",&n);
	assert(n>0);
	
	char **s = (char **)malloc(n*sizeof(char *));
	for(i=0;i<n;i++){
		s[i]=(char *)malloc(20*sizeof(char));
		printf("Inserire stringa %d :: ",i+1);
		scanf("%s",s[i]);
	}
	
	printf("\nPremere\n\n1)Aggiungere stringa\n");
	printf("2)Stringa di lunghezza maggiore\n");
	printf("3)Stringa di lunghezza minore\n");
	printf("4)Cancella stringa\n");
	printf("5)Ricerca stringa\n");
	printf("6)Stringa che contiene la parola...\n");
	printf("7)Esci\n");
	scanf("%d",&x);
	assert(x>=1 && x<=7);
	
	switch(x){
		case 1:
			add(s,n+1);
			break;
		case 2:
			max(s,n);
			break;
		case 3:
			min(s,n);
			break;
		case 4:
			delete(s,n);
			break;
		case 5:
			search(s,n);
			break;
		case 6:
			pos(s,n);
			break;
		case 7:
			break;
	}
	
	free(s);
}

void add(char **s,int n){
	size_t i;
	s=(char **)realloc(s,n*sizeof(char *));
	s[n-1]=(char *)malloc(20*sizeof(char));
	printf("Inserire stringa :: ");
	scanf("%s",s[n-1]);
	printf("Stringhe aggiornate :: ");
	for(i=0;i<n;i++)
		printf("%s ",s[i]);
}

void max(char **s,int n){
	size_t i;
	char *max=s[0];
	for(i=1;i<n;i++)
		max = strlen(s[i])>strlen(max) ? s[i]:max;
	printf("Stringa di lunghezza maggiore :: %s ",max);
}	

void min(char **s,int n){
	size_t i;
	char *min=s[0];
	for(i=1;i<n;i++)
		min = strlen(s[i])<strlen(min) ? s[i]:min;
	printf("Stringa di lunghezza minore :: %s ",min);
}	

void delete(char **s,int n){
	size_t i,j;
	char *del=(char *)malloc(20*sizeof(char));
	printf("Quale stringa desidera cancellare? ");
	scanf("%s",del);
	
	for(i=0;i<n;i++){
		if(!strcmp(s[i],del)){
			for(j=i;j<n;j++)
				s[j]=s[j+1];
			n=n-1;
			s=(char **)realloc(s,n*sizeof(char *));	
		}
	}
	printf("Stringhe aggiornate :: ");
	for(i=0;i<n;i++)
		printf("%s ",s[i]);
}

void search(char **s,int n){
	size_t i;
	char *search=(char *)malloc(20*sizeof(char));
	printf("Quale stringa desidera cercare? ");
	scanf("%s",search);	
	for(i=0;i<n;i++){
		if(!strcmp(s[i],search))
			printf("Stringa trovata in posizione %d\n",i+1);
	}
}

void pos(char **s,int n){
	size_t i;
	char *p=(char *)malloc(20*sizeof(char));
	printf("Parola :: ");
	scanf("%s",p);
	for(i=0;i<n;i++){
		if(strstr(s[i],p))
			printf("Stringa %d\n",i+1);
	}	
}