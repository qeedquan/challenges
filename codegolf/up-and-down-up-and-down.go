/*

Challenge:
Given a positive integer input n, create a vector that follows this pattern:

0  1  0 -1 -2 -1  0  1  2  3  2  1  0 -1 -2 -3 -4 -3 -2 -1 ... ±(n-1) ±n
Or, explained with words: The vector starts at 0, and makes increments of 1 until it reaches the smallest odd positive integer that isn't part of the sequence, then it makes decrements until it reaches the smallest (in magnitude) even negative integer that isn't part of the sequence. It continues this way until n is reached. The sequence will end on positive n if n is odd, and negative n if n is even.

The output format is flexible.

Test cases:
n = 1
0  1
-----------
n = 2
0  1  0 -1 -2
-----------
n = 3
0  1  0 -1 -2 -1  0  1  2  3
-----------
n = 4
0  1  0 -1 -2 -1  0  1  2  3  2  1  0 -1 -2 -3 -4
-----------
n = 5
0  1  0 -1 -2 -1  0  1  2  3  2  1  0 -1 -2 -3 -4 -3 -2 -1  0  1  2  3  4  5
You may choose to take the n zero-indexed. n = 1 would then give 0  1  0 -1 -2.

This is code-golf, so the shortest code in each language wins! Explanations are encouraged as always!

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(1, []int{0, 1})
	test(2, []int{0, 1, 0, -1, -2})
	test(3, []int{0, 1, 0, -1, -2, -1, 0, 1, 2, 3})
	test(4, []int{0, 1, 0, -1, -2, -1, 0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -4})
	test(5, []int{0, 1, 0, -1, -2, -1, 0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r []int) {
	p := solve(n)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func solve(n int) []int {
	r := []int{}
	for i := 1; i <= n; i++ {
		for j := -i; j < i; j++ {
			k := i - abs(j)
			r = append(r, parity(i+1)*k)
			if k == n {
				break
			}
		}
	}
	return r
}

func parity(x int) int {
	if x&1 != 0 {
		return -1
	}
	return 1
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
