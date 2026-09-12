/*

Let's consider the sequence of the binary representation of positive integers (without any leading zero):

1 2  3  4   5   6   7   8    9    10   11   12   ...
1 10 11 100 101 110 111 1000 1001 1010 1011 1100 ...
If we join them together, we get:

1101110010111011110001001101010111100 ...
If we now look for the patterns /1+0+/, we can split it as follows:

110 11100 10 1110 1111000 100 110 10 10 111100 ...
We define sn as the length of the n-th pattern built that way. Your task is to generate this sequence.

The first few terms are:

3, 5, 2, 4, 7, 3, 3, 2, 2, 6, 3, 5, 9, 4, 4, 2, 3, 4, 3, 2, 2, 3, 3, 2, 8, 4, 4, 2, 3, 7, 4, 6, 11, 5, 5, ...
Related OEIS sequence: A056062, which includes the binary representation of 0 in the initial string and counts 0's and 1's separately.

Rules
You may either:

take n as input and return the n-th term, 1-indexed take n as input and return the n-th term, 0-indexed take n as input and return the n first terms take no input and print the sequence forever
This is a code-golf challenge.

Some more examples
The following terms are 1-indexed.

s(81)    = 13
s(100)   = 3
s(101)   = 2
s(200)   = 5
s(1000)  = 5
s(1025)  = 19
s(53249) = 29

*/

package main

import (
	"bytes"
	"fmt"
	"reflect"
	"regexp"
)

func main() {
	tab := []int{3, 5, 2, 4, 7, 3, 3, 2, 2, 6, 3, 5, 9, 4, 4, 2, 3, 4, 3, 2, 2, 3, 3, 2, 8, 4, 4, 2, 3, 7, 4, 6, 11, 5, 5}
	x := gen(53249)

	assert(reflect.DeepEqual(x[:len(tab)], tab))
	assert(x[80] == 13)
	assert(x[99] == 3)
	assert(x[100] == 2)
	assert(x[199] == 5)
	assert(x[999] == 5)
	assert(x[1024] == 19)
	assert(x[53248] == 29)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen(n int) []int {
	re := regexp.MustCompile("1+0+")
	r := []int{}
	s := binstring(n)
	m := re.FindAllString(s, -1)
	for i := 0; i < n; i++ {
		r = append(r, len(m[i]))
	}
	return r
}

func binstring(n int) string {
	w := new(bytes.Buffer)
	for i := 1; i <= n; i++ {
		fmt.Fprintf(w, "%b", i)
	}
	return w.String()
}
