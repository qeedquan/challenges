/*

In mathematics, the standard deviation of a set of n integer numbers is defined as:
S = sqrt((Sum[i=1, n] (x[i] - xmean)^2) / (n - 1))

where x¯ is the average of the set of n integer numbers for which the standard deviation is being calculated. That average is calculated as:
x¯ = 1/n * Sum[i=1, n] x[i]

The task is to calculate, in an efficient way, the standard deviation of the first n odd positive integer numbers.

Input
There are several test cases in the input. Each test case consists of a single line containing a positive
integer number n (2 ≤ n ≤ 10^6) which indicates the amount of consecutive odd numbers (starting from one) that should be considered when calculating the standard deviation.
The last test case has a value of ‘0’, for which you shouldn’t generate any response.

Output
For each test case, you should print a single line containing a floating point number: the standard
deviation of the first n odd positive numbers. The absolute error of your answer should not be greater than 10^-6.

Sample Input
10
100
1000
10000
100000
1000000
0

Sample Output
6.055301
58.022984
577.638872
5773.791360
57735.315593
577350.557865

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(10))
	fmt.Println(solve(100))
	fmt.Println(solve(1000))
	fmt.Println(solve(10000))
	fmt.Println(solve(100000))
	fmt.Println(solve(1000000))
}

func solve(n float64) float64 {
	x_sq := sos(n*2) - 4*sos(n)
	x := son(n*2) - 2*son(n)
	xm := x / n
	return math.Sqrt((x_sq - 2*xm*x + xm*xm*n) / (n - 1))
}

func son(n float64) float64 {
	return n * (n + 1) / 2
}

func sos(n float64) float64 {
	return n * (n + 1) * (2*n + 1) / 6
}
