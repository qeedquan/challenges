/*

The Challenge

Your task is to create a program that takes any given string input, and outputs the input in a squared format. Empty strings should return an empty string.

Examples

Given the input:

golf
Your program should output:

golf
o  l
l  o
flog
Input:

123
Output:

123
2 2
321
Input:

a
Output:

a
Input:

Hello, world!
Output (notice the space between the , and w - the gap is not just a newline):

Hello, world!
e           d
l           l
l           r
o           o
,           w

w           ,
o           o
r           l
l           l
d           e
!dlrow ,olleH
Scoring

This is code-golf, so the shortest answer in each language wins.

*/

package main

import "fmt"

func main() {
	squarification("")
	squarification("ab")
	squarification("abc")
	squarification("Hello, world!")
	squarification("abcdefghijklmnopqrstuvwxyz")
	squarification("golf")
	squarification("a")
	squarification("123")
}

func squarification(s string) {
	fmt.Printf("%q\n", s)
	fmt.Println(s)
	m := len(s) - 1
	for n := 1; m-n > 0; n++ {
		fmt.Printf("%c%*c\n", s[n], m, s[m-n])
	}
	for n := m; n >= 0; n-- {
		fmt.Printf("%c", s[n])
	}
	fmt.Printf("\n\n")
}
