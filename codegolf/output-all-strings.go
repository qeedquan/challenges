/*

Given a set of letters, output all strings made of those letters. (This is Kleene star of the set.) For example, for {'a','b'}, the strings are:

'', 'a', 'b', 'aa', 'ab', 'ba', 'bb', 'aaa', 'aab', ...
Input: A non-empty collection of distinct letters a..z. These may be characters or single-character strings.

Output: All strings in those letters, in any order, without repeats. You may use lists of chars as strings.

This is an infinite list, so you can output it by:

Running forever writing more and more strings. These strings can be written in any flat separated format, meaning that they you can tell where each string ends, but the strings aren't subdivided into groups.
Taking a number n as input and outputting the first n strings in any flat separated format
Yielding each string in turn from a generator object
Producing an infinite object
Be sure that your method eventually produces every string in the output, since it's possible to produce infinitely many strings from the set while never getting to some strings.

You may not output it by

Producing the nth string given n
Providing a membership oracle that decides if a given string belongs to the set
Built-ins are allowed, but I ask voters to give attention to answers that implement the operation themselves over ones that mostly rely on a built-in.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	kleene("ab", 16)
	kleene("xyz", 40)
	kleene("1234", 21)
}

// ported from @Dennis solution
func kleene(s string, n int) {
	fmt.Printf("%q n=%d\n", s, n)
	l := len(s)
	w := new(bytes.Buffer)
	for i := range n {
		w.Reset()
		for j := i; j > 0 && l != 0; j /= l {
			j -= 1
			w.WriteByte(s[j%l])
		}
		fmt.Println(w)
	}
	fmt.Println()
}
