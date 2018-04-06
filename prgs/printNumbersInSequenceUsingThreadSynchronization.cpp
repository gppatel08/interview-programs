/*
Print numbers in sequence using thread synchronization:
-------------------------------------------------------
  The problem is to synchronize n number of threads using pthread library. 
  The idea is take thread count and print 1 in first thread, print 2 in second thread, print 3 in third thread,... print n in nth 
  thread and again repeat from thread 1 infinitely.

Example:
  Input  : 5
  Output : 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 ....
*/

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t *cond = NULL;

int threads;
volatile int count = 0;

/* function to syncronize thread */
void* sequenceNumberGenerate(void* arg) {
  /* whose turn is a basically to identify threads */
  int whoseTurn = *(int*)arg;

   while(1) {
     pthread_mutex_lock(&mutex);
     /* cnt is used to determine which thread should enter into critical section(printf statement) */
     if(whoseTurn != count) {
       pthread_cond_wait(&cond[whoseTurn], &mutex);
     }

     /* its time to print whoseTurn can have value starting from 0. Hence +1 */
     cout << (whoseTurn + 1) << " ";

     /* determine which thread need to be scheduled now */
     if(count < threads - 1)
       count++;
     else
       count = 0;

     /* wake up next thread */
     pthread_cond_signal(&cond[count]);
     pthread_mutex_unlock(&mutex);
   }

   return NULL;
}

int main() {
  pthread_t* tid;
  volatile int i;
  int *arr;

  cout << "Enter the number of THreads: " ;
  cin >> threads;

  /* allocate memory to cond(conditional variable), thread id's and array of size threads */
  cond = (pthread_cond_t*) malloc(sizeof(pthread_cond_t) * threads);
  tid = (pthread_t*) malloc(sizeof(pthread_t) * threads);
  arr = (int*) malloc(sizeof(int) * threads);

  /* create threads */
  for(i = 0; i < threads; i++) {
    arr[i] = i;
    pthread_create(&tid[i], NULL, sequenceNumberGenerate, (void*)&arr[i]);
  }

  /* waiting for thread */
  for(i = 0; i < threads; i++) {
    pthread_join(tid[i], NULL);
  }


  return 0;
}
