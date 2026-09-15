/*

A two-dimensional array of size n×m is given.
Find all rows that contain the minimal element.

Input
First line contains two integers n and m (1≤n,m≤100) — the number of rows and columns, respectively.
The next n lines each contain m integers representing the elements of the array.
All elements are integers with absolute value not exceeding 100.
The numbering of elements starts from 1.

Output
In one line the numbers of all rows that contain the minimal element, in increasing order.

Examples

Input #1
4 5
2 5 3 1 4
3 5 2 3 4
4 6 1 2 3
4 5 6 7 7

Answer #1
1 3

Input #3
10 10
12 13 23 11 21 11 11 11 11 11
11 21 15 11 14 18 11 19 11 11
12 31 61 11 31 17 11 67 11 11
13 14 17 11 12 16 11 11 11 11
14 13 81 11 13 51 11 11 35 44
75 22 19 11 14 14 11 11 11 11
16 34 11 11 15 31 11 11 11 11
17 14 11 11 16 12 11 11 11 11
21 15 11 11 11 11 11 11 11 11
16 34 11 11 15 31 11 11 11 11

Answer #3
1 2 3 4 5 6 7 8 9 10

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve([][]int{
		{2, 5, 3, 1, 4},
		{3, 5, 2, 3, 4},
		{4, 6, 1, 2, 3},
		{4, 5, 6, 7, 7},
	}))

	fmt.Println(solve([][]int{
		{12, 13, 23, 11, 21, 11, 11, 11, 11, 11},
		{11, 21, 15, 11, 14, 18, 11, 19, 11, 11},
		{12, 31, 61, 11, 31, 17, 11, 67, 11, 11},
		{13, 14, 17, 11, 12, 16, 11, 11, 11, 11},
		{14, 13, 81, 11, 13, 51, 11, 11, 35, 44},
		{75, 22, 19, 11, 14, 14, 11, 11, 11, 11},
		{16, 34, 11, 11, 15, 31, 11, 11, 11, 11},
		{17, 14, 11, 11, 16, 12, 11, 11, 11, 11},
		{21, 15, 11, 11, 11, 11, 11, 11, 11, 11},
		{16, 34, 11, 11, 15, 31, 11, 11, 11, 11},
	}))

}

func solve(m [][]int) []int {
	v := math.MaxInt
	for i := range m {
		for j := range m[i] {
			v = min(v, m[i][j])
		}
	}

	r := []int{}
	for i := range m {
		for j := range m[i] {
			if m[i][j] == v {
				r = append(r, i+1)
				break
			}
		}
	}
	return r
}
