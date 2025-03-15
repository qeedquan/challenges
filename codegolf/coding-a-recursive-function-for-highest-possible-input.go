/*

Challenge

You are given the following function:-

https://i.stack.imgur.com/SMy3h.png

which is the same as:-

https://i.stack.imgur.com/POl0F.png

with the base cases q(r, b, L) = 1 whenever r ≤ L, q(r, 0, L) = 0, if r > L and q(r, 0, L) = 1, if r ≤ L.

Your task is to code a program that takes r as input, and outputs the value of q(r, r - L, L) for all L taking integer values from 1 to (r-1), where r is any nonnegative integer.

Example 1

Input

Enter the value of r: 2

Output

q(2,1,1) = 0.3333333333

Example 2

Input

Enter the value of r: 3

Output

q(3,2,1) = 0.1

q(3,1,2) = 0.5

Winning criterion

The code that can correctly output q(r, r-L, L) for all L taking integer values from 1 to (r-1), for the highest value of r, in less than 300 seconds.
In case of a tie, the code with lesser runtime will be considered. As this is a runtime-based challenge, I shall test all submissions on my machine.

*/

package main

import (
	"flag"
	"fmt"
	"os"
	"strconv"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	R, _ := strconv.Atoi(flag.Arg(0))
	for L := 1; L < R; L++ {
		fmt.Printf("%.8f\n", Q(R, R-L, L))
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] R")
	flag.PrintDefaults()
	os.Exit(2)
}

// based on @Peter Taylor solution
func Q(R, B, L int) float64 {
	q := alloc(R+1, B+1)
	for r := 0; r <= L; r++ {
		for b := range q[r] {
			q[r][b] = 1
		}
	}

	for r := L + 1; r < len(q); r++ {
		for b := 1 + (r-L-1)/L; b < len(q[r]); b++ {
			x, m := 0.0, 1.0
			for k := 0; k <= L; k++ {
				x += m * q[r-k][b-1]
				m *= float64(r-k) / float64(r+b-1-k)
			}
			q[r][b] = x * float64(b) / float64(r+b)
		}
	}

	return q[R][B]
}

func alloc(r, c int) [][]float64 {
	m := make([][]float64, r)
	for i := range m {
		m[i] = make([]float64, c)
	}
	return m
}
