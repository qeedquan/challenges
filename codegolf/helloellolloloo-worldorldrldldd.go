/*

Make a program that takes the word you input, and adds that word to the back of itself minus its first letter, then repeats until all letters are gone. For example, cat would become catatt, and hello would become helloellolloloo.

Input
Any of the 26 letters of the English alphabet. There may be multiple words separated by spaces, and the change should be applied to every word.

Output
The word(s) inputted, with each word put after itself with its first letter missing, and then with its second letter missing, and so on until there are no more letters to add.

More examples:

ill eel outputs illlll eelell

laser bat outputs laserasersererr batatt

darth vader outputs dartharthrththh vaderaderdererr

This is code golf, so the shortest code wins.

Clarification:
You can treat the input or output as a list. You can separate words using newline instead of space. You can add a trailing space to the input.

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	assert(elongate("cat") == "catatt")
	assert(elongate("hello") == "helloellolloloo")
	assert(elongate("ill eel") == "illlll eelell")
	assert(elongate("laser bat") == "laserasersererr batatt")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func elongate(s string) string {
	w := new(bytes.Buffer)
	t := strings.Split(s, " ")
	for i := range t {
		for j := 0; j < len(t[i]); j++ {
			fmt.Fprint(w, t[i][j:])
		}
		if i+1 < len(t) {
			fmt.Fprint(w, " ")
		}
	}
	return w.String()
}
