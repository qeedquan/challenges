/*

For the grand opening of the algorithmic games in NlogNsglow, a row of tower blocks is set to be demolished in a grand demonstration of renewal.
Originally the plan was to accomplish this with controlled explosions, one for each tower block, but time constraints now require a hastier solution.

To help you remove the blocks more rapidly you have been given the use of a Universal Kinetic / Incandescent Energy Particle Cannon (UKIEPC).
On a single charge, this cutting-edge contraption can remove either all of the floors in a single tower block, or all the -th floors in all the blocks simultaneously, for user’s choice of the floor number.
In the latter case, the blocks that are less than  floors high are left untouched, while for blocks having more than  floors, all the floors above the removed -th one fall down by one level.

Task
Given the number of floors of all towers, output the minimum number of charges needed to eliminate all floors of all blocks.

Input
The first line of input contains the number of blocks n, where 2 <= n <= 100000. The second line contains consecutive block heights for, where h[i] for 1, 2, ... n, where h[i] <= 1000000.

Output
Output one line containing one integer: the minimum number of charges needed to tear down all the blocks.

Sample Input 1
6
2 1 8 8 2 3

Sample Output 1
5

Sample Input 2
5
1 1 1 1 10

Sample Output 2
2

*/

package main

import (
	"sort"
)

func main() {
	assert(charges([]int{2, 1, 8, 8, 2, 3}) == 5)
	assert(charges([]int{1, 1, 1, 1, 10}) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func charges(a []int) int {
	sort.Ints(a)

	c := 0
	l := 0
	i := 0
	n := len(a)
	for i = 0; i < n; i++ {
		if a[i]-c > n-l {
			break
		}
		if a[i] > c {
			c++
		}
	}
	return c + n - i
}
