/* The following program prints the current time each second and then exits after ten seconds. */
package main
import (
	"fmt"
	"time"
)

func main() {
    stop := time.After(10 * time.Second)
    tick := time.NewTicker(1 * time.Second)
    defer tick.Stop()
    for {
        select {
        case <-tick.C:
            fmt.Println(time.Now())
        case <-stop:
            return
        }
    }
}