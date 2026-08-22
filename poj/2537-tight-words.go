/*

Description

Given is an alphabet {0, 1, ... , k}, 0 <= k <= 9 . We say that a word of length n over this alphabet is tight if any two neighbour digits in the word do not differ by more than 1.

Input

Input is a sequence of lines, each line contains two integer numbers k and n, 1 <= n <= 100.

Output

For each line of input, output the percentage of tight words of length n over the alphabet {0, 1, ... , k} with 5 fractional digits.

Sample Input

4 1
2 5
3 5
8 7
Sample Output

100.00000
40.74074
17.38281
0.10130
Source

Waterloo local 2001.01.27


*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(4, 1, 100.00000)
	test(2, 5, 40.74074)
	test(3, 5, 17.38281)
	test(8, 7, 0.10130)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(k, n int, r float64) {
	v := tightness(k, n)
	fmt.Println(v)
	assert(math.Abs(v-r) < 1e-5)
}

func tightness(k, n int) float64 {
	t := 1
	p := make([][]int, n)
	for i := range p {
		p[i] = make([]int, k+1)
		for j := 0; j <= k; j++ {
			p[0][j] = 1
		}
		t *= (k + 1)
	}

	for i := 1; i < n; i++ {
		for j := 0; j <= k; j++ {
			switch {
			case j == 0:
				p[i][j] += p[i-1][j]
				p[i][j+1] += p[i-1][j]
			case j == k:
				p[i][j-1] += p[i-1][j]
				p[i][j] += p[i-1][j]
			default:
				p[i][j-1] += p[i-1][j]
				p[i][j] += p[i-1][j]
				p[i][j+1] += p[i-1][j]
			}
		}
	}

	r := 0
	for i := 0; i <= k; i++ {
		r += p[n-1][i]
	}
	return float64(r*100) / float64(t)
}
