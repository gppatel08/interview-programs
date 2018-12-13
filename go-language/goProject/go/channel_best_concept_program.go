
/* NOTE: fatal error: all goroutines are asleep - deadlock! -> 
   For channel communication ther must be atleast TWO go routine(main && one child) */
   
package main

import (
	"fmt"
)

var a chan int  // nil channel 

func trace(st string)   { fmt.Println("Starting function: ", st) }
func untrace(st string) { fmt.Println("Ending function  : ", st) }

func main() {
	trace("main")
	defer untrace("main")
	//a = make(chan int, 0)  // or a = make(chan int) // non-nil channel unbuffered
	a = make(chan int, 5)  // non-nil channel buffered
	
	go func() {
		trace("f")
		f := true
		for {
			// 1. panic: close of nil channel, Means nil chanel must not be close otherwise will be panic
			// 2. panic: close of closed channel, here non-nil channel closed and then next iteration again closeing the closed channel
			if f == true {
				//close(a) 
				f = false
			}
		}
		untrace("f")
	}()

	fmt.Println("Waiting for sender to write on channel for receiving.!")
	var y, ok = 0, false 
	
	/* For Unbuffered channel case */
	//y, ok = <- a  // Waiting for sender!
	//a <- 5  // 1. Waiting for receiver! 2. if channel closed, then panic: send on closed channel
	fmt.Printf("%v with channel result %v\n", y, ok)
	
	/* For buffered channel case */
	for i:=0; i<6; i++ {
		//a <- i  // sending on channel will be blocked once buffer is full(i.e 6th iteration), untill receiver ready to receive
		//fmt.Printf("writing to channel index %v\n", i + 1)
		y, ok = <- a  // receiving from empty channel will be blocked (i.e 1th iteration), untill sender send on channel
		fmt.Printf("reading from channel index %v\n", i + 1)
	}
}
