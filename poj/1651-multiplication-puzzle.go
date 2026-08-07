/*

Description

The multiplication puzzle is played with a row of cards, each containing a single positive integer. During the move player takes one card out of the row and scores the number of points equal to the product of the number on the card taken and the numbers on the cards on the left and on the right of it. It is not allowed to take out the first and the last card in the row. After the final move, only two cards are left in the row.

The goal is to take cards in such order as to minimize the total number of scored points.

For example, if cards in the row contain numbers 10 1 50 20 5, player might take a card with 1, then 20 and 50, scoring
10*1*50 + 50*20*5 + 10*50*5 = 500+5000+2500 = 8000

If he would take the cards in the opposite order, i.e. 50, then 20, then 1, the score would be
1*50*20 + 1*20*5 + 10*1*5 = 1000+100+50 = 1150.

Input

The first line of the input contains the number of cards N (3 <= N <= 100). The second line contains N integers in the range from 1 to 100, separated by spaces.

Output

Output must contain a single integer - the minimal score.

Sample Input

6
10 1 50 50 20 5

Sample Output

3650

Source

Northeastern Europe 2001, Far-Eastern Subregion

*/

package main

import "math"

func main() {
	assert(minscore([]int{10, 1, 50, 20, 5}) == 1150)
	assert(minscore([]int{10, 1, 50, 50, 20, 5}) == 3650)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func minscore(x []int) int {
	n := len(x)
	if n == 0 {
		return 0
	}

	p := alloc(n)
	for l := 1; l <= n-2; l++ {
		for s := 0; s+l+1 < n; s++ {
			e := s + l + 1
			if l == 1 {
				p[s][e] = x[s] * x[s+1] * x[e]
			} else {
				p[s][e] = math.MaxInt
				for i := s + 1; i < e; i++ {
					p[s][e] = min(p[s][e], p[s][i]+p[i][e]+x[s]*x[i]*x[e])
				}
			}
		}
	}
	return p[0][n-1]
}

func alloc(n int) [][]int {
	m := make([][]int, n)
	t := make([]int, n*n)
	for i := range m {
		m[i] = t[i*n : (i+1)*n]
	}
	return m
}
