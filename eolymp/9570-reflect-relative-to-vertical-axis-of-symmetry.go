/*

Given a rectangular two-dimensional array with dimensions n×m, your task is to reflect it across the vertical axis of symmetry.

Input
The first line contains two integers, n and m, representing the dimensions of the array.

The following n lines each contain m integers, representing the elements of the array.

Output
Print the transformed array.

Examples
Input #1
2 3
1 2 3
4 5 6

Answer #1
3 2 1
6 5 4

*/

package main

import "fmt"

func main() {
	fmt.Println(solve([][]int{{1, 2, 3}, {4, 5, 6}}))
}

func solve(m [][]int) [][]int {
	for i := range m {
		for j := range len(m[i]) / 2 {
			k := len(m[i]) - j - 1
			m[i][j], m[i][k] = m[i][k], m[i][j]
		}
	}
	return m
}
