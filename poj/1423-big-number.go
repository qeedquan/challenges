/*

Description

In many applications very large integers numbers are required. Some of these applications are using keys for secure transmission of data, encryption, etc. In this problem you are given a number, you have to determine the number of digits in the factorial of the number.

Input

Input consists of several lines of integer numbers. The first line contains an integer n, which is the number of cases to be tested, followed by n lines, one integer 1 <= m <= 10^7 on each line.

Output

The output contains the number of digits in the factorial of the integers appearing in the input.

Sample Input

2
10
20

Sample Output

7
19

Source

Dhaka 2002

*/

package main

import (
	"math"
)

func main() {
	assert(digfact(1) == 1)
	assert(digfact(10) == 7)
	assert(digfact(20) == 19)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A034886
func digfact(n uint64) uint64 {
	if n < 2 {
		return 1
	}

	x := float64(n)
	a := math.Log(2*math.Pi*x) / (2 * math.Ln10)
	b := x * math.Log(x/math.E) / math.Ln10
	r := math.Floor(a+b) + 1
	return uint64(r)
}
