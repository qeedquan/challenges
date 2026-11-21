/*

Hit the target
given a matrix n x n (2-7), determine if the arrow is directed to the target (x).
There will be only 1 arrow '>' and 1 target 'x'
An empty spot will be denoted by a space " ", the target with a cross "x", and the scope ">"

Examples:

given matrix 4x4:
[

  [' ', ' ', ' ', ' '],

  [' ', ' ', ' ', ' '], --> return true

  [' ', '>', ' ', 'x'],

  [' ', ' ', ' ', ' ']

]

given matrix 4x4:
[

  [' ', ' ', ' ', ' '],

  [' ', '>', ' ', ' '], --> return false

  [' ', ' ', ' ', 'x'],

  [' ', ' ', ' ', ' ']

]

given matrix 4x4:
[

  [' ', ' ', ' ', ' '],

  [' ', 'x', '>', ' '], --> return false

  [' ', '', ' ', ' '],

  [' ', ' ', ' ', ' ']

]

In this example, only a 4x4 matrix was used, the problem will have matrices of dimensions from 2 to 7
Happy hacking as they say!

*/

package main

import (
	"bytes"
)

func main() {
	assert(solution([][]byte{
		{' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' '},
		{' ', '>', ' ', 'x'},
		{' ', ' ', ' ', ' '},
	}) == true)

	assert(solution([][]byte{
		{' ', ' ', ' ', ' '},
		{' ', '>', ' ', ' '},
		{' ', ' ', ' ', 'x'},
		{' ', ' ', ' ', ' '},
	}) == false)

	assert(solution([][]byte{
		{' ', ' ', ' ', ' '},
		{' ', 'x', '>', ' '},
		{' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' '},
	}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solution(m [][]byte) bool {
	for i := range m {
		x := bytes.IndexByte(m[i], '>')
		y := bytes.IndexByte(m[i], 'x')
		if x < 0 && y < 0 {
			continue
		}
		if x < 0 || y < 0 || y < x {
			return false
		}
		if x < y {
			return true
		}
	}
	return false
}
