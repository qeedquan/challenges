/*

A permutation of the integers from 1 to n is called good if and only if the absolute values of the differences between each pair of consecutive numbers form a permutation of the integers from 1 to n−1.

For example, the permutation 1 2 3 is not good, because the absolute differences are 1 1, which do not form a permutation of 1 to 2. However, the permutation 3 1 2 is good, because the differences 2 1 form a valid permutation.

In this problem, you are given an integer n, and you are required to find the number of good permutations of n numbers.

Input
A single integer n (2≤n≤30).

Output
Output the number of good permutations of the numbers from 1 to n.

Examples

Input #1
3

Answer #1
4

*/

package main

func main() {
	assert(solve(3) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://arxiv.org/pdf/math/0608513
// https://oeis.org/A006967
func solve(n int) int64 {
	tab := []int64{
		1, 1, 2, 4, 4, 8, 24, 32, 40, 120, 296, 648, 1328, 3200, 9912, 25592,
		55920, 143192, 510696, 1451296, 3497344, 10451824, 38570704, 118914992,
		315235872, 1014824752, 3963684496, 13166130152, 37846301904, 130507967088,
		533318630936, 1884550215976, 5800121391936,
	}

	if n < 0 || n >= len(tab) {
		return -1
	}
	return tab[n]
}
