/*

Disclaimer: The story told within this question is entirely fictional, and invented solely for the purpose of providing an intro.

My boss has gotten a new toy robot, and he wants me to help program it. He wants to be able to enter simple arrow instructions to get it to move. These instructions are: ^ (for move forward) < (for turn left), and > (for turn right). However, now that I've programmed the robot, he wants additional functionality. He wants me to transform any sequence of arrows he inputs, so that rather than having the robot take the path indicated, it moves to the desired location, indicated by the place it would end up if it had taken the inputted path, as efficiently as possible. I appeal to you, the members of PP&CG, to help me with this task.

Your Task:
Write a program or function to convert a string made up of arrows into a string that will get to the location indicated by the input as quickly as possible. Turning takes exactly as long as moving backwards or forwards.

Input:
A string of arrows, as indicated above. If you wish, different characters may be substituted for the arrows, but be sure to include the fact that you do so in your answer. All test cases use the arrows normally.

Output:
A string of arrows (or your equivalent characters), that take the robot to the desired destination as efficiently as possible.

Test Cases:
Note that the solutions offered are only possibilities, and that other solutions may be valid.

>^<<^^>^^    -> ^^<^
^^^^>^^^^    -> ^^^^>^^^^
>>>^^^^^^    -> <^^^^^^
>^>^>^>^     -> (empty string)
^<^^<^^<^^^^ -> >^^>^

Scoring:
The robot's memory is limited, so your program must have the lowest byte count possible.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	test(">^<<^^>^^", "^^<^")
	test("^^^^>^^^^", "^^^^>^^^^")
	test(">>>^^^^^^", "<^^^^^^")
	test(">^>^>^>^", "")
	test("^<^^<^^<^^^^", ">^^>^")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s, r string) {
	p := efficient(s)
	sx, sy := traverse(s)
	px, py := traverse(p)

	fmt.Printf("(%+d, %+d) %q\n", px, py, p)
	assert(sx == px && sy == py)
	assert(len(p) == len(r))
}

func efficient(s string) string {
	x, y := traverse(s)
	if x == 0 && y == 0 {
		return ""
	}

	t := "<"
	if x > 0 {
		t = ">"
	}

	dx := strings.Repeat("^", abs(x))
	dy := strings.Repeat("^", abs(y))

	r := ""
	switch {
	case y > 0:
		r = fmt.Sprintf("%v", dy)
		if dx != "" {
			r += fmt.Sprintf("%v%v", t, dx)
		}

	default:
		r = fmt.Sprintf("%v%v", t, dx)
		if dy != "" {
			r += fmt.Sprintf("%v%v", t, dy)
		}
	}

	return r
}

func traverse(s string) (int, int) {
	x, y, d := 0, 0, 0
	for _, c := range s {
		switch c {
		case '^':
			switch d {
			case 0:
				y += 1
			case 1:
				x += 1
			case 2:
				y -= 1
			case 3:
				x -= 1
			}
		case '<':
			d = mod(d-1, 4)
		case '>':
			d = mod(d+1, 4)
		}
	}
	return x, y
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}

func mod(x, m int) int {
	x %= m
	if x < 0 {
		x += m
	}
	return x
}
