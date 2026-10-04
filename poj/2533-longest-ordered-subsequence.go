/*

Description

A numeric sequence of ai is ordered if a1 < a2 < ... < aN. Let the subsequence of the given numeric sequence (a1, a2, ..., aN) be any sequence (ai1, ai2, ..., aiK), where 1 <= i1 < i2 < ... < iK <= N. For example, sequence (1, 7, 3, 5, 9, 4, 8) has ordered subsequences, e. g., (1, 7), (3, 4, 8) and many others. All longest ordered subsequences are of length 4, e. g., (1, 3, 5, 8).

Your program, when given the numeric sequence, must find the length of its longest ordered subsequence.

Input

The first line of input file contains the length of sequence N. The second line contains the elements of sequence - N integers in the range from 0 to 10000 each, separated by spaces. 1 <= N <= 1000

Output

Output file must contain a single integer - the length of the longest ordered subsequence of the given sequence.

Sample Input

7
1 7 3 5 9 4 8

Sample Output

4
Source

Northeastern Europe 2002, Far-Eastern Subregion

*/

package main

import "slices"

func main() {
	assert(longest([]int{1, 7, 3, 5, 9, 4, 8}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func longest(a []int) int {
	n := len(a)
	p := make([]int, n)
	for i := 0; i < n; i++ {
		p[i] = 1
		for j := 0; j < i; j++ {
			if a[i] > a[j] && p[i] < p[j]+1 {
				p[i] = p[j] + 1
			}
		}
	}
	return slices.Max(p)
}
