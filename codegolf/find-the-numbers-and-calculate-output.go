/*

Objective
Given an input list of 6 distinct digits, find 3 numbers a, b and c such that a × b = c, with a having 2 digits, b having 1 digit and c having 3 digits. In a more visual way, your program must arrange those 6 digits in the boxes of this image:

https://i.stack.imgur.com/3veFP.jpg

If more than one solution exists, you may output any of them.

Input
6 distinct digits. You may take them in any reasonable way for your language.

Output
The 3 numbers a, b and c. The output format is relatively free, as long as the 3 numbers are separated and are always printed in the same order (but not necessarily in the order a, b, c).

Test Cases
1, 2, 3, 4, 5, 6 -> 54,3,162
2, 3, 4, 5, 6, 7 -> 57,6,342 or 52,7,364

Scoring
The shortest code in bytes wins.

*/

package main

import "fmt"

func main() {
	test([6]int{1, 2, 3, 4, 5, 6}, 54, 3, 162)
	test([6]int{2, 3, 4, 5, 6, 7}, 52, 7, 364)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x [6]int, ra, rb, rc int) {
	a, b, c := solve(x)
	fmt.Println(a, b, c)
	assert(a == ra)
	assert(b == rb)
	assert(c == rc)
}

func solve(x [6]int) (int, int, int) {
	z0 := 0
	for i := range x {
		z0 |= 1 << x[i]
	}

	for a := 10; a <= 99; a++ {
		for b := 1; b <= 9; b++ {
			c := a * b
			z1 := 1<<(a/10) | 1<<(a%10)
			z1 |= 1 << b
			z1 |= 1<<(c/100) | 1<<((c/10)%10) | 1<<(c%10)
			if z0 == z1 {
				return a, b, c
			}
		}
	}

	return 0, 0, 0
}
