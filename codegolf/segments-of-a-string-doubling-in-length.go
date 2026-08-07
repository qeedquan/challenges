/*

Simple task today. Given a string whose length is one less than a whole power of 2, divide it into segments with doubling length.

For example for the string abcdefghijklmno, the result should be a, bc, defg, hijklmno:

abcdefghijklmno  (length 15)

a                 length 1
 bc               length 2
   defg           length 4
       hijklmno   length 8
The input will not be the empty string.

This is code-golf; shortest solution per language wins.

*/

package main

import (
	"fmt"
	"math/bits"
	"reflect"
)

func main() {
	test("abcdefghijklmno", []string{"a", "bc", "defg", "hijklmno"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []string) {
	p := segment(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func segment(s string) []string {
	r := []string{}
	n := len(s)
	l := bits.UintSize - bits.LeadingZeros(uint(n))
	for i := range l {
		j := 1<<i - 1
		k := 1<<(i+1) - 1
		if j > n || k > n {
			break
		}
		r = append(r, s[j:k])
	}
	return r
}
