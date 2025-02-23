/*

Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

Example 1:
Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Example 2:
Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.

Example 3:
Input: n = 0
Output: 0

Constraints:

0 <= n <= 10^4

Follow up: Could you write a solution that works in logarithmic time complexity?

*/

package main

func main() {
	assert(trailingzeroes(3) == 0)
	assert(trailingzeroes(5) == 1)
	assert(trailingzeroes(0) == 0)
	assert(trailingzeroes(101) == 24)
	assert(trailingzeroes(803) == 199)
	assert(trailingzeroes(6453) == 1611)
	assert(trailingzeroes(10000) == 2499)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A027868
func trailingzeroes(n uint64) uint64 {
	return (n - digitsum(convb(n, 5, 10))) / 4
}

func convb(n, b, p uint64) uint64 {
	if b == 0 {
		return 0
	}

	r := uint64(0)
	d := []uint64{}
	for ; n > 0; n /= b {
		d = append(d, n%b)
	}
	for i := len(d) - 1; i >= 0; i-- {
		r = (r * p) + d[i]
	}
	return r
}

func digitsum(n uint64) uint64 {
	r := uint64(0)
	for n > 0 {
		r += n % 10
		n /= 10
	}
	return r
}
