/*

The type of regular expression is PCRE.

Write a program that output a valid PCRE such that it matches all natural numbers between m and n and does not match anything else. No leading zeros are allowed.

For example, let m and n be 123 and 4321, then the program might output 1(2[3-9]|[3-9]\d)|[2-9]\d\d|[123]\d\d\d|4([012]\d\d|3([01]\d|2[01])).

This matches the exact string, so ^ and $ anchors are implicit.

One should try to balance the two:

The regular expression should have a reasonable size.

The code should be short.

Let's optimize for

code length in characters + 2*regular expression length for input 123456 and 7654321

Side Note: It be interesting if we can prove the shortest PCRE regular expression is of the size O(log n log log n) or something.

*/

package main

import (
	"bytes"
	"fmt"
	"regexp"
)

func main() {
	test(3, 15)
	test(94, 1000)
	test(123, 4321)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m, n int) {
	re := regexp.MustCompile(gen(m, n))
	for i := -n; i <= n; i++ {
		s := fmt.Sprint(i)
		if re.MatchString(s) {
			assert(m <= i && i <= n)
		} else {
			assert(!(m <= i && i <= n))
		}
	}
}

func gen(m, n int) string {
	if m > n {
		m, n = n, m
	}

	w := new(bytes.Buffer)
	fmt.Fprintf(w, "^(")
	for i := m; i <= n; i++ {
		fmt.Fprint(w, i)
		if i == n {
			fmt.Fprintf(w, ")$")
		} else {
			fmt.Fprintf(w, "|")
		}
	}
	return w.String()
}
