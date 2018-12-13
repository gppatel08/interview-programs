/*
Pointers:
---------
Go has pointers. A pointer holds the memory address of a value.
	The type *T is a pointer to a T value. Its zero value is nil.
		var p *int

	The & operator generates a pointer to its operand.
		i := 42
		p = &i

	The * operator denotes the pointer's underlying value.
		fmt.Println(*p) // read i through the pointer p
		*p = 21         // set i through the pointer p
	
	This is known as "dereferencing" or "indirecting".
	Unlike C, Go has no pointer arithmetic.
	
Structs:
--------
1. A struct is a collection of fields.
2. Struct fields are accessed using a dot.

Pointers to structs:
--------------------
Struct fields can be accessed through a struct pointer.
To access the field X of a struct when we have the struct pointer p we could write (*p).X. 
However, that notation is cumbersome, so the language permits us instead to write just p.X, without the explicit dereference.

Struct Literals:
-----------------
A struct literal denotes a newly allocated struct value by listing the values of its fields.
You can list just a subset of fields by using the Name: syntax. (And the order of named fields is irrelevant.)
The special prefix & returns a pointer to the struct value.

Arrays:
-------
The type [n]T is an array of n values of type T. The expression
	var a [10]int
declares a variable a as an array of ten integers.
An array's length is part of its type, so arrays cannot be resized. so, Go provides a convenient way of working with arrays through slice(dynamically grow).

Slices:
-------
An array has a fixed size. A slice, on the other hand, is a dynamically-sized, flexible view into the elements of an array. 
In practice, slices are much more common than arrays. The type []T is a slice with elements of type T.
A slice is formed by specifying two indices, a low and high bound, separated by a colon:
	a[low : high]
This selects a half-open range which includes the first element, but "excludes the last one".
The following expression creates a slice which includes elements 1 through 3 of a:
	a[1:4]
	
Slices are like references to arrays:
-------------------------------------
A slice does not store any data, it just describes a section of an underlying array.
Changing the elements of a slice modifies the corresponding elements of its underlying array.
Other slices that share the same underlying array will see those changes.

Slice literals:
---------------
A slice literal is like an array literal without the length.
This is an array literal:  [3]bool{true, true, false}
And this below creates the same array as above, then builds a slice that references it:
	[]bool{true, true, false}

Slice defaults:
---------------
When slicing, you may omit the high or low bounds to use their defaults instead.
The default is zero for the low bound and the length of the slice for the high bound.
For the array -> var a [10]int , these slice expressions are equivalent:
	a[0:10]
	a[:10]
	a[0:]
	a[:]

Slice length and capacity:
---------------------------
A slice has both a length and a capacity. The length of a slice is the number of elements it contains.
NOTE: The capacity of a slice is the number of elements in the underlying array, counting from the "first element in the slice".
The length and capacity of a slice s can be obtained using the expressions len(s) and cap(s).
NOTE: You can extend a slice's length by re-slicing it, provided it has sufficient capacity. 
Try changing one of the slice operations in the example program to extend it beyond its capacity and see what happens.

Nil slices:
-----------
The zero value of a slice is nil.
A nil slice has a length and capacity of 0 and has no underlying array.

Creating a slice with make:
---------------------------
Slices can be created with the built-in make function; this is how you create "dynamically-sized arrays".
The make function allocates a "zeroed array" and returns a slice that refers to that array:
	a := make([]int, 5)  // len(a)=5
To specify a capacity, pass a third argument to make:
	b := make([]int, 0, 5) // len(b)=0, cap(b)=5

	b = b[:cap(b)] // len(b)=5, cap(b)=5
	b = b[1:]      // len(b)=4, cap(b)=4

Slices of slices:
-----------------
Slices can contain any type, including other slices.

Appending to a slice:
---------------------
It is common to append new elements to a slice, and so Go provides a built-in append function. 
	func append(s []T, vs ...T) []T
The first parameter s of append is a slice of type T, and the rest are T values to append to the slice.
The resulting value of append is a slice containing all the elements of the original slice plus the provided values.
If the backing array of s is too small to fit all the given values a bigger array will be allocated. 
The returned slice will point to the newly allocated array.

Range:
------
The range "form of the for loop" iterates over a "slice or map".
When ranging over a slice, two values are returned for each iteration. 
	1. The first is the index, and 
	2. the second is a copy of the element at that index.

You can skip the index or value by assigning to _.
If you only want the index, drop the ", value" entirely.	

Maps:
-----
A map maps keys to values.
The zero value of a map is nil. A nil map has no keys, nor can keys be added.
The make function returns a map of the given type, initialized and ready for use.

Map literals:
-------------
Map literals are like struct literals, but the keys are required.
If the top-level type is just a type name, you can omit it from the elements of the literal.

Mutating Maps:
--------------
Insert or update an element in map m: m[key] = elem
Retrieve an element: elem = m[key]
Delete an element: delete(m, key)
Test that a key is present with a two-value assignment:
	elem, ok = m[key]
If key is in m, ok is true. If not, ok is false.
If key is not in the map, then elem is the zero value for the map's element type.
Note: If elem or ok have not yet been declared you could use a short declaration form:
	elem, ok := m[key]

Function values:
----------------
Functions are values too. They can be passed around just like other values.
"Function values" may be used as "function arguments" and "return values".

Function closures:
------------------
Go functions may be closures. A closure is a function value that references variables from outside its body. 
The function may access and assign to the referenced variables; in this sense the function is "bound" to the variables.
For example, the adder function returns a closure. Each closure is bound to its own sum variable.
*/

