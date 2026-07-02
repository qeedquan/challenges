/*

A Bayer matrix is a threshold map used for ordered dithering that gives the illusion of having more shades of color than actually present by using a crosshatch-like pattern.

Bayer matrices are square with a side length that is a power of 2. Here are some examples:

1/4 *
0 2
3 1

1/16 *
   0   8   2  10
  12   4  14   6
   3  11   1   9
  15   7  13   5

1/64 *
   0  32   8  40   2  34  10  42
  48  16  56  24  50  18  58  26
  12  44   4  36  14  46   6  38
  60  28  52  20  62  30  54  22
   3  35  11  43   1  33   9  41
  51  19  59  27  49  17  57  25
  15  47   7  39  13  45   5  37
  63  31  55  23  61  29  53  21


The numbers in the matrix are arranged in such a way so that each number is placed as distant from the previous ones as possible, taking account that the edges wrap.

For example, in the second matrix shown above, the 0 is placed in the top left first, then the 1 is placed two to the right and two below the 0, which is the maximum distance away from the 0. Note that the 1 is not placed in the bottom right, because since the edges wrap, the bottom right would be one to the left and one above the 0. Next, the 2 is placed with a distance of 2 from both 0 and 1, and the 3 is placed similarly.

Note that measuring the distances to generate the matrix is not the simplest method.

Challenge
Your task is to create a program or function, that when given an input side length s, outputs a Bayer matrix that has a side length of s.

Rules
For a side length of s, you may take the input as s or log2(s). You may assume that 2≤s≤16 and that log2(s) is an integer. This means you are allowed to hardcode outputs, but in most cases this is not the shortest method.
The numbers in the output matrix may range from (inclusive) 0 to s^2-1, 1 to s^2, 0 to (s^2-1)/s^2, or 1/s^2 to 1.
For example, for s=2, all of these are acceptable: [[0 2] [3 1]], [[1 3] [4 2]], [[0 0.75] [.50 .25]] , [[0.25 0.75] [1 0.5]]
The output matrix may be offsetted or transposed, reflected, rotated, etc. as long as the general pattern is the same.
This means that when there is a tie for maximum distance, any of the tied options may be chosen. For example, for s=2, any matrix with 0 and 1 in opposite corners and 2 and 3 in opposite corners is acceptable.
Input and output may be in any convenient format.
This is code-golf, so the shortest answer in bytes wins.

*/

package main

import (
	"fmt"
)

func main() {
	for i := 0; i < 5; i++ {
		dump(bayer(i))
	}
}

func dump(m [][]int) {
	n := len(m)
	fmt.Printf("%dx%d 1/%d\n", n, n, n*n)
	for i := range m {
		for j := range m[i] {
			fmt.Printf("% 4d", m[i][j])
		}
		fmt.Println()
	}
	fmt.Println()
}

// https://en.wikipedia.org/wiki/Ordered_dithering
// https://bisqwit.iki.fi/story/howto/dither/jy/
func bayer(n int) [][]int {
	m := alloc(1 << n)
	for i := range m {
		for j := range m[i] {
			x, y, s, v := i^j, j, n-1, 0
			for b := 0; b < 2*n; b, s = b+2, s-1 {
				v |= ((y >> s) & 1) << b
				v |= ((x >> s) & 1) << (b + 1)
			}
			m[j][i] = v
		}
	}
	return m
}

func alloc(n int) [][]int {
	m := make([][]int, n)
	t := make([]int, n*n)
	for i := range m {
		m[i] = t[i*n : (i+1)*n]
	}
	return m
}
