/*

In a string of Latin letters and spaces, replace each sequence of characters "ab" with "ups".

Input
One string that contains Latin letters and spaces.

Output
Print the updated string.

Examples

Input #1
abrakadabra

Answer #1
upsrakadupsra

*/

package main

import "strings"

func main() {
	assert(solve("abrakadabra") == "upsrakadupsra")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) string {
	return strings.Replace(s, "ab", "ups", -1)
}
