/*

The sequence of real numbers a1,a2,…,an is given. Find the number and the sum of positive elements whose indexes are divisible by 3.

Input
The first line contains the number of elements n (n≤100) in the sequence. The second line contains n real numbers, each with an absolute value not exceeding 100.

Output
Print in one line the number of required elements and their sum, with exactly two digits after the decimal point.

Examples
Input #1
6
6 7.5 2.1 2.0 0 -3

Answer #1
1 2.10

*/

package main

import "fmt"

func main() {
	fmt.Println(solve([]float64{6, 7.5, 2.1, 2.0, 0, -3}))
}

func solve(a []float64) (int, float64) {
	c := 0
	s := 0.0
	for i := 2; i < len(a); i += 3 {
		if a[i] > 0 {
			c += 1
			s += a[i]
		}
	}
	return c, s
}
