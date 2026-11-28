/*

Introduction (may be ignored)
Putting all positive numbers in its regular order (1, 2, 3, ...) is a bit boring, isn't it? So here is a series of challenges around permutations (reshuffelings) of all positive numbers. This is the second challenge in this series. The first challenge can be found here.

In this challenge, we use Gray codes to rearrage the natural numbers. A Gray code, or "reflected binary code" is a binary encoding in such a way that two successive values differ in only one bit. A practical application of this encoding is to use it in rotary encoders, hence my reference to "Turn My Way".

https://i.sstatic.net/yU6yA.png

Note that this encoding leaves some degree of freedom.
For example, following binary 1100, there are four possible following codes: 1101, 1110, 1000 and 0100.
This is why I will define a(n) as the smallest, not previously used value that differs only one character in binary encoding.
This sequence corresponds with A163252.

Since this is a "pure sequence" challenge, the task is to output a(n) for a given n as input, where a(n) is A163252.

Task
Given an integer input n, output a(n) in integer format (not in binary format).

a(n) is defined as the least positive integer not occurring earlier in the sequence such that a(n−1) and a(n) differ in only one bit when written in binary.

Note: 1-based indexing is assumed here; you may use 0-based indexing, so a(0)=1;a(1)=3, etc. Please mention this in your answer if you choose to use this.

Test cases
Input | Output
--------------
1     | 1
5     | 4
20    | 18
50    | 48
123   | 121
1234  | 1333
3000  | 3030
9999  | 9997

Rules
Input and output are integers (your program should at least support input and output in the range of 1 up to 32767)
Invalid input (0, floats, strings, negative values, etc.) may lead to unpredicted output, errors or (un)defined behaviour.
In A163252, a(0) is defined as 0. For this challenge, we will ignore this.
Default I/O rules apply.
Default loopholes are forbidden.
This is code-golf, so the shortest answers in bytes wins

Final note
See the following related (but not equal) PP&CG questions:

Finding the next Gray code (input and output in binary)
Generate the all Gray codes of length n

*/

package main

import (
	"math/bits"
)

func main() {
	tab := []uint{
		0, 1, 3, 2, 6, 4, 5, 7, 15, 11, 9, 8, 10, 14, 12, 13, 29, 21, 17, 16,
		18, 19, 23, 22, 20, 28, 24, 25, 27, 26, 30, 31, 63, 47, 39, 35, 33, 32,
		34, 38, 36, 37, 45, 41, 40, 42, 43, 59, 51, 49, 48, 50, 54, 52, 53, 55,
		119, 87, 71, 67, 65, 64, 66, 70, 68, 69, 77, 73, 72, 74, 75, 79, 78,
	}

	assert(grays(1) == 1)
	assert(grays(5) == 4)
	assert(grays(20) == 18)
	assert(grays(50) == 48)
	assert(grays(123) == 121)
	assert(grays(1234) == 1333)
	assert(grays(3000) == 3030)
	assert(grays(9999) == 9997)

	for i := range tab {
		assert(grays(uint(i)) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A163252
func grays(n uint) uint {
	seen := make([]uint, 9*n)
	prev := uint(0)
	for range n {
		curr := uint(1)
		for seen[curr] > 0 || bits.OnesCount(curr^prev) > 1 {
			curr += 1
		}
		seen[curr] += 1
		prev = curr
	}
	return prev
}
