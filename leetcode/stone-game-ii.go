/*

Alice and Bob continue their games with piles of stones.
There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

Example 1:

Input: piles = [2,7,9,4,4]

Output: 10

Explanation:

If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total.
So we return 10 since it's larger.

Example 2:

Input: piles = [1,2,3,4,5,100]

Output: 104

Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 10^4

Hint 1
Use dynamic programming: the states are (i, m) for the answer of piles[i:] and that given m.

*/

package main

func main() {
	assert(stonegame([]int{2, 7, 9, 4, 4}) == 10)
	assert(stonegame([]int{1, 2, 3, 4, 5, 100}) == 104)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func stonegame(p []int) int {
	n := len(p)
	s := make([]int, n+1)
	f := make([][]int, n+1)
	for i, x := range p {
		s[i+1] = s[i] + x
		f[i] = make([]int, n+1)
	}
	return dfs(s, f, n, 0, 1)
}

func dfs(s []int, f [][]int, n, i, m int) int {
	if m*2 >= n-i {
		return s[n] - s[i]
	}
	if f[i][m] > 0 {
		return f[i][m]
	}
	f[i][m] = 0
	for x := 1; x <= m<<1; x++ {
		f[i][m] = max(f[i][m], s[n]-s[i]-dfs(s, f, n, i+x, max(m, x)))
	}
	return f[i][m]
}
