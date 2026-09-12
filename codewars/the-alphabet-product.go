/*

I have four positive integers, A, B, C and D, where A < B < C < D. The input is a list of the integers A, B, C, D, AxB, BxC, CxD, DxA in some order. Your task is to return the value of D.

*/

package main

import (
	"fmt"
	"math/rand"
	"sort"
)

func main() {
	for range 1000000 {
		a := rand.Intn(100000) + 1
		b := a + rand.Intn(1000) + 1
		c := b + rand.Intn(1000) + 1
		d := c + rand.Intn(1000) + 1
		x := [8]int{a, b, c, d, a * b, b * c, c * d, d * a}
		rand.Shuffle(len(x), func(i, j int) {
			x[i], x[j] = x[j], x[i]
		})

		e := alphabet(x)
		if d != e {
			fmt.Printf("MISMATCH: %d %d %d %d | %v\n", a, b, c, d, e)
		}
	}
}

func alphabet(x [8]int) int {
	sort.Ints(x[:])
	if x[0]*x[1] == x[2] {
		x[7] /= x[3]
	} else {
		x[7] /= x[2]
	}
	return x[7]
}
