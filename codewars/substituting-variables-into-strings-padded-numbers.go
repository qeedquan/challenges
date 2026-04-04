/*

Complete the solution so that it returns a formatted string. The return value should equal "Value is VALUE" where value is a 5 digit padded number.

Example:

solution(5) // should return "Value is 00005"

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	assert(solution(5) == "Value is 00005")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solution(value uint) string {
	number := fmt.Sprint(value)
	if len(number) < 5 {
		number = strings.Repeat("0", 5-len(number)) + number
	}
	return fmt.Sprint("Value is ", number)
}
