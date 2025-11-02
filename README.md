# Atomic Variables assignment Answer 

Assignment: implementing spinlock and semaphore using atomic operations 

## How It's Made:
**Tech Used:** C , make
<br />
<br />


## What's left:

There is uncertainty whether the thrid test would run correctly on MacOs. if not we'll need a replacment for `pthread_self()` on macOS. We can also implement some sort of benchmarking tools for the students to test the locks and semaphores implemented in that regard. 

## How to run:
This is based on make.
to run each test separately:
```
make run_test1
make run_test2
make run_test3
```

and for running them all in order: 
```
make check
```

and to remove the `.o` and executable files
```
make clean
```
