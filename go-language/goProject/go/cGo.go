/*
Building cgo packages:
---------------------
To build cgo packages, just use go build or go install as usual. 
The go tool recognizes the special "C" import and automatically uses cgo for those files.
Finally, if you're curious as to how all this works internally, take a look at the introductory comment of the runtime package's cgocall.go.
The cgo command documentation has more detail about the C pseudo-package and the build process(https://golang.org/cmd/cgo/).

Cgo lets Go packages call C code. Given a Go source file written with some special features, 
cgo outputs Go and C files that can be combined into a single Go package.

To lead with an example, here's a Go package that provides two functions - Random and Seed - that wrap C's random and srandom functions.

The rand package imports "C", but you'll find there's no such package in the standard Go library. 
That's because C is a "pseudo-package", a special name interpreted by cgo as a reference to C's name space.
The rand package contains four references to the C package: 
	1. the calls to C.random
	2. and C.srandom, 
	3. the conversion C.uint(i), 
	4. and the import statement.
	
comment above the import statement:
-----------------------------------
Cgo recognizes this comment. Any lines starting with #cgo followed by a space character are removed; these become directives for cgo. 
The remaining lines are used as a header when compiling the C parts of the package. 
In this case those lines are just a single #include statement, but they can be almost any C code. 
The #cgo directives are used to provide flags for the compiler and linker when building the C parts of the package.

There is a limitation: if your program uses any //export directives, then the C code in the comment may only include 
declarations (extern int f();), not definitions (int f() { return 1; }). You can use //export directives to make Go functions accessible to C code.

The #cgo and //export directives are documented in the https://golang.org/cmd/cgo/
*/

package rand

/*
#include <stdlib.h>
*/
import "C"

/*
The Random function calls the standard C library's random function and returns the result. 
In C, random returns a value of the C type long, which cgo represents as the type C.long. 
It must be converted to a Go type before it can be used by Go code outside this package, using an ordinary Go type conversion:

Here's an equivalent function that uses a temporary variable to illustrate the type conversion more explicitly:
	func Random() int {
		var r C.long = C.random()
		return int(r)
	}
*/
func Random() int {
    return int(C.random())
}

/*
The Seed function does the reverse, in a way. 
It takes a regular Go int, converts it to the C unsigned int type, and passes it to the C function srandom.
Note that cgo knows the unsigned int type as C.uint; see the cgo documentation for a complete list of these numeric type names.
https://golang.org/cmd/cgo/
*/
func Seed(i int) {
    C.srandom(C.uint(i))
}


/*
Strings and things:
--------------------
Unlike Go, C doesn't have an explicit string type. Strings in C are represented by a zero-terminated array of chars.
Conversion between Go and C strings is done with the C.CString, C.GoString, and C.GoStringN functions. 
These conversions make a copy of the string data.
This next example implements a Print function that writes a string to standard output using C's fputs function from the stdio library:

Memory allocations made by C code are not known to Go's memory manager. When you create a C string with C.CString (or any C memory allocation) 
you must remember to free the memory when you're done with it by calling C.free.

The call to C.CString returns a pointer to the start of the char array, 
so before the function exits we convert it to an unsafe.Pointer and release the memory allocation with C.free.

A common idiom in cgo programs is to defer the free immediately after allocating (especially when the code that follows is more complex 
than a single function call), as in this rewrite of Print:
	func Print(s string) {
		cs := C.CString(s)
		defer C.free(unsafe.Pointer(cs))
		C.fputs(cs, (*C.FILE)(C.stdout))
	}
*/
package print

// #include <stdio.h>
// #include <stdlib.h>
import "C"
import "unsafe"

func Print(s string) {
    cs := C.CString(s)
    C.fputs(cs, (*C.FILE)(C.stdout))
    C.free(unsafe.Pointer(cs))
}
