/*

Given an integer n, add a dot (".") as the thousands separator and return it in string format.

Example 1:

Input: n = 987
Output: "987"

Example 2:

Input: n = 1234
Output: "1.234"

Constraints:

    0 <= n <= 2^31 - 1

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	assert(sep(987) == "987")
	assert(sep(1234) == "1.234")
	assert(sep(123456789) == "123.456.789")
	assert(sep(1e6) == "1.000.000")
	assert(sep(41223) == "41.223")
	assert(sep(math.MaxUint32) == "4.294.967.295")
	for i := uint(0); i <= 999; i++ {
		assert(sep(i) == fmt.Sprint(i))
	}
	for i := uint(1000); i <= 99999; i++ {
		assert(sep(i) == fmt.Sprintf("%d.%03d", i/1000, i%1000))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sep(x uint) string {
	r := ""
	s := fmt.Sprint(x)
	i := len(s)
	for ; i > 3; i -= 3 {
		r = "." + s[i-3:i] + r
	}
	if i > 0 {
		r = s[:i] + r
	}
	return r
}
