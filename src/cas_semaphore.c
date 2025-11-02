#include <cas_semaphore.h>
#include <stdio.h> 

void cas_sem_init(CAS_SEM * s , int start , int cap) {
    // todo: initializing the semaphore
}

int cas_sem_try_acquire(CAS_SEM *s) {
    // todo: try getting the semaphore ( does not block )
} 


void cas_sem_acquire(CAS_SEM *s) {
    // todo; getting the semaphore ( blocks ) 
} 

int cas_sem_release(CAS_SEM *s) {
    // to do: releasing the semaphore
}