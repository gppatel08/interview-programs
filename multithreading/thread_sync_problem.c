#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];
int counter;

void* doSomeThing(void *arg)
{
    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d started\n", counter);

    for(i=0; i<(0xFFFFFFFF);i++);

    printf("\n Job %d finished\n", counter);

    return NULL;
}

int main(void)
{
    int i = 0;
    int err;

    while(i < 2)
    {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    return 0;
}

/*
  The above code is a simple one in which two threads(jobs) are created and in the start function 
  of these threads, a counter is maintained through which user gets the logs about job number 
  which is started and when it is completed. The code and the flow looks fine but when we see the 
  output :

$ g++ thread_sync_problem.c -o m -lpthread
$ ./m
 Job 1 started
 Job 2 started
 Job 2 finished
 Job 2 finished

  If you focus on the last two logs, you will see that the log ‘Job 2 finished’ is repeated twice 
  while no log for ‘Job 1 finished’ is seen.

  Now, if you go back at the code and try to find any logical flaw, you’ll probably not find any 
  flaw easily. But if you’ll have a closer look and visualize  the execution of the code, 
  you’ll find that :

  1. The log ‘Job 2 started’ is printed just after ‘Job 1 Started’  so it can easily be concluded 
     that while thread 1 was processing the scheduler scheduled the thread 2.
  2. If the above assumption was true then the value of the ‘counter’ variable got incremented 
     again before job 1 got finished.
  3. So, when Job 1 actually got finished, then the wrong value of counter produced the log 
     ‘Job 2 finished’ followed by the ‘Job 2 finished’ for the actual job 2 or vice versa as 
     it is dependent on scheduler.
  4. So we see that its not the repetitive log but the wrong value of the ‘counter’ variable 
     that is the problem.

  The actual problem was the usage of the variable ‘counter’ by second thread when the first thread
  was using or about to use it. In other words we can say that lack of synchronization between the 
  threads while using the shared resource ‘counter’ caused the problems or in one word we can say 
  that this problem happened due to ‘Synchronization problem’ between two threads.

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
