/*

Description
The Gameboy stores tiles as 2 bit-per-pixel 8x8 images, thus 16 bytes. Every two bytes is a complete row with all of the Low-bits of each pixel in the first byte, and all of the High-bits of each pixel in the second.

Input
Input will be exactly 16 bytes, received through Standard IO in one of the following forms:

Array of bytes or strings
16 byte string
Per the Standard IO, these may be in a language convenient form (Deliminated string, on the stack, etc.)

Output
An image, Rendered or Saved, of the Gameboy Tile.

Scale and Aspect Ratio of each pixel is not fixed.

Each 2 bit colour of the Pallet may be anything so long as the Manhattan Distance of the RGB256 representation is atleast 48. Eg. #FFFFFF, #AAAAAA, #555555, #000000. Traditionally, although not a requirement, 00 is the lightest colour, and 11 is the darkest.

Examples
[FF, 00, 7E, FF, 85, 81, 89, 83, 93, 85, A5, 8B, C9, 97, 7E, FF]

A Pokemon Window
https://i.stack.imgur.com/xpqR1.png

[7C, 7C, 00, C6, C6, 00, 00, FE, C6, C6, 00, C6, C6, 00, 00, 00]

The letter A
https://i.stack.imgur.com/tHeTg.png

Final Notes
Standard Loopholes apply
An online demo, and more in-depth explanation of the implementation can be found HERE
This is code-golf, so fewest bytes wins! (The Gameboy only had 65536 bytes of Address Space, after all!)
Have Fun!

*/

package main

import (
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"os"
)

func main() {
	pal := [4]color.RGBA{
		{255, 255, 255, 255},
		{170, 170, 170, 255},
		{85, 85, 85, 255},
		{0, 0, 0, 255},
	}

	img1 := render([]uint8{0xFF, 0x00, 0x7E, 0xFF, 0x85, 0x81, 0x89, 0x83, 0x93, 0x85, 0xA5, 0x8B, 0xC9, 0x97, 0x7E, 0xFF}, 16, pal)
	img2 := render([]uint8{0x7C, 0x7C, 0x00, 0xC6, 0xC6, 0x00, 0x00, 0xFE, 0xC6, 0xC6, 0x00, 0xC6, 0xC6, 0x00, 0x00, 0x00}, 16, pal)

	writeimage("gb1.png", img1)
	writeimage("gb2.png", img2)
}

func render(data []uint8, scale int, pal [4]color.RGBA) *image.RGBA {
	bounds := image.Rect(0, 0, 8*scale, 8*scale)
	img := image.NewRGBA(bounds)

	y := 0
	for i := 0; i+1 < len(data); i += 2 {
		x := 0
		lo := data[i]
		hi := data[i+1]
		for bit := 7; bit >= 0; bit-- {
			tile := 0
			if lo&(1<<bit) != 0 {
				tile |= 1
			}
			if hi&(1<<bit) != 0 {
				tile |= 2
			}
			col := image.NewUniform(pal[tile])
			draw.Draw(img, image.Rect(x*scale, y*scale, (x+1)*scale, (y+1)*scale), col, image.ZP, draw.Src)
			x++
		}
		y++
	}

	return img
}

func writeimage(name string, img *image.RGBA) error {
	f, err := os.Create(name)
	if err != nil {
		return err
	}
	defer f.Close()

	err = png.Encode(f, img)
	xerr := f.Close()
	if err == nil {
		err = xerr
	}
	return err
}
