/*

Description

N soldiers of the land Gridland are randomly scattered around the country.
A position in Gridland is given by a pair (x,y) of integer coordinates. Soldiers can move - in one move, one soldier can go one unit up, down, left or right (hence, he can change either his x or his y coordinate by 1 or -1).

The soldiers want to get into a horizontal line next to each other (so that their final positions are (x,y), (x+1,y), ..., (x+N-1,y), for some x and y). Integers x and y, as well as the final order of soldiers along the horizontal line is arbitrary.

The goal is to minimise the total number of moves of all the soldiers that takes them into such configuration.

Two or more soldiers must never occupy the same position at the same time.

Input

The first line of the input contains the integer N, 1 <= N <= 10000, the number of soldiers.
The following N lines of the input contain initial positions of the soldiers : for each i, 1 <= i <= N, the (i+1)st line of the input file contains a pair of integers x[i] and y[i] separated by a single blank character, representing the coordinates of the ith soldier, -10000 <= x[i],y[i] <= 10000.

Output

The first and the only line of the output should contain the minimum total number of moves that takes the soldiers into a horizontal line next to each other.

Sample Input

5
1 2
2 2
1 3
3 -2
3 3

Sample Output

8

Source

CEOI 1998

*/

package main

import "sort"

func main() {
	assert(horizontal([]int{1, 2, 1, 3, 3}, []int{2, 2, 3, -2, 3}) == 8)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func horizontal(x, y []int) int {
	sort.Ints(x)
	sort.Ints(y)

	for i := range x {
		x[i] -= i
	}
	sort.Ints(x)

	r := 0
	n := len(x)
	for i := 0; i < n; i++ {
		r += abs(x[i]-x[n/2]) + abs(y[i]-y[n/2])
	}
	return r
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
