/*

Given an integer n, find the next number that follows the following requirements:

The next greater number is a number where each digit, from left to right, is greater than or equal to the previous one. For example, 1455:

1<4

4<5

5<=5

The next greater number has to be bigger than n

Testcases
10 -> 11
19 -> 22
99 -> 111
321 -> 333
1455 -> 1456
11123159995399999 -> 11123333333333333

This is code-golf, so shortest code wins!

These numbers make up A009994 - Numbers with digits in nondecreasing order.

*/

package main

import "math"

func main() {
	tab := []uint64{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19, 22, 23, 24, 25, 26, 27, 28, 29, 33, 34, 35, 36, 37, 38, 39, 44, 45, 46, 47, 48, 49, 55, 56, 57, 58, 59, 66, 67, 68, 69, 77, 78, 79, 88, 89, 99, 111, 112, 113, 114, 115, 116, 117, 118, 119, 122}

	assert(ng(10) == 11)
	assert(ng(19) == 22)
	assert(ng(99) == 111)
	assert(ng(321) == 333)
	assert(ng(1455) == 1456)

	x := uint64(0)
	for i := range tab {
		assert(x == tab[i])
		x = ng(x)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A009994
func ng(n uint64) uint64 {
	n += 1
	i := n
	for n != 0 && i < math.MaxUint64 {
		if n%10 < (n/10)%10 {
			i += 1
			n = i
		} else {
			n /= 10
		}
	}
	return i
}
