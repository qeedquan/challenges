/*

Feynman's squares
Richard Phillips Feynman was a well-known American physicist and a recipient of the Nobel Prize in Physics. He worked in theoretical physics and pioneered the field of quantum computing.

Recently, an old farmer found some papers and notes that are believed to have belonged to Feynman. Among notes about mesons and electromagnetism, there was a napkin where he wrote a simple puzzle: "how many different squares are there in a grid of NxN squares?".

For example, when N=2, the answer is 5: the 2x2 square itself, plus the four 1x1 squares in its corners:

Task
Complete the function that solves Feynman's question in general. The input to your function will always be a positive integer.

Examples
1  -->   1
2  -->   5
3  -->  14

(Adapted from the Sphere Online Judge problem SAMER08F by Diego Satoba)

*/

package main

func main() {
	tab := []int{
		0, 1, 5, 14, 30, 55, 91, 140, 204, 285, 385, 506, 650, 819, 1015, 1240,
		1496, 1785, 2109, 2470, 2870, 3311, 3795, 4324, 4900, 5525, 6201, 6930,
		7714, 8555, 9455, 10416, 11440, 12529, 13685, 14910, 16206, 17575, 19019,
		20540, 22140, 23821, 25585, 27434, 29370,
	}

	for i := range tab {
		assert(squares(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A000330
func squares(n int) int {
	return n * (n + 1) * (2*n + 1) / 6
}
