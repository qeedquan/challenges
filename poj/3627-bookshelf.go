/*

Description

Farmer John recently bought a bookshelf for cow library, but the shelf is getting filled up quite quickly, and now the only available space is at the top.

Each of the N cows (1 ≤ N ≤ 20,000) has some height of Hi (1 ≤ Hi ≤ 10,000) and a total height summed across all N cows of S. The bookshelf has a height of B (1 ≤ B ≤ S < 2,000,000,007).

To reach the top of the bookshelf taller than the tallest cow, one or more of the cows can stand on top of each other in a stack, so that their total height is the sum of each of their individual heights. This total height must be no less than the height of the bookshelf. Since more cows than necessary in the stack can be dangerous, your job is to find the set of cows that produces a stack of the smallest number of cows possible such that the stack can reach the bookshelf.

Input

* Line 1: Two space-separated integers: N and B
* Lines 2..N+1: Line i+1 contains a single integer: Hi

Output

* Line 1: A single integer representing the size of the smallest set of cows that can reach the bookshelf.

Sample Input

6 40
6
18
11
13
19
11

Sample Output

3
Source

USACO 2007 December Bronze

*/

package main

import "sort"

func main() {
	assert(cows([]int{6, 18, 11, 13, 19, 11}, 40) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cows(a []int, b int) int {
	sort.Ints(a)

	c := 0
	v := 0
	for i := len(a) - 1; i >= 0; i-- {
		v += a[i]
		c += 1
		if v >= b {
			break
		}
	}
	return c
}
