/*

An alternating permutation is a permutation of the first n integers {1...n}, such that adjacent pairs of values in the permutation alternate between increasing and decreasing (or vice versa).

Equivalently, it is a permutation where there are no "runs" of continuously increasing or decreasing values with a length >2.

For example, 2 4 1 5 3 6 is an alternating permutation for n=6, because 2<4, and 4>1, and 1<5, and 5>3, and 3<6: each pair alternates in their relative comparisons.

However, 1 3 2 4 6 5 is not a valid alternating permutation, because it contains the continuously increasing sequence 2 4 6 (2<4 and 4<6).

In this challenge we will consider the number of alternating permutations for a given positive integer n.

For example, for  n=4, there are 4!=24 permutations, of which 10 are alternating permutations:

1 3 2 4
1 4 2 3
2 1 4 3
2 3 1 4
2 4 1 3
3 1 4 2
3 2 4 1
3 4 1 2
4 1 3 2
4 2 3 1
You may notice that every permutation has a duplicate which is just its reverse. Thus, for this challenge, when there is a pair of permutations which are the reverses of each other, you should only count it once.

Note that for  n=1, there is only one permutation, just 1, which doesn't have a distinct reverse. So for n=1, the output is still 1.

For  n=0, there is also only one permutation, the empty one, but you do not need to handle it (we only care about n≥1).

Your task, finally, is to output the sequence of the number of alternating permutations for positive integers n, excluding reverse-duplicates. This sequence starts:

1, 1, 2, 5, 16, 61, 272, 1385, 7936, 50521, 353792, 2702765

This is A000111 (after n=0) in the OEIS, and it is half of A001250 (after n=1).

Rules
As with standard sequence challenges, you may choose to either:
Take an input  n and output the nth term in the sequence
Take an input n and output the first n terms
Output the sequence indefinitely, e.g. using a generator
You may use  0- or  1-indexing

You may use any standard I/O method
Standard loopholes are forbidden
This is code-golf, so the shortest code in bytes wins

*/

package main

func main() {
	tab := []int{
		1, 1, 1, 2, 5, 16, 61, 272, 1385, 7936, 50521, 353792, 2702765, 22368256, 199360981,
	}

	for i := range tab {
		assert(updown(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A000111
func updown(n int) int {
	if n < 0 {
		return 0
	}
	if n == 0 {
		return 1
	}

	r := 0
	a := make([]int, n+1)
	b := make([]int, n+1)
	a[0] = 1
	for i := 1; n/i > 0; i++ {
		r = 0
		for j := i - 1; j >= 0; j-- {
			r += a[j]
			b[i-j] = r
		}
		a, b = b, a
		clear(b)
	}
	return r
}
