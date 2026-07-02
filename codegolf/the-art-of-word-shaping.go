/*

The Art of Word Shaping
Given a binary matrix and a string of letters, replace all 1's in the matrix, moving from top to bottom and from left to right within each row, with the letters of the string. Once the letters have been formed into the shape of the matrix, print the matrix, replacing 0's with spaces. It's probably easier to just give an example or two.

Case: Base case...

Input One:

[0,0,1,0,0]
[0,1,0,1,0]
[1,0,0,0,1]
[0,1,0,1,0]
[0,0,1,0,0]

"PPCGPPCG"
Output One:

  P
 P C
G   P
 P C
  G
Case: If the input string is longer than the number of ones...

Input Two:

[1,0,0]
[0,1,0]
[1,0,1]

lambda
Output Two:

l
 a
m b
Case: If the input string is shorter than the number of ones...

Input Three:

[1,1,1]
[1,0,1]
[1,1,1]

PPCG
Output Three:

PPC
G P
PCG

Available Assumptions
You may assume the input string is never empty.
You may assume the matrix will never be empty.
You may not assume that the binary matrix will never be all zeros.

Rules
If the string is shorter than the number of ones, repeat the string; all ones must be replaced.
If the string is longer than the number of ones, only use what is needed.
You may use True/False in place of integers/bits for the input.
Trailing spaces ARE REQUIRED, all zeros must be replaced with spaces.
A single trailing newline is acceptable.
This is code-golf, lowest byte count wins.

*/

package main

import "fmt"

func main() {
	wordshape([][]int{
		{0, 0, 1, 0, 0},
		{0, 1, 0, 1, 0},
		{1, 0, 0, 0, 1},
		{0, 1, 0, 1, 0},
		{0, 0, 1, 0, 0},
	}, "PPCGPPCG")

	wordshape([][]int{
		{1, 0, 0},
		{0, 1, 0},
		{1, 0, 1},
	}, "lambda")

	wordshape([][]int{
		{1, 1, 1},
		{1, 0, 1},
		{1, 1, 1},
	}, "PPCG")
}

func wordshape(m [][]int, s string) {
	r := []rune(s)
	if len(r) == 0 {
		return
	}

	n := 0
	for i := range m {
		for j := range m[i] {
			if m[i][j] == 0 {
				fmt.Printf(" ")
			} else {
				fmt.Printf("%c", r[n])
				n = (n + 1) % len(r)
			}
		}
		fmt.Println()
	}
	fmt.Println()
}
