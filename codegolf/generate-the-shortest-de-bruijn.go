/*

A De Bruijn sequence is interesting: It is the shortest, cyclic sequence that contains all possible sequences of a given alphabet of a given length. For example, if we were considering the alphabet A,B,C and a length of 3, a possible output is:

AAABBBCCCABCACCBBAACBCBABAC
You will notice that every possible 3-character sequence using the letters A, B, and C are in there.

Your challenge is to generate a De Bruijn sequence in as few characters as possible. Your function should take two parameters, an integer representing the length of the sequences, and a list containing the alphabet. Your output should be the sequence in list form.

You may assume that every item in the alphabet is distinct.

An example generator can be found here

Standard loopholes apply

*/

package main

import (
	"bytes"
)

func main() {
	assert(debruijn("", 0) == "")
	assert(debruijn("01", 3) == "00010111")
	assert(debruijn("abcd", 2) == "aabacadbbcbdccdd")
	assert(debruijn("ABC", 3) == "AAABAACABBABCACBACCBBBCBCCC")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://en.wikipedia.org/wiki/De_Bruijn_sequence
func debruijn(s string, n int) string {
	k := len(s)
	if k == 0 {
		return ""
	}

	a := make([]int, k*n)
	r := []int{}
	dfs(1, 1, k, n, a, &r)

	w := new(bytes.Buffer)
	for _, i := range r {
		w.WriteByte(s[i])
	}
	return w.String()
}

func dfs(t, p, k, n int, a []int, r *[]int) {
	switch {
	case t > n:
		if n%p == 0 {
			*r = append(*r, a[1:p+1]...)
		}

	default:
		if t >= len(a) {
			return
		}

		a[t] = a[t-p]
		dfs(t+1, p, k, n, a, r)
		for j := a[t-p] + 1; j < k; j++ {
			a[t] = j
			dfs(t+1, t, k, n, a, r)
		}
	}
}
