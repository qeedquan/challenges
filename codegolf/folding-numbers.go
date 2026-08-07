/*

Given a number determine if it is a folding number.

A folding number is a number such that if you take it binary representation and "fold" it in half, That is take the result of XNOR multiplication of the first half of the number and the second half with it digits in reverse, you will get zero.

If the number has a odd number of digits in binary its middle digit must be 1 and is ignored when folding.

Since that might be a bit confusing I will give some examples:

178
The binary representation of 178 is

10110010
To fold this we first split it in half

1011 0010
We reverse the second half

1011
0100
And we XNOR the two halves:

0000
This is zero so this is a folding number.

1644
The binary representation of 1644 is

11001101100
To fold this we first split it in half

11001 1 01100
The middle bit is 1 so we throw it out.

11001 01100
We reverse the second half

11001
00110
And we XNOR the two halves:

00000
This is zero so this is a folding number.

4254
The binary representation of 4254 is

1000010011110
To fold this we first split it in half

100001 0 011110
The middle bit is 0 so this is not a folding number.

Task
Your task is to take in a positive number and return a truthy if the number is folding and falsy if it is not. This is code golf so try to keep the byte count down.

Test Cases
Here are the first 99 folding numbers:

[1, 2, 6, 10, 12, 22, 28, 38, 42, 52, 56, 78, 90, 108, 120, 142, 150, 170, 178, 204, 212, 232, 240, 286, 310, 346, 370, 412, 436, 472, 496, 542, 558, 598, 614, 666, 682, 722, 738, 796, 812, 852, 868, 920, 936, 976, 992, 1086, 1134, 1206, 1254, 1338, 1386, 1458, 1506, 1596, 1644, 1716, 1764, 1848, 1896, 1968, 2016, 2110, 2142, 2222, 2254, 2358, 2390, 2470, 2502, 2618, 2650, 2730, 2762, 2866, 2898, 2978, 3010, 3132, 3164, 3244, 3276, 3380, 3412, 3492, 3524, 3640, 3672, 3752, 3784, 3888, 3920, 4000, 4032, 4222, 4318, 4462, 4558]

*/

package main

import (
	"math"
	"math/bits"
	"slices"
)

func main() {
	tab := []uint{1, 2, 6, 10, 12, 22, 28, 38, 42, 52, 56, 78, 90, 108, 120, 142, 150, 170, 178, 204, 212, 232, 240, 286, 310, 346, 370, 412, 436, 472, 496, 542, 558, 598, 614, 666, 682, 722, 738, 796, 812, 852, 868, 920, 936, 976, 992, 1086, 1134, 1206, 1254, 1338, 1386, 1458, 1506, 1596, 1644, 1716, 1764, 1848, 1896, 1968, 2016, 2110, 2142, 2222, 2254, 2358, 2390, 2470, 2502, 2618, 2650, 2730, 2762, 2866, 2898, 2978, 3010, 3132, 3164, 3244, 3276, 3380, 3412, 3492, 3524, 3640, 3672, 3752, 3784, 3888, 3920, 4000, 4032, 4222, 4318, 4462, 4558}

	assert(fold(178) == true)
	assert(fold(1644) == true)
	assert(fold(4254) == false)
	assert(slices.Equal(gen(len(tab)), tab))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen(n int) []uint {
	r := []uint{}
	for i := uint(0); len(r) < n && i < math.MaxUint; i++ {
		if fold(i) {
			r = append(r, i)
		}
	}
	return r
}

// https://oeis.org/A277238
func fold(n uint) bool {
	if n == 0 {
		return false
	}

	b := bits.UintSize - uint(bits.LeadingZeros(n))
	s := b >> 1
	m := uint(1)<<s - 1
	if b&1 != 0 && n&(1<<s) == 0 {
		return false
	}

	x0 := n >> (s + b&1)
	x1 := bits.Reverse(n) >> (bits.UintSize - s)
	return ^(x0^x1)&m == 0
}
