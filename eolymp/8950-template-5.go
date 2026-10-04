/*

https://static.e-olymp.com/content/46/465e5e87ec1dad74ffd60f811c1a1d1da9f0060f.jpg

Given positive odd integer n. Print the image of size n×n, formed by the asterisk and space characters as shown in the example.

Input
One positive odd integer n (n>1).

Output
Print the image n×n.

Examples
Input #1
5

Answer #1
*   *
** **
*****
** **
*   *

*/

package main

import "fmt"

func main() {
	for i := 1; i <= 11; i += 2 {
		solve(i)
	}
}

func solve(n int) {
	fmt.Printf("n=%d\n", n)
	for y := range n {
		for x := range n {
			fmt.Printf("%c", at(n, x, y))
		}
		fmt.Println()
	}
	fmt.Println()
}

func at(n, x, y int) rune {
	if y <= n/2 {
		if x <= y || x >= n-y-1 {
			return '*'
		}
		return ' '
	}
	if x <= n-y-1 || x >= y {
		return '*'
	}
	return ' '
}
