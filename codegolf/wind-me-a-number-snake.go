/*

Given an input integer n, draw a number snake, that is, a grid measuring n x n consisting of the numbers 1 through n^2 that are wound around each other in the following fashion:

Input n = 3:

7 8 9
6 1 2
5 4 3
Input n = 4:

 7  8  9 10
 6  1  2 11
 5  4  3 12
16 15 14 13
Input n = 5:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13
(Inspired by this problem from Project Euler.)

This is code-golf, the shortest answer in bytes wins!

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	for i := 0; i <= 16; i++ {
		spiral(i)
	}
}

/*

@Julio E. Rodríguez Cabañas

The function calculates and prints the value of each number of the matrix depending on its x, y position by applying this logic:

https://i.stack.imgur.com/WDPWe.jpg

*/

func spiral(n int) {
	fmt.Printf("n=%d\n", n)
	if n < 1 {
		fmt.Println()
		return
	}

	w := ilog10(n*n) + 1
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			x, y := j, i
			if n&1 == 0 {
				x, y = n-j-1, n-i-1
			}
			fmt.Printf("%*d ", w, value(x, y, n))
		}
		fmt.Println()
	}
	fmt.Println()
}

func value(x, y, n int) int {
	var v int
	if y < n-x {
		p := min(x, y)
		v = n - 1 - p*2
		v *= v
		if y >= x {
			v += n - x - y
		} else {
			v += n + x - y - y*2
		}
	} else {
		p := n - max(x, y)
		v = n - p*2
		v *= v
		if x > y {
			v += y - p + 1
		} else {
			v += n + y - x - p*2 + 1
		}
	}
	return v
}

func ilog10(x int) int {
	return int(math.Log10(float64(x)))
}
