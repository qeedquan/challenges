/*

Preface
You are currently working together with a local community to build a school teaching children how to code. First plans have been made and the community wants to decide on the best location for the coding school. In order to make this decision data about the location of students and potential locations is collected.

Problem
In order to be able to attract and teach as many students as possible we want to minimize the total traveling distance for potential students. The streets system is organized in a traditional grid system and students can only travel horizontally or vertically (not diagonal).

The locations of interested students is given as an array with the first value of each entry presenting the x coordinate and the second value presenting the y coordinate:

var students = [[3,7],[2,2],[14,1], ...];

Potential locations are passed as an array of objects with an unique id, a x and y coordinate:

var locations = [{id: 1, x: 3, y: 4}, {id: 2, x: 8, y: 2}, ...];

Your task is now to evaluate which of the school locations would be best to minimize the distance for all potential students to the school.

The desired output should consist of a string indicating the ID of the best suitable location and the x and y coordinates in the following form:

"The best location is number 1 with the coordinates x = 3 and y = 4"

*/

package main

import (
	"fmt"
	"math"
)

type vec2 struct {
	x, y int
}

type location struct {
	id int
	vec2
}

func main() {
	assert(optimum(
		[]vec2{{3, 7}, {2, 2}, {14, 1}},
		[]location{
			location{1, vec2{3, 4}},
			location{2, vec2{8, 2}},
		},
	) == "The best location is number 1 with the coordinates x = 3 and y = 4")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func optimum(students []vec2, locations []location) string {
	best := location{}
	minimum := math.MaxInt
	for _, location := range locations {
		distance := 0
		for _, student := range students {
			distance += abs(student.x-location.x) + abs(student.y-location.y)
		}
		if distance < minimum {
			minimum = distance
			best = location
		}
	}
	return fmt.Sprintf("The best location is number %v with the coordinates x = %v and y = %v", best.id, best.x, best.y)
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
