/*

You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.

You are allowed to make at most k transactions, where each transaction can be either of the following:

Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].

Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].

Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.

Return the maximum total profit you can earn by making at most k transactions.

Example 1:

Input: prices = [1,7,9,8,2], k = 2

Output: 14

Explanation:

We can make $14 of profit through 2 transactions:
A normal transaction: buy the stock on day 0 for $1 then sell it on day 2 for $9.
A short selling transaction: sell the stock on day 3 for $8 then buy back on day 4 for $2.

Example 2:

Input: prices = [12,16,19,19,8,1,19,13,9], k = 3

Output: 36

Explanation:

We can make $36 of profit through 3 transactions:
A normal transaction: buy the stock on day 0 for $12 then sell it on day 2 for $19.
A short selling transaction: sell the stock on day 3 for $19 then buy back on day 4 for $8.
A normal transaction: buy the stock on day 5 for $1 then sell it on day 6 for $19.

Constraints:

2 <= prices.length <= 10^3
1 <= prices[i] <= 10^9
1 <= k <= prices.length / 2

Hint 1
Use dynamic programming.

Hint 2
Keep the following states: idx, transactionsDone, transactionType, isTransactionRunning.

Hint 3
Transactions transition from completed -> running and from running -> completed.

*/

package main

import "math"

func main() {
	assert(profit([]int{1, 7, 9, 8, 2}, 2) == 14)
	assert(profit([]int{12, 16, 19, 19, 8, 1, 19, 13, 9}, 3) == 36)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func profit(p []int, k int) int {
	n := len(p)
	a := make([]int, n+1)
	b := make([]int, n+1)
	r := 0
	for i := range k {
		for j := range b {
			b[j] = math.MinInt
		}

		x := math.MinInt
		y := math.MinInt
		for j := i; j < len(p); j++ {
			x = max(x, a[j]-p[j])
			y = max(y, a[j]+p[j])
			b[j+1] = max(b[j], x+p[j], y-p[j])
		}

		a, b = b, a
		r = max(r, a[n])
	}
	return r
}
