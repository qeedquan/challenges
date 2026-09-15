/*

Challenge
Given a positive integer N≥3, generate an alternating series of N random numbers within the range [1,N], such that their sum equals N.
Expressed mathematically as

N = Sum[1, N] (-1)^(i-1)*a[i] where a[i]∈[1,N] are random terms.

Input

N

Output

A string representing the alternating series of N terms (each prefixed by + or -) that sum up to N.

Notes

Random numbers can be generated using any standard random number generation function. For example, rand() in C, random.randint() in Python, Math.random() in Javascript, etc.,...

Examples
N	alternating series
3	+1-1+3
4	+4-1+3-2
5	+4-2+4-4+3
6	+5-1+4-4+3-1
7	+6-1+4-7+4-1+2
8	+6-7+7-5+7-1+2-1
9	+3-7+8-3+2-8+9-2+7
10	+10-4+4-2+8-3+1-4+5-5
11	+11-7+1-2+2-10+3-5+10-2+10
...	...

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	for i := range 8 {
		solve(i)
	}
}

func solve(n int) {
	fmt.Printf("n=%d\n", n)
	recurse(n, []int{})
	fmt.Println()
}

func recurse(n int, r []int) {
	if len(r) >= n {
		if sum(r) == n {
			fmt.Printf("%+d\n", r)
		}
		return
	}

	p := rand.Perm(n)
	for _, v := range p {
		if v++; len(r)&1 != 0 {
			v = -v
		}
		recurse(n, append(r, v))
	}
}

func sum(a []int) int {
	r := 0
	for _, v := range a {
		r += v
	}
	return r
}
