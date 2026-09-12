/*

Dot Calculator
You have to write a calculator that receives strings for input. The dots will represent the number in the equation. There will be dots on one side, an operator, and dots again after the operator. The dots and the operator will be separated by one space.

Here are the following valid operators :

+ Addition
- Subtraction
* Multiplication
// Integer Division

Your Work (Task)
You'll have to return a string that contains dots, as many the equation returns. If the result is 0, return the empty string. When it comes to subtraction, the first number will always be greater than or equal to the second number.

Examples (Input => Output)
* "..... + ..............." => "...................."
* "..... - ..."             => ".."
* "..... - ."               => "...."
* "..... * ..."             => "..............."
* "..... * .."              => ".........."
* "..... // .."             => ".."
* "..... // ."              => "....."
* ". // .."                 => ""
* ".. - .."                 => ""

*/

package main

import (
	"strings"
)

func main() {
	assert(calc("..... + ...............") == "....................")
	assert(calc("..... - ...") == "..")
	assert(calc("..... - .") == "....")
	assert(calc("..... * ...") == "...............")
	assert(calc("..... * ..") == "..........")
	assert(calc("..... // ..") == "..")
	assert(calc("..... // .") == ".....")
	assert(calc(". // ..") == "")
	assert(calc(".. - ..") == "")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func calc(s string) string {
	t := strings.Split(s, " ")
	if len(t) != 3 {
		return "invalid"
	}

	r := 0
	x := strings.Count(t[0], ".")
	y := strings.Count(t[2], ".")
	switch t[1] {
	case "+":
		r = x + y
	case "-":
		r = x - y
	case "*":
		r = x * y
	case "//":
		if y != 0 {
			r = x / y
		}
	default:
		return "invalid"
	}
	return strings.Repeat(".", r)
}
