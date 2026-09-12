/*

Task
Given two positive integers:

Draw the rectangle with dimensions specified by the two integers.
Repeat Step 3 until there is no more space.
Draw and fill the largest square touching three sides of the (remaining) rectangle.
Output the resulting rectangle.
Example
For example, our input is 6 and 10.

We draw the hollow rectangle of size 6 x 10:

xxxxxxxxxx
xxxxxxxxxx
xxxxxxxxxx
xxxxxxxxxx
xxxxxxxxxx
xxxxxxxxxx
After repeatedly filling squares, this is what we would obtain:

aaaaaabbbb
aaaaaabbbb
aaaaaabbbb
aaaaaabbbb
aaaaaaccdd
aaaaaaccdd
There are 4 squares here (a, b, c, d), each with side length 6, 4, 2, 2 respectively.

Rules and freedom
You must use a different letter for each square.
You can choose which letters to support, as long as the letters supported are all printable characters and there are at least 10 characters supported.
In each iteration of Step 3 above, you have two choices (except in the last iteration, where you only have one choice). Both choices are valid.
The number of squares required will not exceed the number of letters you support.
You can fill in the squares with the letters you support in any order.
Testcases
Input: 6, 10

Output:

aaaaaabbbb
aaaaaabbbb
aaaaaabbbb
aaaaaabbbb
aaaaaaccdd
aaaaaaccdd
or

aaaaaaccdd
aaaaaaccdd
aaaaaabbbb
aaaaaabbbb
aaaaaabbbb
aaaaaabbbb
or

bbbbaaaaaa
bbbbaaaaaa
bbbbaaaaaa
bbbbaaaaaa
ccddaaaaaa
ccddaaaaaa
or

ccddaaaaaa
ccddaaaaaa
bbbbaaaaaa
bbbbaaaaaa
bbbbaaaaaa
bbbbaaaaaa
or

ddddddaaaa
ddddddaaaa
ddddddaaaa
ddddddaaaa
ddddddbbcc
ddddddbbcc
Input: 1,1

Output:

a
Input: 1,10

Output:

abcdefghij
Input: 10,1

Output:

a
b
c
d
e
f
g
h
i
j
Note that there are more possibilities than I can include for the testcases above.

Scoring
This is code-golf. Shortest answer in bytes wins.

Standard loopholes apply.

*/

package main

import "fmt"

func main() {
	vis(6, 10)
	vis(1, 1)
	vis(1, 10)
	vis(10, 1)
}

func vis(r, c int) {
	p := alloc(r, c)
	for z := 'a'; r > 0 && c > 0; z++ {
		fill(p, r, c, z)
		if r < c {
			c -= r
		} else {
			r -= c
		}
	}
	show(p)
}

func alloc(r, c int) [][]rune {
	p := make([][]rune, r)
	for i := range p {
		p[i] = make([]rune, c)
	}
	return p
}

func fill(p [][]rune, r, c int, z rune) {
	for i := range r {
		for j := range c {
			p[i][len(p[i])-j-1] = z
		}
	}
}

func show(p [][]rune) {
	for i := range p {
		for j := range p[i] {
			fmt.Printf("%c", p[len(p)-i-1][j])
		}
		fmt.Println()
	}
	fmt.Println()
}
