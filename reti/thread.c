#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // per sleep

/*
#define NUM_THREADS 5

void *PrintHello(void *threadid){
    long tid= (long)threadid;
    printf("Hello World! It's me, thread #%ld!\n", tid);
    pthread_exit(NULL); // si può omettere (terminazione implicita)
}

int main (int argc, char *argv[]){
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for(t=0; t<NUM_THREADS; t++){
        printf("In main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
        sleep(1); // affinchè il processo principale aspetti la completa creazione del thread prima di crearne un altro
        if (rc){
            printf("ERROR; code pthread_create()%d\n", rc);
            exit(-1);
        }
    }
    pthread_exit(NULL); // serve a tenere la funzione che ha creato i thread in vita per permettere loro di terminare
}

/* per passare un intero al thread */
#define NUM_THREADS 8
char *messages[NUM_THREADS];
void *PrintHello(void *threadid){
    sleep(1);
    printf("Thread %d: %s\n", *(int *) threadid, messages[*(int *) threadid]); // se usassimo int taskids[] avremmo warning sul cast; sizeof(int) < sizeof(void *)
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    pthread_t threads[NUM_THREADS];
    int *taskids[NUM_THREADS]; // poichè sizeof(int *) = sizeof(void *); no warning durante il casting
    int rc, t;
    messages[0] = "English: Hello World!";
    messages[1] = "French: Bonjour, le monde!";
    messages[2] = "Spanish: Hola al mundo";
    messages[3] = "Klingon: Nuq neH!";
    messages[4] = "German: Guten Tag, Welt!";
    messages[5] = "Russian: Zdravstvytye, mir!";
    messages[6] = "Japan: Sekai e konnichiwa!";
    messages[7] = "Latin: Orbis, te saluto!";
    for(t=0;t<NUM_THREADS;t++){
        taskids[t] = (int *) malloc(sizeof(int));
        *taskids[t] = t;
        printf("Creating thread %d\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *) taskids[t]);
    if(rc){
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);}
    }
    pthread_exit(NULL);
}