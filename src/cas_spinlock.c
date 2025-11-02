#include "cas_spinlock.h"


// gets the owner of the calling thread 
static uintptr_t get_owner(void) {
    // to do: identify the owner of the calling thread 
}

void cas_init(CAS_SPINLOCK *spinlock) {
    // todo: initializing the spinlock
}

void cas_lock(CAS_SPINLOCK *spinlock) {
    // todo: getting the lock ( blocks )
}


int cas_trylock(CAS_SPINLOCK *spinlock)  {
    // todo: try getting the lock ( does not block ) 
}



int cas_unlock(CAS_SPINLOCK *spinlock){ 
    // todo: releasing the lock
}
