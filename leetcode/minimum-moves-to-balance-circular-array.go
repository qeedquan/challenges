/*

You are given a circular array balance of length n, where balance[i] is the net balance of person i.

In one move, a person can transfer exactly 1 unit of balance to either their left or right neighbor.

Return the minimum number of moves required so that every person has a non-negative balance. If it is impossible, return -1.

Note: You are guaranteed that at most 1 index has a negative balance initially.

Example 1:

Input: balance = [5,1,-4]

Output: 4

Explanation:

One optimal sequence of moves is:

Move 1 unit from i = 1 to i = 2, resulting in balance = [5, 0, -3]
Move 1 unit from i = 0 to i = 2, resulting in balance = [4, 0, -2]
Move 1 unit from i = 0 to i = 2, resulting in balance = [3, 0, -1]
Move 1 unit from i = 0 to i = 2, resulting in balance = [2, 0, 0]
Thus, the minimum number of moves required is 4.

Example 2:

Input: balance = [1,2,-5,2]

Output: 6

Explanation:

One optimal sequence of moves is:

Move 1 unit from i = 1 to i = 2, resulting in balance = [1, 1, -4, 2]
Move 1 unit from i = 1 to i = 2, resulting in balance = [1, 0, -3, 2]
Move 1 unit from i = 3 to i = 2, resulting in balance = [1, 0, -2, 1]
Move 1 unit from i = 3 to i = 2, resulting in balance = [1, 0, -1, 0]
Move 1 unit from i = 0 to i = 1, resulting in balance = [0, 1, -1, 0]
Move 1 unit from i = 1 to i = 2, resulting in balance = [0, 0, 0, 0]
Thus, the minimum number of moves required is 6.​​​

Example 3:

Input: balance = [-3,2]

Output: -1

Explanation:

It is impossible to make all balances non-negative for balance = [-3, 2], so the answer is -1.

Constraints:

1 <= n == balance.length <= 10^5
-10^9 <= balance[i] <= 10^9
There is at most one negative value in balance initially.

Hint 1
If there is no negative value, then the answer is 0. If the total sum is less than 0, then the answer is -1.

Hint 2
Sort the positive values in nums by their distance from the index with the negative value.

Hint 3
Greedily use as many values as needed from the sorted nums to offset the current negative value.

*/

package main

func main() {
	assert(moves([]int{5, 1, -4}) == 4)
	assert(moves([]int{1, 2, -5, 2}) == 6)
	assert(moves([]int{-3, 2}) == -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func moves(b []int) int {
	n := len(b)
	i := 0
	for ; i < n; i++ {
		if b[i] < 0 {
			break
		}
	}
	if i == n {
		return 0
	}

	s := 0
	for _, v := range b {
		s += v
	}
	if s < 0 {
		return -1
	}

	r := 0
	for d := 1; d <= n/2; d++ {
		i0 := (i + d) % n
		i1 := (((i - d) % n) + n) % n
		c := min(b[i0]+b[i1], -b[i])
		r += c * d
		b[i] += c
		if b[i] == 0 {
			break
		}
	}
	return r
}
