/*

Your task is to, given an unsigned integer n, find the largest number which can be created by removing a single byte (8 consecutive bits) of data.

Example
Given the number 7831, we first convert it to binary (removing any leading zeroes):

1111010010111
We then find the consecutive group of 8 bits which, when removed, will yield the largest new result. In this case, there are 3 solutions, shown below

1111010010111
  ^      ^
   ^      ^
    ^      ^
Removing this any of these yields 11111, which we then convert back to its decimal value 31 for the answer.

Test Cases
256        ->   1
999        ->   3
7831       ->   31
131585     ->   515
7854621    ->   31261
4294967295 ->   16777215 (if your language can handle 32 bit integers)

Rules
It is guaranteed that the bit length of n will be larger than 8.
Your solution should theoretically work for any bit length of n larger than 8, but in practice, needs only work for integers 255 < n < 216
Input/Output should be in decimal.
You may submit a full program or a function.
This is code-golf, so the shortest program (in bytes) wins!

*/

package main

func main() {
	assert(takebyte(256) == 1)
	assert(takebyte(999) == 3)
	assert(takebyte(7831) == 31)
	assert(takebyte(131585) == 515)
	assert(takebyte(7854621) == 31261)
	assert(takebyte(4294967295) == 16777215)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// ported from @xnor solution
func takebyte(n uint64) uint64 {
	if n>>8 == 0 {
		return 0
	}
	return max(n>>8, (takebyte(n>>1)<<1)+(n&1))
}
