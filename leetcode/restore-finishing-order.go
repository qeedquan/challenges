/*

Hint
You are given an integer array order of length n and an integer array friends.

order contains every integer from 1 to n exactly once, representing the IDs of the participants of a race in their finishing order.
friends contains the IDs of your friends in the race sorted in strictly increasing order. Each ID in friends is guaranteed to appear in the order array.
Return an array containing your friends' IDs in their finishing order.

Example 1:

Input: order = [3,1,2,5,4], friends = [1,3,4]

Output: [3,1,4]

Explanation:

The finishing order is [3, 1, 2, 5, 4]. Therefore, the finishing order of your friends is [3, 1, 4].

Example 2:

Input: order = [1,4,5,3,2], friends = [2,5]

Output: [5,2]

Explanation:

The finishing order is [1, 4, 5, 3, 2]. Therefore, the finishing order of your friends is [5, 2].

Constraints:

1 <= n == order.length <= 100
order contains every integer from 1 to n exactly once
1 <= friends.length <= min(8, n)
1 <= friends[i] <= n
friends is strictly increasing

Hint 1
Use a hash set for quick friend lookups from friends.

Hint 2
Iterate over order, checking the set to collect your friends in finishing order.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{3, 1, 2, 5, 4}, []int{1, 3, 4}, []int{3, 1, 4})
	test([]int{1, 4, 5, 3, 2}, []int{2, 5}, []int{5, 2})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(order, friends, expected []int) {
	result := recoverorder(order, friends)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func recoverorder(order, friends []int) []int {
	lookup := make(map[int]bool)
	for _, value := range friends {
		lookup[value] = true
	}

	result := []int{}
	for _, value := range order {
		if lookup[value] {
			result = append(result, value)
		}
	}
	return result
}
