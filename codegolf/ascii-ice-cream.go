/*

Write a program or function that takes in a positive integer N, and prints or returns an N×N ASCII art string whose top half is a semicircle made of ('s and whose bottom half is a downward-pointing triangle made of V's, with spaces used as padding.

In other words, make an ASCII ice cream cone: (output for N = 17)

      (((((
    (((((((((
  (((((((((((((
  (((((((((((((
 (((((((((((((((
 (((((((((((((((
(((((((((((((((((
(((((((((((((((((
VVVVVVVVVVVVVVVVV
 VVVVVVVVVVVVVVV
  VVVVVVVVVVVVV
   VVVVVVVVVVV
    VVVVVVVVV
     VVVVVVV
      VVVVV
       VVV
        V
Examples
Here are the outputs for N = 1 to 5. Note that for odd N, the triangle always must be the larger half.

V

((
VV

(((
VVV
 V

 ((
((((
VVVV
 VV

 (((
(((((
VVVVV
 VVV
  V
Here's an N = 101 pastebin.

And here's an ungolfed Python 3 reference implementation:

N = int(input())
ic = [[' '] * N for _ in range(N)]
for y in range(N//2):
    for x in range(N):
        if (x - (N - 1) / 2)**2 + (y - (N - 1) / 2)**2 < (N / 2)**2:
            ic[y][x] = '('
for y in range(N//2, N):
    for x in range(y - N//2, N - (y - N//2)):
        ic[y][x] = 'V'
for line in ic:
    print(''.join(line))

Details
Take input from stdin, command line, or as function argument. Output to stdout or similar, or you may return the string if you write a function.
The cone portion should exactly match the reference implementation for all N.
The ice cream portion does not need to exactly match the reference implementation as long as it is clearly in the shape of a semicircle for all N. (This is so you don't have to worry about slight differences in the semicircle due to roundoff errors.)
There should not be any unnecessary leading spaces but there may be superfluous trailing spaces.
The output may optionally contain a trailing newline.
You may optionally use any 3 other distinct printable ASCII characters in place of (, V, and space.

Scoring
The shortest submission in bytes wins. Tiebreaker goes to the oldest submission.

*/

package main

import "fmt"

func main() {
	for i := range 21 {
		icecream(i)
	}
}

func icecream(n int) {
	m := alloc(n)
	for y := range m {
		for x := range m[y] {
			m[y][x] = ' '
		}
	}

	for y := range n / 2 {
		for x := range n {
			dx := float64(x) - float64(n-1)/2
			dy := float64(y) - float64(n-1)/2
			dr := float64(n) / 2
			if dx*dx+dy*dy < dr*dr {
				m[y][x] = '('
			}
		}
	}

	for y := n / 2; y < n; y++ {
		for x := y - n/2; x < n-(y-n/2); x++ {
			m[y][x] = 'V'
		}
	}

	output(n, m)
}

func alloc(n int) [][]byte {
	m := make([][]byte, n)
	t := make([]byte, n*n)
	for i := range m {
		m[i] = t[i*n : (i+1)*n]
	}
	return m
}

func output(n int, m [][]byte) {
	fmt.Printf("n=%d\n", n)
	for y := range m {
		for x := range m[y] {
			fmt.Printf("%c", m[y][x])
		}
		fmt.Println()
	}
	fmt.Println()
}
