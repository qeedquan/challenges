/*

You are given a positive integer k.

Find the smallest integer n divisible by k that consists of only the digit 1 in its decimal representation (e.g., 1, 11, 111, ...).

Return an integer denoting the number of digits in the decimal representation of n. If no such n exists, return -1.

Example 1:

Input: k = 3

Output: 3

Explanation:

n = 111 because 111 is divisible by 3, but 1 and 11 are not. The length of n = 111 is 3.

Example 2:

Input: k = 7

Output: 6

Explanation:

n = 111111. The length of n = 111111 is 6.

Example 3:

Input: k = 2

Output: -1

Explanation:

There does not exist a valid n that is a multiple of 2.

Constraints:

2 <= k <= 10^5

Hint 1
Notice that n % k should be 0.

Hint 2
Build the number digit-by-digit using only modulo k. Start with remainder rem = 1 % k.
Repeatedly update rem = (rem * 10 + 1) % k while counting how many 1s have been appended.

Hint 3
Continue until rem == 0 or a remainder repeats (which indicates a cycle and that no such n exists).

*/

package main

func main() {
	tab := []int{
		1, 3, 6, 9, 2, 6, 16, 18, 6, 22, 27, 28, 15, 6, 3, 6, 5, 21, 46, 42, 48,
		13, 18, 58, 60, 18, 33, 66, 35, 8, 6, 13, 81, 41, 84, 44, 6, 15, 96, 18,
		4, 34, 53, 108, 3, 112, 18, 48, 22, 15, 42, 21, 130, 18, 8, 46, 138, 6,
		42, 148, 75, 144, 78, 39, 66, 81, 166, 78, 18, 43, 174, 178,
	}

	assert(solve(3) == 3)
	assert(solve(7) == 6)
	assert(solve(2) == -1)

	for i, k := 0, 0; i < len(tab); k++ {
		r := solve(k)
		if r != -1 {
			assert(r == tab[i])
			i++
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A099679
func solve(k int) int {
	if k%2 == 0 || k%5 == 0 {
		return -1
	}

	r := 0
	for i := 1; i <= k; i++ {
		r = (r*10 + 1) % k
		if r == 0 {
			return i
		}
	}
	return -1
}
