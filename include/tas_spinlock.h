#ifndef TAS_SPINLOCK_H
#define TAS_SPINLOCK_H

#include <stdatomic.h>
#include <stdint.h>
#include <pthread.h>


typedef struct {
    atomic_flag lock;
    uintptr_t owner;
} TAS_SPINLOCK;

void tas_init(TAS_SPINLOCK * spinlock);         // function to initialize the spinlock
void tas_lock(TAS_SPINLOCK * spinlock);         // function to get the lock. blocks
int tas_trylock(TAS_SPINLOCK * spinlock);       // function to try getting the lock. does not block
int tas_unlock(TAS_SPINLOCK *spinlock);         // function to release the lock.

#endif
