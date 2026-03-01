/*

Description

The king pays his loyal knight in gold coins. On the first day of his service, the knight receives one gold coin. On each of the next two days (the second and third days of service), the knight receives two gold coins. On each of the next three days (the fourth, fifth, and sixth days of service), the knight receives three gold coins. On each of the next four days (the seventh, eighth, ninth, and tenth days of service), the knight receives four gold coins. This pattern of payments will continue indefinitely: after receiving N gold coins on each of N consecutive days, the knight will receive N+1 gold coins on each of the next N+1 consecutive days, where N is any positive integer.

Your program will determine the total number of gold coins paid to the knight in any given number of days (starting from Day 1).

Input

The input contains at least one, but no more than 21 lines. Each line of the input file (except the last one) contains data for one test case of the problem, consisting of exactly one integer (in the range 1..10000), representing the number of days. The end of the input is signaled by a line containing the number 0.

Output

There is exactly one line of output for each test case. This line contains the number of days from the corresponding line of input, followed by one blank space and the total number of gold coins paid to the knight in the given number of days, starting with Day 1.

Sample Input

10
6
7
11
15
16
100
10000
1000
21
22
0

Sample Output

10 30
6 14
7 18
11 35
15 55
16 61
100 945
10000 942820
1000 29820
21 91
22 98
Source

Rocky Mountain 2004

*/

package main

import (
	"math"
)

func main() {
	tab := []int{
		1, 3, 5, 8, 11, 14, 18, 22, 26, 30, 35, 40, 45, 50, 55, 61, 67, 73, 79, 85, 91, 98, 105, 112,
		119, 126, 133, 140, 148, 156, 164, 172, 180, 188, 196, 204, 213, 222, 231, 240, 249, 258, 267,
		276, 285, 295, 305, 315, 325, 335, 345, 355, 365, 375, 385, 396, 407, 418,
	}

	assert(gold(10) == 30)
	assert(gold(6) == 14)
	assert(gold(7) == 18)
	assert(gold(11) == 35)
	assert(gold(15) == 55)
	assert(gold(16) == 61)
	assert(gold(100) == 945)
	assert(gold(10000) == 942820)
	assert(gold(1000) == 29820)
	assert(gold(21) == 91)
	assert(gold(22) == 98)

	for i, v := range tab {
		assert(gold(i+1) == v)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A060432
func gold(n int) int {
	m := (n + 1) << 1
	r := isqrt(m)
	k := r + truth(m<<2 > (r<<2)*(r+1)+1) - 1
	return k*(k*(-k-3)+6*n-2)/6 + n
}

func isqrt(x int) int {
	return int(math.Sqrt(float64(x)))
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}
