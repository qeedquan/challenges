/*

Challenge
Given an input n, print an ASCII art cake n layers tall, viewed from the side, with two candles on top. Refer to the examples below for details.

Output
>> cake(1)

 _|_|_
|     |
+-----+

>> cake(3)

     _|_|_
    |     |
  +---------+
  |         |
+-------------+
|             |
+-------------+
...and so on.

Rules
Standard loopholes prohibited
Please make an attempt at a clever solution
This is code-golf, so shortest answer in bytes wins. However, the answer will not be selected.
Have fun!

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	for i := range 11 {
		cake(i)
	}
}

// ported from @edelbitter solution
func cake(n int) {
	fmt.Printf("n=%d\n", n)
	if n < 1 {
		return
	}

	l := 2*n + 1
	r := make([]string, l)
	r[0] = strf("+d+", n*4+1)
	r[1] = strf("|s|", n*4+1)
	for i, j := n, 2; i > 1; i, j = i-1, j+2 {
		r[j] = strf("s+d+", (n-i)*2, i*4+1)
		r[j+1] = strf("s|s|", (n-i+1)*2, (i-1)*4+1)
	}
	r[l-2] = strf("s|     |", (n-1)*2)
	r[l-1] = strf("s _|_|_", (n-1)*2)

	for i := l - 1; i >= 0; i-- {
		fmt.Println(r[i])
	}
	fmt.Println()
}

func strf(s string, a ...int) string {
	w := new(bytes.Buffer)
	i := 0
	for _, r := range s {
		switch r {
		case 'd', 's':
			n := a[i]
			i += 1
			if n < 1 {
				continue
			}

			c := "-"
			if r == 's' {
				c = " "
			}
			w.WriteString(strings.Repeat(c, n))

		default:
			w.WriteRune(r)
		}
	}
	return w.String()
}
