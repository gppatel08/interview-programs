/*
Packages:-
----------
Every Go program is made up of packages.
Programs start running in package main.
This program is using the packages with import paths "fmt" and "math/rand".
By convention, the package name is the same as the last element of the import path. 
For instance, the "math/rand" package comprises files that begin with the statement package rand.

Note: The environment in which these programs are executed is deterministic, so each time you run the example program rand.Intn will return the same number. 
(To see a different number, seed the number generator; see rand.Seed.)

As for all pseudo-random libraries, you have to set the seed only once, 
for example when initializing your program unless you specifically need to reproduce a given sequence
After that you simply call Intn to get the next random integer.
You can also add rand.Seed(...) to the function init(). init() is called automatically before main(). Note that you don't need to call init() from main()

Imports:-
---------
This code groups the imports into a parenthesized, "factored" import statement.
You can also write multiple import statements, like:
	import "fmt"
	import "math"
But it is good style to use the "factored import statement."
*/

package main
import (
	"fmt"
	"math/rand"
	"time"
)

/*//CASE_I_START
func init() {
	rand.Seed(time.Now().UTC().UnixNano())
	fmt.Println("Random Seeding done in init function.")
}

func main() {
	fmt.Println("My favorite number is", rand.Intn(10))
}
//CASE_I_END */

/* //CASE_II_START
func main() {
    rand.Seed( time.Now().UnixNano())
    var bytes int

    for i:= 0 ; i < 5 ; i++{ 
        bytes = rand.Intn(6)+1
        fmt.Println(bytes)
    }
}
//CASE_II_END */

//CASE_III_START
func main() {
    rand.Seed( time.Now().UnixNano())
	for i:= 0 ; i < 5 ; i++{ 
		fmt.Println(randomInt(1, 6))
	}
}
/* It's die six (rands ints 1 =< i =< 6) */
func randomInt (min int , max int  ) int {
    var bytes int
    bytes = min + rand.Intn(max)
    return int(bytes)
}
//CASE_III_END
