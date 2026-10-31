/*

At the start of each season, every player in a football team is assigned their own unique squad number.
Due to superstition or their history certain numbers are more desirable than others.

Write a function generateNumber() that takes two arguments, an array of the current squad numbers (squad) and the new player's desired number (n).
If the new player's desired number is not already taken, return n, else if the desired number can be formed by adding two digits between 1 and 9,
return the number formed by joining these two digits together. E.g. If 2 is taken, return 11 because 1 + 1 = 2. Otherwise return null.

Note: Often there will be several different ways to form a replacement number.
In these cases the number with lowest first digit should be given priority. E.g. If n = 15, but squad already contains 15, return 69, not 78.

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	assert(gen([]int{1, 2, 3, 4, 6, 9, 10, 15, 69}, 11) == 11)
	assert(gen([]int{1, 2, 3, 4, 6, 9, 10, 11, 15, 69}, 11) == 29)
	assert(gen([]int{1, 2, 3, 4, 6, 9, 10, 11, 15, 29, 69}, 11) == 38)
	assert(gen([]int{1, 2, 3, 4, 6, 9, 10, 11, 15, 29, 38, 47, 56, 65, 69, 74, 83, 92}, 11) == nil)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen(s []int, n int) any {
	m := make(map[int]bool)
	for _, v := range s {
		m[v] = true
	}

	if !m[n] {
		return n
	}

	for i := 1; i < min(10, n); i++ {
		t := fmt.Sprintf("%d%d", i, n-i)
		x, _ := strconv.Atoi(t)
		if n-i < 10 && !m[x] {
			return x
		}
	}
	return nil
}
