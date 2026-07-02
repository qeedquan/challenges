/*

Given a sequence of numbers a1,…,an. For given indices l and r, calculate Sl,r = a[l]+a[l+1]+…+a[r]

Input
The first line contains the number of elements n (1≤n≤10^6).
The second line contains the numbers ai (1≤ai≤1000) separated by spaces.
The third line contains the number of queries m (1≤m≤10^6).
Each of the next m lines contains the indices li and ri (1≤li≤ri≤n).

Output
Print the value Sli,ri for each query on a separate line.

Examples

Input #1
5
1 2 3 4 5
5
1 5
2 3
3 4
2 5
1 4

Answer #1
15
5
7
14
10

*/

package main

import "fmt"

func main() {
	solve(
		[]int{1, 2, 3, 4, 5},
		[][2]int{
			{1, 5},
			{2, 3},
			{3, 4},
			{2, 5},
			{1, 4},
		},
	)
}

func solve(numbers []int, queries [][2]int) {
	prefix := prefixsum(numbers)
	for _, query := range queries {
		i := query[1] - 1
		j := query[0] - 2

		result := prefix[i]
		if j >= 0 {
			result -= prefix[j]
		}
		fmt.Println(result)
	}
}

func prefixsum(numbers []int) []int {
	prefix := make([]int, len(numbers))
	if len(prefix) == 0 {
		return prefix
	}

	prefix[0] = numbers[0]
	for i := 1; i < len(prefix); i++ {
		prefix[i] = prefix[i-1] + numbers[i]
	}
	return prefix
}
