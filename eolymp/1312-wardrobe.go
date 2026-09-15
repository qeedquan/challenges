/*

A wardrobe has dimensions a×b×c. Is it possible to carry it through a doorway of size x×y?
The wardrobe can pass through the doorway if there exist two of its dimensions such that, after possibly rotating the wardrobe,
both are less than or equal to the corresponding dimensions of the doorway.

Input
Integer numbers a,b,c,x,y (1≤a,b,c,x,y≤100).

Output
Output YES if it is possible to carry the wardrobe through the doorway; otherwise, output NO.

Examples

Input #1
4 5 6 10 20

Answer #1
YES

Input #5
6 5 4 4 5

Answer #5
YES

*/

package main

func main() {
	assert(solve(4, 5, 6, 10, 20) == "YES")
	assert(solve(6, 5, 4, 4, 5) == "YES")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b, c, x, y int) string {
	if (c <= y && a <= x) || (c <= y && b <= x) || (b <= y && a <= x) || (c <= x && a <= y) || (c <= x && b <= y) || (b <= x && a <= y) {
		return "YES"
	}
	return "NO"
}
