/*

You are given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:

maximum_value = -1
maximum_index = -1
search_cost = 0
n = arr.length
for (i = 0; i < n; i++) {
	if (maximum_value < arr[i]) {
		maximum_value = arr[i]
		maximum_index = i
		search_cost = search_cost + 1
	}
}
return maximum_index

You should build the array arr which has the following properties:

    arr has exactly n integers.
    1 <= arr[i] <= m where (0 <= i < n).
    After applying the mentioned algorithm to arr, the value search_cost is equal to k.

Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 10^9 + 7.

Example 1:

Input: n = 2, m = 3, k = 1
Output: 6
Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]

Example 2:

Input: n = 5, m = 2, k = 3
Output: 0
Explanation: There are no possible arrays that satisfy the mentioned conditions.

Example 3:

Input: n = 9, m = 1, k = 1
Output: 1
Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]

Constraints:

    1 <= n <= 50
    1 <= m <= 100
    0 <= k <= n

Hint 1
Use dynamic programming approach. Build dp table where dp[a][b][c] is the number of ways you can start building the array starting from index a where the search_cost = c and the maximum used integer was b.

Hint 2
Recursively, solve the small sub-problems first. Optimize your answer by stopping the search if you exceeded k changes.

*/

package main

func main() {
	assert(arrays(2, 3, 1) == 6)
	assert(arrays(5, 2, 3) == 0)
	assert(arrays(9, 1, 1) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func arrays(n, m, k int) int {
	const mod = 1000000007

	var d, p [2][][]int
	for i := range 2 {
		d[i] = make([][]int, m+1)
		p[i] = make([][]int, m+1)
		for j := range m + 1 {
			d[i][j] = make([]int, k+1)
			p[i][j] = make([]int, k+1)
		}
	}

	for i := 1; i <= m; i++ {
		d[1][i][1] = 1
		p[1][i][1] = (p[1][i-1][1] + d[1][i][1]) % mod
	}

	for l := 2; l <= n; l++ {
		for i := 1; i <= m; i++ {
			for j := 1; j <= k; j++ {
				x := l % 2
				y := (l - 1) % 2
				d[x][i][j] = (i*d[y][i][j]%mod + p[y][i-1][j-1]) % mod
				p[x][i][j] = (p[x][i-1][j] + d[x][i][j]) % mod
			}
		}
	}

	return p[n%2][m][k]
}
