package main

import (
	"fmt"
	"math"
)

// Newton's method is to approximate Sqrt(x) by picking a starting point z first, and repeating.
func Sqrt(x float64) float64 {
	z := 1.0
	for i := 0; i < 10; i++ {
	    //fmt.Printf("(%f) / (%f)\n", z*z - x, 2*z)
		z -= (z*z - x) / (2*z)
	}
	return z
}

func Sqrt_2(x float64) float64 {
	z := float64(1.5)
	val := float64(0)
	for {
		z = z - (z*z-x)/(2*z)
		if math.Abs(val-z) < 1e-10 {
			break
		}
		val = z
	}
	return val
}

func main() {
	fmt.Println(Sqrt(16))
	fmt.Println(math.Sqrt(16))
	fmt.Println(Sqrt_2(16))
}