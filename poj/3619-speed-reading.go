/*

Description

All K (1 ≤ K ≤ 1,000) of the cows are participating in Farmer John's annual reading contest. The competition consists of reading a single book with N (1 ≤ N ≤ 100,000) pages as fast as possible while understanding it.

Cow i has a reading speed Si (1 ≤ Si ≤ 100) pages per minute, a maximum consecutive reading time Ti (1 ≤ Ti ≤ 100) minutes, and a minimum rest time Ri (1 ≤ Ri ≤ 100) minutes. The cow can read at a rate of Si pages per minute, but only for Ti minutes at a time. After she stops reading to rest, she must rest for Ri minutes before commencing reading again.

Determine the number of minutes (rounded up to the nearest full minute) that it will take for each cow to read the book.

Input

* Line 1: Two space-separated integers: N and K
* Lines 2..K+1: Line i+1 contains three space-separated integers: Si , Ti , and Ri

Output

* Lines 1..K: Line i should indicate how many minutes (rounded up to the nearest full minute) are required for cow i to read the whole book.

Sample Input

10 3
2 4 1
6 1 5
3 3 3

Sample Output

6
7
7

Source

USACO 2007 November Bronze

*/

package main

import (
	"math"
)

func main() {
	assert(wholereads(10, 2, 4, 1) == 6)
	assert(wholereads(10, 6, 1, 5) == 7)
	assert(wholereads(10, 3, 3, 3) == 7)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func wholereads(n, s, t, r int) int {
	v := float64(n/(s*t)) * float64(t+r)
	if n%(s*t) == 0 {
		v -= float64(r)
	} else {
		v += float64(n%(s*t)) / float64(s)
	}
	return int(math.Ceil(v))
}
