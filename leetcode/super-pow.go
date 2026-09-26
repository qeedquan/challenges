/*

Your task is to calculate a^b mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example 1:

Input: a = 2, b = [3]
Output: 8
Example 2:

Input: a = 2, b = [1,0]
Output: 1024
Example 3:

Input: a = 1, b = [4,3,3,8,5,2]
Output: 1


Constraints:

1 <= a <= 2^31 - 1
1 <= b.length <= 2000
0 <= b[i] <= 9
b does not contain leading zeros.

*/

package main

import (
	"math/big"
)

func main() {
	assert(superpow(2, []int64{3}) == 8)
	assert(superpow(2, []int64{1, 0}) == 1024)
	assert(superpow(1, []int64{4, 3, 3, 8, 5, 2}) == 1)
	assert(superpow(0, []int64{1, 3, 3, 7}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func superpow(a int64, b []int64) int64 {
	var (
		ten = big.NewInt(10)
		mod = big.NewInt(1337)
	)

	x := big.NewInt(a)
	y := big.NewInt(0)
	for _, p := range b {
		y.Mul(y, ten)
		y.Add(y, big.NewInt(p))
	}
	x.Exp(x, y, mod)

	return x.Int64()
}
