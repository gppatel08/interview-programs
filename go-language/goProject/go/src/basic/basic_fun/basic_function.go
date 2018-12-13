/*
Functions:-
-----------
1. A function can take zero or more arguments. In this example, add takes two parameters of type int.
2. Notice that the type comes after the variable name.
3. When two or more consecutive "named function parameters" share a type, you can omit the type from all but the last.
4. When two or more consecutive parameters share a type, you can omit the type from all but the last.
5. Multiple results - A function can return any number of results. Example- The swap function returns two strings.
6. Named return values - Go's return values may be named. If so, they are treated as variables defined at the top of the function.
   These names should be used to document the meaning of the return values.
   NOTE: A return statement without arguments returns the named return values. This is known as a "naked" return.
   Naked return statements should be used only in short functions, as with the example shown here. They can harm readability in longer functions.
7. Variables - The var statement declares a list of variables; as in function argument lists, the type is last.
   NOTE: A var statement can be at package or function level.
8. Variables with initializers - A var declaration can include initializers, one per variable.
   If an initializer is present, the type can be omitted; the variable will take the type of the initializer.
9. Short variable declarations - Inside a function, the := short assignment statement can be used in place of a var declaration with implicit type.
   NOTE: Outside a function, every statement begins with a keyword (var, func, and so on) and so the := construct is not available.

10. Basic types - Go's basic types are
	1. bool
	2. string
	3. int  int8  int16  int32  int64
	4. uint uint8 uint16 uint32 uint64 uintptr
	5. byte // alias for uint8
	6. rune // alias for int32, represents a Unicode code point
	7. float32 float64
	8. complex64 complex128
	
	The example shows variables of several types, and also that variable declarations may be "factored" into blocks, as with import statements, like.
		var (
			ToBe   bool       = false
			MaxInt uint64     = 1<<64 - 1
		)
		
	The int, uint, and uintptr types are usually 32 bits wide on 32-bit systems and 64 bits wide on 64-bit systems. 
	NOTE: When you need an integer value you should use int unless you have a specific reason to use a sized or unsigned integer type.

11. Zero values - Variables declared without an explicit initial value are given their zero value.
    The zero value is:
		A. 0 for numeric types,
		B. false for the boolean type, and
		C. "" (the empty string) for strings.

12. Type conversions - The expression T(v) converts the value v to the type T.
	Some numeric conversions:
		var i int = 42
		var f float64 = float64(i)
		var u uint = uint(f)
	
	Or, put more simply:
		i := 42
		f := float64(i)
		u := uint(f)
	Unlike in C, in Go assignment between items of different type requires an explicit conversion. 		

13. Type inference - When declaring a variable without specifying an explicit type (either by using the := syntax or var = expression syntax), 
    the variable's type is inferred from the value on the right hand side.
	
	A. When the right hand side of the declaration is typed, the new variable is of that same type:
		var i int
		j := i // j is an int
	B. But when the right hand side contains an untyped numeric constant, 
	   the new variable may be an int, float64, or complex128 depending on the precision of the constant:
		i := 42           // int
		f := 3.142        // float64
		g := 0.867 + 0.5i // complex128

14. Constants - Constants are declared like variables, but with the const keyword.
	Constants can be character, string, boolean, or numeric values.
	Constants cannot be declared using the := syntax.		

15. Numeric Constants - Numeric constants are high-precision values.
	An untyped constant takes the type needed by its context.
	Try printing needInt(Big) too.
	(An int can store at maximum a 64-bit integer, and sometimes less.)				
*/

package main
import (
	"fmt"
	"math/cmplx"
	"math"
)

func add(x int, y int) int {
	return x + y
}

//Note: When two or more consecutive "named function parameters" share a type, you can omit the type from all but the last.
func mul(x, y int) int {
	return x * y
}

// A function can return any number of results. Example- The swap function returns two strings.
func swap(x, y string) (string, string) {
	return y, x
}

// A return statement without arguments returns the named return values. This is known as a "naked" return.
func split(sum int) (x, y int) {
	x = sum * 4 / 9
	y = sum - x
	return
}

