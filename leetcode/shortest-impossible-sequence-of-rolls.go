/*

You are given an integer array rolls of length n and an integer k. You roll a k sided dice numbered from 1 to k, n times, where the result of the ith roll is rolls[i].

Return the length of the shortest sequence of rolls so that there's no such subsequence in rolls.

A sequence of rolls of length len is the result of rolling a k sided dice len times.

Example 1:

Input: rolls = [4,2,1,2,3,3,2,4,1], k = 4
Output: 3
Explanation: Every sequence of rolls of length 1, [1], [2], [3], [4], can be taken from rolls.
Every sequence of rolls of length 2, [1, 1], [1, 2], ..., [4, 4], can be taken from rolls.
The sequence [1, 4, 2] cannot be taken from rolls, so we return 3.
Note that there are other sequences that cannot be taken from rolls.

Example 2:

Input: rolls = [1,1,2,2], k = 2
Output: 2
Explanation: Every sequence of rolls of length 1, [1], [2], can be taken from rolls.
The sequence [2, 1] cannot be taken from rolls, so we return 2.
Note that there are other sequences that cannot be taken from rolls but [2, 1] is the shortest.

Example 3:

Input: rolls = [1,1,3,2,2,2,3,3], k = 4
Output: 1
Explanation: The sequence [4] cannot be taken from rolls, so we return 1.
Note that there are other sequences that cannot be taken from rolls but [4] is the shortest.

Constraints:

n == rolls.length
1 <= n <= 10^5
1 <= rolls[i] <= k <= 10^5

Hint 1
How can you find the minimum index such that all sequences of length 1 can be formed from the start until that index?

Hint 2
Starting from the previous minimum index, what is the next index such that all sequences of length 2 can be formed?

Hint 3
Can you extend the idea to sequences of length 3 and more?

*/

package main

func main() {
	assert(sequence([]int{4, 2, 1, 2, 3, 3, 2, 4, 1}, 4) == 3)
	assert(sequence([]int{1, 1, 2, 2}, 2) == 2)
	assert(sequence([]int{1, 1, 3, 2, 2, 2, 3, 3}, 4) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sequence(rolls []int, k int) int {
	length := 0
	seen := make(map[int]bool)
	for _, roll := range rolls {
		seen[roll] = true
		if len(seen) == k {
			clear(seen)
			length += 1
		}
	}
	return length + 1
}
