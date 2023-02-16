#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
void main(){
    int n;
    int status;
    if(n=fork() == 0){ /* processo figlio */
        printf("\nSono il figlio = %d",getpid());
        printf("\nQuesto e' mio padre = %d\nAdesso Termino....\n",getppid());
        exit(0); // il processo termina normalmente
    }
    else{ /* processo padre */
        printf("Sono il padre = %d\n",getpid());
        wait(&status); //altrimenti il padre termina prima del figlio che rimarrà orfano
        printf("\nSono di nuovo il padre\nStato figlio terminato = %d\nAdesso termino...\n", status);
        exit(0);
    }
    
}