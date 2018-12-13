package main

import "golang.org/x/tour/pic"

func Pic(dx, dy int) [][]uint8 {
	p := make([][]uint8, dy)
	for y := range p {
		p[y] = make([]uint8, dx)
		for x := 0; x < dx; x++ {
			p[y][x] = uint8(x^y)
		}
	}
	return p
}

func Pic_1(dx, dy int) [][]uint8 {
	sl := make([][]uint8, dy)
	for i := range sl {
		sl[i] = make([]uint8, dx)
		for j := 0; j < dx; j++ {
			sl[i][j] = uint8((i+j)/2 + i ^ j)
		}
	}
	return sl
}

func main() {
	pic.Show(Pic)
	pic.Show(Pic_1)
}
