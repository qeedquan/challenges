/*

The rectangular board of size n×m (n rows and m columns) is given.
The chess knight is located in the left upper corner.
You must relocate it to the right lower corner.
The knight can move only either two cells down and one right, or one cell down and two cells right.

https://static.e-olymp.com/content/c2/c214a391722a6e568aaa40a11f19055b8b114e2b.jpg

Find the number of knight paths from the left upper corner to the right lower corner.

Input
Two positive integers n and m (1≤n,m≤50).

Output
Print the number of ways to relocate the knight from the left upper corner to the right lower corner of the board.

Examples

Input #1
3 2

Answer #1
1

Input #2
31 34

Answer #2
293930

*/

package main

func main() {
	assert(solve(3, 2) == 1)
	assert(solve(31, 34) == 293930)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, m int) int {
	runx := []int{-1, -2}
	runy := []int{-2, -1}

	if n < 0 || m < 0 {
		return 0
	}

	p := make([][]int, n+1)
	for i := range p {
		p[i] = make([]int, m+1)
	}

	p[0][0] = 1
	for i := range n {
		for j := range m {
			for k := range 2 {
				x := i + runx[k]
				y := j + runy[k]
				if x >= 0 && x < n && y >= 0 && y < m && p[x][y] > 0 {
					p[i][j] += p[x][y]
				}
			}
		}
	}
	return p[n-1][m-1]
}
