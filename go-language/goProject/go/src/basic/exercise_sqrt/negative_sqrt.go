package main

import (
	"fmt"
	"math"
)

type NegativeSqrt float64

func (e NegativeSqrt) Error() string {
	return fmt.Sprint(float64(e))
}

func (e NegativeSqrt) String() string {
	return fmt.Sprintf("%f", e)
}

func Sqrt(x float64) (float64, error) {
	if x < 0 {
		return 0, NegativeSqrt(x)
	}
	return math.Sqrt(x), nil
}

func main() {
	fmt.Println(Sqrt(-2))
	fmt.Println(Sqrt(2))
}