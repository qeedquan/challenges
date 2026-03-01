/*

An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

Example 1:

Input: low = 100, high = 300
Output: [123,234]

Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]

Constraints:

10 <= low <= high <= 10^9


Hint 1
Generate all numbers with sequential digits and check if they are in the given range.

Hint 2
Fix the starting digit then do a recursion that tries to append all valid digits.

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(seq(100, 300))
	fmt.Println(seq(1000, 13000))
}

func seq(lo, hi int) []int {
	r := []int{}
	for i := 1; i < 9; i++ {
		x := i
		for j := i + 1; j < 10; j++ {
			x = x*10 + j
			if lo <= x && x <= hi {
				r = append(r, x)
			}
		}
	}
	sort.Ints(r)
	return r
}
