/*

Generate me a QFP chip!
From the sandbox!

QFP is a type of form factor for an electrical component where pins come out the sides of a chip. Here are is a picture of a typical QFP component:

https://i.stack.imgur.com/VF0tx.png

you can see that the general formula is to have 4 sides of equal numbers of pins.

Your challenge is to create a program that takes in an integer, thich represents the number of pins on one side, and creates an ASCII QFP component with numbered pins.

Input:
a single integer which represents the number of pins on one side

Output:
An ASCII QFP chip with an apropriate pinout.

Example:
input:1

  4
 ┌┴┐
1┤ ├3
 └┬┘
  2
input:2

  87
 ┌┴┴┐
1┤  ├6
2┤  ├5
 └┬┬┘
  34
input:12

   444444444333
   876543210987
  ┌┴┴┴┴┴┴┴┴┴┴┴┴┐
 1┤            ├36
 2┤            ├35
 3┤            ├34
 4┤            ├33
 5┤            ├32
 6┤            ├31
 7┤            ├30
 8┤            ├29
 9┤            ├28
10┤            ├27
11┤            ├26
12┤            ├25
  └┬┬┬┬┬┬┬┬┬┬┬┬┘
   111111122222
   345678901234

Rules:
all QFP chips must be enclosed and sealed as well as ascii provides. spacing is of utmost importance. Dust inside a microprocessor is bad stuff!
pin numbering must be done as in the examples (Read left to right, top to bottom, numbered counter clockwise)
You may start numbering at 0, but this must not affect the chip (an input of 12 still needs 12 pins per side)
The only valid characers in your output are 1,2,3,4,5,6,7,8,9,0,┌,┴,┐,├,┘,┬,└,┤, spaces, and newlines.
all encodings for languages are allowed, but your output MUST be consistent with the rules above.
This is a codegolf, and as such, The code with the least number of bytes wins! Good Luck!

*/

package main

import "fmt"

func main() {
	for i := 0; i <= 16; i++ {
		qfp(i)
	}
}

func qfp(n int) {
	if n < 0 {
		return
	}

	l := len(fmt.Sprint(n * 4))
	s := n + 2*(l+1)
	p := alloc(s)

	fill(p, ' ')
	border(p, s, l)
	assign(p, n, s, l)
	output(n, p)
}

func border(p [][]rune, s, l int) {
	p[l][l] = '┌'
	p[l][s-l-1] = '┐'
	p[s-l-1][l] = '└'
	p[s-l-1][s-l-1] = '┘'
	for x := l + 1; x < s-l-1; x++ {
		p[l][x] = '┴'
		p[s-l-1][x] = '┬'
	}
	for y := l + 1; y < s-l-1; y++ {
		p[y][l] = '┤'
		p[y][s-l-1] = '├'
	}
}

func assign(p [][]rune, n, s, l int) {
	tab := []struct {
		x, y   int
		dx, dy int
		sx, sy int
		rev    bool
	}{
		{l - 1, l + 1, -1, 0, 0, 1, true},
		{l + 1, s - l, 0, 1, 1, 0, false},
		{s - l, s - l - 2, 1, 0, 0, -1, false},
		{s - l - 2, l - 1, 0, -1, -1, 0, true},
	}

	id := 1
	for _, t := range tab {
		for i := 0; i < n; i++ {
			b := []rune(fmt.Sprint(id))
			if t.rev {
				reverse(b)
			}

			for j := range b {
				p[t.y+t.dy*j][t.x+t.dx*j] = b[j]
			}
			t.x += t.sx
			t.y += t.sy
			id += 1
		}
	}
}

func reverse(b []rune) {
	n := len(b)
	for i := 0; i < n/2; i++ {
		b[i], b[n-i-1] = b[n-i-1], b[i]
	}
}

func alloc(n int) [][]rune {
	p := make([][]rune, n)
	t := make([]rune, n*n)
	for i := range p {
		p[i] = t[i*n : (i+1)*n]
	}
	return p
}

func fill(p [][]rune, c rune) {
	for y := range p {
		for x := range p[y] {
			p[y][x] = c
		}
	}
}

func output(n int, p [][]rune) {
	fmt.Printf("n=%d\n", n)
	for y := range p {
		for x := range p[y] {
			fmt.Printf("%c", p[y][x])
		}
		fmt.Println()
	}
	fmt.Println()
}
