/*

Given an m x n chessboard where you want to place chess knights. You have to find the number of maximum knights that can be placed in the chessboard such that no two knights attack each other.

Those who are not familiar with chess knights, note that a chess knight can attack 8 positions in the board as shown in the picture.

Input
Input starts with an integer T (≤ 41000), denoting the number of test cases.

Each case contains two integers m, n (1 ≤ m, n ≤ 200). Here m and n corresponds to the number of rows and the number of columns of the board respectively.

Output
For each case, print the case number and maximum number of knights that can be placed in the board considering the above restrictions.

Sample
Input	Output
3
8 8
3 7
4 10

Case 1: 32
Case 2: 11
Case 3: 20

*/

package main

func main() {
	assert(solve(8, 8) == 32)
	assert(solve(3, 7) == 11)
	assert(solve(4, 10) == 20)
	assert(solve(2, 2) == 4)
	assert(solve(358, 2) == 360)
	assert(solve(2, 345) == 346)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, m int) int {
	switch {
	case n == 1 || m == 1:
		return max(n, m)
	case n == 2 || m == 2:
		r := ((m * n) / 8) * 4
		if ((m * n) % 8) >= 4 {
			r += 4
		} else {
			r += (m * n) % 8
		}
		return r
	}
	return (n*m + 1) / 2
}
