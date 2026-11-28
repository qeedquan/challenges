/*

An infinite strip of width 1 is divided into 1×1 cells. A robot is located in one of these cells (in the figure, the robot is marked with a square).
The robot moves according to a sequence of commands, where each command is one of three uppercase Latin letters: L, R, or S.

L: the robot moves one cell to the left;

R: the robot moves one cell to the right;

S: the robot remains in its current cell.

The commands are executed in order, starting from the robot's initial position.

\includegraphics{https://static.e-olymp.com/content/26/26e0fe4b79b5813a3437c5c8d7c864fe966b6320.jpg}

Write a program to determine how many distinct cells the robot visits during the execution of its program.

Input
The robot's program is given as a string consisting of the characters L, R, and S. The string contains no more than 10^4 characters.

Output
Print the number of distinct cells visited by the robot while executing its program.

Examples

Input #1
RRSRRLRR

Answer #1
6

*/

package main

func main() {
	assert(solve("RRSRRLRR") == 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) int {
	v := map[int]bool{0: true}
	p := 0
	for _, r := range s {
		switch r {
		case 'R':
			p += 1
		case 'L':
			p -= 1
		}
		v[p] = true
	}
	return len(v)
}
