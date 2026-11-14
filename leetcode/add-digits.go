/*

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0


Constraints:

0 <= num <= 2^31 - 1

Follow up: Could you do it without any loop/recursion in O(1) runtime?

*/

package main

func main() {
	assert(digitalroot(38) == 2)
	assert(digitalroot(0) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://en.wikipedia.org/wiki/Digital_root
// https://oeis.org/A010888
func digitalroot(n uint) uint {
	const base = 10
	if n == 0 {
		return 0
	}
	return 1 + ((n - 1) % (base - 1))
}
