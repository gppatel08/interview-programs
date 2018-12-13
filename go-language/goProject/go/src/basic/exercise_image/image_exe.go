/*
Exercise: Images
Remember the picture generator you wrote earlier? Let's write another one, but this time it will return an implementation of image.
Image instead of a slice of data. Define your own Image type, implement the necessary methods, and call pic.ShowImage.
Bounds should return a image.Rectangle, like image.Rect(0, 0, w, h).
ColorModel should return color.RGBAModel.
At should return a color; the value v in the last picture generator corresponds to color.RGBA{v, v, 255, 255} in this one.
*/

package main

import (
	"image"
	"image/color"
	"math/rand"
	"time"
	"golang.org/x/tour/pic"
)

type Image struct {
	Width, Height int
	colr          uint8
}

func (r *Image) Bounds() image.Rectangle {
	return image.Rect(0, 0, r.Width, r.Height)
}

func (r *Image) ColorModel() color.Model {
	return color.RGBAModel
}

func (r *Image) At(x, y int) color.Color {
	return color.RGBA{
		randUint8(x%255, 255),
		randUint8(0, y%255+1),
		randUint8(0, (x^y)%255+1),
		randUint8(200, 255)}
}

func randUint8(min int, max int) uint8 {
	return uint8(min + rand.Intn(max - min))
}

func init() {
	rand.Seed(time.Now().UTC().UnixNano())
}

func main() {
	m := Image{500, 500, 0}
	pic.ShowImage(&m)
}