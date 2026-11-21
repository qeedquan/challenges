/*

Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times.
Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 10^9 + 7.

Example 1:

Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]

Example 2:

Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].

Constraints:

1 <= arr.length <= 1000
2 <= arr[i] <= 10^9
All the values of arr are unique.

*/

package main

import "sort"

func main() {
	assert(trees([]int{2, 4}) == 3)
	assert(trees([]int{2, 4, 5, 10}) == 7)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func trees(a []int) int {
	const mod = 1_000_000_007

	sort.Ints(a)
	p := make(map[int]int)
	for i := range a {
		p[a[i]] = 1
		for j := range i {
			if a[i]%a[j] == 0 && p[a[i]/a[j]] > 0 {
				p[a[i]] = (p[a[i]] + p[a[j]]*p[a[i]/a[j]]) % mod
			}
		}
	}

	r := 0
	for _, v := range p {
		r = (r + v) % mod
	}
	return r
}
