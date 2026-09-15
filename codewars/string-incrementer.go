/*

Your job is to write a function which increments a string, to create a new string.

If the string already ends with a number, the number should be incremented by 1.
If the string does not end with a number. the number 1 should be appended to the new string.
Examples:

foo -> foo1

foobar23 -> foobar24

foo0042 -> foo0043

foo9 -> foo10

foo099 -> foo100

Attention: If the number has leading zeros the amount of digits should be considered.

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	assert(strinc("foo") == "foo1")
	assert(strinc("foo23") == "foo24")
	assert(strinc("foo0042") == "foo0043")
	assert(strinc("foo9") == "foo10")
	assert(strinc("foo099") == "foo100")
	assert(strinc("") == "1")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func strinc(input string) string {
	number, digits, one := new(big.Int), 1, big.NewInt(1)
	for index := len(input) - 1; index >= 0; index-- {
		if !('0' <= input[index] && input[index] <= '9') {
			suffix := input[index+1:]
			if len(suffix) > 0 {
				number.SetString(suffix, 10)
				digits = len(suffix)
				input = input[:index+1]
			}
			break
		}
	}
	number.Add(number, one)
	return fmt.Sprintf("%s%0*d", input, digits, number)
}
