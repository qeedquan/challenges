/*

Using the following length-separated lists of words:

https://github.com/Magic Octopus Urn/wordListsByLength

Print 1 word from each list of length n from 1 all the way up to 20, here's a valid example:

a
an
and
hand
hands
handle
handles
abandons
abandoned
understand
outstanding
newfoundland
understanding
characteristic
characteristics
characterization
characterizations
characteristically
characterologically
chemotherapeutically
Alternatively (array):

['a', 'an', 'and', 'hand', 'hands', 'handle', 'handles', 'abandons', 'abandoned', 'understand', 'outstanding', 'newfoundland', 'understanding', 'characteristic', 'characteristics', 'characterization', 'characterizations', 'characteristically', 'characterologically', 'chemotherapeutically']
Alternatively (any printable non-alphabetic separator other than \n):

a:an:and:hand:hands:handle:handles:abandons:abandoned:understand:outstanding:newfoundland:understanding:characteristic:characteristics:characterization:characterizations:characteristically:characterologically:chemotherapeutically
Rules
You may choose your own 20 words.
The words must be from the github page provided, more specifically:
1 from 1.txt, 1 from 2.txt, etc...
Note, files above 20.txt exist, but you do not need any words above 20 characters.
Valid separators are ASCII-printable non-alphabetical characters (even numbers, don't care).
Lowercase or uppercase only, pick one, stick with it; no title-case allowed.
Please don't use a 100% copy of my example 20 words...
You can, but that's no fun.
They are likely suboptimal anyways...
If you DON'T want to use the separated files, and need a full list:
Use unsorted.txt, this is all n.txt files in one, sorted alphabetically.
Note, you CANNOT directly read from the URL, it is a common loophole.
This is code-golf, lowest byte-count will be the winner.
For reference, the output is 229 bytes, so anything that gets under that beats hardcoding.

Possible meta-tag-discussion:

user-driven where the user gets to customize their outputs from a list of possibilities?

*/

package main

import (
	"fmt"
	"math/rand"
	"os"
	"strings"
)

func main() {
	for index := 1; index <= 20; index++ {
		name := fmt.Sprintf("%d.txt", index)
		fmt.Println(getword(name))
	}
}

func getword(name string) string {
	data, err := os.ReadFile(name)
	if err != nil {
		return "Misfortune!"
	}

	words := strings.Replace(string(data), "\r\n", "\n", -1)
	words = strings.TrimSpace(words)
	lines := strings.Split(words, "\n")
	if len(lines) == 0 {
		return "Misfortune!"
	}

	choice := rand.Intn(len(lines))
	return lines[choice]
}
