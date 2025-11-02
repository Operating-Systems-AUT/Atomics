#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h>
#include <stdarg.h>
#include <unistd.h>
#include "cas_semaphore.h"

int counter = 0;

CAS_SEM lock3;
CAS_SEM lock4;

void * cas_sem_worker1 (void * arg) {
    (void)arg;
    for(size_t i = 0 ; i < 1000000; ++i) {
        cas_sem_acquire(&lock3);
        counter++;
        cas_sem_release(&lock3);
    }
    
    return  NULL;
}

void * cas_sem_worker2(void * arg) {
    (void)arg;
    for(size_t i = 0 ; i < 1000000; ++i) {
        cas_sem_acquire(&lock3);
        counter--;
        cas_sem_release(&lock3);
    }
    
    return NULL;
}


void* cas_sem_worker3(void* arg) {
    (void)arg;
    cas_sem_acquire(&lock4);
    printf("tid: %ld going to sleep\n" , pthread_self());
    sleep(2);
    cas_sem_release(&lock4);

    return NULL;
}


void test(const  char * title , int workerc , ...) {
    va_list args;
    va_start(args , workerc);
    pthread_t *t = (pthread_t *)malloc(sizeof(pthread_t) * workerc);
    for(int i = 0 ; i < workerc ; ++i) {
        pthread_create(t + i , NULL , *(va_arg(args , void * (*)(void *))) , NULL);
    }

    for(int i = 0 ; i < workerc ; ++i) {
        pthread_join(*(t + i), NULL);
    }
    
    if(title) printf("%s: %d\n" , title , counter);
}

int main() {
    cas_sem_init(&lock3 , 1 , 1);
    cas_sem_init(&lock4 , 3 , 3);

    test("compare and exchange semaphore counter" , 2 , &cas_sem_worker1 , &cas_sem_worker2);
    test(NULL , 10 , &cas_sem_worker3 , &cas_sem_worker3 ,&cas_sem_worker3 ,&cas_sem_worker3 ,&cas_sem_worker3 , &cas_sem_worker3 ,&cas_sem_worker3 ,&cas_sem_worker3 ,&cas_sem_worker3 ,&cas_sem_worker3);
}