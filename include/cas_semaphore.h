#ifndef CAS_SEMAPHORE_H
#define CAS_SEMAPHORE_H

#include <stdatomic.h>

typedef struct { // semaphore struct 
    atomic_int count;
    int capacity;
} CAS_SEM;

void cas_sem_init(CAS_SEM * s , int start , int cap);  // function to initialize the semaphore
int cas_sem_try_acquire(CAS_SEM *s);                   // function to try acquiring the semaphore. does not block
void cas_sem_acquire(CAS_SEM *s);                      // function to acquire the semaphore . blocks
int cas_sem_release(CAS_SEM *s);                       // function to release the semaphore (adding to the count)

#endif