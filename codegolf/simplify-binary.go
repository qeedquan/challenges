/*

Challenge
Given a binary number as input through any means, "simplify" the number using a full program or a function.

Input
[binary]
binary is a number in binary that is over 0.
Output
Take the input, convert it to base 10 without using a builtin, then if that number contains only 1s and 0s, convert it into a base 10 number as if it were another binary number. Repeat the process until the number cannot be read in binary and output that number.

Other information
If the input is 1, simply output 1. Your program should not go on infinitely simplifying 1.

This is code golf, so shortest answer in bytes by Tuesday (November 17th) wins.

If anything is confusing, leave a comment specifying what I need to clear up and I will edit it accordingly.

Builtins for base conversion are not allowed.

Examples
     Input | Output

         1 | 1
      1010 | 2
      1011 | 3
   1100100 | 4
   1100101 | 5
1111110011 | 3

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	assert(simplify(1) == 1)
	assert(simplify(1010) == 2)
	assert(simplify(1011) == 3)
	assert(simplify(1100100) == 4)
	assert(simplify(1100101) == 5)
	assert(simplify(1111110011) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func simplify(n int64) int64 {
	for n > 1 {
		m, err := strconv.ParseInt(fmt.Sprint(n), 2, 64)
		if err != nil {
			break
		}
		n = m
	}
	return n
}
