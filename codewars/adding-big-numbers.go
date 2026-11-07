/*

We need to sum big numbers, and we require your help.

Write a function that returns the sum of two numbers. The input numbers are strings and the function
must return a string.

## Example

add("123", "321"); // returns "444"
add("11", "99");   // returns "110"

## Notes

* The input numbers are _big_.
* The input is a string of only digits
* The numbers are positives

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	test("123", "321", "444")
	test("11", "99", "110")
	test("1", "1", "2")
	test("123", "456", "579")
	test("888", "222", "1110")
	test("1372", "69", "1441")
	test("12", "456", "468")
	test("100", "101", "201")
	test("04417465004110", "5233514", "4417470237624")
	test("63829983432984289347293874", "90938498237058927340892374089", "91002328220491911630239667963")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s0, s1, s2 string) {
	x0 := mpnew(s0)
	x1 := mpnew(s1)
	x2 := mpadd(x0, x1)
	assert(x2.String() == s2)
}

// https://austinhenley.com/blog/bignum2.html
type mp struct {
	w []uint32
}

func mpnew(s string) *mp {
	x := &mp{w: make([]uint32, (len(s)+8)/9)}
	for i := range s {
		p := i / 9
		o := i % 9
		d := uint32(s[len(s)-i-1] - '0')
		m := uint32(1)
		for range o {
			m *= 10
		}
		x.w[p] += d * m
	}
	return x
}

func mpadd(x, y *mp) *mp {
	n := max(len(x.w), len(y.w))
	z := &mp{w: make([]uint32, n+1)}
	c := uint32(0)
	i := 0
	for ; i < n || c > 0; i++ {
		s := c
		if i < len(x.w) {
			s += x.w[i]
		}
		if i < len(y.w) {
			s += y.w[i]
		}
		z.w[i], c = s%1e9, s/1e9
	}
	if c != 0 {
		z.w = z.w[:i+1]
	} else {
		z.w = z.w[:i]
	}
	return z
}

func (x *mp) String() string {
	w := new(bytes.Buffer)
	l := true
	for i := len(x.w) - 1; i >= 0; i-- {
		if l {
			fmt.Fprintf(w, "%d", x.w[i])
			l = false
		} else {
			fmt.Fprintf(w, "%09d", x.w[i])
		}
	}
	if l {
		fmt.Fprint(w, "0")
	}
	return w.String()
}
