/*

Description

Children are taught to add multi-digit numbers from right-to-left one digit at a time. Many find the "carry" operation - in which a 1 is carried from one digit position to be added to the next - to be a significant challenge. Your job is to count the number of carry operations for each of a set of addition problems so that educators may assess their difficulty.

Input

Each line of input contains two unsigned integers less than 10 digits. The last line of input contains 0 0.

Output

For each line of input except the last you should compute and print the number of carry operations that would result from adding the two numbers, in the format shown below.

Sample Input

123 456
555 555
123 594
0 0

Sample Output

No carry operation.
3 carry operations.
1 carry operation.

Source

Waterloo local 2000.09.23

*/

package main

func main() {
	assert(carries(999, 1) == 3)
	assert(carries(348, 91) == 1)
	assert(carries(398, 91) == 1)
	assert(carries(348, 51) == 0)
	assert(carries(348, 52) == 2)
	assert(carries(5, 15) == 1)
	assert(carries(999, 999) == 3)
	assert(carries(505, 505) == 2)
	assert(carries(123, 456) == 0)
	assert(carries(555, 555) == 3)
	assert(carries(123, 594) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func carries(x, y uint) uint {
	r, c := uint(0), uint(0)
	for x != 0 || y != 0 {
		v := x%10 + y%10 + c
		c = 0
		if v >= 10 {
			c = 1
		}
		r += c
		x /= 10
		y /= 10
	}
	return r
}
