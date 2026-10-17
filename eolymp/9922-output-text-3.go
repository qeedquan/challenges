/*

The program receives two inputs: a natural number n and a string of text, such as Real. Your task is to output this text repeated n times in a single line, with each repetition separated by a plus sign "+".

Input
The first line contains a natural number n, and the second line contains text composed of Latin letters.

Output
The required output for the problem.

Examples

Input #1
4
Real

Answer #1
Real+Real+Real+Real

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	fmt.Println(solve(4, "Real"))
}

func solve(n int, s string) string {
	w := new(bytes.Buffer)
	for i := range n {
		w.WriteString(s)
		if i+1 < n {
			w.WriteRune('+')
		}
	}
	return w.String()
}
