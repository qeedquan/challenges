/*

Challenge
Write a program or function that takes in a string s and integer n as parameters. Your program should print (or return) the string when transformed as follows:

Starting in the top-left and moving down and to the right, write s as a wave of height n. Then, from top to bottom, combine each row as a string (without spaces).

Example
Given the string "WATERMELON" and a height of 3:

The wave should look like this:

W   R   O
 A E M L N
  T   E
Then, combine the rows from top to bottom:

WRO
AEMLN
TE
So, your program should return the string "WROAEMLNTE"

Likewise, "WATERMELON" with height 4 should produce the following wave:

W     E
 A   M L
  T R   O
   E     N
Your program should then return the string "WEAMLTROEN"

Rules
Input
Input can be taken in any reasonable format. The string can be in any case you prefer. You may assume that 0 < n <= s.length

Output
Output should consist only of the transformed string (whether returned or printed to STDOUT), plus any trailing newlines.

Scoring
This is code-golf, so shortest answer in bytes wins! Standard loopholes are not allowed.

Test Cases
Input                        Output

programmingpuzzles, 5 ->     piermnlsomgzgapzru
codegolf, 3           ->     cgoeofdl
elephant, 4           ->     enlatehp
1234567, 3            ->     1524637
qwertyuiop, 1         ->     qwertyuiop

*/

package main

import (
	"bytes"
)

func main() {
	assert(wavy("WATERMELON", 3) == "WROAEMLNTE")
	assert(wavy("WATERMELON", 4) == "WEAMLTROEN")
	assert(wavy("programmingpuzzles", 5) == "piermnlsomgzgapzru")
	assert(wavy("codegolf", 3) == "cgoeofdl")
	assert(wavy("elephant", 4) == "enlatehp")
	assert(wavy("1234567", 3) == "1524637")
	assert(wavy("qwertyuiop", 1) == "qwertyuiop")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func wavy(s string, n int) string {
	w := new(bytes.Buffer)
	for i := range n {
		for j := 0; j < len(s); j++ {
			x := j % max(2*n-2, 1)
			if x == i || x == 2*n-i-2 {
				w.WriteByte(s[j])
			}
		}
	}
	return w.String()
}
