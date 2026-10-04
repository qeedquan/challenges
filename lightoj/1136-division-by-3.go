/*

There is sequence 1, 12, 123, 1234, ..., 12345678910, .... Now you are given two integers A and B, you have to find the number of integers from Ath number to Bth (inclusive) number, which are divisible by 3.

For example, let A = 3. B = 5. So, the numbers in the sequence are, 123, 1234, 12345. And 123, 12345 are divisible by 3. So, the result is 2.

Input
Input starts with an integer T (≤ 10000), denoting the number of test cases.

Each case contains two integers A and B (1 ≤ A ≤ B < 231) in a line.

Output
For each case, print the case number and the total numbers in the sequence between Ath and Bth which are divisible by 3.

Sample
Input	Output
2
3 5
10 110

Case 1: 2
Case 2: 67

*/

package main

func main() {
	tab := []int{
		0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 8, 8, 9, 10, 10, 11, 12, 12, 13, 14,
		14, 15, 16, 16, 17, 18, 18, 19, 20, 20, 21, 22, 22, 23, 24, 24, 25, 26,
		26, 27, 28, 28, 29, 30, 30, 31, 32, 32, 33, 34, 34, 35, 36, 36, 37, 38,
		38, 39, 40, 40, 41, 42, 42, 43, 44, 44, 45, 46,
	}

	assert(solve(3, 5) == 2)
	assert(solve(10, 110) == 67)

	for i := range tab {
		assert(seq(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b int) int {
	return seq(b) - seq(a-1)
}

// https://oeis.org/A004523
func seq(n int) int {
	tab := []int{0, 0, 1, 2, 2, 3, 4, 4, 5, 6}
	if n < 0 {
		return 0
	}
	return ((n / 9) * 6) + tab[n%9]
}
