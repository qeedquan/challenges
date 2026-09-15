/*

One of the teachers has a grasshopper living in their room, and it loves to jump on a one-dimensional checkered board of length n cells.
Unfortunately for the grasshopper, it can only jump forward by 1,2,…,k cells.

One day, the teachers became curious about how many ways the grasshopper could jump from the first cell to the last. Help them answer this question.

Input
Two integers n and k (1≤n≤30,1≤k≤10).

Output
Print the number of ways the grasshopper can jump from the first cell to the last.

Examples

Input #1
8 2

Answer #1
21

Input #2
1 10

Answer #2
1

Input #4
1 1

Answer #4
1

Input #8
30 10

Answer #8
265816832

*/

package main

func main() {
	assert(solve(8, 2) == 21)
	assert(solve(1, 10) == 1)
	assert(solve(1, 1) == 1)
	assert(solve(30, 10) == 265816832)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, k int) int {
	if n < 0 {
		return 0
	}

	p := make([]int, n+1)
	p[0] = 1
	for i := 1; i < n; i++ {
		for j := 1; j <= k; j++ {
			if i-j >= 0 {
				p[i] += p[i-j]
			}
		}
	}
	return p[n-1]
}
