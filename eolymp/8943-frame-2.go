/*

For the given positive integer n print the horizontal rectangular frame of size n×3 from stars, filled with spaces as shown in the sample.

Input
One positive integer n (n≤100).

Output
Print the horizontal rectangular frame of size n×3.

Examples

Input #1
5

Answer #1
***
* *
* *
* *
***

*/

package main

import "fmt"

func main() {
	solve(5)
}

func solve(n int) {
	for y := range n {
		for x := range 3 {
			fmt.Printf("%c", at(x, y, 3, n))
		}
		fmt.Println()
	}
}

func at(x, y, w, h int) rune {
	if x == 0 || x == w-1 || y == 0 || y == h-1 {
		return '*'
	}
	return ' '
}
