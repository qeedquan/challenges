/*

You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.

Example 1:

Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.

Example 2:

Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91


Constraints:

1 <= boxTypes.length <= 1000
1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
1 <= truckSize <= 10^6

Hint:
If we have space for at least one box, it's always optimal to put the box with the most units.
Sort the box types with the number of units per box non-increasingly.
Iterate on the box types and take from each type as many as you can.

*/

package main

import "sort"

func main() {
	assert(maxunits([][2]int{{1, 3}, {2, 2}, {3, 1}}, 4) == 8)
	assert(maxunits([][2]int{{5, 10}, {2, 5}, {4, 7}, {3, 9}}, 10) == 91)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxunits(a [][2]int, t int) int {
	sort.Slice(a, func(i, j int) bool {
		return a[j][1] < a[i][1]
	})

	r := 0
	for _, v := range a {
		c := min(v[0], t)
		r += c * v[1]
		if t -= c; t <= 0 {
			break
		}
	}
	return r
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
