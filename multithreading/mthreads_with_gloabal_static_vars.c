/* A C program to show multiple threads with global and static variables
   As mentioned, all threads share data segment. 
   Global and static variables are stored in data segment. 
   Therefore, they are shared by all threads. 

   The following example program demonstrates the same. */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
// Let us create a global variable to change it in threads
int g = 0;
 
// The function to be executed by all threads
void *myThreadFun(void *vargp)
{
    // Store the value argument passed to this thread
    int *myid = (int *)vargp;
 
    // Let us create a static variable to observe its changes
    static int s = 0;
 
    // Change static and global variables
    ++s; ++g;
 
    // Print the argument, static and global variables
    printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g);
}
 
int main()
{
    int i;
    pthread_t tid;
 
    // Let us create three threads
    for (i = 0; i < 3; i++)
        pthread_create(&tid, NULL, myThreadFun, (void *)&i);
 
    pthread_exit(NULL);
    return 0;
}

/*
$ g++ mthreads_with_gloabal_static_vars.c -o m -lpthread
$ ./m
Thread ID: 3, Static: 4, Global: 4
Thread ID: 3, Static: 2, Global: 2
Thread ID: 3, Static: 6, Global: 6

  Please note that above is simple example to show how threads work. 
  
  Accessing a global variable in a thread is generally a bad idea. What if thread 2 has priority 
  over thread 1 and thread 1 needs to change the variable. 

  In practice, if it is required to access global variable by multiple threads, then they should 
  be accessed using a mutex.
*/
