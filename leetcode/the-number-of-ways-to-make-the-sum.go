/*

You have an infinite number of coins with values 1, 2, and 6, and only 2 coins with value 4.

Given an integer n, return the number of ways to make the sum of n with the coins you have.

Since the answer may be very large, return it modulo 109 + 7.

Note that the order of the coins doesn't matter and [2, 2, 3] is the same as [2, 3, 2].

Example 1:
Input: n = 4
Output: 4
Explanation:
Here are the four combinations: [1, 1, 1, 1], [1, 1, 2], [2, 2], [4].

Example 2:
Input: n = 12
Output: 22
Explanation:
Note that [4, 4, 4] is not a valid combination since we cannot use 4 three times.

Example 3:
Input: n = 5
Output: 4
Explanation:
Here are the four combinations: [1, 1, 1, 1, 1], [1, 1, 1, 2], [1, 2, 2], [1, 4].

Constraints:

1 <= n <= 10^5

*/

package main

func main() {
	tab := []int{
		1, 2, 4, 7, 11, 16, 22, 29, 37, 46, 56, 67, 79, 92, 106, 121, 137, 154,
		172, 191, 211, 232, 254, 277, 301, 326, 352, 379, 407, 436, 466, 497,
		529, 562, 596, 631, 667, 704, 742, 781, 821, 862, 904, 947, 991, 1036,
		1082, 1129, 1177, 1226, 1276, 1327, 1379,
	}

	for i, j := 0, 0; i < len(tab); i, j = i+1, j+2 {
		assert(ways(j) == tab[i])
		assert(ways(j+1) == tab[i])
	}

	assert(ways(4) == 4)
	assert(ways(12) == 22)
	assert(ways(5) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A000124
func ways(n int) int {
	const mod = 1_000_000_007

	m := n / 2
	return (1 + (m+1)*m/2) % mod
}
