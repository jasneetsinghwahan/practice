#include <pthread.h>
#include <stdio.h>
void *thread(void *vargp)
{
    pthread_exit((void*)42);
}
void print_message_function( void *ptr )
{
   char *message;
   message = (char *) ptr;
   printf("%s ", message);
}

int main()
{
    int i;
    pthread_t tid;
    pthread_create(&tid, NULL, thread, NULL);
    pthread_join(tid, (void **)&i);
    printf("%d\n",i);

    pthread_t thread1, thread2;
    char *message1 = "Hello";
    char *message2 = "World";
    
    pthread_create( &thread1, NULL,
                   (void*)&print_message_function, (void*) message1);
    pthread_create(&thread2, NULL, 
                   (void*)&print_message_function, (void*) message2);
    exit(0);
}
