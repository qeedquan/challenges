/*

Your Task:
Write a program or function to check if a number that is inputted is a Fibonacci number. A Fibonacci number is a number contained in the Fibonacci sequence.

The Fibonacci Sequence is defined as: F(n) = F(n - 1) + F(n - 2)

With the seeds being F(0) = 0 and F(1) = 1.

Input:
A non-negative integer between 0 and 1,000,000,000 that may or may not be a Fibonacci number.

Output:
A truthy/falsy value indicating whether or not the input is a Fibonacci number.

Examples:
0-->truthy
1-->truthy
2-->truthy
12-->falsy

Scoring:
This is code-golf, lowest byte count wins.

*/

package main

import (
	"sort"
)

func main() {
	assert(isfib(0) == true)
	assert(isfib(1) == true)
	assert(isfib(2) == true)
	assert(isfib(12) == false)
	assert(isfib(13) == true)
	assert(isfib(21) == true)
	assert(isfib(55) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func isfib(n int) bool {
	x := sort.Search(n+1, func(i int) bool {
		return fib(i) >= n
	})
	return fib(x) == n
}

var cache = map[int]int{
	0: 0,
	1: 1,
}

func fib(n int) int {
	if v, ok := cache[n]; ok {
		return v
	}
	cache[n] = fib(n-1) + fib(n-2)
	return cache[n]
}
