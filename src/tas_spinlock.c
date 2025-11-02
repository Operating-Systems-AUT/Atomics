#include "tas_spinlock.h"


// gets the owner of the calling thread 
static uintptr_t get_owner(void) {
    // to do: identify the owner of the calling thread 
}

void tas_init(TAS_SPINLOCK * spinlock) {
    // todo: initializing the spinlock
}


void tas_lock(TAS_SPINLOCK * spinlock) {         
    // todo: getting the lock. ( blocks )

}

 
int tas_trylock(TAS_SPINLOCK * spinlock) {
    // to do: try getting the lock ( does not block )
}


int tas_unlock(TAS_SPINLOCK *spinlock) {
    // to do: releasing the lock. 
}