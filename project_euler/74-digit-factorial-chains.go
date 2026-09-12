/*

The number 145 is well known for the property that the sum of the factorial of its digits is equal to 145:

    1! + 4! + 5! = 1 + 24 + 120 = 145

Perhaps less well known is 169, in that it produces the longest chain of numbers that link back to 169; it turns out that there are only three such loops that exist:

    169 -> 363601 -> 1454 -> 169
    871 -> 45361 -> 871
    872 -> 45362 -> 872

It is not difficult to prove that EVERY starting number will eventually get stuck in a loop. For example,

    69 -> 363600 -> 1454 -> 169 -> 363601 (-> 1454)
    78 -> 45360 -> 871 -> 45361 (-> 871)
    540 -> 145 (-> 145)

Starting with 69 produces a chain of five non-repeating terms, but the longest non-repeating chain with a starting number below one million is sixty terms.

How many chains, with a starting number below one million, contain exactly sixty non-repeating terms?

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(1000000, 60))
}

func solve(n, c int) int {
	r := 0
	for i := 0; i < n; i++ {
		if fdc(i) == c {
			r++
		}
	}
	return r
}

func fds(n int) int {
	f := []int{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}
	r := 0
	for ; n > 0; n /= 10 {
		r += f[n%10]
	}
	return r
}

func fdc(n int) int {
	m := map[int]bool{n: true}
	for i := 1; i < math.MaxInt; i++ {
		n = fds(n)
		if m[n] {
			return i
		}
		m[n] = true
	}
	return -1
}
