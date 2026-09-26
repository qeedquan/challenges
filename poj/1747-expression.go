/*

Description

It is known that Sheffer stroke function (NOT-AND) can be used to construct any Boolean function. The truth table for this function is given below:
Truth table for Sheffer stroke function
x	y	x|y
0	0	1
0	1	1
1	0	1
1	1	0

Consider the problem of adding two binary numbers A and B, each containing N bits. The individual bits of A and B are numbered from 0 (the least significant) to N-1 (the most significant). The sum of A and B can always be represented by N+1 bits. Let's call most significant bit of the sum (bit number N) the overflow bit.

Your task is to construct a logical expression using the Sheffer stroke function that computes the value of the overflow bit for arbitrary values of A and B. Your expression shall be constructed according to the following rules:
Ai is an expression that denotes value of ith bit of number A.
Bi is an expression that denotes value of ith bit of number B.
(x|y) is an expression that denotes the result of Sheffer stroke function for x and y, where x and y are expressions.

When writing the index, i, for bits in A and B, the index shall be written as a decimal number without leading zeros. For example, bit number 12 of A must be written as A12. The expression should be completely parenthesized (according to the 3rd rule). No blanks are allowed inside the expression.

Input

The input contains a single integer N (1 <= N <= 100).

Output

Write to the output an expression for calculating overflow bit of the addition of two N-bit numbers A and B according to the rules given in the problem statement.
Note: The stroke symbol ( | ) is an ASCII character with code 124 (decimal).

The output size shall not exceed 50*N bytes.

Sample Input

2

Sample Output

((A1|B1)|(((A0|B0)|(A0|B0))|((A1|A1)|(B1|B1))))

Source

Northeastern Europe 1999

*/

package main

import "fmt"

func main() {
	assert(express(2) == "((A1|B1)|(((A0|B0)|(A0|B0))|((A1|A1)|(B1|B1))))")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func express(n int) string {
	return recurse(n - 1)
}

func recurse(n int) string {
	if n < 0 {
		return ""
	}
	if n == 0 {
		return "((A0|B0)|(A0|B0))"
	}
	return fmt.Sprintf("((A%d|B%d)|(%s|((A%d|A%d)|(B%d|B%d))))", n, n, recurse(n-1), n, n, n, n)
}