// var statement can be at package level.
var c, python, java bool

// initializer is present, the type can be omitted; the variable will take the type of the initializer.
var k, j int = 1, 2

// Constants - Constants are declared like variables, but with the const keyword.
const Pi = 3.14

// Numeric Constants - Numeric constants are high-precision values. An untyped constant takes the type needed by its context.
const (
	Big = 1 << 100	// Create a huge number by shifting a 1 bit left 100 places. In other words, the binary number that is 1 followed by 100 zeroes.
	Small = Big >> 99	// Shift it right again 99 places, so we end up with 1<<1, or 2.
)
func needInt(x int) int { return x*10 + 1 }
func needFloat(x float64) float64 {
	return x * 0.1
}

func main() {
	//When two or more consecutive parameters share a type, you can omit the type from all but the last.
	var x, y int = 10, 20
	fmt.Println("Addition      : ", add(x, y))
	fmt.Println("Multiplcation : ", mul(x, y))
	
	a, b := swap("hello", "world")
	fmt.Println("Function Return Multiple results: ", a, b)
	
	fmt.Printf("Named return values: ")
	fmt.Println(split(17))
	
	//var statement can be at function level.
	var i int
	fmt.Println("var statement at package or function level: ", i, c, python, java)
	
	// initializer is present, the type can be omitted; the variable will take the type of the initializer.
	var c_plus_plus, perl = true, "no!"
	fmt.Println("Variables with initializers: ", k, j, c_plus_plus, perl)
	
	// Short variable declarations
	name := "Guru Prasad Patel"
	fmt.Println("Short variable declarations:", name)
	
	// variable declarations may be "factored" into blocks
	var (
		ToBe   bool       = false
		MaxInt uint64     = 1<<64 - 1
		z      complex128 = cmplx.Sqrt(-5 + 12i)
		_z	   complex128 = 5 + 3i
	)
	fmt.Printf("Type: %T Value: %v\n", ToBe, ToBe)
	fmt.Printf("Type: %T Value: %v\n", MaxInt, MaxInt)
	fmt.Printf("Type: %T Value: %v\n", z, z)
	fmt.Printf("Type: %T Value: %v\n", _z, _z)
	
	// Zero values
	var _i int
	var _f float64
	var _b bool
	var _s string
	fmt.Printf("_i : %v, _f : %v, _b : %v, _s : %q\n", _i, _f, _b, _s)
	
	// Type conversions
	var x1, y1 int = 3, 4
	var f1 float64 = math.Sqrt(float64(x1*x1 + y1*y1))
	// var f1 float64 = math.Sqrt((x1*x1 + y1*y1)) //Error - cannot use x1 * x1 + y1 * y1 (type int) as type float64 in argument to math.Sqrt
	var z1 uint = uint(f1)
	fmt.Println("Type conversions: ", x1, y1, z1)
	i_ := 42
	f_ := float64(i_)
	u_ := uint(f_)
	fmt.Printf("Type: %T Value: %v\n", i_, i_)
	fmt.Printf("Type: %T Value: %v\n", f_, f_)
	fmt.Printf("Type: %T Value: %v\n", u_, u_)
	
	// Type inference 
	//v1 := 42 // change me!, Try changing the initial value of v in the example code and observe how its type is affected.
	v1 := "OK!"
	fmt.Printf("v1 is of type %T with %v\n", v1, v1)
	
	// Constants - Constants are declared like variables, but with the const keyword.
	const World = "世界"
	const Truth = true
	fmt.Println("Hello", World, "Go rules?", Truth, "Happy", Pi, "Day")
	
	// Numeric Constants - Numeric constants are high-precision values. Try printing needInt(Big) too.
	fmt.Println("needInt(Small): ", needInt(Small))
	fmt.Println("needFloat(Small): ", needFloat(Small))
	fmt.Println("needFloat(Big): ", needFloat(Big))
	//fmt.Println("needInt(Big): ", needInt(Big))  // Error: constant 1267650600228229401496703205376 overflows int
}