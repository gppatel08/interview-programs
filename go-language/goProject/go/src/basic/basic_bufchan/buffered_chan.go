/*
Buffered Channels:
------------------
Channels can be buffered. Provide the buffer length as the second argument to make to initialize a buffered channel:
	ch := make(chan int, 100)
Sends to a buffered channel block only when the buffer is full. Receives block when the buffer is empty.

Modify the example to overfill the buffer and see what happens.
*/

package main

import "fmt"

func main() {
	ch := make(chan int, 2)
	ch <- 1
	ch <- 2
	// adding below line, program crash: fatal error: all goroutines are asleep - deadlock! goroutine 1 [chan send]:
	//ch <- 3
	fmt.Println(<-ch)
	fmt.Println(<-ch)
	// after printing 1 2,  adding below line, program crash: fatal error: all goroutines are asleep - deadlock! goroutine 1 [chan receive]:
	//fmt.Println(<-ch)
}