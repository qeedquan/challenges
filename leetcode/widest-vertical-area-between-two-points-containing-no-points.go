/*

Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.

A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.

Note that points on the edge of a vertical area are not considered included in the area.

Example 1:
Input: points = [[8,7],[9,9],[7,4],[9,7]]
Output: 1
Explanation: Both the red and the blue area are optimal.

Example 2:
Input: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
Output: 3

Constraints:

    n == points.length
    2 <= n <= 10^5
    points[i].length == 2
    0 <= xi, yi <= 10^9

Hint 1
Try sorting the points

Hint 2
Think whether the y-axis of a point is relevant

*/

package main

import "sort"

func main() {
	assert(widest([][2]int{
		{8, 7},
		{9, 9},
		{7, 4},
		{9, 7},
	}) == 1)

	assert(widest([][2]int{
		{3, 1},
		{9, 0},
		{1, 0},
		{1, 4},
		{5, 3},
		{8, 8},
	}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func widest(p [][2]int) int {
	xs := []int{}
	for _, p := range p {
		xs = append(xs, p[0])
	}
	sort.Ints(xs)

	r, i := 0, -1
	for _, x := range xs {
		if i != -1 {
			r = max(r, x-i)
		}
		i = x
	}
	return r
}
