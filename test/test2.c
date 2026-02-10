#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h>
#include <stdarg.h>
#include "cas_spinlock.h"

int counter = 0;


CAS_SPINLOCK lock2;



void * cas_worker1 (void * arg) {
    (void)arg;
    for(size_t i = 0 ; i < 1000000; ++i) {
        cas_lock(&lock2);
        counter++;
        cas_unlock(&lock2);
    }

    return  NULL;
}

void * cas_worker2(void * arg) {
    (void)arg;
    for(size_t i = 0 ; i < 1000000; ++i) {
        cas_lock(&lock2);
        counter--;
        cas_unlock(&lock2);
    }

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
    free(t);
}



void * cas_bad_worker(void * arg) {
    (void)arg;
    for(size_t i = 0 ; i < 1000000; ++i) {
        cas_unlock(&lock2);
    }
    return NULL;
}

int main() {
    cas_init(&lock2);
    test("compare and exchange spinlock counter" , 3 , &cas_worker1 , &cas_worker2 , &cas_bad_worker);
}