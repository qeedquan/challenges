/*

There is an m x n cake that needs to be cut into 1 x 1 pieces.

You are given integers m, n, and two arrays:

horizontalCut of size m - 1, where horizontalCut[i] represents the cost to cut along the horizontal line i.
verticalCut of size n - 1, where verticalCut[j] represents the cost to cut along the vertical line j.
In one operation, you can choose any piece of cake that is not yet a 1 x 1 square and perform one of the following cuts:

Cut along a horizontal line i at a cost of horizontalCut[i].
Cut along a vertical line j at a cost of verticalCut[j].
After the cut, the piece of cake is divided into two distinct pieces.

The cost of a cut depends only on the initial cost of the line and does not change.

Return the minimum total cost to cut the entire cake into 1 x 1 pieces.

Example 1:

Input: m = 3, n = 2, horizontalCut = [1,3], verticalCut = [5]

Output: 13

Explanation:

https://assets.leetcode.com/uploads/2024/06/04/ezgifcom-animated-gif-maker-1.gif

Perform a cut on the vertical line 0 with cost 5, current total cost is 5.
Perform a cut on the horizontal line 0 on 3 x 1 subgrid with cost 1.
Perform a cut on the horizontal line 0 on 3 x 1 subgrid with cost 1.
Perform a cut on the horizontal line 1 on 2 x 1 subgrid with cost 3.
Perform a cut on the horizontal line 1 on 2 x 1 subgrid with cost 3.
The total cost is 5 + 1 + 1 + 3 + 3 = 13.

Example 2:

Input: m = 2, n = 2, horizontalCut = [7], verticalCut = [4]

Output: 15

Explanation:

Perform a cut on the horizontal line 0 with cost 7.
Perform a cut on the vertical line 0 on 1 x 2 subgrid with cost 4.
Perform a cut on the vertical line 0 on 1 x 2 subgrid with cost 4.
The total cost is 7 + 4 + 4 = 15.

Constraints:

1 <= m, n <= 20
horizontalCut.length == m - 1
verticalCut.length == n - 1
1 <= horizontalCut[i], verticalCut[i] <= 10^3

Hint 1
The intended solution uses Dynamic Programming.

Hint 2
Let dp[sx][sy][tx][ty] denote the minimum cost to cut the rectangle into 1 x 1 pieces.

Hint 3
Iterate on the row or column on which you will perform the next cut, after the cut, the current rectangle will be decomposed into two sub-rectangles.

*/

package main

import "sort"

func main() {
	assert(cost(3, 2, []int{1, 3}, []int{5}) == 13)
	assert(cost(2, 2, []int{7}, []int{4}) == 15)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cost(m, n int, h, v []int) int {
	sort.Slice(h, func(i, j int) bool {
		return h[i] > h[j]
	})

	sort.Slice(v, func(i, j int) bool {
		return v[i] > v[j]
	})

	r := 0
	for i, j := 0, 0; i < len(h) || j < len(v); {
		if j == len(v) || (i < len(h) && h[i] > v[j]) {
			r += h[i] * (j + 1)
			i += 1
		} else {
			r += v[j] * (i + 1)
			j += 1
		}
	}
	return r
}
