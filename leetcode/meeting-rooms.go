/*

Given an array of meeting time intervals consisting of start and end times[[s1,e1],[s2,e2],...](si< ei), determine if a person could attend all meetings.

Example 1:
Input:
[[0,30],[5,10],[15,20]]
Output:
 false

Example 2:
Input:
 [[7,10],[2,4]]

Output:
 true

*/

package main

import "sort"

func main() {
	assert(attendable([][2]int{{0, 30}, {5, 10}, {15, 20}}) == false)
	assert(attendable([][2]int{{7, 10}, {2, 4}}) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func attendable(a [][2]int) bool {
	sort.SliceStable(a, func(i, j int) bool {
		return a[i][0] < a[j][0]
	})

	for i := 1; i < len(a); i++ {
		if a[i-1][1] > a[i][0] {
			return false
		}
	}
	return true
}
