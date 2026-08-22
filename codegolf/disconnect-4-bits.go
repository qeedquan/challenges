/*

Your task: given an input string, determine whether the binary representation of that string does not have 4 1s or 0s in a row, anywhere.
Furthermore, your code itself should not contain any such runs of four in a row.

Test Cases
String      Binary              Result

U3          01010101 00110011   Truthy

48          00110100 00111000   Falsy

Foobar      01000110 01101111   Falsy
            01101111 01100010
            01100001 01110010

Feeber      01000110 01100101   Truthy
            01100101 01100010
            01100101 01110010

$H          00100100 01001000   Truthy

<Empty>     -                   Truthy

Rules
Input will always be within the range of printable ASCII, including whitespace characters.
Your code may use any encoding, since it only matters at the bit level.
Because this condition prevents the use of white space and many other chars, your code actually can contain such runs of four in a row, at a 10 byte penalty for each run.
A run of 5 1s or 0s counts as two runs, 6 in a row counts as three runs, etc.
Input will be a string or char array, not any other form.
You may write a complete program or function.
You must provide the binary representation of your code in your answer.
Good luck, lowest score wins!

This script might help you with your challenge, put your code in the input and it will give you your code's binary representation,
it's length, your penalty, and the total score, if you're using UTF-8.

Leaderboard
Here is a Stack Snippet to generate both a regular leaderboard and an overview of winners by language.

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	assert(dis4("U3") == true)
	assert(dis4("48") == false)
	assert(dis4("Foobar") == false)
	assert(dis4("Feeber") == true)
	assert(dis4("$H") == true)
	assert(dis4("") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func dis4(s string) bool {
	w := new(bytes.Buffer)
	for i := range len(s) {
		fmt.Fprintf(w, "%08b", s[i])
	}

	p := w.String()
	i := strings.Index(p, "1111")
	if i < 0 {
		i = strings.Index(p, "0000")
	}
	return i < 0
}
