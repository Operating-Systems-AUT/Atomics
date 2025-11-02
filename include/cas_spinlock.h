#ifndef CAS_SPINLOCK_H
#define CAS_SPINLOCK_H

#include <stdatomic.h>
#include <pthread.h>
#include <stdint.h>

typedef struct { // spinlock struct 
    atomic_int lock;
    atomic_uintptr_t owner;
} CAS_SPINLOCK;


void cas_init(CAS_SPINLOCK *spinlock);      // function to initialize the spinlock
void cas_lock(CAS_SPINLOCK *spinlock);      // function to get the lock. blocks
int cas_trylock(CAS_SPINLOCK *spinlock);    // function to try getting the lock. does not block
int cas_unlock(CAS_SPINLOCK *spinlock);     // function to release the lock.



#endif