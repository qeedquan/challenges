/*

One way to generalize the concept of a range from the integers to the Gaussian integers (complex numbers with integer real and imaginary part) is taking all numbers contained in the rectangle enclosed by the two ends of the range. So the range between two Gaussian integers a+bi and c+di would be all Gaussian integers x+iy with min(a,c)<=x<=max(a,c) and min(b,d)<=y<=max(b,d).

For instance the range from 1-i to -1+2i would be the following set of numbers:

-1-i, -1, -1+i, -1+2i, -i, 0, i, 2i, 1-i, 1, 1+i, 1+2i

Your task is given two numbers a+bi and c+di to return the 2D range spanned by a+bi to c+di

Examples
1       5      -> [1,2,3,4,5]
-1      -3     -> [-3,-2,-1]
1+i     1+i    -> [1+i]
1-i     -1+2i  -> [-1-i, -1, -1+i, -1+2i, -i, 0, i, 2i, 1-i, 1, 1+i, 1+2i]
1-i     2+i    -> [1-i, 1, 1+i, 2-i, 2, 2+i]
-2-i     1+3i  -> [-2-i, -2, -2+i, -2+2i, -2+3i, -1-i, -1, -1+i, -1+2i, -1+3i, -i, 0, i, 0+2i, 0+3i, 1-i, 1, 1+i, 1+2i, 1+3i]

Rules
You can use pairs of integers to Input/Output Complex numbers
If your language has a built-it for generating this range, please consider adding a non built-in answer as well
The elements in the range can be sorted in any order
Each element can only appear once in the range
This is code-golf the shortest solution (per language) wins

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(1, 5, []complex128{1, 2, 3, 4, 5})
	test(-1, -3, []complex128{-3, -2, -1})
	test(1+1i, 1+1i, []complex128{1 + 1i})
	test(1-1i, -1+2i, []complex128{-1 - 1i, -1, -1 + 1i, -1 + 2i, -1i, 0, 1i, 2i, 1 - 1i, 1, 1 + 1i, 1 + 2i})
	test(1-1i, 2+1i, []complex128{1 - 1i, 1, 1 + 1i, 2 - 1i, 2, 2 + 1i})
	test(-2-1i, 1+3i, []complex128{-2 - 1i, -2, -2 + 1i, -2 + 2i, -2 + 3i, -1 - 1i, -1, -1 + 1i, -1 + 2i, -1 + 3i, -1i, 0, 1i, 0 + 2i, 0 + 3i, 1 - 1i, 1, 1 + 1i, 1 + 2i, 1 + 3i})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b complex128, r []complex128) {
	p := span(a, b)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func span(a, b complex128) []complex128 {
	x0 := min(real(a), real(b))
	x1 := max(real(a), real(b))
	y0 := min(imag(a), imag(b))
	y1 := max(imag(a), imag(b))

	r := []complex128{}
	for x := x0; x <= x1; x++ {
		for y := y0; y <= y1; y++ {
			r = append(r, complex(x, y))
		}
	}
	return r
}
