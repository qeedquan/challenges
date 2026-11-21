/*

Ava, Mark, Sheila, and Pete are at a party. However, Ava and Sheila are only staying if there are at least 4 people, Pete is only staying if there's at least 1 person, and Mark is only staying if there are at least 5 people. Therefore, Mark leaves, which makes Ava and Sheila leave, and Pete is left alone.

Given an array with the preferences of every person at a party for the minimum number of people present, determine how many people will stay.

Examples
[4, 5, 4, 1] ➞ 1
# Ava's minimum number is 4, Mark's is 5, Sheila's is 4, and Pete's is 1.
# Only 1 person (Pete) stays.

[10, 12, 15, 15, 5] ➞ 0

[2, 1, 2, 0] ➞ 4

Notes
All attendees are included in the array.
Any person's count includes themself.
Expect valid input only.
0 <= len(lst) <= 10^5

*/

package main

import "sort"

func main() {
	assert(partypeople([]int{4, 5, 4, 1}) == 1)
	assert(partypeople([]int{10, 12, 15, 15, 5}) == 0)
	assert(partypeople([]int{2, 1, 2, 0}) == 4)
	assert(partypeople([]int{0, 0, 0, 0}) == 4)
	assert(partypeople([]int{5, 5, 5, 5}) == 0)
	assert(partypeople([]int{5, 5, 5, 5, 5}) == 5)
	assert(partypeople([]int{1, 5, 3, 5, 0}) == 5)
	assert(partypeople([]int{13, 8, 11, 15, 13, 3, 12, 13, 6, 3}) == 0)
	assert(partypeople([]int{11, 3, 4, 3, 11, 4, 0, 1, 1, 3}) == 8)
	assert(partypeople([]int{15, 3, 8, 0, 2, 12, 13, 7, 6}) == 3)
	assert(partypeople([]int{3, 11, 15, 5, 3, 4, 10, 8, 14, 6, 13, 1}) == 6)
	assert(partypeople([]int{7, 14, 14, 0, 7, 3, 2, 2}) == 4)
	assert(partypeople([]int{2, 6, 7, 4, 6, 10, 4, 3, 6, 2, 0}) == 11)
	assert(partypeople([]int{0, 2, 3, 5, 6, 6, 6, 7, 11, 12, 13, 14, 16, 19, 20}) == 8)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func partypeople(list []int) int {
	sort.Ints(list)

	count := 0
	for index := range list {
		if list[len(list)-index-1] <= count+len(list)-index {
			count++
		}
	}
	return count
}
