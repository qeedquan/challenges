/*

You are given an integer array degrees, where degrees[i] represents the desired degree of the ith vertex.

Your task is to determine if there exists an undirected simple graph with exactly these vertex degrees.

A simple graph has no self-loops or parallel edges between the same pair of vertices.

Return true if such a graph exists, otherwise return false.

Example 1:

Input: degrees = [3,1,2,2]

Output: true

Explanation:

One possible undirected simple graph is:

Edges: (0, 1), (0, 2), (0, 3), (2, 3)
Degrees: deg(0) = 3, deg(1) = 1, deg(2) = 2, deg(3) = 2.

Example 2:

Input: degrees = [1,3,3,1]

Output: false

Explanation:

degrees[1] = 3 and degrees[2] = 3 means they must be connected to all other vertices.
This requires degrees[0] and degrees[3] to be at least 2, but both are equal to 1, which contradicts the requirement.
Thus, the answer is false.

*/

package main

import "sort"

func main() {
	assert(simple([]int{3, 1, 2, 2}) == true)
	assert(simple([]int{1, 3, 3, 1}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://en.wikipedia.org/wiki/Erd%C5%91s%E2%80%93Gallai_theorem
func simple(d []int) bool {
	t := 0
	for _, v := range d {
		t += v
	}

	if t%2 != 0 {
		return false
	}

	sort.Slice(d, func(i, j int) bool {
		return d[i] > d[j]
	})

	s1 := t
	s2 := 0
	l := 0
	i := len(d) - 1
	for k := 1; k <= len(d); k++ {
		l += d[k-1]
		s1 -= d[k-1]
		for ; i >= 0 && d[i] < k; i-- {
			s2 += d[i]
		}

		r := k * (k - 1)
		if i-k+1 > 0 {
			r += (i-k+1)*k + s2
		} else {
			r += s1
		}

		if !(l <= r) {
			return false
		}
	}

	return true
}
