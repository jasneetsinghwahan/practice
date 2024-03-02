#include "sbuf.h"
#include "prod_cons_amd.h"
#include <pthread.h>
#include <stdio.h>

void * producer(void * arg)
{
    int i;
    int count = (int) arg;

    for (i = 0; i < count; i++) {
	    printf("producer naive: %d\n", i);
    }
    return(NULL);
}
void * consumer(void * arg)
{
    int i;
    int count = (int) arg;

    for (i = 0; i < count; i++) {
	    printf("consumer naive: %d\n", i);
    }
    return(NULL);
}

int main(void){
    int N  = 16;
    pthread_t producerthread, consumerthread;
    Pthread_create(&producerthread, NULL, producer, (void *) N);
    Pthread_create(&consumerthread, NULL, consumer, (void *) N);
    pthread_join(producerthread, NULL);
    pthread_join(consumerthread, NULL);
    exit(0);
}