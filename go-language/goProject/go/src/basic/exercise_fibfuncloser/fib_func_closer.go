package main

import "fmt"

// right implementation
func fibonacci_1() func() int {
  first, second := 0, 1
	return func() int {
		previousFirst := first
		first, second = second, first + second
		return previousFirst
	}
}

func fibonacci_2() func() int {
	prev := 0
	curr := 1
	return func() int {
		prev, curr = curr, prev+curr
		return curr
	}
}

func main() {
	f1 := fibonacci_1()
	f2 := fibonacci_2()
	for i := 0; i < 10; i++ {
		fmt.Println(f1(), " ", f2())
	}
}