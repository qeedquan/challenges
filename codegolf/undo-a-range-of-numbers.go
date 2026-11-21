/*

It is fairly simple to, given a number n, create a range from 0 to n-1. In fact, many languages provide this operation as a builtin.

The following CJam program reads an integer, and then prints out such a range (Try it online!):

ri,
Notice that it prints out numbers without a separator.

The Challenge
Your task is to reverse this process. You should write a program that, given a string representing a range, returns the number used to produce that range.

Specifications
The numbers are given without any separator.
You may assume the string forms a valid range.
You may use 0- or 1-based indexing for your range.
You may assume that a correct output will never exceed 32,767 (so a valid input will never have a length greater than 152,725).
You may assume that a correct output will always be positive (so you do not have to handle 0 or negative).
This is code-golf, so the shortest competing answer (measured in bytes) wins.

Test Cases
0-indexed:

0123 -> 4
0 -> 1
0123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899100 -> 101
1-indexed:

1234 -> 4
1 -> 1
123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899100 -> 100

*/

package main

import (
	"bytes"
	"fmt"
	"math"
	"sort"
)

func main() {
	assert(ranges("0123") == 4)
	assert(ranges("0") == 1)
	assert(ranges("0123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899100") == 101)

	for i := 1; i <= 5000; i++ {
		assert(ranges(gen(i)) == i)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen(n int) string {
	w := new(bytes.Buffer)
	for i := 0; i < n; i++ {
		fmt.Fprint(w, i)
	}
	return w.String()
}

func ranges(s string) int {
	return sort.Search(len(s), func(i int) bool {
		return natpos(i) >= len(s)
	})
}

// https://oeis.org/A117804
func natpos(n int) int {
	if n < 1 {
		return 0
	}
	d := ilog10(n) + 1
	return d*n + 1 - (ipow10(d)+1)/9
}

func ilog10(x int) int {
	return int(math.Log10(float64(x)))
}

func ipow10(x int) int {
	return int(math.Pow(10, float64(x)))
}
