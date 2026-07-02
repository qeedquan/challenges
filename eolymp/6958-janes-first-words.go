/*

Jane (my 2-year-old baby daughter) has started speaking some simple words now. "Daddy" and "Mommy" are the two common first words. Hearing those words for the first time is indeed beautiful and memorable.

Last year, Steven really wanted to record when his baby called him for the first time. So, Steven put a microphone and sound capture program near Jane's baby cot (baby's bed). This microphone captured Jane's sounds, and the program transmitted the list of words captured to Steven. He wrote a program to detect the moment when Jane first called him: "daddy" (or its variants). This time, you will also write a similar program.

Input
You are given one word per line. These are the list of captured sounds. Each line contains only lowercase alphabets without any whitespaces and at most 20 characters.

Output
For each word/line, output She called me!!! in one line if that word matches the regular expression below. Otherwise, output Cooing in one line (to indicate that this is just some baby soft murmuring sound).

Note: Quotes are only for clarity.

The regular expression (regex): da+dd?(i|y).

If you are not familiar with regex, here is an explanation:

'+' means one or more of the preceding element.

'?' means zero or one of the preceding element.

A vertical bar '|' separates alternatives.

Parentheses are used to define the scope and precedence of the operators.

Examples

Input #1
aaaa
eeeh
auwww
dda
daaada
daddy
ouuuww
dadi

Answer #1
Cooing
Cooing
Cooing
Cooing
Cooing
She called me!!!
Cooing
She called me!!!

*/

package main

import "regexp"

func main() {
	assert(solve("aaaa") == "Cooing")
	assert(solve("eeeh") == "Cooing")
	assert(solve("auwww") == "Cooing")
	assert(solve("dda") == "Cooing")
	assert(solve("daaada") == "Cooing")
	assert(solve("daddy") == "She called me!!!")
	assert(solve("ouuuww") == "Cooing")
	assert(solve("dadi") == "She called me!!!")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) string {
	if DADDY.MatchString(s) {
		return "She called me!!!"
	}
	return "Cooing"
}

var DADDY = regexp.MustCompile(`da+dd?(i|y)`)
