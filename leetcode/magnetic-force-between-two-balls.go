/*

In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.

Example 1:

https://assets.leetcode.com/uploads/2020/08/11/q3v1.jpg
Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.

Example 2:

Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.

Constraints:

    n == position.length
    2 <= n <= 10^5
    1 <= position[i] <= 10^9
    All integers in position are distinct.
    2 <= m <= position.length

Hint 1
If you can place balls such that the answer is x then you can do it for y where y < x.

Hint 2
Similarly if you cannot place balls such that the answer is x then you can do it for y where y > x.

Hint 3
Binary search on the answer and greedily see if it is possible.

*/

package main

import (
	"sort"
)

func main() {
	assert(maxdistance([]int{1, 2, 3, 4, 7}, 3) == 3)
	assert(maxdistance([]int{5, 4, 3, 2, 1, 1000000000}, 2) == 999999999)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxdistance(p []int, m int) int {
	if len(p) == 0 {
		return 0
	}

	sort.Ints(p)
	l := 0
	r := p[len(p)-1] - p[0]
	for l <= r {
		x := l + (r-l)/2
		if !check(p, m, x) {
			r = x - 1
		} else {
			l = x + 1
		}
	}
	return r
}

func check(p []int, m, x int) bool {
	c := 1
	q := p[0]
	for i := 1; i < len(p); i++ {
		if p[i]-q >= x {
			c += 1
			q = p[i]
		}
	}
	return c >= m
}
