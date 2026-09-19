/*

Description
You are given a binary array pattern and an object stream of class InfiniteStream representing a 0-indexed infinite stream of bits.

The class InfiniteStream contains the following function:

int next(): Reads a single bit (which is either 0 or 1) from the stream and returns it.
Return the first starting index where the pattern matches the bits read from the stream.
For example, if the pattern is [1, 0], the first match is the highlighted part in the stream [0, 1, 0, 1, ...].

Example 1:

Input: stream = [1,1,1,0,1,1,1,...], pattern = [0,1]
Output: 3
Explanation: The first occurrence of the pattern [0,1] is highlighted in the stream [1,1,1,0,1,...], which starts at index 3.

Example 2:

Input: stream = [0,0,0,0,...], pattern = [0]
Output: 0
Explanation: The first occurrence of the pattern [0] is highlighted in the stream [0,...], which starts at index 0.

Example 3:

Input: stream = [1,0,1,1,0,1,1,0,1,...], pattern = [1,1,0,1]
Output: 2
Explanation: The first occurrence of the pattern [1,1,0,1] is highlighted in the stream [1,0,1,1,0,1,...], which starts at index 2.

Constraints:

1 <= pattern.length <= 100
pattern consists only of 0 and 1.
stream consists only of 0 and 1.
The input is generated such that the pattern's start index exists in the first 10^5 bits of the stream.

*/

package main

import (
	"fmt"
	"math"
)

type Stream interface {
	Next() int
}

type Circular struct {
	index  int
	values []int
}

func main() {
	test([]int{1, 1, 1, 0, 1, 1, 1}, []int{0, 1}, 3)
	test([]int{0, 0, 0, 0}, []int{0}, 0)
	test([]int{1, 0, 1, 1, 0, 1, 1, 0, 1}, []int{1, 1, 0, 1}, 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(values, pattern []int, expected int) {
	stream := &Circular{values: values}
	result := find(stream, pattern)
	fmt.Println(result)
	assert(result == expected)
}

func find(stream Stream, pattern []int) int {
	a := 0
	b := 0
	m := len(pattern)
	half := m >> 1
	mask1 := (1 << half) - 1
	mask2 := (1 << (m - half)) - 1
	for i := 0; i < half; i++ {
		a |= pattern[i] << (half - 1 - i)
	}
	for i := half; i < m; i++ {
		b |= pattern[i] << (m - 1 - i)
	}

	x, y := 0, 0
	for i := 1; i < math.MaxInt; i++ {
		v := stream.Next()
		y = y<<1 | v
		v = (y >> (m - half)) & 1
		y &= mask2
		x = x<<1 | v
		x &= mask1
		if i >= m && a == x && b == y {
			return i - m
		}
	}
	return -1
}

func (c *Circular) Next() int {
	if len(c.values) == 0 {
		return 0
	}

	if c.index >= len(c.values) {
		c.index = 0
	}

	value := c.values[c.index]
	c.index += 1
	return value
}
