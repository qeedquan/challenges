/*

Challenge
Given a positive integer N, repeat each of its digits d1,d2,d3,⋯,dn a number of times corresponding to its position in N.
In other words, each digit dk should be repeated k times (for each 1≤k≤n, 1-indexed), thus creating the new number:

d1d2d2d3d3d3...dndndndn...dn
                 n times

Then, write it down both horizontally and vertically and fill in the blanks with copies of the digit that corresponds to the greater index between the column index and the row index of the blank space.
The final output should look like this:

[ d1d2d2d3d3d3...]
[ d2d2d2d3d3d3...]
[ d3d3d3d3d3d3...]
[ ...............]

Specs
You may take N
 as an integer, a string, a list of digits or a list of characters representing the digits.
 The output can be a newline-separated string, a list of strings / integers or a list of lists of characters / digits, but please include a pretty-print version too, if possible.
 If the output is a newline-separated string, it is also acceptable to:

have leading / trailing whitespace, as long as the visual appearance of the output doesn't change
separate the columns using a consistent amount spaces or the rows with a consistent (non-zero) amount of newlines
You can take input and provide output through any standard method, while taking note that these loopholes are forbidden by default.
This is code-golf, so try to complete the task in the least bytes you can manage in your language of choice.

Test cases
65:

655
555
555

---------------

203:

200333
000333
000333
333333
333333
333333

--------------

233:

233333
333333
333333
333333
333333
333333

---------------

5202:

5220002222
2220002222
2220002222
0000002222
0000002222
0000002222
2222222222
2222222222
2222222222
2222222222

---------------

12345:

122333444455555
222333444455555
222333444455555
333333444455555
333333444455555
333333444455555
444444444455555
444444444455555
444444444455555
444444444455555
555555555555555
555555555555555
555555555555555
555555555555555
555555555555555

*/

package main

import (
	"fmt"
	"image"
	"sort"
)

func main() {
	mosaic("")
	mosaic("1")
	mosaic("65")
	mosaic("203")
	mosaic("233")
	mosaic("5202")
	mosaic("12345")
}

func mosaic(s string) {
	fmt.Printf("%q\n", s)
	n := triangular(len(s))
	for y := range n {
		for x := range n {
			fmt.Printf("%c", at(s, x, y))
		}
		fmt.Println()
	}
	fmt.Println()
}

func at(s string, x, y int) byte {
	p := image.Pt(x, y)
	i := sort.Search(len(s), func(x int) bool {
		n := triangular(x)
		r := image.Rect(0, 0, n, n)
		return p.In(r)
	})

	if i-1 >= len(s) {
		return '?'
	}
	return s[i-1]
}

func triangular(n int) int {
	return n * (n + 1) / 2
}
