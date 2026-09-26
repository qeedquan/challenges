/*

##Task: You have to write a function add which takes two binary numbers as strings and returns their sum as a string.

##Note:

You are not allowed to convert binary to decimal & vice versa.
The sum should contain No leading zeroes.
##Examples:

add('111','10'); => '1001'
add('1101','101'); => '10010'
add('1101','10111') => '100100'

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	assert(add("111", "10") == "1001")
	assert(add("1101", "101") == "10010")
	assert(add("1101", "10111") == "100100")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func add(a, b string) string {
	x := new(big.Int)
	y := new(big.Int)
	x.SetString(a, 2)
	y.SetString(b, 2)
	x.Add(x, y)
	return fmt.Sprintf("%b", x)
}
