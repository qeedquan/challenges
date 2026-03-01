/*

There is a group of n members, and a list of various crimes they could commit. The ith crime generates a profit[i] and requires group[i] members to participate in it. If a member participates in one crime, that member can't participate in another crime.

Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit, and the total number of members participating in that subset of crimes is at most n.

Return the number of schemes that can be chosen. Since the answer may be very large, return it modulo 10^9 + 7.

Example 1:

Input: n = 5, minProfit = 3, group = [2,2], profit = [2,3]
Output: 2
Explanation: To make a profit of at least 3, the group could either commit crimes 0 and 1, or just crime 1.
In total, there are 2 schemes.
Example 2:

Input: n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
Output: 7
Explanation: To make a profit of at least 5, the group could commit any crimes, as long as they commit one.
There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).

Constraints:

1 <= n <= 100
0 <= minProfit <= 100
1 <= group.length <= 100
1 <= group[i] <= 100
profit.length == group.length
0 <= profit[i] <= 100

*/

package main

func main() {
	assert(profitscheme(5, 3, []int{2, 2}, []int{2, 3}) == 2)
	assert(profitscheme(10, 5, []int{2, 3, 5}, []int{6, 7, 8}) == 7)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func profitscheme(G, P int, g, p []int) int {
	const mod = 1_000_000_007

	c := make([][]int, P+1)
	for i := range c {
		c[i] = make([]int, G+1)
	}

	c[0][0] = 1
	for k := range g {
		for i := P; i >= 0; i-- {
			for j := G - g[k]; j >= 0; j-- {
				c0 := min(i+p[k], P)
				c1 := j + g[k]
				c[c0][c1] = (c[c0][c1] + c[i][j]) % mod
			}
		}
	}

	r := 0
	for _, v := range c[P] {
		r = (r + v) % mod
	}
	return r
}
