/*

Given five points on a straight line such that their pairwise distances are 1,2,4, ..., 14,18,20 (after ordering), find the respective positions of the five points (relative to the furthest point on the left).

*/

package main

import (
	"fmt"
	"math/rand"
	"sort"
)

func main() {
	x := solve()
	d := sd(x[:])
	fmt.Println(x)
	fmt.Println(d)
}

/*

https://xianblog.wordpress.com/2011/02/04/le-monde-puzzle-4/

A fairly simple puzzle in this weekend Le Monde magazine: given five points on a line such that their pairwise distances are 1,2,4,…,14,18,20,
find the respective positions of the five points over the line and deduce the missing distances.
Without loss of generality, we can set the first point at 0 and the fifth point at 20.
The three remaining points are in between 1 and 19, but again without loss of generality we can choose the fourth point to be at 18. (Else the second point would be at 2.)

Removing 18 from the above takes about the same time! A solution (modulo permutations) is 0, 13, 14, 18, 20.

The idea is to keep generating random points for the 3 unknown points and calculate the flatten sorted distance matrix until we match the pairwise distance we want.

*/

func solve() [5]int {
	x := [5]int{0: 0, 4: 20}
	for {
		x[1] = 1 + rand.Intn(19)
		x[2] = 1 + rand.Intn(19)
		x[3] = 1 + rand.Intn(19)
		if x[1] == x[2] || x[2] == x[3] || x[1] == x[3] {
			continue
		}

		sort.Ints(x[:])
		d := sd(x[:])
		if d[0] == 1 && d[1] == 2 && d[2] == 4 && d[7] == 14 {
			break
		}
	}
	return x
}

func sd(x []int) []int {
	d := []int{}
	n := len(x)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			d = append(d, abs(x[i]-x[j]))
		}
	}
	sort.Ints(d)
	return d
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
