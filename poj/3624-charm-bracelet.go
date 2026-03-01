/*

Description

Bessie has gone to the mall's jewelry store and spies a charm bracelet. Of course, she'd like to fill it with the best charms possible from the N (1 ≤ N ≤ 3,402) available charms. Each charm i in the supplied list has a weight Wi (1 ≤ Wi ≤ 400), a 'desirability' factor Di (1 ≤ Di ≤ 100), and can be used at most once. Bessie can only support a charm bracelet whose weight is no more than M (1 ≤ M ≤ 12,880).

Given that weight limit as a constraint and a list of the charms with their weights and desirability rating, deduce the maximum possible sum of ratings.

Input

* Line 1: Two space-separated integers: N and M
* Lines 2..N+1: Line i+1 describes charm i with two space-separated integers: Wi and Di

Output

* Line 1: A single integer that is the greatest sum of charm desirabilities that can be achieved given the weight constraints

Sample Input

4 6
1 4
2 6
3 12
2 7

Sample Output

23

Source

USACO 2007 December Silver

*/

package main

func main() {
	assert(charmy([][2]int{
		{1, 4},
		{2, 6},
		{3, 12},
		{2, 7},
	}, 6) == 23)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func charmy(a [][2]int, m int) int {
	p := make([]int, m+1)
	for _, v := range a {
		w, d := v[0], v[1]
		for i := m; i >= w; i-- {
			p[i] = max(p[i], p[i-w]+d)
		}
	}
	return p[m]
}
