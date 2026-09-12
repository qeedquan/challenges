/*

You are given two integers m and n representing the number of rows and columns of a grid, respectively.

The cost to enter cell (i, j) is defined as (i + 1) * (j + 1).

You are also given a 2D integer array waitCost where waitCost[i][j] defines the cost to wait on that cell.

The path will always begin by entering cell (0, 0) on move 1 and paying the entrance cost.

At each step, you follow an alternating pattern:

On odd-numbered seconds, you must move right or down to an adjacent cell, paying its entry cost.
On even-numbered seconds, you must wait in place for exactly one second and pay waitCost[i][j] during that second.
Return the minimum total cost required to reach (m - 1, n - 1).

Example 1:

Input: m = 1, n = 2, waitCost = [[1,2]]

Output: 3

Explanation:

The optimal path is:

Start at cell (0, 0) at second 1 with entry cost (0 + 1) * (0 + 1) = 1.
Second 1: Move right to cell (0, 1) with entry cost (0 + 1) * (1 + 1) = 2.
Thus, the total cost is 1 + 2 = 3.

Example 2:

Input: m = 2, n = 2, waitCost = [[3,5],[2,4]]

Output: 9

Explanation:

The optimal path is:

Start at cell (0, 0) at second 1 with entry cost (0 + 1) * (0 + 1) = 1.
Second 1: Move down to cell (1, 0) with entry cost (1 + 1) * (0 + 1) = 2.
Second 2: Wait at cell (1, 0), paying waitCost[1][0] = 2.
Second 3: Move right to cell (1, 1) with entry cost (1 + 1) * (1 + 1) = 4.
Thus, the total cost is 1 + 2 + 2 + 4 = 9.

Example 3:

Input: m = 2, n = 3, waitCost = [[6,1,4],[3,2,5]]

Output: 16

Explanation:

The optimal path is:

Start at cell (0, 0) at second 1 with entry cost (0 + 1) * (0 + 1) = 1.
Second 1: Move right to cell (0, 1) with entry cost (0 + 1) * (1 + 1) = 2.
Second 2: Wait at cell (0, 1), paying waitCost[0][1] = 1.
Second 3: Move down to cell (1, 1) with entry cost (1 + 1) * (1 + 1) = 4.
Second 4: Wait at cell (1, 1), paying waitCost[1][1] = 2.
Second 5: Move right to cell (1, 2) with entry cost (1 + 1) * (2 + 1) = 6.
Thus, the total cost is 1 + 2 + 1 + 4 + 2 + 6 = 16.

Constraints:

1 <= m, n <= 10^5
2 <= m * n <= 10^5
waitCost.length == m
waitCost[0].length == n
0 <= waitCost[i][j] <= 10^5

Hint 1
Use dynamic programming

Hint 2
Observe that you need to wait at each cell except the first and last

Hint 3
Transition: dp[i][j] <- min(dp[i‑1][j], dp[i][j‑1]) + waitCost[i][j] + (i+1)*(j+1)

Hint 4
The answer is dp[m‑1][n‑1] - waitCost[m‑1][n‑1]

*/

package main

import "math"

func main() {
	assert(cost(1, 2, [][]int{{1, 2}}) == 3)
	assert(cost(2, 2, [][]int{{3, 5}, {2, 4}}) == 9)
	assert(cost(2, 3, [][]int{{6, 1, 4}, {3, 2, 5}}) == 16)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cost(m, n int, w [][]int) int {
	if m < 1 || n < 1 {
		return 0
	}

	w[0][0] = 0
	w[m-1][n-1] = 0

	p := make([]int, n)
	for i := range m {
		for j := range n {
			z := math.MaxInt
			if i == 0 && j == 0 {
				z = 0
			}
			if i-1 >= 0 {
				z = min(z, p[j])
			}
			if j-1 >= 0 {
				z = min(z, p[j-1])
			}
			p[j] = z + w[i][j] + (i+1)*(j+1)
		}
	}
	return p[n-1]
}
