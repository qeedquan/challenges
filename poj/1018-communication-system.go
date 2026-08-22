/*

Description

We have received an order from Pizoor Communications Inc. for a special communication system. The system consists of several devices. For each device, we are free to choose from several manufacturers. Same devices from two manufacturers differ in their maximum bandwidths and prices.
By overall bandwidth (B) we mean the minimum of the bandwidths of the chosen devices in the communication system and the total price (P) is the sum of the prices of all chosen devices. Our goal is to choose a manufacturer for each device to maximize B/P.

Input

The first line of the input file contains a single integer t (1 ≤ t ≤ 10), the number of test cases, followed by the input data for each test case. Each test case starts with a line containing a single integer n (1 ≤ n ≤ 100), the number of devices in the communication system, followed by n lines in the following format: the i-th line (1 ≤ i ≤ n) starts with mi (1 ≤ mi ≤ 100), the number of manufacturers for the i-th device, followed by mi pairs of positive integers in the same line, each indicating the bandwidth and the price of the device respectively, corresponding to a manufacturer.

Output

Your program should produce a single line for each test case containing a single number which is the maximum possible B/P for the test case. Round the numbers in the output to 3 digits after decimal point.

Sample Input

1 3
3 100 25 150 35 80 25
2 120 80 155 40
2 100 100 120 110

Sample Output

0.649

Source

Tehran 2002, First Iran Nationwide Internet Programming Contest

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test([][][2]int{
		{{4, 1}, {2, 2}, {3, 3}},
		{{2, 3}, {2, 4}},
		{{1, 4}},
	}, 0.125)

	test([][][2]int{
		{{100, 25}, {150, 35}, {80, 25}},
		{{120, 80}, {155, 40}},
		{{100, 100}, {120, 110}},
	}, 0.649)

	test([][][2]int{
		{{1, 2}, {3, 4}, {5, 6}},
		{{3, 5}, {4, 6}},
	}, 0.333)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a [][][2]int, r float64) {
	v := com(a)
	fmt.Printf("%.3f\n", v)
	assert(math.Abs(v-r) < 1e-3)
}

func com(a [][][2]int) float64 {
	n := len(a)
	dp := alloc(maxsize(a))
	for i := range dp {
		for j := range dp[i] {
			dp[i][j] = math.MaxInt
		}
	}

	for i := 1; i <= n; i++ {
		for j := range a[i-1] {
			b, p := a[i-1][j][0], a[i-1][j][1]
			switch i {
			case 1:
				dp[i][b] = min(p, dp[i][b])

			default:
				for z := 1; z < len(dp[i-1]); z++ {
					if dp[i-1][z] != math.MaxInt {
						k := min(z, b)
						dp[i][k] = min(dp[i][k], dp[i-1][z]+p)
					}
				}
			}
		}
	}

	r := 0.0
	for i := 1; i < len(dp[n]); i++ {
		if dp[n][i] != math.MaxInt {
			r = max(r, float64(i)/float64(dp[n][i]))
		}
	}
	return r
}

func maxsize(a [][][2]int) int {
	s := len(a)
	for i := range a {
		s = max(s, len(a[i]))
		for j := range a[i] {
			for k := range a[i][j] {
				s = max(s, a[i][j][k])
			}
		}
	}
	return s + 1
}

func alloc(n int) [][]int {
	p := make([][]int, n)
	t := make([]int, n*n)
	for i := range p {
		p[i] = t[i*n : (i+1)*n]
	}
	return p
}
