/*

Description
You are given an integer array nums of length n and an integer k.

For each index i, define the delayed count as the number of indices j such that:

i + k < j <= n - 1, and
nums[j] == nums[i]
Return an array ans where ans[i] is the delayed count of index i.

Example 1:

Input: nums = [1,2,1,1], k = 1

Output: [2,0,0,0]

Explanation:

i	nums[i]	possible j	nums[j]	satisfying
nums[j] == nums[i]	ans[i]
0	1	[2, 3]	[1, 1]	[2, 3]	2
1	2	[3]	[1]	[]	0
2	1	[]	[]	[]	0
3	1	[]	[]	[]	0
Thus, ans = [2, 0, 0, 0].

Example 2:

Input: nums = [3,1,3,1], k = 0

Output: [1,1,0,0]

Explanation:

i	nums[i]	possible j	nums[j]	satisfying
nums[j] == nums[i]	ans[i]
0	3	[1, 2, 3]	[1, 3, 1]	[2]	1
1	1	[2, 3]	[3, 1]	[3]	1
2	3	[3]	[1]	[]	0
3	1	[]	[]	[]	0
Thus, ans = [1, 1, 0, 0]

Constraints:

1 <= n == nums.length <= 10^5
1 <= nums[i] <= 10^5
0 <= k <= n - 1

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{1, 2, 1, 1}, 1, []int{2, 0, 0, 0})
	test([]int{3, 1, 3, 1}, 0, []int{1, 1, 0, 0})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, k int, r []int) {
	p := delayedcount(a, k)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func delayedcount(a []int, k int) []int {
	n := len(a)
	c := make(map[int]int)
	r := make([]int, n)
	for i := n - k - 2; i >= 0; i-- {
		c[a[i+k+1]] += 1
		r[i] = c[a[i]]
	}
	return r
}
