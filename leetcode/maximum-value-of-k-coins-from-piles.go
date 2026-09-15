/*

There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.

In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.

Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, and a positive integer k,
return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.

Example 1:
https://assets.leetcode.com/uploads/2019/11/09/e1.png
Input: piles = [[1,100,3],[7,8,9]], k = 2
Output: 101
Explanation:
The above diagram shows the different ways we can choose k coins.
The maximum total we can obtain is 101.

Example 2:

Input: piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
Output: 706
Explanation:
The maximum total can be obtained if we choose all coins from the last pile.

Constraints:

n == piles.length
1 <= n <= 1000
1 <= piles[i][j] <= 105
1 <= k <= sum(piles[i].length) <= 2000

Hint 1
For each pile i, what will be the total value of coins we can collect if we choose the first j coins?

Hint 2
How can we use dynamic programming to combine the results from different piles to find the most optimal answer?

*/

package main

func main() {
	assert(solve([][]int{{1, 100, 3}, {7, 8, 9}}, 2) == 101)
	assert(solve([][]int{{100}, {100}, {100}, {100}, {100}, {100}, {1, 1, 1, 1, 1, 1, 700}}, 7) == 706)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a [][]int, k int) int {
	d1 := []int{0}
	for _, p := range a {
		d2 := make([]int, min(len(d1)+len(p), k+1))
		for i := 0; i < len(d1); i++ {
			for j, c := 0, 0; j <= min(k-i, len(p)); j++ {
				d2[i+j] = max(d2[i+j], d1[i]+c)
				if j < len(p) {
					c += p[j]
				}
			}
		}
		d1 = d2
	}
	return d1[len(d1)-1]
}
