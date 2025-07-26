/*

You are given an integer n.

Each number from 1 to n is grouped according to the sum of its digits.

Return the number of groups that have the largest size.

Example 1:

Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
There are 4 groups with largest size.
Example 2:

Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.


Constraints:

1 <= n <= 10^4

*/

package main

func main() {
	assert(largestgroup(13) == 4)
	assert(largestgroup(2) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func digitsum(n int) int {
	r := 0
	for ; n > 0; n /= 10 {
		r += n % 10
	}
	return r
}

func largestgroup(n int) int {
	c := 0
	r := 0
	m := make(map[int]int)
	for i := 1; i <= n; i++ {
		k := digitsum(i)
		if m[k]++; m[k] > c {
			c = m[k]
			r = 1
		} else if m[k] == c {
			r += 1
		}
	}
	return r
}
