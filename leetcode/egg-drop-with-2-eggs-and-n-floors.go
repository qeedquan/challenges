/*

You are given two identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

In each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

Example 1:

Input: n = 2
Output: 2
Explanation: We can drop the first egg from floor 1 and the second egg from floor 2.
If the first egg breaks, we know that f = 0.
If the second egg breaks but the first egg didn't, we know that f = 1.
Otherwise, if both eggs survive, we know that f = 2.
Example 2:

Input: n = 100
Output: 14
Explanation: One optimal strategy is:
- Drop the 1st egg at floor 9. If it breaks, we know f is between 0 and 8. Drop the 2nd egg starting from floor 1 and going up one at a time to find f within 8 more drops. Total drops is 1 + 8 = 9.
- If the 1st egg does not break, drop the 1st egg again at floor 22. If it breaks, we know f is between 9 and 21. Drop the 2nd egg starting from floor 10 and going up one at a time to find f within 12 more drops. Total drops is 2 + 12 = 14.
- If the 1st egg does not break again, follow a similar process dropping the 1st egg from floors 34, 45, 55, 64, 72, 79, 85, 90, 94, 97, 99, and 100.
Regardless of the outcome, it takes at most 14 drops to determine f.


Constraints:

1 <= n <= 1000

Hint:
Is it really optimal to always drop the egg on the middle floor for each move?
Can we create states based on the number of unbroken eggs and floors to build our solution?

*/

package main

import (
	"math"
)

func main() {
	assert(twoeggdrop(2) == 2)
	assert(twoeggdrop(100) == 14)
	for i := 0; i < 3000; i++ {
		assert(twoeggdrop(i) == twoeggdropdp(i))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

https://oeis.org/A123578
https://spencermortensen.com/articles/egg-problem/
https://walkccc.me/LeetCode/problems/1884/

*/

func twoeggdrop(n int) int {
	if n < 0 {
		return 0
	}
	return int(math.Sqrt(float64(n*8))+1) / 2
}

func twoeggdropdp(n int) int {
	if n < 0 {
		return 0
	}
	return drop(2, n, alloc(2, n))
}

func alloc(k, n int) [][]int {
	p := make([][]int, k+1)
	t := make([]int, (k+1)*(n+1))
	for i := range p {
		p[i] = t[i*(n+1) : (i+1)*(n+1)]
		for j := range p[i] {
			p[i][j] = -1
		}
	}
	return p
}

func drop(k, n int, dp [][]int) int {
	switch {
	case k == 0:
		return 0
	case k == 1:
		return n
	case n == 0:
		return 0
	case n == 1:
		return 1
	case dp[k][n] != -1:
		return dp[k][n]
	}

	l := 1
	r := n + 1
	for l < r {
		m := (l + r) / 2
		broken := drop(k-1, m-1, dp)
		unbroken := drop(k, n-m, dp)
		if broken >= unbroken {
			r = m
		} else {
			l = m + 1
		}
	}

	dp[k][n] = 1 + drop(k-1, l-1, dp)
	return dp[k][n]
}
