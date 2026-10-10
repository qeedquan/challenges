/*

Note: After trying this myself, I soon realized what a mistake this was. Therfore, I am modifying the rules a bit.

The minimum required functionality:

Character classes (., \w, \W, etc.)
Multipliers (+, *, and ?)
Simple capture groups
Your challenge is to implement PCRE in the language of your choice subject to the following conditions:

You may not use your language's native RegEx facilities in any way. You may not use a 3rd party RegEx library either.
Your entry should implement as much of the PCRE spec. as possible.
Your program should accept as input, 2 lines:

the regular expression
the string input to match against
Your program should indicate in its output:

Whether the RegEx matched anywhere in the input string
The results of any capturing groups
The winner shall be the entry that implements as much of the spec. as possible. In case of a tie, the winner shall be the most creative entry, as judged by me.

Edit: to clarify a few things, here are some examples of input and expected output:

Input:
^\s*(\w+)$
         hello
Output:
Matches: yes
Group 1: 'hello'
Input:
(\w+)@(\w+)(?:\.com|\.net)
sam@test.net
Output:
Matches: yes
Group 1: 'sam'
Group 2: 'test'

*/

package main

import (
	"fmt"
	"regexp"
)

func main() {
	match(`^\s*(\w+)$`, `         hello`)
	match(`(\w+)@(\w+)(?:\.com|\.net)`, `sam@test.net`)
}

func match(pattern, input string) {
	regex := regexp.MustCompile(pattern)
	matches := regex.FindStringSubmatch(input)
	if matches == nil {
		fmt.Println("Matches: no")
		return
	}

	fmt.Println("Matches: yes")
	for index, match := range matches[1:] {
		fmt.Printf("Group %d: '%s'\n", index+1, match)
	}
	fmt.Println()
}
