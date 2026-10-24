/*

You are given a string of words and numbers. Extract the expression including:

the operator: either addition ("gains") or subtraction ("loses")
the two numbers that we are operating on
Return the result of the calculation.

Notes:

"loses" and "gains" are the only two words describing operators
No fruit debts nor bitten apples = The numbers are integers and no negatives
Examples
"Panda has 48 apples and loses 4"  -->  44
"Jerry has 34 apples and gains 6"  -->  40

Should be a nice little kata for you :)

*/

package main

import (
	"regexp"
	"strconv"
	"strings"
)

func main() {
	assert(calc("Panda has 48 apples and loses 4") == 44)
	assert(calc("Jerry has 34 apples and gains 6") == 40)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func calc(s string) int {
	re := regexp.MustCompile(`\d+`)
	m := re.FindAllString(s, -1)
	if len(m) != 2 {
		return 0
	}

	x, _ := strconv.Atoi(m[0])
	y, _ := strconv.Atoi(m[1])
	r := 0
	switch {
	case strings.Index(s, "gains") >= 0:
		r = x + y
	case strings.Index(s, "loses") >= 0:
		r = x - y
	}
	return r
}
