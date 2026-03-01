/*

For a given positive integer, try to find out the smallest possible rotation resulted by rotating it 0 or more bits.

For example, when the given number is 177, whose binary representation is 10110001(2):

10110001(2)=177
01100011(2)=99
11000110(2)=198
10001101(2)=141
00011011(2)=27
00110110(2)=54
01101100(2)=108
11011000(2)=216
27 is the smallest rotating result. So we output 27 for 177.

Input / Output
You may choose one of the following behaviors:

Input a positive integer n. Output its smallest bit rotation as defined above.
Input a positive integer n. Output smallest bit rotation for numbers 1…n.
Input nothing, output this infinity sequence.
Due to definition of this sequence. You are not allowed to consider it as 0-indexed, and output smallest bit rotate for n−1, n+1 if you choose the first option. However, if you choose the second or the third option, you may optionally include 0 to this sequence, and smallest bit rotation for 0 is defined as 0. In all other cases, handling 0 as an input is not a required behavior.

Test cases
So, here are smallest bit rotate for numbers 1…100:

 1  1  3  1  3  3  7  1  3  5
 7  3  7  7 15  1  3  5  7  5
11 11 15  3  7 11 15  7 15 15
31  1  3  5  7  9 11 13 15  5
13 21 23 11 27 23 31  3  7 11
15 13 23 27 31  7 15 23 31 15
31 31 63  1  3  5  7  9 11 13
15  9 19 21 23 19 27 29 31  5
13 21 29 21 43 43 47 11 27 43
55 23 55 47 63  3  7 11 15 19

Notes
This is code-golf as usual.
This is A163381.
The largest bit rotation is A163380. A233569 is similar but different. (The first different item is the 37th).

*/

package main

import (
	"math/bits"
)

func main() {
	tab := []uint{1, 1, 3, 1, 3, 3, 7, 1, 3, 5, 7, 3, 7, 7, 15, 1, 3, 5, 7, 5, 11, 11, 15, 3, 7, 11, 15, 7, 15, 15, 31, 1, 3, 5, 7, 9, 11, 13, 15, 5, 13, 21, 23, 11, 27, 23, 31, 3, 7, 11, 15, 13, 23, 27, 31, 7, 15, 23, 31, 15, 31, 31, 63, 1, 3, 5, 7, 9, 11, 13, 15, 9, 19, 21, 23, 19, 27, 29, 31, 5, 13, 21, 29}

	for i := range tab {
		assert(sbr(uint(i+1)) == tab[i])
	}

	assert(sbr(177) == 27)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A163381
func sbr(x uint) uint {
	b := bits.UintSize - bits.LeadingZeros(x)
	m := uint(1<<b) - 1
	r := x
	for range b {
		x = (x<<1 | x>>(b-1)) & m
		r = min(r, x)
	}
	return r
}
