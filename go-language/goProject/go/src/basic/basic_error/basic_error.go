/*
Errors:
--------
Go programs express error state with error values.
The error type is a built-in interface similar to "fmt.Stringer":
	type error interface {
		Error() string
	}
(As with fmt.Stringer, the fmt package looks for the error interface when printing values.)
Functions often return an error value, and calling code should handle errors by testing whether the error equals nil.
	i, err := strconv.Atoi("42")
	if err != nil {
		fmt.Printf("couldn't convert number: %v\n", err)
		return
	}
	fmt.Println("Converted integer:", i)
	
NOTE: A nil error denotes success; a non-nil error denotes failure.

Readers:
---------
The io package specifies the 'io.Reader' interface, which represents the read end of a stream of data.
The Go standard library contains many implementations of these interfaces, including "files, network connections, compressors, ciphers, and others".
The io.Reader interface has a Read method: 
		func (T) Read(b []byte) (n int, err error)
Read populates the given byte slice with data and returns the number of bytes populated and an error value. It returns an io.EOF error when the stream ends.

Images:
--------
Package image defines the Image interface:
package image
type Image interface {
    ColorModel() color.Model
    Bounds() Rectangle
    At(x, y int) color.Color
}
Note: the Rectangle return value of the Bounds method is actually an image.Rectangle, as the declaration is inside package image.
The color.Color and color.Model types are also interfaces, but we'll ignore that by using the predefined implementations color.RGBA and color.RGBAModel. 
These interfaces and types are specified by the image/color package

*/

package main
import (
	"fmt"
	"time"
	"math"
	"io"
	"os"
	"strings"
	"golang.org/x/tour/reader"
	"image"
)

type MyError struct {
	When time.Time
	What string
}
func (e *MyError) Error() string {
	return fmt.Sprintf("at %v, %s",	e.When, e.What)
}
func run() error {
	return &MyError{time.Now(), "it didn't work",}
}

/*
Exercise: Errors
Copy your Sqrt function from the earlier exercise and modify it to return an error value.
Sqrt should return a non-nil error value when given a negative number, as it doesn't support complex numbers. */

/* Note: A call to fmt.Sprint(e) inside the Error method will send the program into an infinite loop.  
   You can avoid this by converting e first: fmt.Sprint(float64(e)). Why? */
func (e ErrNegativeSqrt) Error() string {
	return fmt.Sprintf("cannot Sqrt negative number: %g", float64(e))
	// below runtime: goroutine stack exceeds 250000000-byte limit, fatal error: stack overflow
	//return fmt.Sprint("cannot Sqrt negative number: ", e)
}
type ErrNegativeSqrt float64
func Sqrt(x float64) (float64, error) {
	if x < 0 {
		return x, ErrNegativeSqrt(x)
	}
	return math.Sqrt(x), nil
}

/* Exercise: Readers
   Implement a Reader type that emits an infinite stream of the ASCII character 'A'. */
type MyReader struct{ str string }
// TODO: Add a Read([]byte) (int, error) method to MyReader.
func (mr MyReader) Read(b []byte) (int, error) {
	for i := range b {
	//for i := 0; i < len(b); i++ {
		//You can either use 65 or 'A'
		b[i] = 65
	}
	return len(b), nil
}

/* Exercise: rot13Reader
A common pattern is an io.Reader that wraps another io.Reader, modifying the stream in some way.
For example, the gzip.NewReader function takes an io.Reader (a stream of compressed data) and returns a *gzip.
Reader that also implements io.Reader (a stream of the decompressed data).

Implement a rot13Reader that implements io.Reader and reads from an io.Reader, modifying the stream 
by applying the rot13 substitution cipher to all alphabetical characters.

The rot13Reader type is provided for you. Make it an io.Reader by implementing its Read method.
*/
type rot13Reader struct {
	r io.Reader
}
func (rot *rot13Reader) Read(p []byte) (n int, err error) {
	n, err = rot.r.Read(p)
	for i, c := range p {
		switch {
		case c >= 'A' && c <= 'M' || c >= 'a' && c <= 'm':
			p[i] += 13
		case c >= 'N' && c <= 'Z' || c >= 'n' && c <= 'z':
			p[i] -= 13
		}
	}
	return
}

func main() {
	if err := run(); err != nil {
		fmt.Println(err)
	}
	
	fmt.Println(Sqrt(2))
	fmt.Println(Sqrt(-2))
	
	// The example code creates a strings.Reader and consumes its output 8 bytes at a time.
	r := strings.NewReader("Hello, Reader!")
	b := make([]byte, 8)
	for {
		n, err := r.Read(b)
		fmt.Printf("n = %v err = %v b = %v\n", n, err, b)
		fmt.Printf("b[:n] = %q\n", b[:n])
		if err == io.EOF {
			break
		}
	}
	
	// Exercise: Readers
	reader.Validate(MyReader{})
	//r1 := MyReader{"aaaaxxaaaaaaxxaaaaxxaaaaaxxaaaaaaaa"}
	r1 := strings.NewReader("aaaaxxaaaaaaxxaaaaxxaaaaaxxaaaaaaaa")
	b1 := make([]byte, 9)
	for {
		n, err := r1.Read(b1)
		fmt.Printf("n = %v err = %v b = %v\n", n, err, b1)
		fmt.Printf("b1[:n] = %q\n", b1[:n])
		if err == io.EOF {
			break
		}
	}
	
	// Exercise: rot13Reader - A common pattern is an io.Reader that wraps another io.Reader, modifying the stream in some way.
	str := strings.NewReader("Lbh penpxrq gur pbqr!")
	rtr := rot13Reader{str}
	io.Copy(os.Stdout, &rtr)
	
	// Images Package image defines the Image interface:
	m := image.NewRGBA(image.Rect(0, 0, 100, 100))
	fmt.Println("\n", m.Bounds())
	fmt.Println(m.At(0, 0).RGBA())
}
