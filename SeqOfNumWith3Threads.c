/*
 * Multi-threaded program with 3 threads that prints sequence of numbers
 * 3 threads and prints 0,1,2,3,4,5,.... and so on.
	Thread 1 - prints 0,3,6,9 and so on
	Thread 2 - prints 1,4,7,10 and so on
	Thread 3 - prints 2,5,8,11 and so on

   1. One possible solution involves messages queues. Each thread has a message queue.
	1. Thread 1 writes 0, then sends 0 to message queue_2.
	2. Thread 2 reads value from message queue_2, increments that value and sends new value to message queue_3.
	3. Thread 3 reads value from message queue_3, increments it and then sends new value to message queue_1
	4. From here, you should infer what thread 1 shall do next.
 */

/* Multi-threaded program with 3 threads that prints sequence of numbers using condition variable and mutex. */

#define BEST_SOLUTION_CPP
//#define DOUBT_SOLUTION_CPP

#ifdef BEST_SOLUTION_CPP

#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<unistd.h>
using namespace std;

#define MAX 10

condition_variable cv1, cv2, cv3; 
mutex m1;
int i;
void function1() {
    while (i < MAX) {
        unique_lock<mutex> lock(m1);
        cv1.wait(lock);
        cout << "Thread 1 : " << i << endl;
        i++;
        lock.unlock();
        cv2.notify_one();
    }

}
void function2() {
    while (i < MAX) {
        unique_lock<mutex> lock(m1);
        cv2.wait(lock);
        cout << "Thread 2 : " << i << endl;
        i++;
        lock.unlock();
        cv3.notify_one();
    }
}

void function3() {   
    while (i < MAX) {
        unique_lock<mutex> lock(m1);        
        cv3.wait(lock);
        cout << "Thread 3 : " << i << endl;
        i++;
        lock.unlock();
        cv1.notify_one();
    }
}

int main() {
    thread t3(function3);
    thread t1(function1);
    thread t2(function2);
    cout << "Sleep is introdused Here for until function1() => cv1.wait(lock); execute" << endl;
    sleep(1);
    cv1.notify_one();
    t1.join();
    t2.join();
    t3.join();

    return 0;

}
/*
Sleep is introdused Here for until function1() => cv1.wait(lock); execute                                                        
Thread 1 : 0                                                                                                                     
Thread 2 : 1                                                                                                                     
Thread 3 : 2                                                                                                                     
Thread 1 : 3                                                                                                                     
Thread 2 : 4                                                                                                                     
Thread 3 : 5                                                                                                                     
Thread 1 : 6                                                                                                                     
Thread 2 : 7                                                                                                                     
Thread 3 : 8                                                                                                                     
Thread 1 : 9                                                                                                                     
Thread 2 : 10                                                                                                                    
Thread 3 : 11
*/
#endif


#ifdef DOUBT_SOLUTION_CPP

#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

//Creating 3 condition variable to perform synchronization in 3 different functions using wait and notify function on condition variable
condition_variable cv1, cv2, cv3;
//creating mutex variable to lock and unlock the resource
mutex m1;
void function1() {
    //creating unique_lock on the mutex so that we don't have to take care whether mutex is unlocked or not, as mutex gets unlocked 
    //as soon as unique_lock is out of scope (using concept of RAII)
    unique_lock<mutex> lock(m1);
    for(int i=0; i<10; i+=3) {
        cout<<i<<endl;

        //We notify function2 using notify_one function, once we are done printing values from function one 
	//and makes function1 in wait state by calling wait function
        cv2.notify_one();
        cv1.wait(lock);
    }

}
void function2() {
    unique_lock<mutex> lock(m1);
    for(int i=1; i<10; i+=3) {
        cout<<i<<endl;

        //We notify function3 using notify_one function, once we are done printing values from function2 
	//and makes function2 in wait state by calling wait function
        cv3.notify_one();
        cv2.wait(lock);
    }
}

void function3() {
    unique_lock<mutex> lock(m1);
    for(int i=2; i<10; i+=3) {
        cout<<i<<endl;

       //We notify function1 using notify_one function, once we are done printing values from function3 
       //and makes function3 in wait state by calling wait function
        cv1.notify_one();
        cv3.wait(lock);
    }
}

int main() {
    //creating 3 threads (t1, t2 & t3) and associating functions with each thread
    thread t1(function1);
    thread t2(function2);
    thread t3(function3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

#endif
