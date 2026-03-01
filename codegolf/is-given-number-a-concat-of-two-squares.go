/*

Given a positive integer, determine if it can be represented as a concatenation of two square numbers. Concatenated numbers may not begin with 0 (except for 0). Any leading zeros in input should be ignored.

Examples

11 -> true // because 1 and 1 are squares
90 -> true // because 9 and 0 are squares
1001 -> true // because 100 and 1 are squares
144100 -> true // because 144 and 100 are squares
151296561 -> true // because 15129 and 6561 are squares
164 -> true // because 1 and 64 are squares (also 16 and 4)
101 -> false // can't be 1+01 as a number may not begin with 0
016 -> false // leading 0 is ignored and 16 doesn't count
9 -> false // need two squares
914 -> false // need two squares (there are three)

Task

Given a positive integer return a value indicating if it is a concatenation of two squares.

This is code-golf the goal is to minimize the size of the source code as measured in bytes.

*/

package main

import (
	"math"
	"strconv"
)

func main() {
	assert(ccs("") == false)
	assert(ccs("0") == false)
	assert(ccs("00") == false)
	assert(ccs("11") == true)
	assert(ccs("90") == true)
	assert(ccs("1001") == true)
	assert(ccs("144100") == true)
	assert(ccs("151296561") == true)
	assert(ccs("164") == true)
	assert(ccs("101") == false)
	assert(ccs("016") == false)
	assert(ccs("9") == false)
	assert(ccs("914") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func ccs(s string) bool {
	for i := 1; i < len(s); i++ {
		if (s[:i] != "0" && psq(s[:i])) && psq(s[i:]) {
			return true
		}
	}
	return false
}

func psq(s string) bool {
	if s == "" || (s[0] == '0' && s != "0") {
		return false
	}

	n, err := strconv.Atoi(s)
	if err != nil || n < 0 {
		return false
	}

	x := int(math.Sqrt(float64(n)))
	return x*x == n
}
