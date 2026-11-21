/*

A sequence of numbers is given. Sort these numbers in non-decreasing order according to their last digit;
if the last digits are equal, sort these numbers themselves in non-decreasing order.

Input
The first line contains the number n (1≤n≤100), and the second line contains positive integers, each not greater than 32000.

Output
Print the sequence of numbers sorted according to the described rules.

Examples

Input #1
7
12
15
43
13
20
1
15

Answer #1
20 1 12 13 43 15 15

Input #2
2
1004
1002

Answer #2
1002 1004

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(trickysort([]int{12, 15, 43, 13, 20, 1, 15}))
	fmt.Println(trickysort([]int{1004, 1002}))
}

func trickysort(a []int) []int {
	sort.Slice(a, func(i, j int) bool {
		x, y := a[i]%10, a[j]%10
		if x == y {
			return a[i] < a[j]
		}
		return x < y
	})
	return a
}
