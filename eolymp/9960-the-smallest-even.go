/*

Find the smallest even element in a given array of n integers. Output the index and value of this element.

If multiple even elements have the smallest value, select the one with the lowest index. If there are no even elements in the array, output NO. Assume the array is zero-indexed.

Input
The first line contains an integer n (1≤n≤100) — the number of elements in the array.

The second line contains n integers a0,a1,…,a[n-1], each satisfying ∣ai∣≤100.

Output
If there is at least one even element, print two integers: the index of the smallest even element, followed by its value.

If there are no even elements, print NO.

Examples

Input #1
5
0 7 8 -8 2

Answer #1
3 -8

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	solve([]int{0, 7, 8, -8, 2})
}

func solve(a []int) {
	n, m := -1, math.MaxInt
	for i, v := range a {
		if v&1 == 0 && (n < 0 || m > v) {
			n, m = i, v
		}
	}
	if n >= 0 {
		fmt.Println(n, m)
	} else {
		fmt.Println("NO")
	}
}
