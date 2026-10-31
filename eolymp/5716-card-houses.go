/*

Slavik dreams of becoming a performer of an original genre, so he constantly practices manipulating various objects.
Lately, he has been dedicating all his free time to building card houses.
He has already managed to construct a four-story card house at home, which required 26 cards.
During a technology class, Slavik secretly demonstrated his skill to his classmates by building a three-story card house using only 15 cards.

The "creations" of the future artist are captured in the photos below:

https://static.e-olymp.com/content/9c/9c34dd7a65501fd94341f498495229b213c4fa99.jpg


Now Slavik is interested in a mathematical question: how many cards are needed to build a card house of n stories?

He asks for your help, as mathematics is not his strongest subject.

https://static.e-olymp.com/content/0c/0c4fe4d8e3ebb06be199d6418dfb0c69697b3006.gif

Input
One non-negative integer n (n≤10^8) — the number of stories in the card house to be built.

Output
Print the number of cards required to build a card house with n stories.

Examples

Input #1
3

Answer #1
15

Input #2
4

Answer #2
26

*/

package main

func main() {
	tab := []int{
		0, 2, 7, 15, 26, 40, 57, 77, 100, 126, 155, 187, 222, 260, 301, 345,
		392, 442, 495, 551, 610, 672, 737, 805, 876, 950, 1027, 1107, 1190,
		1276, 1365, 1457, 1552, 1650, 1751, 1855, 1962, 2072, 2185, 2301, 2420,
		2542, 2667, 2795, 2926, 3060, 3197, 3337, 3480,
	}

	assert(solve(3) == 15)
	assert(solve(4) == 26)

	for i := range tab {
		assert(solve(i) == tab[i])
	}

	for i := range 10000 {
		assert(solve(i) == solvebf(i))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A005449
func solve(n int) int {
	return n * (3*n + 1) / 2
}

func solvebf(n int) int {
	r := 0
	for i := 1; i <= n; i++ {
		r += (3 * i) - 1
	}
	return r
}
