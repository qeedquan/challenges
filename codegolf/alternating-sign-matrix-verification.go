/*

An alternating sign matrix is an n by n matrix consisting of the numbers -1, 0, 1, such that:

The sum of each row and column is 1
The nonzero entries in each row and column alternate in sign
These matrices generalise permutation matrices, and the number of such matrices for a given n was of interest for some time. They occur naturally during the Dodgson condensation method of computing matrix determinants (named after Charles Dodgson, better known as Lewis Carroll).

Here are some examples of 4 by 4 alternating sign matrices:

 0  1  0  0          1  0  0  0          0  0  1  0          0  0  1  0
 0  0  1  0          0  0  1  0          0  1 -1  1          1  0 -1  1
 1  0  0  0          0  1 -1  1          1 -1  1  0          0  1  0  0
 0  0  0  1          0  0  1  0          0  1  0  0          0  0  1  0
And here are some examples of 4 by 4 matrices which aren't alternating sign matrices:

 0  1  0  0
 0  0  0  1
 1  0  0  0
 0  0  1 -1    (last row and last column don't add to 1)

 0  0  0  1
 1  0  0  0
-1  1  1  0
 1  0  0  0    (third row does not alternate correctly)
Your program or function will be given an n by n matrix (n >= 1) of -1s, 0s and 1s — output a truthy value if the given matrix is an alternating sign matrix, otherwise output a falsy value.

This is code-golf, so the goal is to minimise the number of bytes used.

Test cases
The following test cases are given in a Python-like 2D list format.

Truthy:

[[1]]
[[1,0],[0,1]]
[[0,1],[1,0]]
[[0,1,0],[0,0,1],[1,0,0]]
[[0,1,0],[1,-1,1],[0,1,0]]
[[0,1,0,0],[0,0,1,0],[1,0,0,0],[0,0,0,1]]
[[1,0,0,0],[0,0,1,0],[0,1,-1,1],[0,0,1,0]]
[[0,0,1,0],[0,1,-1,1],[1,-1,1,0],[0,1,0,0]]
[[0,0,1,0],[1,0,-1,1],[0,1,0,0],[0,0,1,0]]
[[0,0,1,0,0],[0,1,-1,1,0],[1,-1,1,0,0],[0,1,0,-1,1],[0,0,0,1,0]]
[[0,0,1,0,0,0,0,0],[1,0,-1,0,1,0,0,0],[0,0,0,1,-1,0,0,1],[0,0,1,-1,1,0,0,0],[0,0,0,0,0,0,1,0],[0,0,0,0,0,1,0,0],[0,1,-1,1,0,0,0,0],[0,0,1,0,0,0,0,0]]
[[0,0,0,0,1,0,0,0],[0,0,1,0,-1,1,0,0],[0,0,0,1,0,0,0,0],[1,0,0,-1,1,-1,1,0],[0,1,-1,1,-1,1,0,0],[0,0,0,0,1,0,0,0],[0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1]]
Falsy:

[[0]]
[[-1]]
[[1,0],[0,0]]
[[0,0],[0,1]]
[[-1,1],[1,0]]
[[0,1],[1,-1]]
[[0,0,0],[0,0,0],[0,0,0]]
[[0,1,0],[1,0,1],[0,1,0]]
[[-1,1,1],[1,-1,1],[1,1,-1]]
[[0,0,1],[1,0,0],[0,1,-1]]
[[0,1,0,0],[0,0,0,1],[1,0,0,0],[0,0,1,-1]]
[[0,0,1,0],[0,0,1,0],[1,0,-1,1],[0,1,0,0]]
[[0,0,0,1],[1,0,0,0],[-1,1,1,0],[1,0,0,0]]
[[1,0,1,0,-1],[0,1,0,0,0],[0,0,0,0,1],[0,0,0,1,0],[0,0,0,0,1]]
[[0,0,1,0,0],[0,1,-1,1,0],[1,-1,1,0,0],[0,1,1,-1,0],[0,0,-1,1,1]]
[[0,-1,0,1,1],[1,-1,1,-1,1],[0,1,1,0,-1],[1,1,-1,1,-1],[-1,1,0,0,1]]
[[0,0,1,0,0,0,0,0],[1,0,1,0,1,0,0,0],[0,0,0,1,-1,0,0,1],[0,0,1,-1,1,0,0,0],[0,0,0,0,0,0,1,0],[0,0,0,0,0,1,0,0],[0,1,-1,1,0,0,0,0],[0,0,1,0,0,0,0,0]]

*/

package main

