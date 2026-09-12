/*

Given the coordinates (x,y) of some points in 2-dimensional plane, find out which quadrant (Q1-Q4) the points belong to.
Some points belong to AXIS if they are located on X-axis or Y-axis.

https://static.e-olymp.com/content/ef/eff09728cf8fc39206c9971c2c891674f186724d.jpg

Input
The first line contains an integer n (1≤n≤1000) which determines the number of points.
The following n lines contain two integers which correspond to the coordinates (xi,yi) of each point (-10^6≤xi,yi≤10^6).

Output
Print out the total number of points in each quadrant and the axis in the same format as the sample output below.

Examples

Input #1
5
0 0
0 1
1 1
3 -3
2 2

Answer #1
Q1: 2
Q2: 0
Q3: 0
Q4: 1
AXIS: 2

*/

package main

import (
	"fmt"
)

func main() {
	solve([][2]int{
		{0, 0},
		{0, 1},
		{1, 1},
		{3, -3},
		{2, 2},
	})
}

func solve(p [][2]int) {
	var q1, q2, q3, q4, qa int
	for _, p := range p {
		x, y := p[0], p[1]
		switch {
		case x == 0 || y == 0:
			qa += 1
		case x > 0 && y > 0:
			q1++
		case x > 0 && y < 0:
			q4++
		case x < 0 && y > 0:
			q2++
		case x < 0 && y < 0:
			q3++
		}
	}

	fmt.Printf("Q1: %d\n", q1)
	fmt.Printf("Q2: %d\n", q2)
	fmt.Printf("Q3: %d\n", q3)
	fmt.Printf("Q4: %d\n", q4)
	fmt.Printf("AXIS: %d\n", qa)
}
