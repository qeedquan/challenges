/*

You are given an array of network towers towers, where towers[i] = [xi, yi, qi] denotes the ith network tower with location (xi, yi) and quality factor qi.
All the coordinates are integral coordinates on the X-Y plane, and the distance between the two coordinates is the Euclidean distance.

You are also given an integer radius where a tower is reachable if the distance is less than or equal to radius.
Outside that distance, the signal becomes garbled, and the tower is not reachable.

The signal quality of the ith tower at a coordinate (x, y) is calculated with the formula ⌊qi / (1 + d)⌋, where d is the distance between the tower and the coordinate.
The network quality at a coordinate is the sum of the signal qualities from all the reachable towers.

Return the array [cx, cy] representing the integral coordinate (cx, cy) where the network quality is maximum.
If there are multiple coordinates with the same network quality, return the lexicographically minimum non-negative coordinate.

Note:

A coordinate (x1, y1) is lexicographically smaller than (x2, y2) if either:
x1 < x2, or
x1 == x2 and y1 < y2.
⌊val⌋ is the greatest integer less than or equal to val (the floor function).

Example 1:
Input: towers = [[1,2,5],[2,1,7],[3,1,9]], radius = 2
Output: [2,1]
Explanation: At coordinate (2, 1) the total quality is 13.
- Quality of 7 from (2, 1) results in ⌊7 / (1 + sqrt(0)⌋ = ⌊7⌋ = 7
- Quality of 5 from (1, 2) results in ⌊5 / (1 + sqrt(2)⌋ = ⌊2.07⌋ = 2
- Quality of 9 from (3, 1) results in ⌊9 / (1 + sqrt(1)⌋ = ⌊4.5⌋ = 4
No other coordinate has a higher network quality.

Example 2:
Input: towers = [[23,11,21]], radius = 9
Output: [23,11]
Explanation: Since there is only one tower, the network quality is highest right at the tower's location.

Example 3:
Input: towers = [[1,2,13],[2,1,7],[0,1,9]], radius = 2
Output: [1,2]
Explanation: Coordinate (1, 2) has the highest network quality.

Constraints:

1 <= towers.length <= 50
towers[i].length == 3
0 <= xi, yi, qi <= 50
1 <= radius <= 50

Hint 1
The constraints are small enough to consider every possible coordinate and calculate its quality.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(
		[][3]int{{1, 2, 5}, {2, 1, 7}, {3, 1, 9}}, 2,
		[2]int{2, 1},
	)
	test(
		[][3]int{{23, 11, 21}}, 9,
		[2]int{23, 11},
	)
	test(
		[][3]int{{1, 2, 13}, {2, 1, 7}, {0, 1, 9}}, 2,
		[2]int{1, 2},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(towers [][3]int, radius int, expected [2]int) {
	result := coordinate(towers, radius)
	fmt.Println(result)
	assert(result == expected)
}

func coordinate(towers [][3]int, radius int) [2]int {
	x0 := math.MaxInt
	x1 := math.MinInt
	y0 := math.MaxInt
	y1 := math.MinInt
	for _, t := range towers {
		x0 = min(x0, t[0])
		x1 = max(x1, t[0])
		y0 = min(y0, t[1])
		y1 = max(y1, t[1])
	}

	r := [2]int{}
	m := 0
	for x := x0; x <= x1; x++ {
		for y := y0; y <= y1; y++ {
			q := 0
			for _, t := range towers {
				d := math.Sqrt(float64((t[0]-x)*(t[0]-x) + (t[1]-y)*(t[1]-y)))
				if d <= float64(radius) {
					q += int(float64(t[2]) / (1 + d))
				}
			}

			if q > m {
				m = q
				r = [2]int{x, y}
			}
		}
	}
	return r
}
