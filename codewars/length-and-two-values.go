/*

Given an integer n and two other values, build an array of size n filled with these two values alternating.

Examples
5, true, false     -->  [true, false, true, false, true]
10, "blue", "red"  -->  ["blue", "red", "blue", "red", "blue", "red", "blue", "red", "blue", "red"]
0, "one", "two"    -->  []

Good luck!

*/

package main

import "fmt"

func main() {
	fmt.Println(alt(5, true, false))
	fmt.Println(alt(10, "blue", "red"))
	fmt.Println(alt(0, "one", "two"))
}

func alt(n int, x, y any) any {
	r := make([]any, n)
	for i := 0; i < n; i += 2 {
		r[i] = x
	}
	for i := 1; i < n; i += 2 {
		r[i] = y
	}
	return r
}
