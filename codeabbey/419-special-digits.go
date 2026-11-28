/*

Some of the digits in an integer number may be Special Digits. A Special Digit must have the following properties:

A Special Digit cannot be either the first or the last digit in the integer number.
A Special Digit is EITHER larger than each of its two immediate neighbours OR it is smaller than each of its two immediate neighbours.
A Special Digit which is larger than each of its two immediate neighbours is called a Greater Special Digit and has a score of 2.
A Special Digit which is smaller than each of its two immediate neighbours is called a Lesser Special Digit and has a score of 1.

For example, the integer number 16598324 contains 4 Special Digits. These are: 6 (which is larger than 1 and 5), 5 (which is smaller than 6 and 9), 9 (which is larger than 5 and 8) and 2 (which is smaller than 3 and 4). So 6 and 9 are Greater Special Digits while 5 and 2 are Lesser Special Digits. We have 2 Greater Special Digits and 2 Lesser Special Digits so the number 16598324 has a score of 6.

If we consider the range of numbers from 1098 to 1101 inclusive, we find the following scores:

1098 scores 3,
1099 scores 1,
1100 scores 0 and
1101 scores 1.
The total score for the range is 5. You will be given a number of ranges and are required to calculate the total score for each range.

Input/Output description: The first line of the input data will contain a single integer N, the number of ranges to process. N lines will follow. Each line contains two numbers n1 and n2, separated by a space.

Answer: find the total score for all numbers in the range from n1 to n2 inclusive. Combine all answers into a single string, separated by spaces.

Example:

input:
4
1098 1101
68 2003
3524 635783
652797 5079646

answer:
5 2590 2139270 19135752

*/

package main

import "fmt"

func main() {
	assert(solve(1098, 1101) == 5)
	assert(solve(68, 2003) == 2590)
	assert(solve(3524, 635783) == 2139270)
	assert(solve(652797, 5079646) == 19135752)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n1, n2 int) int {
	r := 0
	for n := n1; n <= n2; n++ {
		r += score(n)
	}
	return r
}

func score(n int) int {
	if n < 0 {
		return 0
	}

	r := 0
	s := fmt.Sprint(n)
	for i := 1; i < len(s)-1; i++ {
		p0 := int(s[i-1] - '0')
		p1 := int(s[i] - '0')
		p2 := int(s[i+1] - '0')
		if p1 > p0 && p1 > p2 {
			r += 2
		} else if p1 < p0 && p1 < p2 {
			r += 1
		}
	}
	return r
}
