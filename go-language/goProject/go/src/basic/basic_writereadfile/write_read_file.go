/* The following example program writes data to a file, and then copies its contents to standard output. */
package main
import (
	"io/ioutil"
	"log"
	"fmt"
)

func main() {
    const filename = "E:\\goProject\\go\\src\\file.txt"

    err := ioutil.WriteFile(filename, []byte("Hello, Guru Prasad Patel\n"), 0644)
    if err != nil {
        log.Fatal(err)
    }

    b, err := ioutil.ReadFile(filename)
    if err != nil {
        log.Fatal(err)
    }

    fmt.Printf("%s", b)
}