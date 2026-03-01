/*

Given an integer n and an integer array rounds. We have a circular track which consists of n sectors labeled from 1 to n. A marathon will be held on this track, the marathon consists of m rounds. The ith round starts at sector rounds[i - 1] and ends at sector rounds[i]. For example, round 1 starts at sector rounds[0] and ends at sector rounds[1]

Return an array of the most visited sectors sorted in ascending order.

Notice that you circulate the track in ascending order of sector numbers in the counter-clockwise direction (See the first example).

Example 1:
https://assets.leetcode.com/uploads/2020/08/14/tmp.jpg

Input: n = 4, rounds = [1,3,1,2]
Output: [1,2]
Explanation: The marathon starts at sector 1. The order of the visited sectors is as follows:
1 --> 2 --> 3 (end of round 1) --> 4 --> 1 (end of round 2) --> 2 (end of round 3 and the marathon)
We can see that both sectors 1 and 2 are visited twice and they are the most visited sectors. Sectors 3 and 4 are visited only once.

Example 2:

Input: n = 2, rounds = [2,1,2,1,2,1,2,1,2]
Output: [2]

Example 3:

Input: n = 7, rounds = [1,3,5,7]
Output: [1,2,3,4,5,6,7]


Constraints:

    2 <= n <= 100
    1 <= m <= 100
    rounds.length == m + 1
    1 <= rounds[i] <= n
    rounds[i] != rounds[i + 1] for 0 <= i < m

Hint 1
For each round increment the visits of the sectors visited during the marathon with 1.

Hint 2
Determine the max number of visits, and return any sector visited the max number of visits.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(
		4, []int{1, 3, 1, 2},
		[]int{1, 2},
	)

	test(
		2, []int{2, 1, 2, 1, 2, 1, 2, 1, 2},
		[]int{2},
	)

	test(
		7, []int{1, 3, 5, 7},
		[]int{1, 2, 3, 4, 5, 6, 7},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, a, r []int) {
	v := mostvisited(n, a)
	fmt.Println(v)
	assert(reflect.DeepEqual(v, r))
}

func mostvisited(n int, a []int) []int {
	r := []int{}
	if len(a) == 0 {
		return r
	}

	i0 := a[0]
	i1 := a[len(a)-1]
	if i0 <= i1 {
		for i := i0; i <= i1; i++ {
			r = append(r, i)
		}
	} else {
		for i := 1; i <= i1; i++ {
			r = append(r, i)
		}
		for i := i0; i <= n; i++ {
			r = append(r, i)
		}
	}
	return r
}
