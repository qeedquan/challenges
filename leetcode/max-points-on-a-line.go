/*

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

Example 1:
Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4

Constraints:

1 <= points.length <= 300
points[i].length == 2
-10^4 <= xi, yi <= 10^4
All the points are unique.

*/

package main

func main() {
	assert(maxpoints([][2]int{
		{-1, 1}, {0, 0}, {1, 1}, {2, 2}, {3, 3}, {3, 4},
	}) == 4)

	assert(maxpoints([][2]int{
		{1, 1}, {2, 2}, {3, 3},
	}) == 3)

	assert(maxpoints([][2]int{
		{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4},
	}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://www.geeksforgeeks.org/dsa/count-maximum-points-on-same-line/
func maxpoints(points [][2]int) int {
	size := len(points)
	if size < 2 {
		return size
	}

	maxpoint := 0
	for i := 0; i < size; i++ {
		slopemap := make(map[[2]int]int)
		curmax := 0
		overlaps := 0
		verticals := 0
		for j := i + 1; j < size; j++ {
			switch {
			case points[i] == points[j]:
				overlaps += 1
			case points[i][0] == points[j][0]:
				verticals += 1
			default:
				dy := points[j][1] - points[i][1]
				dx := points[j][0] - points[i][0]
				g := gcd(dx, dy)
				key := [2]int{dy / g, dx / g}
				slopemap[key] += 1
				curmax = max(curmax, slopemap[key])
			}
			curmax = max(curmax, verticals)
		}
		maxpoint = max(maxpoint, curmax+overlaps+1)
	}
	return maxpoint
}

func gcd(a, b int) int {
	for b != 0 {
		t := b
		b = a % b
		a = t
	}
	return a
}
