/*

Task
In the field, two beggars A and B found some gold at the same time. They all wanted the gold, and they decided to use simple rules to distribute gold:

They divided gold into n piles and be in line.
The amount of each pile and the order of piles all are randomly.

They took turns to take away a pile of gold from the
far left or the far right.

They always choose the bigger pile. That is to say,
if the left is 1, the right is 2, then choose to take 2.

If the both sides are equal, take the left pile.

Given an integer array golds, and assume that A always takes first. Please calculate the final amount of gold obtained by A and B. returns a two-element array [amount of A, amount of B].

Example
For golds = [4,2,9,5,2,7], the output should be [14,15].

The pile of most left is 4,
The pile of most right is 7,
A choose the largest one -- > take 7

The pile of most left is 4,
The pile of most right is 2,
B choose the largest one -- > take 4

The pile of most left is 2,
The pile of most left is 2,
A choose the most left one -- > take 2

The pile of most left is 9,
The pile of most right is 2,
B choose the largest one -- > take 9

The pile of most left is 5,
The pile of most left is 2,
A choose the largest one -- > take 5

Tehn, only 1 pile left,
B  -- > take 2

A: 7 + 2 + 5 = 14
B: 4 + 9 + 2 = 15

For golds = [10,1000,2,1], the output should be [12,1001].

A take 10
B take 1000
A take 2
B take 1

A: 10 + 2 = 12
B: 1000 + 1 = 1001

*/

package main

import "fmt"

func main() {
	test([]int{4, 2, 9, 5, 2, 7}, [2]int{14, 15})
	test([]int{10, 1000, 2, 1}, [2]int{12, 1001})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, r [2]int) {
	p := distribution(a)
	fmt.Println(p)
	assert(p == r)
}

func distribution(a []int) [2]int {
	c := [2]int{}
	for n, i, j := 0, 0, len(a)-1; i <= j; n ^= 1 {
		switch {
		case a[j] > a[i]:
			c[n], j = c[n]+a[j], j-1
		default:
			c[n], i = c[n]+a[i], i+1
		}
	}
	return c
}
