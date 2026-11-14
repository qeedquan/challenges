/*

Given an integer n, decompose it into a sum of maximal triangular numbers (where Tm represents the mth triangular number, or the sum of the integers from 1 to m) as follows:

while n > 0,

find the largest possible triangular number Tm such that Tm ≤ n.

append m to the triangular-decomposition representation of n.

subtract Tm from n.

For example, an input of 44 would yield an output of 8311, because:

1+2+3+4+5+6+7+8 = 36 < 44, but 1+2+3+4+5+6+7+8+9 = 45 > 44.

the first digit is 8; subtract 36 from 44 to get 8 left over.
1+2+3 = 6 < 8, but 1+2+3+4 = 10 > 8.

the second digit is 3; subtract 6 from 8 to get 2 left over.
1 < 2, but 1+2 = 3 > 2.

the third and fourth digits must be 1 and 1.
Use the digits 1 through 9 to represent the first 9 triangular numbers, then use the letters a through z (can be capitalized or lowercase) to represent the 10th through 35th triangular number. You will never be given an input that will necessitate the use of a larger "digit".

The bounds on the input are 1 ≤ n < 666, and it will always be an integer.

All possible inputs and outputs, and some selected test cases (listed as input, then output):

1 1
2 11
3 2
4 21
5 211
6 3
100 d32
230 k5211
435 t
665 z731
An output of ∞ for an input of -1/12 is not required. :)

*/

var assert = require('assert');

/*

@Arnauld

How?
Rather than explicitly computing Ti = 1 + 2 + 3 + … + i, we start with t = 0 and iteratively subtract t + 1 from n while t < n, incrementing t at each iteration. When the condition is not fulfilled anymore, a total of Tt has been subtracted from n and the output is updated accordingly. We repeat the process until n = 0.

Below is a summary of all operations for n = 100.

 n  |  t | t < n | output
----+----+-------+--------
100 |  0 | yes   | ""
 99 |  1 | yes   | ""
 97 |  2 | yes   | ""
 94 |  3 | yes   | ""
 90 |  4 | yes   | ""
 85 |  5 | yes   | ""
 79 |  6 | yes   | ""
 72 |  7 | yes   | ""
 64 |  8 | yes   | ""
 55 |  9 | yes   | ""
 45 | 10 | yes   | ""
 34 | 11 | yes   | ""
 22 | 12 | yes   | ""
  9 | 13 | no    | "d"
----+----+-------+--------
  9 |  0 | yes   | "d"
  8 |  1 | yes   | "d"
  6 |  2 | yes   | "d"
  3 |  3 | no    | "d3"
----+----+-------+--------
  3 |  0 | yes   | "d3"
  2 |  1 | yes   | "d3"
  0 |  2 | no    | "d32"

*/

function encode(number, counter=0) {
	if (counter < number)
		return encode(number - (counter + 1), counter + 1);
	return counter.toString(36) + ((number) ? encode(number) : "");
}

assert(encode(1) == "1");
assert(encode(2) == "11");
assert(encode(3) == "2");
assert(encode(4) == "21");
assert(encode(5) == "211");
assert(encode(6) == "3");
assert(encode(100) == "d32");
assert(encode(230) == "k5211");
assert(encode(435) == "t");
assert(encode(665) == "z731");
