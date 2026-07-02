/*

We will generate a sequence of binary integers as follows.

Start with the sequence:

0
1
-
Reflect this sequence with respect to a horizontal line: prefix each number in the first half with 0, and in the reflected (second) half with 1. The result is:

00
01
11
10
Repeat this process to obtain a sequence of 8 numbers:

000 0
001 1
011 3
010 2
110 6
111 7
101 5
100 4

The corresponding decimal values are shown on the right.

These sequences are called reflected Gray codes for n=1,2,3. In general, a Gray code of length n is a sequence of 2
n
  different n-bit integers such that every two neighboring integers differ in exactly one bit. A reflected Gray code for n bits is constructed as shown above.

Input
The first line contains the number of test cases t (1≤t≤250000). Each of the following t lines contains two integers: n (1≤n≤30) and k (0≤k<2^n).

Output
For each test case, output the integer that appears at position k in the sequence of n-bit reflected Gray codes, each in a separate line.

Examples

Input #1
14
1 0
1 1
2 0
2 1
2 2
2 3
3 0
3 1
3 2
3 3
3 4
3 5
3 6
3 7

Answer #1
0
1
0
1
3
2
0
1
3
2
6
7
5
4

*/

package main

import "fmt"

func main() {
	solve([][2]uint{
		{1, 0},
		{1, 1},
		{2, 0},
		{2, 1},
		{2, 2},
		{2, 3},
		{3, 0},
		{3, 1},
		{3, 2},
		{3, 3},
		{3, 4},
		{3, 5},
		{3, 6},
		{3, 7},
	})
}

func solve(x [][2]uint) {
	for i := range x {
		fmt.Println(bin2gray(x[i][1]))
	}
}

func bin2gray(n uint) uint {
	return n ^ (n >> 1)
}
