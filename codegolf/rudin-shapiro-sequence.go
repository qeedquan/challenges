/*

The Rudin-Shapiro sequence is a sequence of 1s and -1s defined as follows: rn=(−1)un, where un is the number of occurrences of (possibly overlapping) 11 in the binary representation of n.

For example, r[461]=-1, because 461 in binary is 111001101, which contains 3 occurrences of 11: 111001101, 111001101, 111001101.

This is sequence A020985 in the OEIS.

The first few terms of the sequence are:

1, 1, 1, -1, 1, 1, -1, 1, 1, 1, 1, -1, -1, -1, 1, -1, 1, 1, 1, -1, 1, 1, -1, 1, -1, -1, -1, 1, 1, 1, -1, 1, 1, 1, 1, -1, 1, 1, -1, 1, 1, 1, 1, -1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1, 1, -1, 1, 1, 1, -1, -1, -1, 1, -1, 1, 1, 1, -1, 1, 1, -1, 1, 1, 1, 1, -1, -1, -1, 1, -1, 1

Task

Generate the Rudin-Shapiro sequence.

As with standard sequence challenges, you may choose to:

    Take an integer n

as input and output the nth term of the sequence.

Take an integer n as input and output the first n terms of the sequence.
Take no input and output the sequence indefinitely.

This is code-golf, so the shortest code in bytes in each language wins.
Test cases

0 -> 1
1 -> 1
2 -> 1
3 -> -1
4 -> 1
5 -> 1
6 -> -1
7 -> 1
8 -> 1
9 -> 1
10 -> 1
11 -> -1
12 -> -1
13 -> -1
14 -> 1
15 -> -1
16 -> 1
17 -> 1
18 -> 1
19 -> -1

*/

package main

import "math/bits"

func main() {
	tab := []int{1, 1, 1, -1, 1, 1, -1, 1, 1, 1, 1, -1, -1, -1, 1, -1, 1, 1, 1, -1, 1, 1, -1, 1, -1, -1, -1, 1, 1, 1, -1, 1, 1, 1, 1, -1, 1, 1, -1, 1, 1, 1, 1, -1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1, 1, -1, 1, 1, 1, -1, -1, -1, 1, -1, 1, 1, 1, -1, 1, 1, -1, 1, 1, 1, 1, -1, -1, -1, 1, -1, 1}

	for i := range tab {
		assert(rs(uint(i)) == tab[i])
	}
	assert(rs(461) == -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A020985
func rs(n uint) int {
	b := bits.OnesCount((n & (n >> 1)))
	if b&1 != 0 {
		return -1
	}
	return 1
}
