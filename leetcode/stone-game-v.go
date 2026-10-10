/*

There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.

The game ends when there is only one stone remaining. Alice's score is initially zero.

Return the maximum score that Alice can obtain.

Example 1:

Input: stoneValue = [6,2,3,4,5,5]
Output: 18
Explanation: In the first round, Alice divides the row to [6,2,3], [4,5,5]. The left row has the value 11 and the right row has value 14. Bob throws away the right row and Alice's score is now 11.
In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).
The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.

Example 2:

Input: stoneValue = [7,7,7,7,7,7,7]
Output: 28
Example 3:

Input: stoneValue = [4]
Output: 0

Constraints:

1 <= stoneValue.length <= 500
1 <= stoneValue[i] <= 10^6

Hint 1
We need to try all possible divisions for the current row to get the max score.

Hint 2
As calculating all possible divisions will lead us to calculate some sub-problems more than once, we need to think of dynamic programming.

*/

package main

func main() {
	assert(stonegame([]int{6, 2, 3, 4, 5, 5}) == 18)
	assert(stonegame([]int{7, 7, 7, 7, 7, 7, 7}) == 28)
	assert(stonegame([]int{4}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func stonegame(x []int) int {
	n := len(x)
	if n == 0 {
		return 0
	}

	s := make([]int, n+1)
	for i, x := range x {
		s[i+1] = s[i] + x
	}

	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	return dfs(x, s, f, 0, n-1)
}

func dfs(x, s []int, f [][]int, i, j int) int {
	if i >= j {
		return 0
	}

	if f[i][j] != -1 {
		return f[i][j]
	}

	v, l, r := 0, 0, s[j+1]-s[i]
	for k := i; k < j; k++ {
		l += x[k]
		r -= x[k]
		if l < r {
			if v > l*2 {
				continue
			}
			v = max(v, dfs(x, s, f, i, k)+l)
		} else if l > r {
			if v > r*2 {
				break
			}
			v = max(v, dfs(x, s, f, k+1, j)+r)
		} else {
			v = max(v, max(dfs(x, s, f, i, k), dfs(x, s, f, k+1, j))+l)
		}
	}
	f[i][j] = v
	return v
}
