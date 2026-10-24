/*

Your challenge is to write a program or function that hiccups a string. It should take a string as input (via any standard method), then follow these steps:

Generate a (not necessarily uniformly) random integer n between 1 and 10, inclusive.
Wait n seconds.
Print the initial/next n chars of the input, or the rest of the input if there are less than n chars.
If there is input left to print, go back to step 1.
Rules
The input will always be a non-empty string containing only ASCII chars (32-126).
The wait time does not have to be exactly n seconds, but it must be within 10% of n.
You may print a trailing newline each time a section of text is printed.
Example
A space here represents 1 second. If the input is Hiccupinator!, an output might be:

   Hic     cupin a          tor!

Scoring
This is code-golf, so the shortest code in bytes wins.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	hiccup("Hiccupinator!")
}

func hiccup(s string) {
	l := len(s)
	for i := 0; i < l; {
		n := min(l-i, 1+rand.Intn(10))
		time.Sleep(time.Duration(n) * time.Second)
		fmt.Print(s[i : i+n])
		i += n
	}
	fmt.Println()
}
