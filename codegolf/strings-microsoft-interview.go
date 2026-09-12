/*

You are given an array of strings , you have to construct a single array containing all of them so that the same array of strings can be reconstructed from the large array.
The strings may contain any ASCII character. How to determine length of the single large array?

Example= let a = ["asd";"dfg";"rew"]. Problem is to combine them in a single string in such a way that it can reconstructed. How to figure out the size of the string which will store the concatenation ?

*/

package main

import (
	"bytes"
	"reflect"
)

func main() {
	test([]string{"asd", "dfg", "rew"})
	test([]string{"s"})
	test([]string{"ktx", "z"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s []string) {
	t := cat(s)
	p := uncat(t)
	assert(reflect.DeepEqual(p, s))
}

/*

@gnibbler

This was a very common in style in Apple ][ binaries.
The high bit of the first character of each word was set.
You know you can do this since ASCII was specifically mentioned and the high bit is never set for ASCII.
This technique relies on strings that know their own length.
We can assume this is the case, since the strings can "contain any ASCII" characters, so C style (null terminated) strings can't work.

*/

func cat(s []string) string {
	w := new(bytes.Buffer)
	for i := range s {
		for j := 0; j < len(s[i]); j++ {
			c := s[i][j]
			if j == 0 {
				c |= 0x80
			}
			w.WriteByte(c)
		}
	}
	return w.String()
}

func uncat(s string) []string {
	r := []string{}
	w := new(bytes.Buffer)
	for i := 0; i < len(s); i++ {
		w.WriteByte(s[i] & 0x7f)
		if (i+1 < len(s) && s[i+1]&0x80 != 0) || i+1 == len(s) {
			r = append(r, w.String())
			w = new(bytes.Buffer)
		}
	}
	return r
}
