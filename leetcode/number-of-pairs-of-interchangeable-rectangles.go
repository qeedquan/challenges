/*

You are given n rectangles represented by a 0-indexed 2D integer array rectangles, where rectangles[i] = [widthi, heighti] denotes the width and height of the ith rectangle.

Two rectangles i and j (i < j) are considered interchangeable if they have the same width-to-height ratio.
More formally, two rectangles are interchangeable if widthi/heighti == widthj/heightj (using decimal division, not integer division).

Return the number of pairs of interchangeable rectangles in rectangles.

Example 1:

Input: rectangles = [[4,8],[3,6],[10,20],[15,30]]
Output: 6
Explanation: The following are the interchangeable pairs of rectangles by index (0-indexed):
- Rectangle 0 with rectangle 1: 4/8 == 3/6.
- Rectangle 0 with rectangle 2: 4/8 == 10/20.
- Rectangle 0 with rectangle 3: 4/8 == 15/30.
- Rectangle 1 with rectangle 2: 3/6 == 10/20.
- Rectangle 1 with rectangle 3: 3/6 == 15/30.
- Rectangle 2 with rectangle 3: 10/20 == 15/30.

Example 2:

Input: rectangles = [[4,5],[7,8]]
Output: 0
Explanation: There are no interchangeable pairs of rectangles.

Constraints:

n == rectangles.length
1 <= n <= 10^5
rectangles[i].length == 2
1 <= widthi, heighti <= 10^5

Hint 1
Store the rectangle height and width ratio in a hashmap.

Hint 2
Traverse the ratios, and for each ratio, use the frequency of the ratio to add to the total pair count.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][2]int{{4, 8}, {3, 6}, {10, 20}, {15, 30}}, 6)
	test([][2]int{{4, 5}, {7, 8}}, 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(rectangles [][2]int, expected int) {
	result := interchanges(rectangles)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func interchanges(rectangles [][2]int) int {
	count := make(map[[2]int]int)
	for _, rectangle := range rectangles {
		width := rectangle[0]
		height := rectangle[1]
		multiple := gcd(width, height)
		key := [2]int{width / multiple, height / multiple}
		count[key] += 1
	}

	total := 0
	for _, value := range count {
		total += value * (value - 1) / 2
	}
	return total
}

func gcd(a, b int) int {
	for b != 0 {
		t := b
		b = a % b
		a = t
	}
	return a
}
