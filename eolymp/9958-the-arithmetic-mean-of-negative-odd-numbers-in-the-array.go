/*

Given an array of n integers, your task is to calculate the arithmetic mean of the negative odd numbers within the array.
If there are no negative odd numbers, output NO.

Input
The first line contains the integer n (1≤n≤100), representing the number of elements in the array.
The second line contains n integers, each with an absolute value not exceeding 100.

Output
Print the arithmetic mean of the negative odd numbers, formatted to two decimal places. If there are no such numbers, print NO.

Examples

Input #1
5
-5 -4 -3 2 1

Answer #1
-4.00

Input #2
5
1 3 5 5 1

Answer #2
NO

*/

package main

import "fmt"

func main() {
	fmt.Println(solve([]int{-5, -4, -3, 2, 1}))
	fmt.Println(solve([]int{1, 3, 5, 5, 1}))
}

func solve(a []int) any {
	s, n := 0, 0
	for _, v := range a {
		if v < 0 && v&1 != 0 {
			s, n = s+v, n+1
		}
	}
	if n == 0 {
		return "NO"
	}
	return float64(s) / float64(n)
}
