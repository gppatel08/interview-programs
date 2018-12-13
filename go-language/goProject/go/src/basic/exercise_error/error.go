package main

import (
	"fmt"
	"math"
)

type ErrNegativeSqrt float64

func (e ErrNegativeSqrt) Error() string {
	return fmt.Sprintf("cannot Sqrt negative number: %g", float64(e))
}

func Sqrt(x float64) (float64, error) {

	if x < 0 {
		return 0, ErrNegativeSqrt(x)
	}
	z := float64(1.5)
	val := float64(0)
	for {
		z = z - (z*z-x)/(2*z)
		if math.Abs(val-z) < 1e-10 {
			break
		}
		val = z
	}
	return val, nil

}

func main() {
	fmt.Println(Sqrt(2))
	fmt.Println(Sqrt(-2))
}