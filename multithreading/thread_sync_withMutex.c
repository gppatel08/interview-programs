/*
Mutexes-:
---------
  Now since we have understood the base problem, lets discuss the solution to it. 
  The most popular way of achieving thread synchronization is by using Mutexes.

  A Mutex is a lock that we set before using a shared resource and release after using it. 
  When the lock is set, no other thread can access the locked region of code. So we see that even 
  if thread 2 is scheduled while thread 1 was not done accessing the shared resource and the code 
  is locked by thread 1 using mutexes then thread 2 cannot even access that region of code. 
  So this ensures a synchronized access of shared resources in the code.

Internally it works as follows :
--------------------------------
  1. Suppose one thread has locked a region of code using mutex and is executing that piece of code
  2. Now if scheduler decides to do a context switch, then all the other threads which are ready to
     execute the same region are unblocked.
  3. Only one of all the threads would make it to the execution but if this thread tries to execute 
     the same region of code that is already locked then it will again go to sleep.
  4. Context switch will take place again and again but no thread would be able to execute the 
     locked region of code until the mutex lock over it is released.
  5. Mutex lock will only be released by the thread who locked it.
  6. So this ensures that once a thread has locked a piece of code then no other thread can execute      the same region until it is unlocked by the thread who locked it.
  7. Hence, this system ensures synchronization among the threads while working on shared resources.

A mutex is initialized and then a lock is achieved by calling the following two functions :

  int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
  int pthread_mutex_lock(pthread_mutex_t *mutex);

  The first function initializes a mutex and through second function any critical region 
  in the code can be locked.


The mutex can be unlocked and destroyed by calling following functions :

  int pthread_mutex_unlock(pthread_mutex_t *mutex);
  int pthread_mutex_destroy(pthread_mutex_t *mutex);

  The first function above releases the lock and the second function destroys the lock so that 
  it cannot be used anywhere in future.
*/

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void* doSomeThing(void *arg)
{
    pthread_mutex_lock(&lock);

    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d started\n", counter);

    for(i=0; i<(0xFFFFFFFF);i++);

    printf("\n Job %d finished\n", counter);

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(void)
{
    int i = 0;
    int err;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

    while(i < 2)
    {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}

/*
In the code above :

  1. A mutex is initialized in the beginning of the main function.
  2. The same mutex is locked in the ‘doSomeThing()’ function while using the shared 
     resource ‘counter’
  3. At the end of the function ‘doSomeThing()’ the same mutex is unlocked.
  4. At the end of the main function when both the threads are done, the mutex is destroyed.

$ g++ thread_sync_withMutex.c -o m -lpthread
$ ./m
 Job 1 started
 Job 1 finished
 Job 2 started
 Job 2 finished
*/
