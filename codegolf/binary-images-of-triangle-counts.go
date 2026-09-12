/*

My challenges tend to be a little bit hard and unattractive. So here something easy and fun.

Alcuin's sequence
Alcuin's sequence A(n) is defined by counting triangles. A(n) is the number of triangles with integer sides and perimeter n. This sequence is called after Alcuin of York.

The first few elements of this sequence, starting with n = 0 are:

0, 0, 0, 1, 0, 1, 1, 2, 1, 3, 2, 4, 3, 5, 4, 7, 5, 8, 7, 10, 8, ...
For instance A(9) = 3, because the only triangles with integer sides and perimeter 9 are 1 - 4 - 4, 3 - 3 - 3 and 2 - 3 - 4. You can see the 3 valid triangles down below.

https://i.stack.imgur.com/GVdTq.png

There are some quite interesting pattern in this sequence. For instance A(2*k) = A(2*k - 3).

For more information, see A005044 on OEIS.

Challenge
But your challenge is about the binary representation of these numbers. If we convert each sequence number to it's binary representation, put them in column vectors and line them up, it creates a quite interesting binary picture.

In the following picture you can see the binary representation of the sequence numbers A(0), A(1), ..., A(149). In the first column you can see the binary representation of A(1), in the second column the representation of A(1), and so on.

https://i.stack.imgur.com/tv3jS.png

You can see some sort of repeating pattern in this picture. It even looks kinda like fractals, if you look for instance at the image with the sequence numbers A(600), A(601), ..., A(899).

https://i.stack.imgur.com/vWbcz.png

Your job is to generate such an image. Your function, your script will receive two integer 0 <= m < n, and it has to generate the binary image of Alcuin's sequence A(m), A(m+1), A(m+2), ..., A(n-2), A(n-1). So the input 0, 150 generates the first picture, the input 600, 900 the second picture.

You can use any popular graphics format you want. Let's say every format that can be converted to png using image.online-convert.com. Alternatively, you may display the image on screen. No leading white rows are allowed!

This is code-golf. So the shortest code (in bytes) wins.

*/

package main

import (
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"math"
	"os"
	"slices"
)

func main() {
	tab := []int{0, 0, 0, 1, 0, 1, 1, 2, 1, 3, 2, 4, 3, 5, 4, 7, 5, 8, 7, 10, 8, 12, 10, 14, 12, 16, 14, 19, 16, 21, 19, 24, 21, 27, 24, 30, 27, 33, 30, 37, 33, 40, 37, 44, 40, 48, 44, 52, 48, 56, 52, 61, 56, 65, 61, 70, 65, 75, 70, 80, 75, 85, 80, 91, 85, 96, 91, 102, 96, 108, 102, 114, 108, 120}

	for i := range tab {
		assert(alcuin(i) == tab[i])
	}

	png.Encode(os.Stdout, makeimage(1000))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A005044
func alcuin(n int) int {
	a := n * n
	b := 48
	if n&1 != 0 {
		a = (n + 3) * (n + 3)
	}
	return a/b + truth(a%b >= b/2)
}

func truth(b bool) int {
	if b {
		return 1
	}
	return 0
}

func ilog2(x int) int {
	return int(math.Ceil(math.Log2(float64(x))))
}

func makeimage(n int) *image.RGBA {
	v := []int{}
	for i := 0; i < n; i++ {
		v = append(v, alcuin(i))
	}

	w := n
	h := ilog2(slices.Max(v))
	r := image.Rect(0, 0, w, h)
	m := image.NewRGBA(r)
	draw.Draw(m, r, image.NewUniform(color.White), image.ZP, draw.Src)
	for x := 0; x < w; x++ {
		for y := 0; y < h; y++ {
			if v[x]&(1<<y) != 0 {
				m.SetRGBA(x, y, color.RGBA{0, 0, 0, 255})
			}
		}
	}

	return m
}
