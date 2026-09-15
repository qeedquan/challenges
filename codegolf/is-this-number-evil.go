/*

Introduction
In number theory, a number is considered evil if there are an even number of 1's in its binary representation. In today's challenge, you will be identifying whether or not a given number is evil.

Challenge
Your job is to write a full program or function which accepts a single, non-negative integer as input and outputs (or returns) whether or not that number is evil.

You may output any truthy value if the number is evil, and any falsy value if the number is not evil.
You may input and output in any acceptable format.
Standard loopholes are disallowed.
OEIS sequence A001969 is the sequence containing all evil numbers.
Here is a list of the first 10000 evil numbers, for reference (and more test cases!)
This question is code-golf, so the shorter, the better.
Don't be put off by extremely short answers in golfing languages. I encourage you to submit in any language you like.
Here are some test cases:

3 => True
11 => False
777 => True
43 => True
55 => False
666 => False

*/

package main

import "math/bits"

func main() {
	tab := []uint{0, 3, 5, 6, 9, 10, 12, 15, 17, 18, 20, 23, 24, 27, 29, 30, 33, 34, 36, 39, 40, 43, 45, 46, 48, 51, 53, 54, 57, 58, 60, 63, 65, 66, 68, 71, 72, 75, 77, 78, 80, 83, 85, 86, 89, 90, 92, 95, 96, 99, 101, 102, 105, 106, 108, 111, 113, 114, 116, 119, 120, 123, 125, 126, 129}

	assert(evil(3) == true)
	assert(evil(11) == false)
	assert(evil(777) == true)
	assert(evil(43) == true)
	assert(evil(55) == false)
	assert(evil(666) == false)
	for _, v := range tab {
		assert(evil(v) == true)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A001969
func evil(n uint) bool {
	return bits.OnesCount(n)&1 == 0
}
