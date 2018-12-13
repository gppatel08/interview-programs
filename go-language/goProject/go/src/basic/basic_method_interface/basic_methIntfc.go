/*
Methods:
--------
Go does not have classes. However, you can define methods on types.
A method is a function with a special receiver argument.
The receiver appears in its own argument list between the func keyword and the method name.
In this example, the Abs method has a receiver of type Vertex named v.

Methods are functions:
----------------------
Remember: a method is just a function with a receiver argument.
You can declare a method on non-struct types, too.
You can only declare a method with a receiver whose type is defined in the same package as the method. 
You cannot declare a method with a receiver whose type is defined in another package (which includes the built-in types such as int).

Pointer receivers:
------------------
You can declare methods with pointer receivers.
This means the receiver type has the literal syntax *T for some type T. (Also, T cannot itself be a pointer such as *int.)
For example, the Scale method here is defined on *Vertex.
Methods with pointer receivers can modify the value to which the receiver points (as Scale does here). 
Since methods often need to modify their receiver, pointer receivers are more common than value receivers.

With a value receiver, the Scale method operates on a copy of the original Vertex value. (This is the same behavior as for any other function argument.) 
The Scale method must have a pointer receiver to change the Vertex value declared in the main function.

Methods and pointer indirection:
--------------------------------
Comparing the previous two programs, you might notice that functions with a pointer argument must take a pointer:
	var v Vertex
	ScaleFunc(v, 5)  // Compile error!
	ScaleFunc(&v, 5) // OK
while methods with pointer receivers take "either a value or a pointer as the receiver" when they are called:
	var v Vertex
	v.Scale(5)  // OK
	p := &v
	p.Scale(10) // OK
For the statement v.Scale(5), even though v is a value and not a pointer, the method with the pointer receiver is called automatically. 
That is, as a convenience, Go interprets the statement v.Scale(5) as (&v).Scale(5) since the Scale method has a pointer receiver.

  ----------------------------------------------------------
 |  The equivalent thing happens in the reverse direction.  |
  ----------------------------------------------------------
		func (v Vertex) Abs() float64 { }
		func Abs(v Vertex) float64 { }
NOTE: Functions that take a value argument must take a value of that specific type:
		var v Vertex
		fmt.Println(Abs(v))  // OK
		fmt.Println(Abs(&v)) // Compile error!
NOTE: while methods with value receivers take either a value or a pointer as the receiver when they are called:
		var v Vertex
		fmt.Println(v.Abs()) // OK
		p := &v
		fmt.Println(p.Abs()) // OK, AS method call p.Abs() is interpreted as (*p).Abs()
NOTE : In this case, the method call p.Abs() is interpreted as (*p).Abs().

Choosing a value or pointer receiver - There are two reasons to use a pointer receiver.
1. The first is so that the method can modify the value that its receiver points to.
2. The second is to avoid copying the value on each method call. This can be more efficient if the receiver is a large struct.
NOTE: In general, all methods on a given type should have "either value or pointer receivers", "but not a mixture of both."

Interfaces:
-------------
An interface type is defined as a set of method signatures.
A value of interface type can hold any value that implements those methods.

Interfaces are implemented implicitly:
--------------------------------------
A type implements an interface by implementing its methods. 
There is no explicit declaration of intent, no "implements" keyword.
Implicit interfaces decouple the definition of an interface from its implementation, which could then appear in any package without prearrangement.

Interface values with nil underlying values:
---------------------------------------------
If the concrete value inside the interface itself is nil, the method will be called with a nil receiver.
In some languages this would trigger a null pointer exception, but in Go it is common to write methods 
that gracefully handle being called with a nil receiver (as with the method M in this example.)
Note that an interface value that holds a nil concrete value is itself non-nil.

Nil interface values:
---------------------
A nil interface value holds neither value nor concrete type.
Calling a method on a nil interface is a run-time error because there is no type inside the interface tuple to indicate which concrete method to call.

The empty interface:
--------------------
The interface type that specifies zero methods is known as the empty interface:
		interface{}
An empty interface may hold values of any type. (Every type implements at least zero methods.)
Empty interfaces are used by code that handles values of unknown type. For example, "fmt.Print" takes any number of arguments of type interface{}.

Type assertions:
-----------------
A type assertion provides access to an interface value's underlying concrete value.
	t := i.(T)
This statement asserts that the interface value i holds the concrete type T and assigns the underlying T value to the variable t.
If i does not hold a T, the statement will trigger a panic.

To test whether an interface value holds a specific type, a type assertion can return two values: the underlying value 
and a boolean value that reports whether the assertion succeeded.
	t, ok := i.(T)
If i holds a T, then t will be the underlying value and ok will be true.
If not, ok will be false and t will be the zero value of type T, and no panic occurs.
Note the similarity between this syntax and that of reading from a map.

Type switches:
---------------
A type switch is a construct that permits several type assertions in series.
A type switch is like a regular switch statement, but the cases in a type switch specify types (not values), 
and those values are compared against the type of the value held by the given interface value.
	switch v := i.(type) {
		case T:
		// here v has type T
		case S:
			// here v has type S
		default:
			// no match; here v has the same type as i
	}
The declaration in a type switch has the same syntax as a type assertion i.(T), but the specific type T is replaced with the keyword type.
This switch statement tests whether the interface value i holds a value of type T or S. 
In each of the T and S cases, the variable v will be of type T or S respectively and hold the value held by i. 
In the default case (where there is no match), the variable v is of the same interface type and value as i.

Stringers:
-----------
One of the most ubiquitous interfaces is Stringer defined by the fmt package.
	type Stringer interface {
		String() string
	}
A Stringer is a type that can describe itself as a string. The fmt package (and many others) look for this interface to print values.


*/

