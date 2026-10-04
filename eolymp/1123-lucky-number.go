/*

To Chinese people, 8 is considered a lucky number. Your task is to determine if a given number is lucky.

A number is called lucky if it is a multiple of 8, or the sum of its digits is a multiple of 8, or the sum of the squares of its digits is a multiple of 8.

Input
The first line contains the number of test cases, which does not exceed 10.

Each test case is given in a single line containing an integer n (n≥0). All numbers do not exceed 2⋅10^9.

Output
For each test case, output "Lucky number!" if the number is lucky, otherwise output "What a pity!" on a separate line.

Examples

Input #1
2
0
8

Answer #1
Lucky number!
Lucky number!

*/

package main

func main() {
	assert(solve(0) == "Lucky number!")
	assert(solve(8) == "Lucky number!")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) string {
	if n%8 == 0 || digsump(n, 1)%8 == 0 || digsump(n, 2)%8 == 0 {
		return "Lucky number!"
	}
	return "What a pity!"
}

func digsump(n, p int) int {
	r := 0
	for ; n > 0; n /= 10 {
		r += ipow(n%10, p)
	}
	return r
}

func ipow(x, p int) int {
	r := 1
	for range p {
		r *= x
	}
	return r
}
