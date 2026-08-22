/*

Last time you made a square of text, but now, can you make a cube of text?

The Challenge
Given a string, output the string in the form of a cube.

You can assume the string will always have 2 chars or more, and will only have printable ascii characters.

How to Make a Text Cube
https://i.sstatic.net/hABjp.png

Test Cases
Input:
Test

Output:
   Test
  e  ss
 s  e e
tseT  T
s  e e
e  ss
Test

Input:
Hello, world!

Output:
            Hello, world!
           e           dd
          l           l l
         l           r  r
        o           o   o
       ,           w    w

     w           ,      ,
    o           o       o
   r           l        l
  l           l         l
 d           e          e
!dlrow ,olleH           H
d           e          e
l           l         l
r           l        l
o           o       o
w           ,      ,

,           w    w
o           o   o
l           r  r
l           l l
e           dd
Hello, world!

Input:
Hi

Output:
 Hi
iHH
Hi
Reference Implementation in Python
text = raw_input("Enter a string: ")

print " " * (len(text) - 1) + text

spaces = len(text) - 2
_spaces = spaces

for i in range(1, len(text) - 2 + 1):
    print " " * spaces + text[i] + " " * _spaces + text[(i + 1) * -1] + " " * (_spaces - spaces) + text[(i + 1) * -1]
    spaces -= 1

print text[::-1] + " " * _spaces + text[0]

spaces = _spaces - 1

for i in range(1, len(text) - 2 + 1):
    print text[(i + 1) * -1] + " " * _spaces + text[i] + " " * spaces + text[i]
    spaces -= 1

print text

Rules
This is code-golf, so shortest answer in bytes wins! Tiebreaker is most upvoted.
Standard loopholes are disallowed.
Trailing newline and trailing spaces are allowed.

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	cubetext("Test")
	cubetext("Hello, world!")
	cubetext("Hi")
	cubetext("")
}

func cubetext(s string) {
	l := len(s)
	n := l - 2
	m := n

	fmt.Printf("%q\n", s)
	if l == 0 {
		return
	}
	output(" s", l-1, s)
	for i := 1; i <= l-2; i, n = i+1, n-1 {
		j := l - i - 1
		output(" c c c", n, s[i], m, s[j], m-n, s[j])
	}
	output("r c", s, m, s[0])

	n = m - 1
	for i := 1; i <= l-2; i, n = i+1, n-1 {
		j := l - i - 1
		output("c c c", s[j], m, s[i], n, s[i])
	}
	output("s", s)
	fmt.Println()
}

func output(f string, a ...any) {
	for i := 0; i < len(f); i++ {
		switch f[i] {
		case ' ':
			n := a[i].(int)
			fmt.Print(spaces(n))
		case 'c':
			c := a[i].(byte)
			fmt.Printf("%c", c)
		case 's':
			s := a[i].(string)
			fmt.Print(s)
		case 'r':
			s := a[i].(string)
			r := reverse(s)
			fmt.Print(r)
		}
	}
	fmt.Println()
}

func reverse(s string) string {
	w := new(bytes.Buffer)
	for i := len(s) - 1; i >= 0; i-- {
		w.WriteByte(s[i])
	}
	return w.String()
}

func spaces(n int) string {
	if n < 1 {
		return ""
	}
	return strings.Repeat(" ", n)
}
