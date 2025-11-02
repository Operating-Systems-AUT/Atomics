#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h>
#include <stdarg.h>
#include "tas_spinlock.h"


int counter = 0;

TAS_SPINLOCK lock1;


void * tas_worker1 (void * arg) {
    (void)arg;
    for(size_t i = 0 ; i < 1000000; ++i) {
        tas_lock(&lock1);
        counter++;
        tas_unlock(&lock1);
    }

    return  NULL;
}

void * tas_worker2(void * arg) {
    (void)arg;
    for(size_t i = 0 ; i < 1000000; ++i) {
        tas_lock(&lock1);
        counter--;
        tas_unlock(&lock1);
    }

    return NULL;
}

void * tas_bad_worker(void * arg) {
    (void)arg;
    for(size_t i = 0 ; i < 1000000; ++i) {
        tas_unlock(&lock1);
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
}

int main () {
    tas_init(&lock1);
    test("test and set spinlock counter" , 3 , &tas_worker1 , &tas_worker2 , &tas_bad_worker);
}