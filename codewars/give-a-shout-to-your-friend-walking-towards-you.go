/*

You are walking on the sidwalk, you notice your friend is also walking on the sidewalk. You need to give a shout to your friend in order to grab their attention.

Kata
Write the function madShout that takes a string input sidewalk to calculate the shout string and return it.

The shout phrase is "Oi F!" but depending on the distance between your friend, the word expands.

Example for input 'sidewalk'
'---------Y-----F------------'

Y = You
F = Friend

'Shout' phrase:
Since in the example, the difference between the friends is 6 (F's index is 15 & that of Y's is 9), the shout phrase becomes 'Oiii F!'

Consider the following differences and its output:
Difference is 4 => 'Oii F!'
2 => 'Oi F!'
9 => 'Oiiiii F!'
0 => 'Oi F!'
1 => 'Oi F!'
20 => 'Oiiiiiiiiii F!'

Some guides for coding
Y will always be on the left and F will be on the right.
The number of 'i's in the output must be >= 1
All the inputs are valid.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	assert(madshout("---------Y-----F------------") == "Oiii F!")
	assert(madshout("Y-F") == "Oi F!")
	assert(madshout("Y---F") == "Oii F!")
	assert(madshout("YF") == "Oi F!")
	assert(madshout("Y--------F") == "Oiiiii F!")
	assert(madshout("Y-------------------F") == "Oiiiiiiiiii F!")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func madshout(s string) string {
	i := strings.IndexByte(s, 'Y')
	j := strings.IndexByte(s, 'F')
	if i < 0 || j < 0 {
		return ""
	}

	d := abs(i - j)
	return fmt.Sprintf("Oi%s F!", strings.Repeat("i", (d-1)/2))
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
