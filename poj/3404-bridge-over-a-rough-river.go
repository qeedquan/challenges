/*

Description

A group of N travelers (1 ≤ N ≤ 50) has approached an old and shabby bridge and wishes to cross the river as soon as possible. However, there can be no more than two persons on the bridge at a time. Besides it's necessary to light the way with a torch for safe crossing but the group has only one torch.

Each traveler needs ti seconds to cross the river on the bridge; i=1, ... , N (ti are integers from 1 to 100). If two travelers are crossing together their crossing time is the time of the slowest traveler.

The task is to determine minimal crossing time for the whole group.

Input

The input consists of two lines: the first line contains the value of N and the second one contains the values of ti (separated by one or several spaces).

Output

The output contains one line with the result.

Sample Input

4
6 7 6 5

Sample Output

29

Source

Northeastern Europe 2001, Western Subregion

*/

package main

import (
	"sort"
)

func main() {
	assert(crossing([]int{6, 7, 6, 5}) == 29)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func crossing(a []int) int {
	sort.Ints(a)

	n := len(a)
	if n < 1 {
		return 0
	}

	if n < 3 {
		return a[n-1]
	}

	x, y, z := a[0], a[1], 0
	for i := 2; i < n; i++ {
		z = min(y+a[i]+a[0], x+a[0]+a[i]+2*a[1])
		x, y = y, z
	}
	return z
}
