#include "sbuf.h"
#include "prod_cons_amd.h"
#include <pthread.h>
#include <stdio.h>

sem_t producedindicator, consumedindicator; 
void * producer(void * arg)
{
    int i;
    int count = (int) arg;

    for (i = 0; i < count; i++) {
        P(&consumedindicator);
	    printf("producer: %d\n", i);
        V(&producedindicator);
    }
    return(NULL);
}
void * consumer(void * arg)
{
    int i;
    int count = (int) arg;

    for (i = 0; i < count; i++) {
        P(&producedindicator);
	    printf("consumer: %d\n", i);
        V(&consumedindicator);
    }
    return(NULL);
}

int main(void){
    int N  = 8;
    pthread_t producerthread, consumerthread;
    Sem_init(&producedindicator, 0, 0);
    Sem_init(&consumedindicator, 0, 1);
    Pthread_create(&producerthread, NULL, producer, (void *) N);
    Pthread_create(&consumerthread, NULL, consumer, (void *) N);
    pthread_join(producerthread, NULL);
    pthread_join(consumerthread, NULL);
    exit(0);
}