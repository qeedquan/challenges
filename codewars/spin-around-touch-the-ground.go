/*

Given a list of directions to spin, "left" or "right", return an integer of how many full 360° rotations were made. Note that each word in the array counts as a 90° rotation in that direction.

Worked Example
["right", "right", "right", "right", "left", "right"] ➞ 1
# You spun right 4 times (90 * 4 = 360)
# You spun left once (360 - 90 = 270)
# But you spun right once more to make a full rotation (270 + 90 = 360)

Examples
["left", "right", "left", "right"] ➞ 0

["right", "right", "right", "right", "right", "right", "right", "right"] ➞ 2

["left", "left", "left", "left"] ➞ 1

Notes
Return a positive number.
All tests will only include the words "right" and "left".

*/

package main

func main() {
	assert(spin([]string{"right", "right", "right", "right", "left", "right"}) == 1)
	assert(spin([]string{"left", "right", "left", "right"}) == 0)
	assert(spin([]string{"right", "right", "right", "right", "right", "right", "right", "right"}) == 2)
	assert(spin([]string{"left", "left", "left", "left"}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func spin(turns []string) int {
	angle := 0
	for _, turn := range turns {
		switch turn {
		case "right":
			angle += 90
		case "left":
			angle -= 90
		}
	}
	return abs(angle / 360)
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
