/*

This came to me in a dream somehow. I've seen similar questions around, but hope this is novel.

The premise is straightforward:

Input: one positive integer.

Output is a pretty square squared using these fancy characters.

Examples:
n = 1

╔═══╗
║   ║
╚═══╝
n = 2

╔═══╦═══╗
║   ║   ║
╠═══╬═══╣
║   ║   ║
╚═══╩═══╝
...

n = 10

╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗
║   ║   ║   ║   ║   ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║   ║   ║   ║   ║
╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝
Note that it's three across and one high (plus corners) so that it appears more squarely.

     -3-
    ╔═══╗
  1 ║   ║
    ╚═══╝
Take your input and output as desired, trailing spaces and lines are fine.

It's code-golf, go for the fewest bytes in your preferred lang!

*/

package main

import "fmt"

func main() {
	square(1)
	square(2)
	square(10)
}

func square(n int) {
	fmt.Printf("n=%d\n", n)
	for y := range 2*n + 1 {
		for x := range 4*n + 1 {
			fmt.Printf("%c", at(n, x, y))
		}
		fmt.Println()
	}
	fmt.Println()
}

/*

@Ted

Explanation
In essence, we iterate through all the rows an columns (of the character grid, not of the box grid), denoted by r and c.

We define some checks for each cell:

(r%2,c%4,r,c,r-n*2,c-n*4)
These will either be truthy or falsy depending on the row and column. This is then converted as if the booleans were bits into a number. Then we modulo the whole thing by 21, which gives us the smallest resulting domain of numbers without causing collisions between characters (found by exhaustive search).

Then we lookup the resulting value in the string " ║═╔║║╗╦═╚═╠╝╩╣╬"

*/

func at(n, x, y int) rune {
	sym := []rune{' ', '║', '═', '╔', '║', '║', '╗', '╦', '═', '╚', '═', '╠', '╝', '╩', '╣', '╬'}
	bit := []int{y % 2, x % 4, y, x, n*2 - y, n*4 - x}

	v := 0
	for i, x := range bit {
		if x > 0 {
			v |= 1 << (len(bit) - i - 1)
		}
	}
	return sym[v%21]
}
