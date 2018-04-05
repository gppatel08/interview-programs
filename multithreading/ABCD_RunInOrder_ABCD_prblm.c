/*
Comments w.r.t Problem:
-----------------------
 1. You have no control over which of the threads will run first. You need to figure out some 
    other way to synchronize the threads. Condition variables maybe? Or multiple mutexes if it's a 
    requirement to use those?
 2. If you wish for your processes to run "in order", you have no need for threads or mutexes. 
    A mutex is used to prevent multiple threads from writing to the same location, nothing else.
 3. Either use conditional variable or shared handler to synchronize the all threads.
 4. Semaphores are only an optional feature in POSIX and in C's thread option they aren't present 
    at all. Use a condition variable, instead. (Also POSIX semaphores are quite tricky to handle 
    correctly because their functions are interruptible.).  
    Using pthread_cond_wait respectively cnd_wait, obviously.

*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* processA(void *args);
void* processB(void *args);
void* processC(void *args);
void* processD(void *args);

pthread_mutex_t mutex;

int main(){
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;

    pthread_mutex_init(&mutex,NULL);

    pthread_create(&thread1, NULL, &processA, NULL);
    pthread_create(&thread2, NULL, &processB, NULL);
    pthread_create(&thread3, NULL, &processC, NULL);
    pthread_create(&thread4, NULL, &processD, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);            

    pthread_mutex_destroy(&mutex);
}

void* processA(void *args)
{
    while (1)
    {
        sleep(1);
        pthread_mutex_lock(&mutex);
        printf("A \n");
        pthread_mutex_unlock(&mutex);
    }
}

void* processB(void *args)
{
    while (1)
    {
        sleep(1);
        pthread_mutex_lock(&mutex);
        printf("B \n");
        pthread_mutex_unlock(&mutex);
    }
}

void* processC(void *args)
{
    while (1)
    {
        sleep(1);
        pthread_mutex_lock(&mutex);
        printf("C \n");
        pthread_mutex_unlock(&mutex);
    }
}

void* processD(void *args)
{
    while (1)
    {
        sleep(1);
        pthread_mutex_lock(&mutex);
        printf("D \n");
        pthread_mutex_unlock(&mutex);
    }
}

/*
Solution suggested:
 1. mutex is for creating mutual exclusion on some context. 
    For example if you have an object that should be reached by one thread at a time, 
    you can use mutex.

    You should use 3 semaphores for implementing such feature. You can say:

    //semaphore1 = up, semaphore2 = up, semaphore3 = up
    //Thread A
        //wait for semaphore1 is up
           //work
        //make semaphore1 down
    //Thread B
        //wait for semaphore1 is down
           //work
        //make semaphore2 down    
    //Thread C
        //wait for semaphore2 is down
           //work
        //make semaphore3 down    
    //Thread D
        //wait for semaphore3 is down
           //work

 2. Semaphores are only an optional feature in POSIX and in C's thread option they aren't present 
    at all. Use a condition variable, instead. (Also POSIX semaphores are quite tricky to handle 
    correctly because their functions are interruptible.).  
    Using pthread_cond_wait respectively cnd_wait, obviously.
*/
