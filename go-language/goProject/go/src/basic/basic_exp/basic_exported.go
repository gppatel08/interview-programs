/*
Exported names:-
----------------
In Go, a name is exported if it begins with a CAPITAL letter. For example, Pizza is an exported name, as is Pi, which is exported from the math package.
'pizza' and 'pi' do not start with a CAPITAL letter, so they are not exported.

Note: When importing a package, you can refer only to its exported names. Any "unexported" names are not accessible from outside the package.

Run the code. Notice the error message.
To fix the error, rename math.pi to math.Pi and try it again.
src\basic\basic_exp\basic_exported.go:22:14: cannot refer to unexported name math.pi
src\basic\basic_exp\basic_exported.go:22:14: undefined: math.pi
*/

package main

import (
	"fmt"
	"math"
)

func main() {
	//fmt.Println(math.pi)
	fmt.Println(math.Pi)
}