Variadic parameters:
--------------------
The ... specifies that the final parameter of the function is variadic.
what is the meaning about `…Type` in golang
this code is in builti.go

/* The append built-in function appends elements to the end of a slice. If it has sufficient capacity, the destination is resliced to accommodate the
   new elements. If it does not, a new underlying array will be allocated. Append returns the updated slice. It is therefore necessary to store the
   result of append, often in the variable holding the slice itself:
		slice = append(slice, elem1, elem2)
		slice = append(slice, anotherSlice...)
   As a special case, it is legal to append a string to a byte slice, like this:
		slice = append([]byte("hello "), "world"...)
func append(slice []Type, elems ...Type) []Type

package main
import "fmt"
func main() {
   s := []int{1,2,3,4,5}
   s1 := s[:2]
   s2 := s[2:]
   s3 := append(s1, s2...)
   fmt.Println(s1, s2, s3)
}

the result is: [1 2] [3 4 5] [1 2 3 4 5]

The code in builtin.go serves as documentation. The code is not compiled.
The ... specifies that the final parameter of the function is variadic. Variadic parameters are documented in the Go Language specification.
The Type part is a stand-in for any Go type.