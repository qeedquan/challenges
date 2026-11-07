/*

The challenge here is to take a string and output all its rotations, by repeatedly moving the first character to the end, once per character in the string, ending with the original string:

john -> ohnj, hnjo, njoh, john
You may also cycle in the other direction, moving characters from the end:

john -> njoh, hnjo, ohnj, john
You should still output one rotation per letter even if the original word is reached before that:

heehee -> eeheeh, eheehe, heehee, eeheeh, eheehe, heehee
Character arrays are allowed, as long as the result works as shown above.

Shortest answer wins!

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test("john", []string{"ohnj", "hnjo", "njoh", "john"})
	test("heehee", []string{"eeheeh", "eheehe", "heehee", "eeheeh", "eheehe", "heehee"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []string) {
	p := rotations(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func rotations(s string) []string {
	r := []string{}
	for i := range s {
		r = append(r, s[i+1:]+s[:i+1])
	}
	return r
}
