/*

Challenge
Generate the 2D sequence of bits of A141727. (Allowed I/O methods explained at the bottom.)

                  1
                1 0 1
              1 0 0 1 0
            1 0 1 0 1 0 0
          1 0 0 1 1 0 1 1 1
        1 0 1 0 0 0 0 0 1 1 0
      1 0 0 1 0 0 0 0 1 1 1 0 0
    1 0 1 0 1 0 0 0 1 1 0 0 1 1 1
  1 0 0 1 1 0 1 1 0 0 0 1 0 0 1 1 0
1 0 1 0 0 0 0 0 0 1 1 0 1 0 1 1 1 0 0

This triangle is generated as follows: starting with a row of single 1, generate the bits row-by-row, from left to right. Each bit is the parity of the sum (in other words, XOR-sum) of the neighboring bits already placed (8-way neighborhood).

[1]  initial condition

   1
[1]? ?   only one neighbor being 1, sum is 1

   1
 1[0]?   two 1-neighbors, sum is 0

   1
 1 0[1]  two neighbors (0 and 1), sum is 1

     1
   1 0 1
[1]? ? ? ?  one neighbor, sum 1

     1
   1 0 1
 1[0]? ? ?  three neighbors, sum 0

     1
   1 0 1
 1 0[0]? ?  four neighbors, sum 0

     1
   1 0 1
 1 0 0[1]?  three neighbors, sum 1

     1
   1 0 1
 1 0 0 1[0] two neighbors, sum 0

...
sequence default I/O methods apply. In this challenge, you can interpret the sequence as a sequence of individual bits or a sequence of rows of bits, so the following are accepted:

Given n (0- or 1-indexed), output n-th bit or n-th row
Given n (positive), output first n bits or first n rows
Given no input, output the infinite sequence of bits or the sequence of rows (refer to sequence rules for exactly which methods count as infinite output)
Standard code-golf rules apply. The shortest code in bytes wins.

*/

package main

import (
	"fmt"
	"math"
	"slices"
	"strings"
)

func main() {
	tab := []int{1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0}

	assert(slices.Equal(gen(len(tab)), tab))

	n := 8
	for i := range n {
		fmt.Printf("%s%v\n", strings.Repeat(" ", (2*n-2*i)), triangle(i))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen(n int) []int {
	r := []int{}
	for i := 0; i < math.MaxInt && len(r) < n; i++ {
		r = append(r, triangle(i)...)
	}
	return r[:n]
}

// https://oeis.org/A141727
func triangle(n int) []int {
	if n < 0 {
		return []int{}
	}

	r := []int{1}
	if n < 1 {
		return r
	}

	p := append(triangle(n-1), []int{0, 0}...)
	for i := range n * 2 {
		j := i - 1
		if j < 0 {
			j = len(p) - 1
		}

		r = append(r, p[j]^p[i]^p[i+1]^r[len(r)-1])
	}
	return r
}
