package main

import (
	"io"
	"os"
	"strings"
)

type rot13Reader struct {
	in io.Reader
}

func (rot *rot13Reader) Read(p []byte) (n int, err error) {
	n, err = rot.in.Read(p)
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
	s := strings.NewReader("Lbh penpxrq gur pbqr!")
	r := rot13Reader{s}
	io.Copy(os.Stdout, &r)
}