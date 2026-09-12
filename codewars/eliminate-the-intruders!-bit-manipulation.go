/*

Task

You are given a string representing a number in binary. Your task is to delete all the unset bits in this string and return the corresponding number (after keeping only the '1's).

In practice, you should implement this function:

long eliminate_unset_bits(const char* number);

Examples

eliminate_unset_bits("11010101010101") ->  255 (= 11111111)
eliminate_unset_bits("111") ->  7
eliminate_unset_bits("1000000") -> 1
eliminate_unset_bits("000") -> 0

*/

package main

import "strings"

func main() {
	assert(eliminate("11010101010101") == 0xff)
	assert(eliminate("111") == 7)
	assert(eliminate("1000000") == 1)
	assert(eliminate("000") == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eliminate(s string) int {
	return (1 << strings.Count(s, "1")) - 1
}
