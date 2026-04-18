/*

Any positive integer can be written as the sum of several consecutive integers. For example,
15 = 1 + . . . + 5 = 4 + . . . + 6 = 7 + . . . + 8 = 15 + . . . + 15
Given a positive integer n, what are the consecutive positive integers with sum being n? If there
are multiple solutions, which one consists of more numbers?

Input
Input consists of multiple problem instances. Each instance consists of a single positive integer n, where n ≤ 10^9.
The input data is terminated by a line containing ‘-1’. There will be at most 1000 test cases.

Output
For each input integer n, print out the desired solution with the format:
N = A + ... + B
in a single line. (Read sample output for a clearer representation of the exact formatting.)

Sample Input
8
15
35
-1

Sample Output
8 = 8 + ... + 8
15 = 1 + ... + 5
35 = 2 + ... + 8

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(8))
	fmt.Println(solve(15))
	fmt.Println(solve(35))
}

func solve(s int) (int, int, int) {
	if s < 1 {
		return 0, 0, 0
	}

	x := 0
	n := isqrt(2 * s)
	for ; n > 0; n-- {
		if (2*s+n-n*n)%(2*n) == 0 {
			x = (2*s + n - n*n) / (2 * n)
			break
		}
	}
	return s, x, x + n - 1
}

func isqrt(x int) int {
	return int(math.Sqrt(float64(x)))
}
