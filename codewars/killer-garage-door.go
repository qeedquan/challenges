/*

Situation
You have been hired by a company making electric garage doors. Accidents with the present product line have resulted in numerous damaged cars, broken limbs and several killed pets. Your mission is to write a safer version of their controller software.

Specification
We always start with a closed door. The remote control has exactly one button, with the following behaviour.

If the door is closed, a push starts opening the door, and vice-versa
It takes 5 seconds for the door to open or close completely
While the door is moving, one push pauses movement, another push resumes movement in the same direction
In order to make the door safer, it has been equipped with resistance-based obstacle detection. When the door detects an obstacle, it must immediately reverse the direction of movement.

Input
A string where each character represents one second, with the following possible values.

'.' No event
'P' Button has been pressed
'O' Obstacle has been detected (supersedes P)
As an example, '..P....' means that nothing happens for two seconds, then the button is pressed, then no further events.

Output
A string where each character represents one second and indicates the position of the door (0 if fully closed and 5 fully open). The door starts moving immediately, hence its position changes at the same second as the event.

Example
..P...O..... as input should yield 001234321000 as output

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(door("...P") == "0001")
	assert(door("P....") == "12345")
	assert(door("P.....P....") == "12345543210")
	assert(door("P.P..") == "12222")
	assert(door("P.P..P..") == "12222345")
	assert(door("P...O.....") == "1234321000")
	assert(door("P..OP..P..") == "1232222100")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func door(events string) string {
	output := new(bytes.Buffer)
	state := 0
	move := 0
	direction := 1
	run := 1
	for _, event := range events {
		switch event {
		case 'P':
			if move == 1 {
				run ^= 1
			} else {
				move = 1
			}

		case 'O':
			direction = -direction

		case '.':

		default:
			return "ERROR"
		}

		state += move * direction * run
		if move == 1 && (state <= 0 || state >= 5) {
			state = clamp(state, 0, 5)
			move = 0
			direction = -direction
		}

		fmt.Fprint(output, state)
	}
	return output.String()
}

func clamp(x, a, b int) int {
	return max(a, min(x, b))
}
