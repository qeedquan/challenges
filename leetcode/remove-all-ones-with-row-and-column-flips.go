/*

You are given an m x n binary matrix grid.

In one operation, you can choose any row or column and flip each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Return true if it is possible to remove all 1's from grid using any number of operations or false otherwise.

Example 1:
https://assets.leetcode.com/uploads/2022/01/03/image-20220103191300-1.png
Input: grid = [[0,1,0],[1,0,1],[0,1,0]]
Output: true
Explanation: One possible way to remove all 1's from grid is to:
- Flip the middle row
- Flip the middle column

Example 2:
https://assets.leetcode.com/uploads/2022/01/03/image-20220103181204-7.png
Input: grid = [[1,1,0],[0,0,0],[0,0,0]]
Output: false
Explanation: It is impossible to remove all 1's from grid.

Example 3:
https://assets.leetcode.com/uploads/2022/01/03/image-20220103181224-8.png
Input: grid = [[0]]
Output: true
Explanation: There are no 1's in grid.

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is either 0 or 1.

*/

package main

func main() {
	assert(removeones([][]int{
		{0, 1, 0},
		{1, 0, 1},
		{0, 1, 0},
	}) == true)

	assert(removeones([][]int{
		{1, 1, 0},
		{0, 0, 0},
		{0, 0, 0},
	}) == false)

	assert(removeones([][]int{
		{0},
	}) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func removeones(grid [][]int) bool {
	seen := map[string]bool{}
	for _, row := range grid {
		key := []byte{}
		for _, value := range row {
			if row[0] == 1 {
				value ^= 1
			}
			key = append(key, byte(value)+'0')
		}
		seen[string(key)] = true
	}
	return len(seen) == 1
}
