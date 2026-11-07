/*

Given a sequence of powers of 2, i.e., the numbers 2,4,8,…,2^n, written one after another in a single line without any spaces, determine the value of n.

Input
A single line contains n (1≤n≤1000) consecutive powers of 2 written without any spaces.

Output
Print the value of n.

Examples
Input #1
248163264128

Answer #1
7

*/

package main

import (
	"bytes"
	"math/big"
)

func main() {
	assert(solve("248163264128") == 7)
	for i := 1; i <= 2000; i++ {
		assert(solve(gen(i)) == i)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen(n int) string {
	w := new(bytes.Buffer)
	x := new(big.Int)
	for i := 1; i <= n; i++ {
		x.SetInt64(1)
		x.Lsh(x, uint(i))
		w.WriteString(x.String())
	}
	return w.String()
}

func solve(s string) int {
	n := len(s)
	if n == 0 {
		return 0
	}

	r := 1
	for i, m := 1, 1; i < n; r++ {
		c := s[i]
		i += m
		if c > '4' {
			m += 1
		}
	}
	return r
}
