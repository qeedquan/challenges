/*

You will be given a string.

You need to return an array of three strings by gradually pulling apart the string.

You should repeat the following steps until the string length is 1:

a) remove the final character from the original string, add to solution string 1. b) remove the first character from the original string, add to solution string 2.

The final solution string value is made up of the remaining character from the original string, once originalstring.length == 1.

Example:

"exampletesthere" becomes: ["erehtse","example","t"]

The Kata title gives a hint of one technique to solve.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test("reusetestcasesbitcointakeovertheworldmaybewhoknowsperhaps", [3]string{"spahrepswonkohwebyamdlroweht", "reusetestcasesbitcointakeove", "r"})
	test("turnsoutrandomtestcasesareeasierthanwritingoutbasicones", [3]string{"senocisabtuognitirwnahtreis", "turnsoutrandomtestcasesaree", "a"})
	test("exampletesthere", [3]string{"erehtse", "example", "t"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r [3]string) {
	p := popshift(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func popshift(s string) [3]string {
	r := [3]string{}
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		r[0] += string(s[j])
		r[1] += string(s[i])
	}
	if s != "" {
		r[2] = string(s[len(s)/2])
	}
	return r
}
