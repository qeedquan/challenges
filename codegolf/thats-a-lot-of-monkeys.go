/*

The infinite monkey theorem states that, given infinite time, a machine sending an endless stream of random characters will always type any given text.

That sounds to me like a great idea for a challenge.

Process
In order to monkey-ize a string A, the following steps should be taken:

Take an empty string. We will call this string B.
Pick a uniformly random printable ASCII character (characters in the range 0x20 to 0x7E) and add that character to B.
If A is a substring of B, B is our monkey-ized string. Otherwise, repeat step 2 until A is a substring of B.
This process is only an example, easier methods may exist depending on your language. You do not need to follow this method exactly, as long as the same distribution of outputs is achieved.

The challenge
Write a program or function that, given a non-empty string in any reasonable format, returns a monkey-ized version of that string.

Your program only has to practically work for inputs of length 3 or less. For longer inputs, it is allowed to terminate early with or without outputting anything.

Example
Unfortunately, it's kind of hard to create examples for this question due to the random nature of it and the large outputs.

However, I can supply a single example for the input hi, on Hastebin.

Scoring
Since this is code-golf, the submission with the fewest bytes wins.

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	monkeyize("infinite monkey theorem")
}

func monkeyize(input string) string {
	output := ""
	for input != output {
		next := fmt.Sprintf("%s%c", output, 32+rand.Intn(95))
		fmt.Println(next)
		if next != input[:len(next)] {
			continue
		}
		output = next
	}
	return output
}
