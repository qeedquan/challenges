/*

Due to the modernization of the toothbrush factory on Tau Ceti, it has been decided to update the list of robots servicing the factory.
Each robot is identified by two numbers: a primary number and a secondary number.
The updated list must adhere to the following rules:

If one robot appears before another in the new list, then the primary number of the first robot must be less than or equal to the primary number of the second robot.

If two robots have the same primary number, they should appear in the same order as they do in the original list.

The Tau Cetians have requested your help to reorganize the list. Assist them in modernizing their operations!

Input
The first line of the input contains the integer N (1≤N≤100000), which represents the number of robots in the factory.
Each of the next N lines contains 2 numbers: the primary and secondary numbers of a robot.
Both numbers are non-negative and do not exceed 10^9.

Output
Output N lines, where the i-th line contains 2 numbers: the primary and secondary numbers of the i-th robot in the new list.

Examples
Input #1
10
1 8
8 9
2 10
1 11
4 2
7 2
3 11
2 23
3 3
6 7

Answer #1
1 8
1 11
2 10
2 23
3 11
3 3
4 2
6 7
7 2
8 9

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(solve([][2]int{
		{1, 8},
		{8, 9},
		{2, 10},
		{1, 11},
		{4, 2},
		{7, 2},
		{3, 11},
		{2, 23},
		{3, 3},
		{6, 7},
	}))
}

func solve(a [][2]int) [][2]int {
	sort.SliceStable(a, func(i, j int) bool {
		return a[i][0] < a[j][0]
	})
	return a
}
