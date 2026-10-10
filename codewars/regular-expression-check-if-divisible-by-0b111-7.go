/*

Create a regular expression capable of evaluating binary strings (which consist of only 1's and 0's) and determining whether the given string represents a number divisible by 7.

Note:

Empty strings should be rejected.
Your solution should reject strings with any character other than 0 and 1.
No leading 0's will be tested unless the string exactly denotes 0.

*/

package main

import (
	"fmt"
	"regexp"
)

func main() {
	for i := range 1000000 {
		s := fmt.Sprintf("%b", i)
		if isdiv7.MatchString(s) {
			assert(i%7 == 0)
		} else {
			assert(i%7 != 0)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var (
	isdiv7 = gen()
)

func gen() *regexp.Regexp {
	const (
		p00 = "0|111"
		p44 = "(1|00)0"
		p55 = "001*0"
		p04 = "100"
		p40 = "011"
		p05 = "1101*0|101"
		p50 = "01"
		p45 = "(1|00)1|0101*0"
		p54 = "1"

		pattern = "(((%s)(%s)*(%s))|%s)"
	)

	P00 := fmt.Sprintf(pattern, p04, p44, p40, p00)
	P55 := fmt.Sprintf(pattern, p54, p44, p45, p55)
	P05 := fmt.Sprintf(pattern, p04, p44, p45, p05)
	P50 := fmt.Sprintf(pattern, p54, p44, p40, p50)
	re := "^(" + fmt.Sprintf(pattern, P05, P55, P50, P00) + ")+$"
	return regexp.MustCompile(re)
}
