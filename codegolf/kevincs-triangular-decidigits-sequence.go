/*

Input:

A positive integer n which is 1 <= n <= 25000.

Output:

In this sequence we start with the decimal number 1/n.
Then we take the sum of digits up until the n'th digit after the comma (1-indexed); followed by the sum of digits up until the (n-1)'th, then (n-2)'th, etc. Continue until n is 1.
The output is the sum of all these combined.
For example:

n = 7
1/7 = 0.1428571428...
7th digit-sum = 1+4+2+8+5+7+1 = 28
6th digit-sum = 1+4+2+8+5+7 = 27
5th digit-sum = 1+4+2+8+5 = 20
4th digit-sum = 1+4+2+8 = 15
3rd digit-sum = 1+4+2 = 7
2nd digit-sum = 1+4 = 5
1st digit     = 1
Output = 28+27+20+15+7+5+1 = 103

Challenge rules:

If the decimal of 1/n doesn't have n digits after the comma, the missing ones will be counted as 0 (i.e. 1/2 = 0.50 => (5+0) + (5) = 10).
You take the digits without rounding (i.e. the digits of 1/6 are 166666 and not 166667)

General rules:

Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.

First 1 - 50 in the sequence:

0, 10, 18, 23, 10, 96, 103, 52, 45, 10, 270, 253, 402, 403, 630, 183, 660, 765, 819, 95, 975, 1034, 1221, 1500, 96, 1479, 1197, 1658, 1953, 1305, 1674, 321, 816, 2490, 2704, 4235, 2022, 3242, 2295, 268, 2944, 3787, 3874, 4097, 1980, 4380, 4968, 3424, 4854, 98

Last 24990 - 25000 in the sequence:

1405098782, 1417995426, 1364392256, 1404501980, 1408005544, 1377273489, 1395684561, 1405849947, 1406216741, 1142066735, 99984

*/

package main

import (
	"math/big"
)

func main() {
	tab1 := []int{0, 10, 18, 23, 10, 96, 103, 52, 45, 10, 270, 253, 402, 403, 630, 183, 660, 765, 819, 95, 975, 1034, 1221, 1500, 96, 1479, 1197, 1658, 1953, 1305, 1674, 321, 816, 2490, 2704, 4235, 2022, 3242, 2295, 268, 2944, 3787, 3874, 4097, 1980, 4380, 4968, 3424, 4854, 98}
	tab2 := []int{1405098782, 1417995426, 1364392256, 1404501980, 1408005544, 1377273489, 1395684561, 1405849947, 1406216741, 1142066735, 99984}

	for i := range tab1 {
		assert(ktds(i+1) == tab1[i])
	}
	for i := range tab2 {
		assert(ktds(24990+i) == tab2[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func ktds(n int) int {
	return sum(digits(n))
}

func digits(n int) []int {
	x := big.NewRat(1, int64(n))
	s := x.FloatString((n + 1) * 10)
	if len(s) > 2 {
		s = s[2:]
	}

	d := make([]int, n)
	for i := 0; i < n; i++ {
		d[i] = int(s[i] - '0')
	}
	return d
}

func sum(a []int) int {
	r := 0
	for i, v := range a {
		r += v * (len(a) - i)
	}
	return r
}
