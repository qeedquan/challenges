/*

What I want:
Quite simply, I want a text based display, that asks for an input, n, then shows that value on the display! But there's a catch. Each of the 'true' 'pixels' (the ones filled in) has to be represented by that number n..

Example :
You are given an input n. You can assume n will be a single digit

Input: 0
Output:
000
0 0
0 0
0 0
000

Input: 1
Output:
  1
  1
  1
  1
  1

Input: 2
Output:
222
  2
222
2
222

Input: 3
Output:
333
  3
333
  3
333

Input: 4
Output:
4 4
4 4
444
  4
  4

Input: 5
Output:
555
5
555
  5
555

Input: 6
Output:
666
6
666
6 6
666

Input: 7
Output:
777
  7
  7
  7
  7

Input: 8
Output:
888
8 8
888
8 8
888

Input: 9
Output:
999
9 9
999
  9
999

Challenge:
Do the above it in as few bytes as possible.

I will only accept answers that meet all requirements.

Surrounding whitespace is optional, as long as the digit is displayed properly.

Also, <75 bytes is a vote from me, the lowest accept, but I could always change the accepted answer, so don't be discouraged to answer.

*/

package main

import "fmt"

func main() {
	for i := 0; i < 10; i++ {
		display(i)
	}
}

func display(n int) {
	lut := []string{ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE}
	fmt.Println(lut[n])
}

const ZERO = `
000
0 0
0 0
0 0
000
`

const ONE = `
  1
  1
  1
  1
  1
`

const TWO = `
222
  2
222
2
222
`

const THREE = `
333
  3
333
  3
333
`

const FOUR = `
4 4
4 4
444
  4
  4
`

const FIVE = `
555
5
555
  5
555
`

const SIX = `
666
6
666
6 6
666
`

const SEVEN = `
777
  7
  7
  7
  7
`

const EIGHT = `
888
8 8
888
8 8
888
`

const NINE = `
999
9 9
999
  9
999
`
