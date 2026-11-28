/*

Description

Count the number of permutations that have a specific number of inversions.
Given a permutation a1, a2, a3,..., an of the n integers 1, 2, 3, ..., n, an inversion is a pair (ai, aj) where i < j and ai > aj. The number of inversions in a permutation gives an indication on how "unsorted" a permutation is. If we wish to analyze the average running time of a sorting algorithm, it is often useful to know how many permutations of n objects will have a certain number of inversions.

In this problem you are asked to compute the number of permutations of n values that have exactly k inversions.

For example, if n = 3, there are 6 permutations with the indicated inversions as follows:
123			0 inversions



132			1 inversion (3 > 2)



213			1 inversion (2 > 1)



231			2 inversions (2 > 1, 3 > 1)



312			2 inversions (3 > 1, 3 > 2)



321			3 inversions (3 > 2, 3 > 1, 2 > 1)

Therefore, for the permutations of 3 things
1 of them has 0 inversions
2 of them have 1 inversion
2 of them have 2 inversions
1 of them has 3 inversions
0 of them have 4 inversions
0 of them have 5 inversions
etc.


Input

The input consists one or more problems. The input for each problem is specified on a single line, giving the integer n (1 <= n <= 18) and a non-negative integer k (0 <= k <= 200). The end of input is specified by a line with n = k = 0.

Output

For each problem, output the number of permutations of {1, ..., n}with exactly k inversions.

Sample Input

3 0
3 1
3 2
3 3
4 2
4 10
13 23
18 80
0 0

Sample Output

1
2
2
1
5
0
46936280
184348859235088

Source

Rocky Mountain 2003

*/

package main

func main() {
	assert(inversions(3, 0) == 1)
	assert(inversions(3, 1) == 2)
	assert(inversions(3, 2) == 2)
	assert(inversions(3, 3) == 1)
	assert(inversions(4, 2) == 5)
	assert(inversions(4, 10) == 0)
	assert(inversions(13, 23) == 46936280)
	assert(inversions(18, 80) == 184348859235088)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func inversions(n, k int) uint64 {
	l := max(n, k)
	p := alloc(l + 2)

	p[1][0] = 1
	for i := 2; i <= l; i++ {
		for j := 0; p[i-1][j] > 0; j++ {
			for k := 0; k <= i-1 && j+k <= l; k++ {
				p[i][j+k] += p[i-1][j]
			}
		}
	}
	return p[n][k]
}

func alloc(n int) [][]uint64 {
	p := make([][]uint64, n)
	t := make([]uint64, n*n)
	for i := range p {
		p[i] = t[i*n : (i+1)*n]
	}
	return p
}
