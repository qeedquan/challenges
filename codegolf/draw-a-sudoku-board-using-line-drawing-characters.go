/*

This is code golf. For this challenge, I will accept a method (you don't need a full program), but the method signature does count towards the byte count and I want to see the full signature (not a lamdba). The input for the method is an integer array with 81 elements. The output/return value from the method is a string that represents the array as an ascii sudoku board.

If you're using an esoteric language or something that absolutely doesn't have methods, you can adapt, but if the language supports this at all I want to see something might actually be plugged into a "real" ungolfed program, even if the method body itself is a pain to work with. The requirement is not meant to block languages like Jelly or 05AB1E, but to make it easier for languages like Java to build something that makes sense for that platform.

For the input, integer values 1-9 should have obvious meanings. A 0 should always be interpreted as a blank cell. You may also interpret anything else outside the 1-9 range as a blank cell, but this is not required. Positioning from the array to the puzzle starts at the top left and fills each row from left to right before moving to the next row.

For the boxes, I want double lines around the outside and between each 3x3 region, and single lines between other cells. These should be drawn with line drawing characters (if your I/O format represents strings as a sequence of bytes rather than a sequence of characters, you should represent them in a well-known encoding such as UTF-8 or codepage 347).

For this challenge, I am NOT asking you to generate the sudoku puzzle. That is the input for the function. I am NOT asking you to solve the puzzle. I'm just asking you to produce a string to "draw" what you're given (in as few bytes as possible).

Example Input:
Values for the array:

{ 8, 5, 0, 0, 0, 2, 4, 0, 0, 7, 2, 0, 0, 0, 0, 0, 0, 9, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 7, 0, 0, 2, 3, 0, 5, 0, 0, 0, 9, 0, 0 ,0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 7, 0, 0, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6, 0, 4, 0}
The values can use whatever mechanism is natural for your language: int[], ArrayList, sequence, tuple, string of digits, whatever, as long as you have a value in the input for every cell (no maps for only populated cells to positions). Remember that the input is supplied... it is not part of your byte count. But the input might represent any sudoku puzzle, and the puzzle might not even have a valid solution. You do get to assume that puzzle is printable. You won't get something with 82 elements, for example.

You also get to assume a reasonable fixed-width font.

Corresponding Output:
╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗
║ 8 │ 5 │   ║   │   │ 2 ║ 4 │   │   ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║ 7 │ 2 │   ║   │   │   ║   │   │ 9 ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║   │   │ 4 ║   │   │   ║   │   │   ║
╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣
║   │   │   ║ 1 │   │ 7 ║   │   │ 2 ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║ 3 │   │ 5 ║   │   │   ║ 9 │   │   ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║   │ 4 │   ║   │   │   ║   │   │   ║
╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣
║   │   │   ║   │ 8 │   ║   │ 7 │   ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║   │ 1 │ 7 ║   │   │   ║   │   │   ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║   │   │   ║   │ 3 │ 6 ║   │ 4 │   ║
╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝

*/

package main

import "fmt"

func main() {
	sudoku([81]int{8, 5, 0, 0, 0, 2, 4, 0, 0, 7, 2, 0, 0, 0, 0, 0, 0, 9, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 7, 0, 0, 2, 3, 0, 5, 0, 0, 0, 9, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 7, 0, 0, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6, 0, 4, 0})
}

func sudoku(m [81]int) {
	const board = `
╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗
║ X │ X │ X ║ X │ X │ X ║ X │ X │ X ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║ X │ X │ X ║ X │ X │ X ║ X │ X │ X ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║ X │ X │ X ║ X │ X │ X ║ X │ X │ X ║
╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣
║ X │ X │ X ║ X │ X │ X ║ X │ X │ X ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║ X │ X │ X ║ X │ X │ X ║ X │ X │ X ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║ X │ X │ X ║ X │ X │ X ║ X │ X │ X ║
╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣
║ X │ X │ X ║ X │ X │ X ║ X │ X │ X ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║ X │ X │ X ║ X │ X │ X ║ X │ X │ X ║
╟───┼───┼───╫───┼───┼───╫───┼───┼───╢
║ X │ X │ X ║ X │ X │ X ║ X │ X │ X ║
╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝
`

	i := 0
	for _, r := range board {
		if r == 'X' {
			r, i = rune('0'+m[i]), i+1
			if r == '0' {
				r = ' '
			}
		}
		fmt.Printf("%c", r)
	}
}
