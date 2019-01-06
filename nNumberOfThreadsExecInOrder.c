/*
N number of Threads Print inOrder:
---------------------------------- 
You cannot make threads to run in order with only a mutex because they go in execution in an unpredictable order. 
In my approach I use a condition variable and a shared integer variable to create a queueing system. 
Each thread takes a number and when the current_n number is equal to the one of the actual thread, 
it enters the critical section and prints its number.
*/
#include <pthread.h>
#include <stdio.h>
#define N_THREAD 7

int current_n = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t number = PTHREAD_COND_INITIALIZER;

void *text (void *arg) {
   int i = (int)arg;
   pthread_mutex_lock(&mutex);
   while ( i > current_n ) {
      pthread_cond_wait(&number, &mutex);
   }

   //i = current_n at this point
   /*I use stderr because is not buffered and the output will be printed immediately.
     Alternatively you can use printf and then fflush(stdout). */
   fprintf(stderr, "I'm thread n=%d\n", i);
   current_n ++;

   pthread_cond_broadcast(&number);
   pthread_mutex_unlock(&mutex);
   return (void*)0;
}

int main() {
   pthread_t tid[N_THREAD];
   int i = 0;
   for(i = 0; i < N_THREAD; i++) {
      pthread_create(&tid[i], NULL, text, (void *)i);
   }

   for(i = 0; i < N_THREAD; i++) {
      if(pthread_join(tid[i], NULL)) {
        fprintf(stderr, "A thread failed to join\n");
      }
   }
   return 0;
}
/*
I'm thread n=0                                                                                                          
I'm thread n=1                                                                                                          
I'm thread n=2                                                                                                          I'm thread n=3                                                                                                          
I'm thread n=4                                                                                                          I'm thread n=5                                                                                                          I'm thread n=6
*/
