/*

Determine the number of distinct numbers that appear in at least one of the given sets.

Input
The first line contains an integer n (1≤n≤10) - the number of sets.

The next n lines describe the sets. Each line begins with k (1≤k≤1000) - the number of elements in the set.
Then k integers follow: a1,…,ak (-10^9≤ai≤10^9) - the elements of the set.

Output
Output a single number — the number of distinct elements that appear in at least one of the sets.

Examples

Input #1
2
3 1 2 3
3 2 4 3

Answer #1
4

Input #2
3
3 2 4 6
4 1 2 3 4
3 4 5 7

Answer #2
7

*/

package main

func main() {
	assert(solve([][]int{
		{3, 1, 2, 3},
		{3, 2, 4, 3},
	}) == 4)

	assert(solve([][]int{
		{3, 2, 4, 6},
		{4, 1, 2, 3, 4},
		{3, 4, 5, 7},
	}) == 7)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a [][]int) int {
	m := make(map[int]bool)
	for i := range a {
		for j := range a[i] {
			m[a[i][j]] = true
		}
	}
	return len(m)
}
