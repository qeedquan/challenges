/*

You are given a stream of points on the X-Y plane. Design an algorithm that:

    Adds new points from the stream into a data structure. Duplicate points are allowed and should be treated as different points.
    Given a query point, counts the number of ways to choose three points from the data structure such that the three points and the query point form an axis-aligned square with positive area.

An axis-aligned square is a square whose edges are all the same length and are either parallel or perpendicular to the x-axis and y-axis.

Implement the DetectSquares class:

    DetectSquares() Initializes the object with an empty data structure.
    void add(int[] point) Adds a new point point = [x, y] to the data structure.
    int count(int[] point) Counts the number of ways to form axis-aligned squares with point point = [x, y] as described above.

Example 1:

https://assets.leetcode.com/uploads/2021/09/01/image.png
Input
["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]
[[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], [[11, 10]]]
Output
[null, null, null, null, 1, 0, null, 2]

Explanation
DetectSquares detectSquares = new DetectSquares();
detectSquares.add([3, 10]);
detectSquares.add([11, 2]);
detectSquares.add([3, 2]);
detectSquares.count([11, 10]); // return 1. You can choose:
                               //   - The first, second, and third points
detectSquares.count([14, 8]);  // return 0. The query point cannot form a square with any points in the data structure.
detectSquares.add([11, 2]);    // Adding duplicate points is allowed.
detectSquares.count([11, 10]); // return 2. You can choose:
                               //   - The first, second, and third points
                               //   - The first, third, and fourth points
Constraints:

    point.length == 2
    0 <= x, y <= 1000
    At most 3000 calls in total will be made to add and count.

Hint 1
Maintain the frequency of all the points in a hash map.

Hint 2
Traverse the hash map and if any point has the same y-coordinate as the query point, consider this point and the query point to form one of the horizontal lines of the square.

*/

package main

import "image"

func main() {
	d := NewDetector()
	d.Add(image.Pt(3, 10))
	d.Add(image.Pt(11, 2))
	d.Add(image.Pt(3, 2))
	assert(d.Count(image.Pt(11, 10)) == 1)
	assert(d.Count(image.Pt(14, 8)) == 0)
	d.Add(image.Pt(11, 2))
	assert(d.Count(image.Pt(11, 10)) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Detector struct {
	points []image.Point
	counts map[image.Point]int
}

func NewDetector() *Detector {
	return &Detector{
		counts: make(map[image.Point]int),
	}
}

func (d *Detector) Add(point image.Point) {
	d.points = append(d.points, point)
	d.counts[point] += 1
}

func (d *Detector) Count(point image.Point) int {
	result := 0
	for _, location := range d.points {
		if point.X != location.X && point.Y != location.Y && abs(point.X-location.X) == abs(point.Y-location.Y) {
			key0 := image.Pt(point.X, location.Y)
			key1 := image.Pt(location.X, point.Y)
			result += d.counts[key0] * d.counts[key1]
		}
	}
	return result
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
