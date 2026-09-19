/*

You are in a cave, a deep cave! The cave can be represented by an 1 x N grid. Some cells in the cave might contain gold!

Initially, you are in position 1. In each move, you throw a perfect 6 sided dice. If you get X in the dice after throwing, you add X to your position and collect all the gold from the new position. If your new position is outside of the cave, you keep throwing the dice again until you get a suitable result. When you reach the Nth position you stop your journey.

Given the information about the cave, you have to find the expected amount of gold you can collect using the procedure described above.

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case contains a blank line and an integer N (1≤ N ≤ 100) denoting the dimension of the cave. The next line contains N space separated integers. The ith integer denotes the amount of gold you will get if you come to the ith cell. You may safely assume that all the given integers will be non-negative and not greater than 1000.

Output
For each case, print the case number and the expected number of gold you will collect. Errors less than 10-6 will be ignored.

Sample
Input	Output
3

1
101

2
10 3

3
3 6 9

Case 1: 101
Case 2: 13.000000
Case 3: 15.0000000000

*/

package main

import "fmt"

func main() {
	fmt.Println(solve([]float64{101}))
	fmt.Println(solve([]float64{10, 3}))
	fmt.Println(solve([]float64{3, 6, 9}))
}

func solve(cells []float64) float64 {
	return recurse(cells, make(map[int]float64), 1)
}

func recurse(cells []float64, memo map[int]float64, position int) float64 {
	if size := len(cells); position >= size {
		return cells[size-1]
	}

	if result, found := memo[position]; found {
		return result
	}

	result := 0.0
	for index := 1; index <= 6; index++ {
		if position+index <= len(cells) {
			denom := min(6, len(cells)-position)
			result += (1.0 / float64(denom)) * recurse(cells, memo, position+index)
		}
	}
	memo[position] = cells[position-1] + result
	return memo[position]
}
