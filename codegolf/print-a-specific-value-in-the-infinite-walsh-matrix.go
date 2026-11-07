/*

The Walsh matrix is an interesting fractal matrix with the property that every single value in a Walsh matrix has a value of either -1 or 1. Additionally, the size of a Walsh matrix is always a power of 2.

Because each Walsh matrix is identical to the top-left quarter of the immediately higher-order Walsh matrix, we can create a generalized "infinite Walsh matrix" by considering the limit of the sequence of Walsh matrices of order N, as N goes to infinity. From here on, we will call this infinite generalization the Walsh matrix.

Your task is to build a program that takes the coordinates of a location in the Walsh matrix and returns the value that occurs there.

Your program will accept two integers x and y as input (in any form you choose), and output the value that appears in the x+1th row of the y+1th column of the Walsh matrix. For example, the input

2 5
will return 1, as the 3rd row in the 6th column of the Walsh matrix has a value of 1. The input

6 4
will return -1, as the 7th row in the 5th column of the Walsh matrix has a value of -1. The input

2834719 394802
will return -1, as the 2384720th row of the 394803rd column has a value of -1.

The shortest code to do this in any language wins.

*/

package main

import "math/bits"

func main() {
	assert(walshvalue(2, 5) == 1)
	assert(walshvalue(6, 4) == -1)
	assert(walshvalue(2834719, 394802) == -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@Blckknght

The algorithm is this:

For coordinates X and Y, find X & Y, the bitwise AND of their values.
Count the number of 1 bits in X & Y. This is the number of times the requested coordinate is in the bottom right quadrant of a level of the matrix.
If the count is odd, the result is -1. If the count is even, the result is 1.

*/

func walshvalue(x, y uint) int {
	if bits.OnesCount(x&y)&1 != 0 {
		return -1
	}
	return 1
}
