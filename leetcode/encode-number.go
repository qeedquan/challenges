/*

Given a non-negative integer num, Return its encoding string.
The encoding is done by converting the integer to a string using a secret function that you should deduce from the following table:

0 | ""
1 | "0"
2 | "1"
3 | "00"
4 | "01"
5 | "10"
6 | "11"
7 | "000"

Example 1:
Input: num = 23 Output: "1000"

Example 2:
Input: num = 107 Output: "101100"


Constraints:

0 <= num <= 10^9

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	tab := []string{"", "0", "1", "00", "01", "10", "11", "000"}
	for i, r := range tab {
		assert(encode(i) == r)
	}
	assert(encode(23) == "1000")
	assert(encode(107) == "101100")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://massivealgorithms.blogspot.com/2019/12/leetcode-1256-encode-number.html
func encode(n int) string {
	if n < 1 {
		return ""
	}

	l := int(math.Log2(float64(n + 1)))
	r := (n + 1) & ((1 << l) - 1)
	return fmt.Sprintf("%0*b", l, r)
}
