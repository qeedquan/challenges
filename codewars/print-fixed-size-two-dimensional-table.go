/*

Create function that outputs 2 dimensional table and places a character in it. Table size is 4 x 4. Function takes row, column and a character.

Assume that row and column values are between 0 inclusive and 4 exclusive.

Assume that character has length of 1.

Example:

row = 2
column = 3
character = "B"

---------
| | | | | 0
---------
| | | | | 1
---------
| | | |B| 2
---------
| | | | | 3
---------
 0 1 2 3

*/

package main

import "fmt"

func main() {
	table(2, 3, 'B')
}

func table(row, column int, char rune) {
	fmt.Println("---------")
	for y := range 4 {
		for x := range 4 {
			fmt.Printf("|")
			if x == column && y == row {
				fmt.Printf("%c", char)
			} else {
				fmt.Printf(" ")
			}
		}
		fmt.Printf("| %d\n", y)
		fmt.Println("---------")
	}
	fmt.Println(" 0 1 2 3 ")
}
