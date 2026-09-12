/*

Write a program that implements the following encryption scheme:

It reads in some string of data of length N. Then, lay out that string in the smallest possible perfect power of two square that can fit the data.

For example, "My country, tis of thee" is 23 characters long. Therefore, it fits into a 5x5 square 25 characters long like this:

My co
untry
, tis
 of t
hee
However, when we constrain it to be a power of two, instead we end up with an 8x8 square, and laying it out looks like

My count
ry, tis
of thee
However, the encrytion part happens when, instead of laying out letters of the square from left to right as above, you lay out the square using a Z-order code instead, like so.

Myouofhe
 cnt te
ryti
, s
Write a program that reads a string from standard input and can encrypt to a z-order square, and vice-versa

*/

package main

import "fmt"

func main() {
	fmt.Printf("%q\n", crypt('e', "My country, tis of thee"))
	fmt.Printf("%q\n", crypt('d', "Myouofhe cnt te ryti    , s"))
}

func crypt(op rune, input string) string {
	width := getsquare(input)
	square := width * width
	output := make([]byte, square)
	for index := range square {
		zindex := zorder(index, width)
		index0 := index
		index1 := zindex
		if op == 'd' {
			index0, index1 = index1, index0
		}
		if index0 >= len(input) {
			output[index1] = ' '
		} else {
			output[index1] = input[index0]
		}
	}
	return string(output)
}

func zorder(position, width int) int {
	count, x, y := 1, 0, 0
	for position > 0 {
		if position&0x1 != 0 {
			x += count
		}
		if position&0x2 != 0 {
			y += count
		}
		position >>= 2
		count += count
	}
	return y*width + x
}

func getsquare(input string) int {
	width := 2
	square := 0
	length := len(input)
	for square < length {
		width += width
		square = width * width
	}
	return width
}
