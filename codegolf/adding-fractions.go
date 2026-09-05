/*

Write a program or a function that takes two non-empty lists of the same length as input and does the following:

uses elements of first list to get numerators,
uses elements of the second list to get denominators,
displays resulting fractions after simplification (2/4=>1/2), separated by "+"s,
displays "=" and result of addition after last fraction.

Example:

Input
[1, 2, 3, 3, 6]
[2, 9, 3, 2, 4]

Output
1/2+2/9+1+3/2+3/2=85/18
About rules
elements of lists will be positive integers,
elements can be separated by spaces, eg: 1/2 + 2/9 + 1 + 3/2 + 3/2 = 85/18 is ok,
trailing newline is allowed,
lists can be taken in other formats than above, eg.: (1 2 3 3 6) or {1;2;3;3;6}, etc.,
1 can be expressed as 1/1,
instead of printing you can return appropriate string,
you do not need to handle wrong input,
shortest code wins.

*/

package main

import (
	"bytes"
	"fmt"
	"math/big"
)

func main() {
	assert(fradd([]int64{1, 2, 3, 3, 6}, []int64{2, 9, 3, 2, 4}) == "1/2+2/9+1+3/2+3/2=85/18")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func fradd(a, b []int64) string {
	w := new(bytes.Buffer)
	n := min(len(a), len(b))
	r := new(big.Rat)
	for i := 0; i < n; i++ {
		x := big.NewRat(a[i], b[i])
		if x.IsInt() {
			fmt.Fprint(w, x.Num())
		} else {
			fmt.Fprint(w, x)
		}

		if i+1 < n {
			fmt.Fprint(w, "+")
		} else {
			fmt.Fprint(w, "=")
		}

		r.Add(r, x)
	}
	fmt.Fprint(w, r)
	return w.String()
}
