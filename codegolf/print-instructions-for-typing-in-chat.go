/*

Background
As far as we can tell from trying everything (besides cheating with ZWSPs), you can't type `\ in Stack Exchange chat. However, you can type \` by doing `\\``.

So, if you want to tell someone in chat how to type backslash-backtick, you'd need to type out `\`\\`\`` to format `\\`` into a codeblock.

Challenge
Your challenge will be to take a string of backticks and backslashes and output a string of backticks and backslashes that will format into that (as a code block) when you type it into SE chat. You can test this in the chat sandbox.

One important thing to note is that a backslash prevents the next backtick from starting or ending a code block, but a backslash will not actually make the next backslash not escape - basically, three backslashes and a backtick will become two literal backslashes and a literal backtick, the latter of which will not function as a code block delimiter anymore.

Thus, one way to solve this challenge is to take each block of backslashes (including the zero-length ones between consecutive backticks) and add a backslash to each, then surround the string in backticks.

You may assume it is possible; that is, the input will not end with a backslash. You also do not need to handle empty input.

Input / Output
Input and output will be taken and provided as a string of backticks and backslashes. For this challenge, you must use these characters specifically. You can input or output as a flat list of characters instead, and input and output do not have to use the same format.

Test Cases
These test cases follow my example solution. I don't actually know if another solution exists, but if you can find an alternative that works in SE chat and isn't just the aforementioned approach, I may offer a bounty.

\`                => `\\``
`\\`\`\\``        => `\`\\\`\\`\\\`\``
`\`\\\`\\`\\\`\`` => `\`\\`\\\\`\\\`\\\\`\\`\``
``````            => `\`\`\`\`\`\``
\\\\\\\\\`        => `\\\\\\\\\\``
`                 => `\``
`\`\`\`\`\`\`\`   => `\`\\`\\`\\`\\`\\`\\`\\``

Reference Implementation in Python; you can input as many lines as you want and it will print a valid answer to each using my approach.

while True:
	try:
		line = input()
	except:
		break
	backslashes = 0
	output = ""
	for char in line:
		if char == "`":
			output += "\\" * backslashes + "\\" + "`"
			backslashes = 0
		else:
			backslashes += 1
	print("`" + output + "`")

Standard Loopholes are disallowed as usual.

This is a code-golf challenge, so the shortest code in bytes per language wins in its language category. Happy golfing!

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	assert(escape("\\`") == "`\\\\``")
	assert(escape("`\\\\`\\`\\\\``") == "`\\`\\\\\\`\\\\`\\\\\\`\\``")
	assert(escape("`\\`\\\\\\`\\\\`\\\\\\`\\``") == "`\\`\\\\`\\\\\\\\`\\\\\\`\\\\\\\\`\\\\`\\``")
	assert(escape("``````") == "`\\`\\`\\`\\`\\`\\``")
	assert(escape("\\\\\\\\\\\\\\\\\\`") == "`\\\\\\\\\\\\\\\\\\\\``")
	assert(escape("`") == "`\\``")
	assert(escape("`\\`\\`\\`\\`\\`\\`\\`") == "`\\`\\\\`\\\\`\\\\`\\\\`\\\\`\\\\`\\\\``")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func escape(s string) string {
	w := new(bytes.Buffer)
	nb := 0
	fmt.Fprint(w, "`")
	for _, r := range s {
		if r == '`' {
			fmt.Fprintf(w, "%v\\`", strings.Repeat(`\`, nb))
			nb = 0
		} else {
			nb += 1
		}
	}
	fmt.Fprint(w, "`")
	return w.String()
}
