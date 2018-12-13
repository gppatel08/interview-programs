https://golang.org/cmd/cgo/
Cgo enables the creation of Go packages that call C code.

Using cgo with the go command:
------------------------------
To use cgo write normal Go code that imports a pseudo-package "C". 
The Go code can then refer to types such as C.size_t, variables such as C.stdout, or functions such as C.putchar.

If the import of "C" is immediately preceded by a comment, that comment, called the "preamble", is used as a header when compiling the C parts of the package. 
For example:
	// #include <stdio.h>
	// #include <errno.h>
	import "C"
	
The preamble may contain any C code, including function and variable declarations and definitions. 
These may then be referred to from Go code as though they were defined in the package "C". 
All names declared in the preamble may be used, even if they start with a lower-case letter. 
Exception: static variables in the preamble may not be referenced from Go code; static functions are permitted.


CFLAGS, CPPFLAGS, CXXFLAGS, FFLAGS and LDFLAGS may be defined with pseudo #cgo directives within these comments to tweak the behavior of the C, C++ or Fortran compiler. 
Values defined in multiple directives are concatenated together. The directive can include a list of build constraints limiting its effect to 
systems satisfying one of the constraints (see https://golang.org/pkg/go/build/#hdr-Build_Constraints for details about the constraint syntax). For example:
	// #cgo CFLAGS: -DPNG_DEBUG=1
	// #cgo amd64 386 CFLAGS: -DX86=1
	// #cgo LDFLAGS: -lpng
	// #include <png.h>
	import "C"
	
