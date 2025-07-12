/*

Given two arbitrary numbers A,B. Print number B as a Digital LED Pattern where A is the scale.

input:

1 2320451640799518
ouput:

 _  _  _  _     _     _     _  _  _  _  _     _
 _| _| _|| ||_||_   ||_ |_|| |  ||_||_||_   ||_|
|_  _||_ |_|  | _|  ||_|  ||_|  |  |  | _|  ||_|
input:

2 23
ouput:

 __  __
   |   |
 __| __|
|      |
|__  __|
Rules:

Use STDIN/STDOUT for input/output

Code with most up-votes wins. In case of Tie, shortest code will be accepted

Most up voted Answer will be accepted at 01/02/2014 (Accepted this answer with highest 12 votes)

*/

package main

import "fmt"

func main() {
	display(1, "2320451640799518")
	display(2, "23")
	display(3, "0123456789")
	display(4, "0123456789")
}

// ported from @reima solution
func display(n int, s string) {
	const sym1 = "_|_||_| "
	const sym2 = "zG<lMfvH~N"

	w := n + 2
	h := 2*n + 1
	for y := range h {
		for _, c := range s {
			if !('0' <= c && c <= '9') {
				continue
			}

			for x := range w {
				k := (y+n-1)/n*3 + (x+n-1)/n
				i := x % (n + 1) * (y % n)
				switch {
				case i != 0:
					i = 7
				case k < 3:
					i = (^k & 1) * 7
				default:
					i = k - 2
				}

				p := (sym2[c-'0'] + 1) >> i
				if p&1 != 0 {
					p = byte(i)
				} else {
					p = 7
				}
				fmt.Printf("%c", sym1[p])
			}
		}
		fmt.Println()
	}
}
