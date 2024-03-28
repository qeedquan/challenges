/*

Given a positive integer n, your task is to find out the number of partitions a[1]+a[2]+⋯+a[k]=n where each a[j] has exactly j bits set.

For instance, there are 6 such partitions for n=14:

14 = 0b1 + 0b110 + 0b111 (1 + 6 + 7)
14 = 0b10 + 0b101 + 0b111 (2 + 5 + 7)
14 = 0b10 + 0b1100 (2 + 12)
14 = 0b100 + 0b11 + 0b111 (4 + 3 + 7)
14 = 0b100 + 0b1010 (4 + 10)
14 = 0b1000 + 0b110 (8 + 6)

This is code-golf, so the shortest answer wins.

Test cases
n  f(n)
-------
1  1
2  1
3  0
4  2
5  1
10 2
14 6
19 7
20 10
25 14
33 32
41 47
44 55
50 84
54 102
59 132

*/

package main

import (
	"math/bits"
)

func main() {
	assert(partitions(1) == 1)
	assert(partitions(2) == 1)
	assert(partitions(3) == 0)
	assert(partitions(4) == 2)
	assert(partitions(5) == 1)
	assert(partitions(10) == 2)
	assert(partitions(14) == 6)
	assert(partitions(19) == 7)
	assert(partitions(20) == 10)
	assert(partitions(25) == 14)
	assert(partitions(33) == 32)
	assert(partitions(41) == 47)
	assert(partitions(44) == 55)
	assert(partitions(50) == 84)
	assert(partitions(54) == 102)
	assert(partitions(59) == 132)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func partitions(n uint) uint {
	return recurse(n, 1)
}

func recurse(n uint, m int) uint {
	if n < 1 {
		return 1
	}

	r := uint(0)
	for i := uint(0); i <= n; i++ {
		if bits.OnesCount(i) == m {
			r += recurse(n-i, m+1)
		}
	}
	return r
}
