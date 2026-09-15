/*

Given positive integer n < 10, create a 2 dimensional matrix where each location is filled with its x and y index (starting from the top left).

For example:

Input: 2

00 10
10 11
Input: 3

00 10 20
01 11 21
02 12 22
Once the grid is created, randomly fill each index. This can be with an 'x' or any other way to denote a spot has been filled.

You determine which location to fill by randomly generating indices to fill the matrix. You can only fill n^2 times so you cannot fill as many times as you want until the matrix is completely filled. At the end the matrix must be filled so you must do some work to make sure that you check the random numbers that you use to fill to make sure that spot is not already filled.

Refresh or print after each fill in order to show the progression of the filling iterations.

Example for filling:

Input: 2

00 10
01 11
00 is randomly chosen:

XX 10
01 11
01 is randomly chosen:

XX 10
XX 11
00 is randomly chosen, but since it's already been chosen a re-roll chooses 10:

XX XX
XX 11
11 is randomly chosen:

XX XX
XX XX
Do not print out the random numbers as visually I should be able to see which index was selected. By this I mean do not print "11 is randomly chosen:". It is here for exploratory sake.

Since this is code-golf The shortest code wins.

Have fun and happy golfing!

*/

package main

import (
	"fmt"
	"math/rand/v2"
)

func main() {
	gen(2)
	gen(3)
}

func gen(n int) {
	fmt.Printf("n=%d\n", n)
	if n < 0 || n >= 10 {
		return
	}

	m := alloc(n)
	p := rand.Perm(n * n)
	for _, i := range p {
		m[i/n][i%n] = "XX"
		dump(m)
	}
}

func alloc(n int) [][]string {
	m := make([][]string, n)
	for i := range m {
		m[i] = make([]string, n)
		for j := range m {
			m[i][j] = fmt.Sprintf("%02d", 10*j+i)
		}
	}
	return m
}

func dump(m [][]string) {
	for i := range m {
		for j := range m[i] {
			fmt.Printf("%-3s", m[i][j])
		}
		fmt.Println()
	}
	fmt.Println()
}
