/*

Given an input of a positive integer, output the number of steps it takes to find the input via a binary search starting at 1.

We are simulating a binary search for the integer that was given as input, in which the simulated searcher can repeatedly guess an integer and be told whether it is too high, too low, or correct. The strategy for finding the integer is as follows:

Let n be the integer given as input that we are trying to find.

Start with a guess of 1. (For every guess, increment the number of steps (regardless of whether it was correct or not), and immediately stop and output the total number of steps if the guess was correct.)

Double the guess repeatedly until the guess is greater than n (the target number). (Or if it is correct, but that's already covered by our correct-guess rule mentioned above.)

Now, set an upper bound of the first power of 2 that's greater than n (i.e. the number that was just guessed), and set a lower bound of the power of 2 directly below it.

Repeatedly guess the average (rounded down) of the upper bound and the lower bound. If it is too high, set it as the upper bound. If it is too low, set it as the lower bound. This procedure is guaranteed to eventually result in a correct guess.

Here's an example, for the input of n=21:

1 -> 2 -> 4 -> 8 -> 16 -> 32 -> 24 -> 20 -> 22 -> 21
\__________________________/
   repeated doubling      \________________________/
                             repeated averaging
Since this is code-golf, the shortest code in bytes will win.

Here are all outputs from n=1 to n=100:

1
2
4
3
6
5
6
4
8
7
8
6
8
7
8
5
10
9
10
8
10
9
10
7
10
9
10
8
10
9
10
6
12
11
12
10
12
11
12
9
12
11
12
10
12
11
12
8
12
11
12
10
12
11
12
9
12
11
12
10
12
11
12
7
14
13
14
12
14
13
14
11
14
13
14
12
14
13
14
10
14
13
14
12
14
13
14
11
14
13
14
12
14
13
14
9
14
13
14
12

And here are some larger test cases:

1234 -> 21
1337 -> 22
3808 -> 19
12345 -> 28
32768 -> 16
32769 -> 32
50000 -> 28

*/

package main

import (
	"math/bits"
)

func main() {
	tab := []int{
		1, 2, 4, 3, 6, 5, 6, 4, 8, 7, 8, 6, 8, 7, 8, 5,
		10, 9, 10, 8, 10, 9, 10, 7, 10, 9, 10, 8, 10, 9, 10,
		6, 12, 11, 12, 10, 12, 11, 12, 9, 12, 11, 12, 10, 12,
		11, 12, 8, 12, 11, 12, 10, 12, 11, 12, 9, 12, 11, 12,
		10, 12, 11, 12, 7, 14, 13, 14, 12, 14, 13, 14, 11, 14,
		13, 14, 12, 14, 13, 14, 10, 14, 13, 14, 12, 14, 13, 14,
		11, 14, 13, 14, 12, 14, 13, 14, 9, 14, 13, 14, 12,
	}

	for i, v := range tab {
		assert(binsearchs(uint(i+1)) == v)
	}

	assert(binsearchs(1234) == 21)
	assert(binsearchs(1337) == 22)
	assert(binsearchs(3808) == 19)
	assert(binsearchs(12345) == 28)
	assert(binsearchs(32768) == 16)
	assert(binsearchs(32769) == 32)
	assert(binsearchs(50000) == 28)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@Neil

As alluded to by other answers, you can calculate the number of steps from the positions of the first and last bits.

The number of steps in the doubling phase is n=33-Math.clz32(x-1). We want 2ⁿ ≥ x but n=33-Math.clz32(x) gives us 2ⁿ > x so we subtract 1 from x to compensate.

The number of steps in the averaging phase is easier, it's simply n=Math.clz32(x&-x)-Math.clz32(x). x&-x is a handy expression that evaluates to the lowest bit of x (as a power of 2).

*/

func binsearchs(n uint) int {
	return bits.UintSize + 1 - bits.LeadingZeros(n-1) + bits.LeadingZeros(n & ^(n-1)) - bits.LeadingZeros(n)
}
