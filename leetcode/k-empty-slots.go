/*

You have N bulbs in a row numbered from 1 to N. Initially, all the bulbs are turned off. We turn on exactly one bulb everyday until all bulbs are on after N days.

You are given an array bulbs of length N where bulbs[i] = x means that on the (i+1)th day, we will turn on the bulb at position x where i is 0-indexed and x is 1-indexed.

Given an integer K, find out the minimum day number such that there exists two turned on bulbs that have exactly K bulbs between them that are all turned off.

If there isn't such day, return -1.

Example 1:

Input:
bulbs: [1,3,2]
K: 1
Output: 2
Explanation:
On the first day: bulbs[0] = 1, first bulb is turned on: [1,0,0]
On the second day: bulbs[1] = 3, third bulb is turned on: [1,0,1]
On the third day: bulbs[2] = 2, second bulb is turned on: [1,1,1]
We return 2 because on the second day, there were two on bulbs with one off bulb between them.
Example 2:

Input:
bulbs: [1,2,3]
K: 1
Output: -1

Note:

1 <= N <= 20000
1 <= bulbs[i] <= N
bulbs is a permutation of numbers from 1 to N.
0 <= K <= 20000

*/

package main

import "math"

func main() {
	assert(kempty([]int{1, 3, 2}, 1) == 2)
	assert(kempty([]int{1, 2, 3}, 1) == -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func kempty(f []int, k int) int {
	d := make([]int, len(f))
	for i := range f {
		d[f[i]-1] = i
	}

	v := math.MaxInt
	l := 0
	r := k + 1
	for i := 0; r < len(d); i++ {
		if d[i] < d[l] || d[i] <= d[r] {
			if i == r {
				v = min(v, max(d[l], d[r]))
			}
			l = i
			r = k + i + 1
		}
	}
	if v == math.MaxInt {
		return -1
	}
	return v + 1
}
