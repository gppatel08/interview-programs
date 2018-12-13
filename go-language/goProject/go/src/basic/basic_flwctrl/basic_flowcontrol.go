/*
For - Go has only one looping construct, the for loop.
The basic for loop has three components separated by semicolons:
	the init statement: executed before the first iteration
	the condition expression: evaluated before every iteration
	the post statement: executed at the end of every iteration

The init statement will often be a short variable declaration, and the variables declared there are visible only in the scope of the for statement.
The loop will stop iterating once the boolean condition evaluates to false.

1. NOTE: Unlike other languages like C, Java, or JavaScript there are no parentheses surrounding the three components of the for statement and 
	  the braces { } are always required.
2. The init and post statements are optional.
3. For is Go's "while":
   At that point you can drop the semicolons: C's while is spelled for in Go.
   
4. Forever: 
   If you omit the loop condition it loops forever, so an infinite loop is compactly expressed.
   
5. Go's if statements are like its for loops; the expression need not be surrounded by parentheses ( ) but the braces { } are required.
6. If with a short statement:
   Like for, the if statement can start with a short statement to execute before the condition.
   Variables declared by the statement are "only in scope until the end of the if".
   
7. If and else - Variables declared inside an if short statement are also available inside any of the else blocks.
8. Switch- 
   A switch statement is a shorter way to write a sequence of if - else statements. 
   It runs the first case whose value is equal to the condition expression.
   Go's switch is like the one in C, C++, Java, JavaScript, and PHP, except that Go only runs the selected case, not all the cases that follow. 
   In effect, the break statement that is needed at the end of each case in those languages is provided automatically in Go. 
   Another important difference is that Go's switch cases need not be constants, and the values involved need not be integers.

9. Switch evaluation order - Switch cases evaluate cases from top to bottom, stopping when a case succeeds.
   (For example,
		switch i {
			case 0:
			case f():
		}
	does not call f if i==0.)
	
10. Switch with no condition - Switch without a condition is the same as switch true.
    This construct can be a clean way to write long if-then-else chains.
	
11. Defer - A defer statement defers the execution of a function until the surrounding function returns.
    The deferred call's arguments are evaluated immediately, but the function call is not executed until the surrounding function returns.
	
12. Stacking defers -
    Deferred function calls are pushed onto a stack. When a function returns, its deferred calls are executed in last-in-first-out order.
*/

package main
import (
	"fmt"
	"math"
	"runtime"
	"time"
)

// if statements are like its for loops; the expression need not be surrounded by parentheses ( ) but the braces { } are required.
func sqrt(x float64) string {
	if x < 0 {
		return sqrt(-x) + "i"
	}
	return fmt.Sprint(math.Sqrt(x))
}

// If with a short statement - if statement can start with a short statement to execute before the condition.
// Variables declared by the statement are "only in scope until the end of the if".
func pow(x, n, lim float64) float64 {
	if v := math.Pow(x, n); v < lim {
		return v
	}
	return lim
}

// Variables declared inside an if short statement are also available inside any of the else blocks.
func power(x, n, lim float64) float64 {
	if v := math.Pow(x, n); v < lim {
		fmt.Printf("%g < %g\n", v, lim)
		return v
	} else if v == lim {
		fmt.Printf("%g == %g\n", v, lim)
		return v
	} else {
		fmt.Printf("%g > %g\n", v, lim)
	}
	// can't use v here, though
	return lim
}


func main() {
	sum := 0
	for i := 0; i < 10; i++ {
		sum += i
	}
	fmt.Println("Sum : ", sum)
	
	// init and post statements are optional
	_sum := 1
	for ; _sum < 1000; {
		_sum += _sum
	}
	fmt.Println("Sum : ", _sum)
	
	// For is Go's "while" - At that point you can drop the semicolons
	total := 1
	for total < 1000 {
		total += total
	}
	fmt.Println("Total : ", total)
	
	// omitting the loop condition it loops forever, so an infinite loop is compactly expressed. Hence put break condition for exit.
	i := 1
	for {
		fmt.Println("Infinite Loop with Break exit")
		if i >= 5 {
			break
		}
		i++ // Error with this statement -> ++i
	}
	
	fmt.Println("if statements: ", sqrt(2), sqrt(-4))
	
	fmt.Println("If with a short statement: ",
		pow(3, 2, 10),
		pow(3, 3, 20),
	)
	
	// NOTE: Both calls to power function are executed and return, before the call to fmt.Println() in main begins.
	fmt.Println("If and else with a short statement: ",
		power(3, 2, 10),
		power(3, 2, 9),
		power(3, 3, 20),
	)
	
	fmt.Print("Go runs on -> ")
	switch os := runtime.GOOS; os {
	case "darwin":
		fmt.Println("OS X.")
	case "linux":
		fmt.Println("Linux.")
	default:
		// freebsd, openbsd, plan9, windows...
		fmt.Printf("%s.\n", os)
	}
	
	// Note: Time in the Go playground always appears to start at 2009-11-10 23:00:00 UTC, a value whose significance is left as an exercise for the reader.
	fmt.Printf("When's Saturday? -> ")
	today := time.Now().Weekday()
	switch time.Saturday {
	case today + 0:
		fmt.Printf("Today.")
	case today + 1:
		fmt.Printf("Tomorrow.")
	case today + 2:
		fmt.Printf("In two days.")
	default:
		fmt.Printf("Too far away.")
	}
	
	// Switch without a condition is the same as switch true.
	t := time.Now()
	switch {
	case t.Hour() < 12:
		fmt.Print("\nGood morning!")
	case t.Hour() < 17:
		fmt.Print("\nGood afternoon.")
	default:
		fmt.Print("\nGood evening.")
	}
	
	// The deferred call's arguments are evaluated immediately, but the function call is not executed until the surrounding function returns.
	defer fmt.Println("world")
	fmt.Print("\nHello ")
	
	// Deferred function calls are pushed onto a stack. When a function returns, its deferred calls are executed in last-in-first-out order.
	fmt.Println("counting")
	for i := 1; i <= 5; i++ {
		defer fmt.Println(i)
	}
	fmt.Println("done")
}
