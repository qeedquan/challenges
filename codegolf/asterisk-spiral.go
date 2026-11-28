/*

Given the spiral of size S and the step N, output the "square" S*S spiral having N asterisks, built from the outer to inner radius clockwise.

Test cases (examples) below.

Input: 4 3

Output:

***
Input: 4 6

Output:

****
   *
   *
Input: 4 11

Output:

****
   *
*  *
****
Input: 6 18

Output:

******
     *
     *
*    *
*    *
******
Input: 6 22

Output:

******
***  *
*    *
*    *
*    *
******
Input: 6 27

Output:

******
******
*   **
*   **
*   **
******
Input: 1 1

Output:

*
It's not necessary to handle the cases when:

provided N asterisks can't "fit" in the spiral of given S*S dimensions.

either N or S is zero.

The challenge is code-golf, shortest bytes answer wins, any languages can be used.

Your output may have as many trailing (but not leading) spaces/newlines as you wish.

*/

package main

import "fmt"

func main() {
	spiral(4, 3)
	spiral(4, 6)
	spiral(4, 11)
	spiral(6, 18)
	spiral(6, 22)
	spiral(6, 27)
	spiral(1, 1)
}

func spiral(s, n int) {
	p := alloc(s)
	for y := range p {
		for x := range p[y] {
			p[y][x] = ' '
		}
	}

	x0, y0 := 0, 0
	x1, y1 := s-1, s-1
	for n > 0 {
		if x0 == x1 && y0 == y1 {
			p[y0][x0] = '*'
		}

		if x0 >= x1 || y0 >= y1 {
			break
		}

		for x, y := x0, y0; x <= x1 && n > 0; x, n = x+1, n-1 {
			p[y][x] = '*'
		}

		for x, y := x1, y0+1; y <= y1 && n > 0; y, n = y+1, n-1 {
			p[y][x] = '*'
		}

		for x, y := x1-1, y1; x >= x0 && n > 0; x, n = x-1, n-1 {
			p[y][x] = '*'
		}

		for x, y := x0, y1-1; y > y0 && n > 0; y, n = y-1, n-1 {
			p[y][x] = '*'
		}

		x0, y0 = x0+1, y0+1
		x1, y1 = x1-1, y1-1
	}
	output(p)
}

func alloc(n int) [][]byte {
	p := make([][]byte, n)
	t := make([]byte, n*n)
	for i := range p {
		p[i] = t[i*n : (i+1)*n]
	}
	return p
}

func output(p [][]byte) {
	for y := range p {
		for x := range p[y] {
			fmt.Printf("%c", p[y][x])
		}
		fmt.Println()
	}
	fmt.Println()
}
