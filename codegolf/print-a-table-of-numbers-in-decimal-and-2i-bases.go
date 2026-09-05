/*

Computers live by binary. All programmers know binary.

But the 2**x bases are often neglected as non-practical, while they have beautiful relations to binary.

To show you one example of such a beatiful relation, 19 will be my testimonial.

19 10011 103 23 13 j
19 is decimal, included for clarity.

10011 is 19 in binary.

103, in base 4 is made starting from binary this way:

log2(4) == 2, let us remember two.
Pad 10011 so that it has a multiple of 2 length -> 010011
Take digits 2 by 2 from left to right and treat them as 2-digits binary numbers:

01 -> 1
00 -> 0
11 -> 3
Done, 10011 in base-4 is 103.

For base 8, do the same but 3-by-3 as log2(8) = 3.

Pad 010011
010 -> 2
011 -> 3

23, Done.

For base 16, do the same but 4-by-4 as log2(16) = 4.

Pad 00010011
0001 -> 1
0011 -> 3

13, Done.

Task

Given a max number as input, you shall output a table

base-ten-i base-two-i base-four-i base-eight-i base-sixteen-i base-thirtytwo-i
for i that goes from 0 to n inclusive. Binary numbers are the epitome of the absolute minimum needed to work, so your code should be as short as possible.

Restrictions and bonuses

Base-ten -> binary and binary -> Base-ten built-ins are considered loopholes as Base-a -> Base-b are.

If you generate all the 2**i (for i > 2) bases by using the relations over mentioned you get a *0.6 bonus, but general base conversions (written by yourself) are allowed.

Example table

> 32
0 0 0 0 0 0
1 1 1 1 1 1
2 10 2 2 2 2
3 11 3 3 3 3
4 100 10 4 4 4
5 101 11 5 5 5
6 110 12 6 6 6
7 111 13 7 7 7
8 1000 20 10 8 8
9 1001 21 11 9 9
10 1010 22 12 a a
11 1011 23 13 b b
12 1100 30 14 c c
13 1101 31 15 d d
14 1110 32 16 e e
15 1111 33 17 f f
16 10000 100 20 10 g
17 10001 101 21 11 h
18 10010 102 22 12 i
19 10011 103 23 13 j
20 10100 110 24 14 k
21 10101 111 25 15 l
22 10110 112 26 16 m
23 10111 113 27 17 n
24 11000 120 30 18 o
25 11001 121 31 19 p
26 11010 122 32 1a q
27 11011 123 33 1b r
28 11100 130 34 1c s
29 11101 131 35 1d t
30 11110 132 36 1e u
31 11111 133 37 1f v
32 100000 200 40 20 10

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	table(32)
}

func table(n int64) {
	f := strconv.FormatInt
	for i := int64(0); i <= n; i++ {
		fmt.Println(i, f(i, 2), f(i, 4), f(i, 8), f(i, 16), f(i, 32))
	}
}
