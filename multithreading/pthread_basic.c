/* A simple C program to demonstrate use of pthread basic functions
Please note that the below program may compile only with C compilers with pthread library. 

  In main() we declare a variable called thread_id, which is of type pthread_t, which is an integer
  used to identify the thread in the system. After declaring thread_id, we call pthread_create() 
  function to create a thread. pthread_create() takes 4 arguments.

        pthread_create(&tid, NULL, myThreadFun, NULL);

        The first argument is a pointer to thread_id which is set by this function.
        The third argument is name of function to be executed for the thread to be created.
        The fourth argument is used to pass arguments to thread.

  The pthread_join() function for threads is the equivalent of wait() for processes. 
  A call to pthread_join blocks the calling thread until the thread with identifier equal to the 
  first argument terminates.

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
 
// A normal C function that is executed as a thread 
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
    sleep(1);
    printf("Printing GuruPrasad from Thread \n");
    return NULL;
}
  
int main()
{
    pthread_t tid;
    printf("Before Thread\n");
    pthread_create(&tid, NULL, myThreadFun, NULL);
    pthread_join(tid, NULL);
    printf("After Thread\n");
    exit(0);
}

/*
Note: If we dont give the flag -lpthread which add the thread libabry while compiling, compiler
      throws below error.

$ g++ pthread_basic.c -o m 
/tmp/ccCTPJH1.o: In function `main':
pthread_basic.c:(.text+0x5f): undefined reference to `pthread_create'
pthread_basic.c:(.text+0x70): undefined reference to `pthread_join'
collect2: error: ld returned 1 exit status

$ g++ pthread_basic.c -o m -lpthread // valid way of compilation
*/
