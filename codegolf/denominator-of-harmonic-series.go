/*

Earlier, we did the pseudofactorial of a number, which is the LCM of the numbers from 1 to n.

It would be useful in adding fractions together.

However, we find that the denominator of 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 is 20 instead of the pseudofactorial of 6, which is 60.

Your task is to find the denominator of 1/1 + 1/2 + ... + 1/n given positive integer n.

Testcases
 n result
 1 1
 2 2
 3 6
 4 12
 5 60
 6 20
 7 140
 8 280
 9 2520
10 2520
11 27720
12 27720
13 360360
14 360360
15 360360
16 720720
17 12252240
18 4084080
19 77597520
20 15519504
21 5173168
22 5173168
23 118982864
24 356948592
25 8923714800
26 8923714800
27 80313433200
28 80313433200
29 2329089562800
30 2329089562800
List for n from 1 to 200.
List for n from 1 to 1000.
List for n from 1 to 10000.
References
Obligatory OEIS A002805 (thanks to @FryAmTheEggman)

*/

package main

import (
	"fmt"
	"math/big"
	"strings"
)

func main() {
	tab := []int64{
		1, 2, 6, 12, 60, 20, 140, 280, 2520, 2520, 27720, 27720,
		360360, 360360, 360360, 720720, 12252240, 4084080,
		77597520, 15519504, 5173168, 5173168, 118982864,
		356948592, 8923714800, 8923714800, 80313433200,
		80313433200, 2329089562800, 2329089562800,
		72201776446800,
	}
	for i, v := range tab {
		assert(denom(int64(i)+1) == fmt.Sprint(v))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A002805
func denom(n int64) string {
	r := new(big.Rat)
	for i := int64(1); i <= n; i++ {
		x := big.NewRat(1, i)
		r.Add(r, x)
	}

	s := r.String()
	i := strings.Index(s, "/")
	if i < 0 {
		return "1"
	}
	return s[i+1:]
}
