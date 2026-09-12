/*

As part of this Kata, you need to find the length of the sequence in an array, between the first and the second occurrence of a specified number.

For example, for a given array arr

[0, -3, 7, 4, 0, 3, 7, 9]

Finding length between two 7s like

lengthOfSequence([0, -3, 7, 4, 0, 3, 7, 9], 7)

would return 5.

For sake of simplicity, there will only be numbers (positive or negative) in the supplied array.

If there are less or more than two occurrences of the number to search for, return 0, or in Haskell, Nothing.

*/

package main

func main() {
	assert(find([]int{1, 1}, 1) == 2)
	assert(find([]int{1, 2, 3, 1}, 1) == 4)
	assert(find([]int{-7, 5, 0, 2, 9, 5}, 5) == 5)
	assert(find([]int{-7, 6, 2, -7, 4}, -7) == 4)
	assert(find([]int{0, -3, 7, 4, 0, 3, 7, 9}, 7) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func find(a []int, x int) int {
	r := [2]int{}
	n := 0
	for i, v := range a {
		if x == v {
			r[n], n = i, n+1
			if n >= len(r) {
				break
			}
		}
	}
	if r[0] == r[1] {
		return 0
	}
	return r[1] - r[0] + 1
}
