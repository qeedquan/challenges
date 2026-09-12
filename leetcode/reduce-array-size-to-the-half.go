/*

You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.
Example 2:

Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.


Constraints:

2 <= arr.length <= 10^5
arr.length is even.
1 <= arr[i] <= 10^5

*/

package main

import (
	"sort"
)

func main() {
	assert(minsetsize([]int{3, 3, 3, 3, 5, 5, 5, 2, 2, 7}) == 2)
	assert(minsetsize([]int{7, 7, 7, 7, 7, 7}) == 1)
	assert(minsetsize([]int{1, 2, 3, 4, 5, 6, 7, 8}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func minsetsize(a []int) int {
	p := freqsort(a)
	n := len(p)
	return uniq(p[n/2:])
}

func freqsort(a []int) []int {
	m := make(map[int]int)
	for _, v := range a {
		m[v]++
	}

	r := append([]int{}, a...)
	sort.Slice(r, func(i, j int) bool {
		return m[r[i]] < m[r[j]]
	})
	return r
}

func uniq(a []int) int {
	m := make(map[int]bool)
	for _, v := range a {
		m[v] = true
	}
	return len(m)
}
