/* Producer Consumer through GO Buffered Channel 
   [ Write<-Fast but Read->Slow ] -> To check buffer full scenario @Some Point (Make read sleep more then write)
   [ Write<-Slow but Read->Fast ] -> To check buffer empty scenario @Some Point (Make write sleep more then read)
*/
   
package main
import (
	"fmt"
	"time"
)

var ch chan int
var c chan int

func write() {
    i := 1
	for {
	    if i > 30 {
		   /* if we comment below close(ch) channel line then read() go routine will be in blocking state as soon as(once read ALL) ch buffer becomes empy.
		      Hence  main() goroutine will ALSO will be in blocking state as chan receive c is waiting for channel c send from read() after loop 
			  fatal error: all goroutines are asleep - deadlock!
				goroutine 1 [chan receive]:
				main.main()
					E:/goProject/go/chan_com.go:44 +0x115

				goroutine 20 [chan receive]:
				main.read()
					E:/goProject/go/chan_com.go:31 +0xda
          */
		   //close(ch) 
		   fmt.Println("Channel Closed.!")
		   break;
		}
		ch <- i
		fmt.Println("  Writing Data on Channel: ", i)
		time.Sleep(time.Second)
		i++
	}
}

func read() {
	for i := range ch {
		fmt.Println("Read Data from Channel:    ", i)
		time.Sleep(time.Second * 2)
	}
	c <- 0
}

func main() {
    fmt.Println("Start Main.!")
    c = make(chan int)
    ch = make(chan int, 10)
	go write()
	go read()
	<- c
	fmt.Println("Reading finished from Channel.!")
	fmt.Println("Exiting Main.")	
}