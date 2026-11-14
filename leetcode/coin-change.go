/*

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0


Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4

*/

package main

func main() {
	assert(change([]int{1, 2, 5}, 11) == 3)
	assert(change([]int{2}, 3) == -1)
	assert(change([]int{1}, 0) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func change(c []int, n int) int {
	p := make([]int, n+1)
	for i := 1; i <= n; i++ {
		p[i] = n + 1
	}

	for _, c := range c {
		for i := c; i <= n; i++ {
			p[i] = min(p[i], p[i-c]+1)
		}
	}

	if p[n] == n+1 {
		return -1
	}
	return p[n]
}
