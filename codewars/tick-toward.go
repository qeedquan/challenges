/*

Define a function that generates medial values between two coordinates and returns them in an array from start to target. For example, if the starting point is [1,1] and the target point is [3,2] then the shortest route from start to target would be [[1,1], [2,2], [3,2]]. The route should go only through integral coordinates.

Note: you should move diagonally until the path from your current position to the target can be represented as a fully horizontal/vertical line.

Examples:
tickToward([5,5],[5,7])  // => [[5,5],[5,6],[5,7]]
tickToward([3,2],[4,5])  // => [[3,2],[4,3],[4,4],[4,5]]
tickToward([5,1],[5,-2]) // => [[5,1],[5,0],[5,-1],[5,-2]]

*/

package main

import (
	"fmt"
	"image"
)

func main() {
	fmt.Println(ticktoward(image.Pt(5, 5), image.Pt(5, 7)))
	fmt.Println(ticktoward(image.Pt(3, 2), image.Pt(4, 5)))
	fmt.Println(ticktoward(image.Pt(5, 1), image.Pt(5, -2)))
}

func ticktoward(start, end image.Point) []image.Point {
	position := start
	route := []image.Point{position}
	for position != end {
		if position.X < end.X {
			position.X++
		} else if position.X > end.X {
			position.X--
		}
		if position.Y < end.Y {
			position.Y++
		} else if position.Y > end.Y {
			position.Y--
		}
		route = append(route, position)
	}
	return route
}
