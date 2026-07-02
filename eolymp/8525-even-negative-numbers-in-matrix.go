/*

Given matrix of size n⋅n. Find the number and the sum of its even negative elements.

Input
The first line contains number n (1≤n≤100). The next lines contain the n⋅n matrix. All numbers in the matrix are no more than 100 by absolute value.

Output
Print in one line the number and the sum of even negative numbers in the matrix.

Examples

Input #1
3
4 -2 5
1 -4 -12
0 1 -3

Answer #1
3 -18

*/

package main

import "fmt"

func main() {
	fmt.Println(solve([][]int{
		{4, -2, 5},
		{1, -4, -12},
		{0, 1, -3},
	}))
}

func solve(m [][]int) (int, int) {
	s, n := 0, 0
	for i := range m {
		for j := range m[i] {
			if m[i][j] < 0 && m[i][j]&1 == 0 {
				s += m[i][j]
				n += 1
			}
		}
	}
	return n, s
}