package main
import "fmt"
import "strings"
import "math"

type Vertex struct {
	X int
	Y int
}

type LatLong struct {
	Lat, Long float64
}

// Struct Literals
var (
	vv1 = Vertex{1, 2}  // has type Vertex
	vv2 = Vertex{X: 1}  // Y:0 is implicit
	vv3 = Vertex{}      // X:0 and Y:0
	pp1 = &Vertex{1, 2} // has type *Vertex
)

// "Function values" used as "function arguments"
func compute(fn func(float64, float64) float64) float64 {
	return fn(3, 4)
}

func main() {
	i, j := 42, 2701

	p := &i         // point to i
	fmt.Println("*p : ", *p) // read i through the pointer
	*p = 21         // set i through the pointer
	fmt.Println("i  : ", i)  // see the new value of i

	p = &j         // point to j
	*p = *p / 37   // divide j through the pointer
	fmt.Println("j  : ", j) // see the new value of j
	
	fmt.Println("Vertex : ", Vertex{1, 2})
	
	v := Vertex{1, 2}
	v.X = 4
	fmt.Println("v.X : ", v.X)
	fmt.Println("v.Y : ", v.Y)
	
	v1 := Vertex{1, 2}
	p1 := &v1
	p1.X = 1e9
	fmt.Println("Structur through pointer: ", v1, p1, *p1)
	
	fmt.Println("Struct Literals : ", vv1, pp1, vv2, vv3)
	
	// Arrays
	fmt.Println("-----------------------------")
	var a [2]string
	a[0] = "Hello"
	a[1] = "World"
	primes := [6]int{2, 3, 5, 7, 11, 13}
	fmt.Println(a[0], a[1])
	fmt.Println(a)
	fmt.Println(primes)
	
	// Slice
	fmt.Println("-----------------------------")
	_primes := [6]int{2, 3, 5, 7, 11, 13}
	var s []int = _primes[1:4]
	fmt.Println("Slice : ", s)
	
	// Slices are like references to arrays
	fmt.Println("-----------------------------")
	names := [4]string{
		"John",
		"Paul",
		"George",
		"Ringo",
	}
	fmt.Println(names)

	a1 := names[0:2]
	b1 := names[1:3]
	fmt.Println(a1, b1)

	b1[0] = "XXX"
	fmt.Println(a1, b1)
	fmt.Println(names)
	
	// Slice literals
	fmt.Println("-----------------------------")
	q1 := []int{2, 3, 5, 7, 11, 13}
	fmt.Println(q1)
	r1 := []bool{true, false, true, true, false, true}
	fmt.Println(r1)
	s1 := []struct {
		i int
		b bool
	}{
		{2, true},
		{3, false},
		{5, true},
		{7, true},
		{11, false},
		{13, true},
	}
	fmt.Println(s1)
	
	// Slice defaults
	fmt.Println("-----------------------------")
	ss := []int{2, 3, 5, 7, 11, 13}
	ssP := &ss
	fmt.Println("ss[]    -> ", ss)
	ss = ss[1:4]  // {3, 5, 7}
	fmt.Println("ss[1:4] -> ", ss)
	ss = ss[:2]  // {3, 5}
	fmt.Println("ss[:2]  -> ", ss)
	ss = ss[1:]  // {5}
	fmt.Println("ss[1:]  -> ", ss)
	ss[0] = 777
	fmt.Println("ssP[]   -> ", *ssP)  // {777}
	
	// Slice length and capacity
	fmt.Println("-----------------------------")
	sss := []int{2, 3, 5, 7, 11, 13}
	sp := &sss
	fmt.Printf("len=%d cap=%d %v\n", len(sss), cap(sss), sss)
	// My Understanding: zero length of a slice means slice doesn't created its own underlying array for this, still refering the parent slice.
	// NOTE: looks like slice variable won't take reference from first element bcz of zeo length.
	sss = sss[:0]  // Slice the slice to give it zero length. 
	fmt.Printf("len=%d cap=%d %v\n", len(sss), cap(sss), sss)
	sss = sss[:4]  // Extend its length.
	fmt.Printf("len=%d cap=%d %v\n", len(sss), cap(sss), sss)
	sss = sss[2:]  // Drop its first two values.
	fmt.Printf("len=%d cap=%d %v\n", len(sss), cap(sss), sss)
	fmt.Printf("len=%d cap=%d %v\n", len(*sp), cap(*sp), *sp)
	
	// Nil slices - The zero value of a slice is nil
	fmt.Println("-----------------------------")
	var sn []int
	fmt.Println(sn, len(sn), cap(sn))
	if sn == nil {
		fmt.Println("Nil slices!")
	}
	
	// Creating a slice with make
	fmt.Println("-----------------------------")
	aa := make([]int, 5)
	printSlice("aa", aa)
	bb := make([]int, 0, 5)
	printSlice("bb", bb)
	cc := bb[:2]
	printSlice("cc", cc)
	dd := cc[2:4]
	printSlice("dd", dd)
	
	// Slices of slices
	fmt.Println("-----------------------------")
	board := [][]string{
		[]string{"X", "_", "X"},
		[]string{"_", "X", "_"},
		[]string{"X", "_", "X"},
	}
	for i := 0; i < len(board); i++ {
		fmt.Printf("%s\n", strings.Join(board[i], " "))
	}
	
	// Appending to a slice
	fmt.Println("-----------------------------")
	var sl []int
	printSliceInt(sl)
	sl = append(sl, 0)  // append works on nil slices.
	printSliceInt(sl)
	sl = append(sl, 1)  // The slice grows as needed.
	printSliceInt(sl)
	sl = append(sl, 2)  // The slice grows as needed.
	printSliceInt(sl)
	sl = append(sl, 3, 4, 5)  // // We can add more than one element at a time.
	printSliceInt(sl)
	sl = append(sl, 6, 7, 8)  // // We can add more than one element at a time.
	printSliceInt(sl)
	
	// ranging over a slice
	fmt.Println("-----------------------------")
	var pow = []int{1, 2, 4, 8, 16, 32, 64, 128}
	for i, v := range pow {
		fmt.Printf("2**%d = %d\n", i, v)
	}
	
	// skip the index or value by assigning to '_'
	_pow := make([]int, 10)
	for i := range _pow {
		_pow[i] = 1 << uint(i) // == 2**i
	}
	for _, value := range _pow {
		fmt.Printf("%d\n", value)
	}
	
	// Maps - A map maps keys to values.
	fmt.Println("-----------------------------")
	var m map[string]LatLong  // A nil map has no keys, nor can keys be added. Hence create non-nil map through make() function.
	//m["Bell-Labs"] = LatLong{40.68433, -74.39967}  // execution error: panic: assignment to entry in nil map
	fmt.Println(m["Bell-Labs"])
	m = make(map[string]LatLong)
	m["Bell Labs"] = LatLong{40.68433, -74.39967}
	fmt.Println(m["Bell Labs"])
	
	// Map literals - Map literals are like struct literals, but the keys are required.
	fmt.Println("-----------------------------")
	var mm = map[string]LatLong{ "Bell Labs": LatLong{40.68433, -74.39967,}, 
	                             "Google": LatLong{37.42202, -122.08408,},}
	fmt.Println(mm)
	
	// If the top-level type is just a type name, you can omit it from the elements of the literal.
	fmt.Println("-----------------------------")
	var mt = map[string]LatLong{"Bell Labs":{40.68433, -74.39967}, "Google":{37.42202, -122.08408},}
	fmt.Println(mt)
	
	mmt := make(map[string]int)
	mmt["Answer"] = 42
	fmt.Println("The value:", mmt["Answer"])
	mmt["Answer"] = 48
	fmt.Println("The value:", mmt["Answer"])
	delete(mmt, "Answer")
	fmt.Println("The value:", mmt["Answer"])
	val, ok := mmt["Answer"]
	fmt.Println("The value:", val, "Present?", ok)
	
	// Function values
	fmt.Println("-----------------------------")
	hypot := func(x, y float64) float64 {
		return math.Sqrt(x*x + y*y)
	}
	fmt.Println("hypot(5, 12) : ", hypot(5, 12))
	// "Function values" used as "function arguments"
	fmt.Println("compute(hypot): ", compute(hypot)) // Equal -> hypot(x=3, y=4) -> math.Sqrt(x*x + y*y)
	fmt.Println("math.Pow(3, 4): ", compute(math.Pow)) // Equal -> math.Pow(3, 4)
	
	//Function closures - Go functions may be closures. A closure is a function value that references variables from outside its body. 
	fmt.Println("-----------------------------")
	pos, neg := adder(), adder()
	for i := 0; i < 10; i++ {
		fmt.Println("Function closures: ",
			pos(i),
			neg(-2*i),
		)
	}
	
	// Implement a fibonacci function that returns a function (a closure) that returns successive fibonacci numbers (0, 1, 1, 2, 3, 5, ...).
	fmt.Println("-----------------------------")
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}

// fibonacci is a function that returns a function that returns an int.
func fibonacci() func() int {
	f1 := 1
	f2 := 0
	sum := 0
	return func() int {
		sum = f2 + f1
		f1 = f2
		f2 = sum
		return f1
	}
}

func adder() func(int) int {
	sum := 0
	// A closure is a function value that references variables from outside its body, Here is sum.
	return func(x int) int {
		sum += x
		return sum
	}
}

func printSlice(s string, x []int) {
	fmt.Printf("%s len=%d cap=%d %v\n", s, len(x), cap(x), x)
}

func printSliceInt(s []int) {
	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s)
}