/*

NOTE: It is recommended to complete the corner case ( https://www.codewars.com/kata/62c4ad0e86f0166ec7bb8485 ) before working on this edge case.

Number Pyramid:
Image a number pyramid starts with 1, and the numbers increasing by 1.

For example, when the pyramid has 4 levels:

   1
  2 3
 4 5 6
7 8 9 10

And the sum of all numbers of the edges (including corners) are:

1 + 2 + 3 + 4 + 6 + 7 + 8 + 9 + 10 = 50 (5 is not on the edges)

Input:
You will be given a number n, which means how many levels the pyramid has.

0 <= n <= 5000

Output:
You need to return the sum of all numbers on the edges (corners are included) of the pyramid.

When there is no level, return 0 as there is no edge.

When there is only one level, return 1 as it is the only number on edge/corner.

Examples:

sum_edges(0) --> 0 or 0.0
sum_edges(1) --> 1 or 1.0
sum_edges(2) --> 6 or 6.0
sum_edges(3) --> 21 or 21.0
sum_edges(4) --> 50 or 50.0

Golfing Message:
The length of your code should be less or equal to 50.

It is possible to do it within the length of 46.

If you like this series, welcome to do other kata ( https://www.codewars.com/collections/code-golf-number-pyramid-series ) of it.

*/

package main

func main() {
	tab := []int{0, 1, 6, 21, 50}
	for i := range tab {
		assert(sumedges(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sumedges(n int) int {
	if n < 1 {
		return 0
	}
	if n == 1 {
		return 1
	}
	return n*(5*n*n-3*n+10)/6 - 2
}
