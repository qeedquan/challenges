/*

Description

The cows don't use actual bowling balls when they go bowling. They each take a number (in the range 0..99), though, and line up in a standard bowling-pin-like triangle like this:

          7



        3   8



      8   1   0



    2   7   4   4



  4   5   2   6   5
Then the other cows traverse the triangle starting from its tip and moving "down" to one of the two diagonally adjacent cows until the "bottom" row is reached. The cow's score is the sum of the numbers of the cows visited along the way. The cow with the highest score wins that frame.

Given a triangle with N (1 <= N <= 350) rows, determine the highest possible sum achievable.

Input

Line 1: A single integer, N

Lines 2..N+1: Line i+1 contains i space-separated integers that represent row i of the triangle.

Output

Line 1: The largest sum achievable using the traversal rules

Sample Input

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

Sample Output

30

Hint

Explanation of the sample:

          7

         *

        3   8

       *

      8   1   0

       *

    2   7   4   4

       *

  4   5   2   6   5
The highest score is achievable by traversing the cows as shown above.

Source

USACO 2005 December Bronze

*/

package main

func main() {
	assert(highpoint([][]int{
		{7},
		{3, 8},
		{8, 1, 0},
		{2, 7, 4, 4},
		{4, 5, 2, 6, 5},
	}) == 30)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func highpoint(a [][]int) int {
	n := len(a)
	if n == 0 {
		return 0
	}
	p := alloc(n)

	p[0][0] = a[0][0]
	for i := 1; i < n; i++ {
		for j := 0; j <= i; j++ {
			switch {
			case j == 0:
				p[i][j] = p[i-1][j] + a[i][j]
			case j == i:
				p[i][j] = p[i-1][j-1] + a[i][j]
			case p[i-1][j-1] > p[i-1][j]:
				p[i][j] = p[i-1][j-1] + a[i][j]
			default:
				p[i][j] = p[i-1][j] + a[i][j]
			}
		}
	}

	r := 0
	for i := 0; i < n; i++ {
		r = max(r, p[n-1][i])
	}
	return r
}

func alloc(n int) [][]int {
	p := make([][]int, n)
	t := make([]int, n*n)
	for i := range p {
		p[i] = t[i*n : (i+1)*n]
	}
	return p
}