func main() {
	assert(altmat([][]int{
		{1},
	}) == true)

	assert(altmat([][]int{
		{1, 0},
		{0, 1},
	}) == true)

	assert(altmat([][]int{
		{0, 1},
		{1, 0},
	}) == true)

	assert(altmat([][]int{
		{0, 1, 0},
		{0, 0, 1},
		{1, 0, 0},
	}) == true)

	assert(altmat([][]int{
		{0, 1, 0},
		{1, -1, 1},
		{0, 1, 0},
	}) == true)

	assert(altmat([][]int{
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{1, 0, 0, 0},
		{0, 0, 0, 1},
	}) == true)

	assert(altmat([][]int{
		{1, 0, 0, 0},
		{0, 0, 1, 0},
		{0, 1, -1, 1},
		{0, 0, 1, 0},
	}) == true)

	assert(altmat([][]int{
		{0, 0, 1, 0},
		{0, 1, -1, 1},
		{1, -1, 1, 0},
		{0, 1, 0, 0},
	}) == true)

	assert(altmat([][]int{
		{0, 0, 1, 0},
		{1, 0, -1, 1},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
	}) == true)

	assert(altmat([][]int{
		{0, 0, 1, 0, 0},
		{0, 1, -1, 1, 0},
		{1, -1, 1, 0, 0},
		{0, 1, 0, -1, 1},
		{0, 0, 0, 1, 0},
	}) == true)

	assert(altmat([][]int{
		{0, 0, 1, 0, 0, 0, 0, 0},
		{1, 0, -1, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, -1, 0, 0, 1},
		{0, 0, 1, -1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 1, 0, 0},
		{0, 1, -1, 1, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0},
	}) == true)

	assert(altmat([][]int{
		{0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 1, 0, -1, 1, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0},
		{1, 0, 0, -1, 1, -1, 1, 0},
		{0, 1, -1, 1, -1, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1},
	}) == true)

	assert(altmat([][]int{
		{0},
	}) == false)

	assert(altmat([][]int{
		{-1},
	}) == false)

	assert(altmat([][]int{
		{1, 0},
		{0, 0},
	}) == false)

	assert(altmat([][]int{
		{0, 0},
		{0, 1},
	}) == false)

	assert(altmat([][]int{
		{-1, 1},
		{1, 0},
	}) == false)

	assert(altmat([][]int{
		{0, 1},
		{1, -1},
	}) == false)

	assert(altmat([][]int{
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
	}) == false)

	assert(altmat([][]int{
		{0, 1, 0},
		{1, 0, 1},
		{0, 1, 0},
	}) == false)

	assert(altmat([][]int{
		{-1, 1, 1},
		{1, -1, 1},
		{1, 1, -1},
	}) == false)

	assert(altmat([][]int{
		{0, 0, 1},
		{1, 0, 0},
		{0, 1, -1},
	}) == false)

	assert(altmat([][]int{
		{0, 1, 0, 0},
		{0, 0, 0, 1},
		{1, 0, 0, 0},
		{0, 0, 1, -1},
	}) == false)

	assert(altmat([][]int{
		{0, 0, 1, 0},
		{0, 0, 1, 0},
		{1, 0, -1, 1},
		{0, 1, 0, 0},
	}) == false)

	assert(altmat([][]int{
		{0, 0, 0, 1},
		{1, 0, 0, 0},
		{-1, 1, 1, 0},
		{1, 0, 0, 0},
	}) == false)

	assert(altmat([][]int{
		{1, 0, 1, 0, -1},
		{0, 1, 0, 0, 0},
		{0, 0, 0, 0, 1},
		{0, 0, 0, 1, 0},
		{0, 0, 0, 0, 1},
	}) == false)

	assert(altmat([][]int{
		{0, 0, 1, 0, 0},
		{0, 1, -1, 1, 0},
		{1, -1, 1, 0, 0},
		{0, 1, 1, -1, 0},
		{0, 0, -1, 1, 1},
	}) == false)

	assert(altmat([][]int{
		{0, -1, 0, 1, 1},
		{1, -1, 1, -1, 1},
		{0, 1, 1, 0, -1},
		{1, 1, -1, 1, -1},
		{-1, 1, 0, 0, 1},
	}) == false)

	assert(altmat([][]int{
		{0, 0, 1, 0, 0, 0, 0, 0},
		{1, 0, 1, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, -1, 0, 0, 1},
		{0, 0, 1, -1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 1, 0, 0},
		{0, 1, -1, 1, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0},
	}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func altmat(m [][]int) bool {
	for i := range m {
		r, c := 0, 0
		rp, cp := 0, 0
		for j := range m[i] {
			if !between(m[i][j], -1, 1) || !between(m[j][i], -1, 1) {
				return false
			}

			if !xpar(&rp, m[i][j]) || !xpar(&cp, m[j][i]) {
				return false
			}

			r, c = r+m[i][j], c+m[j][i]
		}

		if r != 1 || c != 1 {
			return false
		}
	}
	return true
}

func between(x, n, m int) bool {
	return n <= x && x <= m
}

func xpar(x *int, y int) bool {
	if y == 0 {
		return true
	}

	if *x == 0 || (*x == -1 && y == 1) || (*x == 1 && y == -1) {
		*x = y
		return true
	}

	return false
}
