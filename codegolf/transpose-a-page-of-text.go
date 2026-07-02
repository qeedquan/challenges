/*

EDIT I modified the wording of the rules to make some things which were implicit more explicit. I also added some emphasis to clear up some points of apparent confusion, and explicitly defined the option of making a standalone program instead of a function.

The goal here is to make a function that takes a text file (or string) and transposes it so that lines become columns and vice versa.

Example:

I am a text.
Transpose me.
Can you do it?
Results in:

ITC
 ra
aan
mn
 sy
apo
 ou
ts
eed
x o
tm
.ei
 .t
  ?
The rules:

You are allowed to assume that the only whitespace characters used are " " and "\n" and that there is no trailing whitespace on any line.
You may assume that the file is ASCII. Which endline marker you want to use is up to you.(CRLF or LF). It must work correctly on the example, but it should also work on any input that satisfies the above assumptions.
You might have to insert spaces (as in the example) where there were none in order to keep the columns in line.
Your result must not have trailing whitespace on any line.
The final newline character(for the last line) is optional.
It should be either a function or a complete program. If your function accepts a string, then it should return the results as a string. If it accepts a filename, then you return the name of the file where you saved the result. You are additionally allowed to write a complete program that accepts input from STDIN and outputs the correct result to STDOUT; if you do this, you must not output anything to STDERR.
Shortest procedure wins, but I will upvote any answer I like.
Based on the rules, the output on the example is either 53 or 52 bytes long (for LF newlines) depending on whether the final newline is included or not.

Note: It is not a specific requirement, but if your function, when run twice successively is not identical to the original(the final newline might be differ, and any empty lines at the end of the file will be deleted), then you are probably breaking one of the rules.

*/

package main

import (
	"bytes"
	"fmt"
	"reflect"
)

func main() {
	test([]string{
		"I am a text.",
		"Transpose me.",
		"Can you do it?",
	}, []string{
		"ITC",
		" ra",
		"aan",
		"mn ",
		" sy",
		"apo",
		" ou",
		"ts ",
		"eed",
		"x o",
		"tm ",
		".ei",
		" .t",
		"  ?",
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s, r []string) {
	p := transpose(s)
	output(p)
	assert(reflect.DeepEqual(p, r))
}

func output(s []string) {
	for i := range s {
		fmt.Printf("%q\n", s[i])
	}
}

func transpose(s []string) []string {
	w, h := 0, len(s)
	for i := range s {
		w = max(w, len(s[i]))
	}

	r := []string{}
	for x := range w {
		b := new(bytes.Buffer)
		for y := range h {
			if x < len(s[y]) {
				b.WriteByte(s[y][x])
			} else {
				b.WriteByte(' ')
			}
		}
		r = append(r, b.String())
	}

	return r
}