package main
import (
	"fmt"
	"math"
)

type Vertex struct {
	X, Y float64
}

// A method is a function with a special receiver argument, With a value receiver.
func (v Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func (v *Vertex) AbsPR() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

// Pointers and functions - Here we see the Abs and Scale methods rewritten as functions.
func ScaleFunc(v *Vertex, f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}

// Methods with pointer receivers can modify the value to which the receiver points (as Scale Pointer Receiver does here). 
func (v *Vertex) ScalePR(f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}
// Methods with value receivers can NOT modify the value to which the receiver points (as Scale Pointer Receiver does here).
// Here Scale method operates on a copy of the original Vertex value
func (v Vertex) ScaleVR(f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}

// Here's Abs written as a regular function with no change in functionality.
func Abs(v Vertex) float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

type Person struct {
	Name string
	Age  int
}
func (p Person) String() string {
	return fmt.Sprintf("%v (%v years)", p.Name, p.Age)
}

type Abser interface {
	Abs() float64
}

// In this example we see a numeric type MyFloat with an Abs method.
type MyFloat float64
func (f MyFloat) Abs() float64 {
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}

// Interfaces are implemented implicitly
type Y interface {
	M()
}
type X struct {
	S string
}
// This method means type X implements the interface Y, but we don't need to explicitly declare that it does so.
func (t *X) M() {
	if t == nil {
		fmt.Println("<nil>")
		return
	}
	fmt.Println("X : ", t.S)
}
func (f MyFloat) M() {
	fmt.Println("MyFloat : ", f)
}
func describeY(i Y) {
	fmt.Printf("(%v, %T)\n", i, i)
}

// Nil interface values - A nil interface value holds neither value nor concrete type.
type I interface {
	M()
}
func describe(i I) {
	fmt.Printf("I_Nil_YesMethod : (%v, %T)\n", i, i)  // A nil interface value holds neither value nor concrete type. Hence OUTPUT: (<nil>, <nil>)
}

type I_Nil_NoMethod interface {
	//M()
}
func describe_I_Nil_NoMethod(i I_Nil_NoMethod) {
	fmt.Printf("I_Nil_NoMethod  : (%v, %T)\n", i, i)  // A nil interface value holds neither value nor concrete type. Hence OUTPUT: (<nil>, <nil>)
}

// A type switch is a construct that permits several type assertions in series.
func typeSwitch(i interface{}) {
	// The declaration in a type switch has the same syntax as a type assertion i.(T), but the specific type T is replaced with the keyword "type".
	switch v := i.(type) {
	case int:
		fmt.Printf("Twice %v is %v\n", v, v*2)
	case string:
		fmt.Printf("%q is %v bytes long\n", v, len(v))
	default:
		fmt.Printf("I don't know about type %T!\n", v)
	}
}

/*
Exercise: Stringers
Make the IPAddr type implement fmt.Stringer to print the address as a dotted quad.
For instance, IPAddr{1, 2, 3, 4} should print as "1.2.3.4"
*/
type IPAddr [4]byte
// TODO: Add a "String() string" method to IPAddr.
func (p IPAddr) String() string {
	return fmt.Sprintf("%v.%v.%v.%v", p[0], p[1], p[2], p[3])
}

func describePrint(i interface{}) {
	fmt.Printf("(%v, %T)\n", i, i)
}

func main() {
	v := Vertex{3, 4}
	fmt.Println("Method   : ", v.Abs())
	fmt.Println("Function : ", Abs(v))

	f := MyFloat(-math.Sqrt2)
	fmt.Println(f.Abs())
	
	// Pointer receivers
	vr := Vertex{3, 4}
	fmt.Println("-------------------------------")
	fmt.Println("ScaleVR before : ", vr)
	vr.ScaleVR(10)
	fmt.Println("ScaleVR after  : ", vr)
		
	pr := Vertex{3, 4}
	fmt.Println("ScalePR before : ", pr)
	pr.ScalePR(10)
	fmt.Println("ScalePR after  : ", pr)
	
	varg_fun_arg := Vertex{3, 4}
	fmt.Println("Scale function arg before  : ", varg_fun_arg)
	ScaleFunc(&varg_fun_arg, 10)  // for func ScaleFunc(v Vertex, f float64), remove '&' here as ScaleFunc(varg_fun_arg, 10)
	fmt.Println("Scale function arg after   : ", varg_fun_arg)
	
	_vr := Vertex{3, 4}
	_pr := &Vertex{4, 3}
	fmt.Println("Before : ", _vr, _pr)
	_vr.ScalePR(2) // Go interprets the statement _vr.ScalePR(5) as (&_vr).ScalePR(5) since the ScalePR method has a pointer receiver.
	_pr.ScalePR(3)
	ScaleFunc(&_vr, 10)
	ScaleFunc(_pr, 8)
	fmt.Println("[{3, 4} * 2 * 10 ], [{4, 3} * 3 * 8] ")
	fmt.Println("After  : ", _vr, _pr)
	
	vv := Vertex{3, 4}
	fmt.Println(vv.Abs())
	fmt.Println(Abs(vv))
	//fmt.Println(Abs(&vv)) // Compile error! cannot use &vv (type *Vertex) as type Vertex in argument to Abs
	pp := &Vertex{4, 3}
	fmt.Println(pp.Abs())
	//fmt.Println(Abs(pp)) // Compile error! cannot use pp (type *Vertex) as type Vertex in argument to Abs
	fmt.Println(Abs(*pp))
	
	// Choosing a value or pointer receiver 
	vc := &Vertex{3, 4}
	fmt.Printf("Before scaling: %+v, Abs: %v\n", vc, vc.AbsPR())
	fmt.Printf("Scaling with 5\n")
	vc.ScalePR(5)
	fmt.Printf("After scaling : %+v, Abs: %v\n", vc, vc.AbsPR())
	
	// Interfaces - An interface type is defined as a set of method signatures.
	fmt.Println("-------------------------------")
	var a_in Abser
	f_in := MyFloat(-math.Sqrt2)
	v_in := Vertex{3, 4}
	a_in = f_in  // a MyFloat implements Abser
	a_in = &v_in // a *Vertex implements Abser  // OK
	fmt.Println(a_in.Abs())
	//Error -  In the following line, v_in is a Vertex (not *Vertex) and does NOT implement Abser. 
	//  cannot use v_in (type Vertex) as type Abser in assignment: Vertex does not implement Abser (Abs method has pointer receiver)
	//but if 'Vertex' implements Abser as like func (v Vertex) Abs() float64 { } then it will work for both Vertex and *Vertex for Abser()
	a_in = v_in  // NOT OK, if (Abs method has pointer receiver)
	fmt.Println(a_in.Abs()) 
	
	// type X implements the interface Y
	fmt.Println("-------------------------------")
	var iN Y  // Under the hood, interface values can be thought of as a tuple of a value and a concrete type: (value, type)
	iN = &X{"hello"}  // An interface value holds a value of a specific underlying concrete type.
	describeY(iN)
	iN.M()  // Calling a method on an interface value executes the method of the same name on its underlying type.
	iN = MyFloat(math.Pi) // An interface value holds a value of a specific underlying concrete type.
	describeY(iN)
	iN.M()  // Calling a method on an interface value executes the method of the same name on its underlying type.
	
	var t *X
	iN = t  // Note that an interface value that holds a nil concrete value is itself non-nil.
	describeY(iN)
	iN.M()  // If the concrete value inside the interface itself is nil, the method will be called with a nil receiver.
	
	// A Stringer is a type that can describe itself as a string.
	fmt.Println("-------------------------------")
	a := Person{"Arthur Dent", 42}
	z := Person{"Zaphod Beeblebrox", 9001}
	fmt.Println(a, z)
	
	// Nil interface values - A nil interface value holds neither value nor concrete type.
	fmt.Println("-------------------------------")
	var i_nil_nomethod I_Nil_NoMethod
	describe_I_Nil_NoMethod(i_nil_nomethod)
	
	var i_nil I
	describe(i_nil)
	// calling a method on a nil interface is a run-time error because there is no type inside the interface tuple to indicate which concrete method to call.
	//i_nil.M()  // (<nil>, <nil>) panic: runtime error: invalid memory address or nil pointer dereference
	
	// The empty interface - The interface type that specifies zero methods is known as the empty interface: interface{}
	fmt.Println("-------------------------------")
	var in interface{}
	describePrint(in)
	in = 42
	describePrint(in)
	in = "hello"
	describePrint(in)
	
	// Type assertions - A type assertion provides access to an interface value's underlying concrete value.
	fmt.Println("-------------------------------")
	var i interface{} = "hello"
	s := i.(string)
	fmt.Println(s)
	s, ok := i.(string)
	fmt.Println(s, ok)
	fmt.Printf("%v is type of %T\n", s, s)
	
	fv, ok := i.(float64)
	fmt.Println(fv, ok)
	fmt.Printf("%v is type of %T\n", fv, fv)
	
	iv, ok := i.(int32)
	fmt.Println(iv, ok)
	fmt.Printf("%v is type of %T\n", iv, iv)

	var _fv string
	//_fv = i.(float64) // panic: interface conversion: interface {} is string, not float64
	_fv = i.(string)  // This will work as interface {} is string and converting to string "i.(string)"
	fmt.Println("_fv : ", _fv)
	
	// A type switch is a construct that permits several type assertions in series.
	fmt.Println("-------------------------------")
	typeSwitch(21)
	typeSwitch("hello")
	typeSwitch(true)
	
	// Exercise: Stringers
	fmt.Println("-------------------------------")
	hosts := map[string]IPAddr{
		"loopback ":  {127, 0, 0, 1},
		"googleDNS": {8, 8, 8, 8},
	}
	for name, ip := range hosts {
		fmt.Printf("%v: %v\n", name, ip)
	}
}