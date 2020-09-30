#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


void *PrintHello()
{
    printf("Hello World! Kudos You have created a thread \n");
}

int main(int argc, char *argv[])
{
    pthread_t thread_id; 
    int rc = pthread_create(&thread_id, NULL, PrintHello, NULL);
    if(rc)
    {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
    } 
    pthread_exit(NULL);
}