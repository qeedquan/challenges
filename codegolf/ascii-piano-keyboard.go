/*

Piano keys are 3 characters wide, and 7 characters tall. However, if every key was 3 charactes wide, there wouldn't be enough room for the black keys. That's why some of the white keys have parts of them cut out. There are 3 types of white keys.

Keys with the right half missing (R):

____
|  |
|  |
|  |
|  |
|   |
|   |
|___|
Keys with the left half missing (L):

 ____
 |  |
 |  |
 |  |
 |  |
|   |
|   |
|___|
And keys with the left and right halves missing (M):

 ___
 | |
 | |
 | |
 | |
|   |
|   |
|___|
On a real keyboard, the pattern of these goes like this:

RMLRMML, RMLRMML, RMLRMML...
and repeats for a total of 88 keys. Now you can't see it when the keys are shown individually, but when you shove them together, you can see the black keys.

_________________________________________________________
|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |
|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |
|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |
|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |
|   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|___|___|___|___|___|___|___|___|___|___|___|___|___|___|
Your task
Given a positive integer N, print this ASCII-art of a piano with N white keys. You should be able to handle any N from 1 to 52 inclusive (since real 88-key pianos have 52 white keys). Here is test output from 1 to 8, and after that the pattern increases in a similar fashion.

1
____
|  |
|  |
|  |
|  |
|   |
|   |
|___|

2
________
|  | | |
|  | | |
|  | | |
|  | | |
|   |   |
|   |   |
|___|___|

3
_____________
|  | | | |  |
|  | | | |  |
|  | | | |  |
|  | | | |  |
|   |   |   |
|   |   |   |
|___|___|___|

4
________________
|  | | | |  |  |
|  | | | |  |  |
|  | | | |  |  |
|  | | | |  |  |
|   |   |   |   |
|   |   |   |   |
|___|___|___|___|

5
____________________
|  | | | |  |  | | |
|  | | | |  |  | | |
|  | | | |  |  | | |
|  | | | |  |  | | |
|   |   |   |   |   |
|   |   |   |   |   |
|___|___|___|___|___|

6
________________________
|  | | | |  |  | | | | |
|  | | | |  |  | | | | |
|  | | | |  |  | | | | |
|  | | | |  |  | | | | |
|   |   |   |   |   |   |
|   |   |   |   |   |   |
|___|___|___|___|___|___|

7
_____________________________
|  | | | |  |  | | | | | |  |
|  | | | |  |  | | | | | |  |
|  | | | |  |  | | | | | |  |
|  | | | |  |  | | | | | |  |
|   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |
|___|___|___|___|___|___|___|

8
________________________________
|  | | | |  |  | | | | | |  |  |
|  | | | |  |  | | | | | |  |  |
|  | | | |  |  | | | | | |  |  |
|  | | | |  |  | | | | | |  |  |
|   |   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |   |
|___|___|___|___|___|___|___|___|
And last but not least, here is a full 52 key output:

_________________________________________________________________________________________________________________________________________________________________________________________________________________
|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |
|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |
|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |
|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |
|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|
Standard loopholes are banned, and the shortest answer in bytes wins!

*/

package main

import "fmt"

func main() {
	for i := 1; i <= 52; i++ {
		draw(i)
	}
}

func draw(keys int) {
	p := NewPiano()
	fmt.Println(keys)
	fmt.Println(p.Render(keys))
	fmt.Println()
}

// Ported from @Sophie Coyne solution
const (
	LEFT = iota
	MIDDLE
	RIGHT
)

type Piano struct {
	lines map[int]string
}

func NewPiano() *Piano {
	return &Piano{
		lines: make(map[int]string),
	}
}

func (p *Piano) Render(keys int) string {
	pattern := []int{LEFT, MIDDLE, RIGHT, LEFT, MIDDLE, MIDDLE, RIGHT}
	for i := range keys {
		p.fill(pattern[i%len(pattern)])
	}
	return p.combine()
}

func (p *Piano) fill(kind int) {
	p.append(1, "_____")
	switch kind {
	case LEFT:
		p.append(2, "|  | ")
		p.append(3, "|  | ")
		p.append(4, "|  | ")
		p.append(5, "|  | ")

	case MIDDLE:
		p.append(2, " | | ")
		p.append(3, " | | ")
		p.append(4, " | | ")
		p.append(5, " | | ")

	case RIGHT:
		p.append(2, " |  |")
		p.append(3, " |  |")
		p.append(4, " |  |")
		p.append(5, " |  |")
	}
	p.append(6, "|   |")
	p.append(7, "|   |")
	p.append(8, "|___|")
}

func (p *Piano) append(index int, value string) {
	if index < 1 || index > 8 {
		return
	}
	p.lines[index] += value
}

func (p *Piano) combine() string {
	output := ""
	for key := 1; key <= 8; key++ {
		output += p.lines[key] + "\n"
	}
	return output
}
